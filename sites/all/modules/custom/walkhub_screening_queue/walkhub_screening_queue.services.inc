<?php
/**
 * @file
 * Screening queue resource implementations.
 */


/**
 * The walkhub-walkthrough-screening-queue service resource callback function.
 *
 * @return array
 *   An array of nodes that were marked for screening.
 */
function walkhub_screening_queue_get_queue() {
  // Load the mark for screening flag by machine name.
  $mark_for_screening = flag_get_flag('mark_for_screening');
  // If the flag does not exists return NULL.
  if (!$mark_for_screening) {
    return NULL;
  }

  $query = db_select('node', 'n');
  $query->join('flagging', 'f', 'n.nid = f.entity_id AND f.entity_type = :entity_type AND f.fid = :fid',
    array(':entity_type' => 'node', ':fid' => $mark_for_screening->fid));
  $query->fields('n', array('uuid', 'uid', 'title', 'type', 'nid'));
  $query->fields('f', array('timestamp'));
  $query->orderBy('f.timestamp');

  $results = $query->execute()->fetchAll();
  foreach ($results as $result) {
    $node = node_load($result->nid);

    // Check that the currently logged in user is able to update the node.
    if (node_access('update', $node)) {
      $return[] = $result;
    }
  }

  return $return;
}

/**
 * Create screening node.
 *
 * @param string $title
 *   Node title.
 * @param string $lang
 *   (Optional) Node language.
 * @param string|int $referenced_walkthrough
 *   Walkthrough node nid or uuid.
 *
 * @return string
 *   The newly created screening node uuid.
 */
function walkhub_screening_queue_create_screening($title, $lang = NULL, $referenced_walkthrough = NULL) {
  if ($lang === NULL) {
    $lang = LANGUAGE_NONE;
  }

  $node = new stdClass();
  $node->title = $title;
  $node->type = 'screening';
  $node->language = $lang;

  // Save walkthrough reference.
  if ($referenced_walkthrough) {
    $walkthrough = NULL;

    // Try loading by node id.
    if (is_numeric($referenced_walkthrough)) {
      $walkthrough = node_load($referenced_walkthrough);
    }

    // Try loading by uuid.
    if (!$walkthrough) {
      $walkthroughs = entity_load('node', FALSE, array('uuid' => $referenced_walkthrough));
      $walkthrough = array_pop($walkthroughs);
    }

    if ($walkthrough) {
      $node->field_screening_walkthrough[$lang][0]['target_id'] = $walkthrough->nid;
    }
  }

  node_object_prepare($node);
  node_save($node);

  return $node->uuid;
}

/**
 * Update walkhub screening node.
 *
 * @param string $uuid
 *   Universally Unique ID.
 * @param int $time
 *   Time running the walkthrough took in seconds.
 * @param string $junit
 *   JUnit test output.
 * @param array $screenshots
 *   Screenshot structure.
 *   [step] => (Optional)Step entity id
 *   [file] => Base64 encoded png file
 * @param string $result
 *   Screening result (Successful, Broken, Timeout).
 */
function walkhub_screening_queue_update_screening($uuid, $time, $junit, $screenshots, $result) {
  $screening = entity_load('node', FALSE, array('uuid' => $uuid));
  if (!empty($screening)) {
    $screening = reset($screening);

    if ($screening->type == "screening") {
      $lang = $screening->language;

      $field_instance = field_info_instance('node', 'field_screening_time', 'screening');
      if (!empty($time) && !empty($field_instance)) {
        $screening->field_screening_time[$lang][0]['value'] = (float) $time;
      }

      $field_instance = field_info_instance('node', 'field_screening_junit', 'screening');
      if (!empty($junit) && !empty($field_instance)) {
        $screening->field_screening_junit[$lang][0]['value'] = $junit;
      }

      $field_instance = field_info_instance('node', 'field_screening_result', 'screening');
      if (!empty($result) && !empty($field_instance)) {
        $screening->field_screening_result[$lang][0]['value'] = $result;
      }

      foreach ($screenshots as $screenshot) {
        _walkhub_screening_queue_save_screenshot($screening, $screenshot);
      }

      entity_save('node', $screening);
    }
  }
}

/**
 * Helper function to save a screenshot in a screening.
 *
 * @param object $screening
 *   Walkthrough screening node.
 * @param array $screenshot
 *   Screenshot structure.
 *   [step] => (Optional) Step entity id
 *   [file] => Base64 encoded png file
 */
function _walkhub_screening_queue_save_screenshot($screening, $screenshot) {
  $lang = $screening->language;
  $step = (!empty($screenshot['step'])) ? $screenshot['step'] : _walkhub_screening_queue_get_next_step($screening);

  $file_uri = _walkhub_screening_queue_screenshot_directory() . $screening->nid . '-' . $step . '-' . drupal_random_key() . '.png';
  $file_path = _walkhub_screening_queue_save_base64_image($screenshot['file'], $file_uri);

  $file = new stdClass();
  $file->filename = basename($file_path);
  $file->filepath = $file_path;
  $file->filemime = file_get_mimetype($file_path);
  $file->filesize = filesize($file_path);
  $file->uri = $file_uri;

  $file->uid = $screening->uid;
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);

  $fc = entity_create('field_collection_item', array(
    'field_name' => 'field_screening_fc_screenshots',
  ));

  if ($step) {
    $walkthrough = entity_metadata_wrapper('node', $screening)->field_screening_walkthrough->value();
    if ($walkthrough && _walkhub_screening_queue_walkthrough_has_step($walkthrough, $step)) {
      $fc->field_fc_screenshots_step[$lang][0]['target_id'] = $step;
    }
  }
  $fc->field_fc_screenshots_screenshot[$lang][0]['fid'] = $file->fid;
  $fc->setHostEntity('node', $screening);
  $fc->save();
}

/**
 * Helper function to check if a step is referenced in the walkthrough.
 *
 * @param object $walkthrough
 *   Walkthrough node object.
 * @param int $step
 *   Step entity id.
 *
 * @return bool
 *   TRUE if Walkthrough has $step as a step, FALSE otherwise.
 */
function _walkhub_screening_queue_walkthrough_has_step($walkthrough, $step) {
  $walkthrough_entity = entity_metadata_wrapper('node', $walkthrough);
  foreach ($walkthrough_entity->field_fc_steps->getIterator() as $step_wrapper) {
    if ($step_wrapper->item_id->value() == $step) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Gets the first step without a screenshot from a screening.
 *
 * @param object $screening
 *   Drupal screening node.
 *
 * @return int|null
 *   Step entity id or NULL, if there is no step without a screenshot.
 */
function _walkhub_screening_queue_get_next_step($screening) {
  $lang = $screening->language;

  $walkthrough = entity_metadata_wrapper('node', $screening)->field_screening_walkthrough->value();
  $steps = $walkthrough->field_fc_steps[$lang];

  // Get existing steps into an array.
  $steps = array_map(function($step) {
    return $step['revision_id'];
  }, $steps);

  if ($walkthrough) {
    $screenshots = entity_metadata_wrapper('node', $screening)->field_screening_fc_screenshots->value();

    // Get steps of the screenshots into an array.
    $screenshots = array_map(function($screenshot) {
      $value = NULL;
      if (!empty($screenshot->field_fc_screenshots_step[LANGUAGE_NONE])) {
         $value = $screenshot->field_fc_screenshots_step[language_none][0]['target_id'];
      }
      return $value;
    }, $screenshots);

    // Find the first step we don't have a screenshot of.
    while (!empty($steps)) {
      $step = array_shift($steps);
      if (!in_array($step, $screenshots)) {
        return $step;
      }
    }
  }

  return NULL;
}

/**
 *
 */
function _walkhub_screening_queue_resource_access($op = 'view', $args = array()) {
  module_load_include('inc', 'walkhub');
  return _walkhub_node_resource_access('screening', $op, $args);
}

/**
 * Saves an image from base64 data.
 *
 * @param string $base64_data
 *   Base64 PNG image data.
 * @param string $filename
 *   Target file name.
 *
 * @return string|bool
 *   String of the filename on success, FALSE othwerwise.
 */
function _walkhub_screening_queue_save_base64_image($base64_data, $filename) {
  $tmpfile = drupal_tempnam(file_directory_temp(), 'wh-screening-');
  file_put_contents($tmpfile, base64_decode($base64_data, TRUE));

  $file = file_unmanaged_copy($tmpfile, $filename);
  unlink($tmpfile);

  return $file;
}

/**
 * Prepares the screenshot directory.
 *
 * @return string
 *   Screenshot directory.
 */
function _walkhub_screening_queue_screenshot_directory() {
  $directory = 'public://wh-screening/';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY|FILE_MODIFY_PERMISSIONS);

  return $directory;
}

<?php
/**
 * @file
 *  Resource implementations.
 */


/**
 * The walkhub-walkthrough-screening-queue service resource callback function.
 *
 * @return array
 *  An array of nodes that were marked for screening.
 */
function _walkhub_screening_queue_get_queue() {
  // Load the mark for screening flag by machine name.
  $mark_for_screening = flag_get_flag('mark_for_screening');
  // If the flag does not exists return NULL.
  if (!$mark_for_screening) {
    return NULL;
  }

  $query = db_select('node', 'n');
  $query->join('flagging', 'f', 'n.nid = f.entity_id AND f.entity_type = :entity_type AND f.fid = :fid',
    array(':entity_type' => 'node', ':fid' => $mark_for_screening->fid));
  $query->fields('n', array('uuid', 'uid', 'title', 'type'));
  $query->fields('f', array('timestamp'));
  $query->orderBy('f.timestamp');

  return $query->execute()->fetchAll();
}

/**
 * Create screening node.
 *
 * @param string $title
 * @param string $lang
 *
 * @return
 *  The newly created screening node uuid.
 */
function _walkhub_screening_queue_create_screening($title, $lang = LANGUAGE_NONE) {
  $node = new stdClass();
  $node->title = $title;
  $node->type = 'screening';
  $node->language = $lang;
  node_object_prepare($node);

  node_save($node);

  return $node->uuid;
}

/**
 *
 *
 * @param $uuid
 * @param $time
 * @param $junit
 * @param $screenshots
 */
function _walkhub_screening_queue_update_screening($uuid, $time, $junit, $screenshots) {
  $screening = entity_load('node', FALSE, array('uuid' => $uuid));
  if (!empty($screening)) {
    $screening = reset($screening);

    if ($screening->type == "screening") {
      $lang = $screening->language;

      $field_instance = field_info_instance('node', 'field_screening_time', 'screening');
      if (!empty($time) && !empty($field_instance)) {
        $screening->field_screening_time[$lang][0]['value'] = $time;
      }

      $field_instance = field_info_instance('node', 'field_screening_junit', 'screening');
      if (!empty($junit) && !empty($field_instance)) {
        $screening->field_screening_junit[$lang][0]['value'] = $junit;
      }

      foreach ($screenshots as $screenshot) {
        // @todo get next step by default
        $step = $screenshot['step'];

        $file_uri = _walkhub_screening_screenshot_directory() . $screening->nid . '-' . $step . '-' . drupal_random_key() . '.png';
        $file_path = _walkhub_screening_save_base64_image($screenshot['file'], $file_uri);

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

        $fc->field_fc_screenshots_step[$lang][0]['target_id'] = $step;
        $fc->field_fc_screenshots_screenshot[$lang][0]['fid'] = $file->fid;
        $fc->setHostEntity('node', $screening);
        $fc->save();
      }

      entity_save('node', $screening);
    }
  }
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
 * @param $base64_data string
 * @param $filename string
 *
 * @return string|bool
 *   String of the filename on success, FALSE othwerwise.
 */
function _walkhub_screening_save_base64_image($base64_data, $filename) {
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
function _walkhub_screening_screenshot_directory() {
  $directory = 'public://wh-screening/';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY|FILE_MODIFY_PERMISSIONS);

  return $directory;
}

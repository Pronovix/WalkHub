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

      $field_instance = field_info_instance('field_collection_item', 'field_fc_screenshots_screenshot',
        'field_screening_fc_screenshots');

      module_load_include('inc', 'services', 'resources/node_resources');
      list($files, $file_objs) = _node_resource_file_save_upload('screening', 'field_fc_screenshots_screenshot');
      if (!empty($screenshots) && is_array($screenshots) && !empty($field_instance)) {
        foreach ($file_objs as $file) {

        }
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

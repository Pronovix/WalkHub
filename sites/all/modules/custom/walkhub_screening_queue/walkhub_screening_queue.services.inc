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
  $return = array();

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

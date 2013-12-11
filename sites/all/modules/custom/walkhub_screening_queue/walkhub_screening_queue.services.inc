<?php
/**
 * @file
 *  Resource implementations.
 */


/**
 * Mark for screening flag entity id (fid).
 */
define('MARK_FOR_SCREENING_FID', 2);


/**
 * The walkhub-walkthrough-screening-queue service resource callback function.
 *
 * @return array
 *  An array filled wit walkthroughs or walkthrough_set uuid that has marked for screening.
 */
function _walkhub_screening_queue_get_queue() {
  $query = db_select('node', 'n');
  $query->join('flagging', 'f', 'n.nid = f.entity_id AND f.entity_type = :entity_type AND f.fid = :fid',
    array(':entity_type' => 'node', ':fid' => MARK_FOR_SCREENING_FID));
  $query->fields('n', array('uuid', 'uid', 'title', 'type'));
  $query->fields('f', array('timestamp'));
  $query->orderBy('f.timestamp');

  return $query->execute()->fetchAll();
}

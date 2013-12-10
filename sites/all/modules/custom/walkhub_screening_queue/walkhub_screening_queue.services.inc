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
 * Walkthrough content type machine name.
 */
define('WALKTHROUGH_CONTENT_TYPE', 'walkthrough');

/**
 * Walkthrough set content type machine name.
 */
define('WALKTHROUGH_SET_CONTENT_TYPE', 'walkthrough_set');


/**
 * The walkhub-walkthrough-screening-queue service resource callback function.
 *
 * @return array
 *  Every walkthrough's uuid that has marked for screening.
 */
function _walkhub_screening_queue_get_queue() {
  $query = db_select('node', 'n');
  $query->join('flagging', 'f', 'n.nid = f.entity_id AND f.entity_type = :entity_type AND f.fid = :fid',
    array(':entity_type' => 'node', ':fid' => MARK_FOR_SCREENING_FID));
  $query->condition('n.type', WALKTHROUGH_CONTENT_TYPE);
  $query->fields('n', array('uuid'));
  $query->orderBy('f.timestamp');

  return $query->execute()->fetchCol();
}

/**
 * The walkhub-walkthrough-set-screening-queue service resource callback function.
 *
 * @return array
 *  Every walkthrough's uuid that has marked for screening.
 */
function walkhub_walkthrough_set_screening_queue_get_queue() {
  $query = db_select('node', 'n');
  $query->join('flagging', 'f', 'n.nid = f.entity_id AND f.entity_type = :entity_type AND f.fid = :fid',
    array(':entity_type' => 'node', ':fid' => MARK_FOR_SCREENING_FID));
  $query->condition('n.type', WALKTHROUGH_SET_CONTENT_TYPE);
  $query->fields('n', array('uuid'));
  $query->orderBy('f.timestamp');

  return $query->execute()->fetchCol();
}

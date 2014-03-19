<?php
/**
 * @file
 * walkthrough_screening.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkthrough_screening_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function walkthrough_screening_flag_default_flags() {
  $flags = array();
  // Exported flag: "Mark for screening".
  $flags['mark_for_screening'] = array(
    'entity_type' => 'node',
    'title' => 'Mark for screening',
    'global' => 1,
    'types' => array(
      0 => 'walkthrough',
      1 => 'walkthrough_set',
    ),
    'flag_short' => 'Mark for screening',
    'flag_long' => 'Add to the screening queue',
    'flag_message' => 'Marked for screening',
    'unflag_short' => 'Undo Mark for screening',
    'unflag_long' => 'Remove from the screening queue',
    'unflag_message' => 'Not marked for screening',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'entity_reference' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'walkthrough_screening',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function walkthrough_screening_node_info() {
  $items = array(
    'screening' => array(
      'name' => t('Screening'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

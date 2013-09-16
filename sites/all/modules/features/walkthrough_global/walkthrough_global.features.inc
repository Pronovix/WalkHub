<?php
/**
 * @file
 * walkthrough_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkthrough_global_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function walkthrough_global_flag_default_flags() {
  $flags = array();
  // Exported flag: "Walkthrough broken".
  $flags['walkthrough_broken'] = array(
    'entity_type' => 'node',
    'title' => 'Walkthrough broken',
    'global' => 0,
    'types' => array(
      0 => 'walkthrough',
    ),
    'flag_short' => 'Mark walkthrough as broken',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark walkthrough as working',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'walkthrough_global',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

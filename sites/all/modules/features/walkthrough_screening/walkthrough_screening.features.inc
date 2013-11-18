<?php
/**
 * @file
 * walkthrough_screening.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkthrough_screening_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
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

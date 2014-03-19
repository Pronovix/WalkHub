<?php
/**
 * @file
 * walkhub_collections.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_collections_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function walkhub_collections_node_info() {
  $items = array(
    'walkthrough_collection' => array(
      'name' => t('Private Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'walkthrough_public_collection' => array(
      'name' => t('Public Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

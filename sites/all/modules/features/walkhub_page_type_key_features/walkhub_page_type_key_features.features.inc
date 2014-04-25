<?php
/**
 * @file
 * walkhub_page_type_key_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_page_type_key_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function walkhub_page_type_key_features_node_info() {
  $items = array(
    'walkhub_key_feature' => array(
      'name' => t('Walkhub key feature'),
      'base' => 'node_content',
      'description' => t('This node type represents a key feature.'),
      'has_title' => '1',
      'title_label' => t('Feature Title'),
      'help' => '',
    ),
  );
  return $items;
}

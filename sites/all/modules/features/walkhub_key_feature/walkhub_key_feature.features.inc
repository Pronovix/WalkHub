<?php
/**
 * @file
 * walkhub_key_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_key_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function walkhub_key_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function walkhub_key_feature_node_info() {
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

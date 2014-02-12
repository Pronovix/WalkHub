<?php
/**
 * @file
 * blog_entry_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function blog_entry_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function blog_entry_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function blog_entry_features_node_info() {
  $items = array(
    'blog_entry' => array(
      'name' => t('Blog entry'),
      'base' => 'node_content',
      'description' => t('This node type represents a Blog article content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

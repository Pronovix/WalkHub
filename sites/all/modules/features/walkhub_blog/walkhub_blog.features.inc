<?php
/**
 * @file
 * walkhub_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function walkhub_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function walkhub_blog_node_info() {
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

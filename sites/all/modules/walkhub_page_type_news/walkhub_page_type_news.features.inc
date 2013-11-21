<?php
/**
 * @file
 * walkhub_page_type_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_page_type_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function walkhub_page_type_news_node_info() {
  $items = array(
    'walkhub_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

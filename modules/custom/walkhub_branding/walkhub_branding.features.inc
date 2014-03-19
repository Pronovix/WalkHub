<?php
/**
 * @file
 * walkhub_branding.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_branding_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function walkhub_branding_node_info() {
  $items = array(
    'branding' => array(
      'name' => t('Branding'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * walkhub.features.inc
 */

/**
 * Implements hook_views_api().
 */
function walkhub_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_ctools_plugin_api().
 */
function walkhub_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function walkhub_node_info() {
  $items = array(
    'step' => array(
      'name' => t('Step'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'walkthrough' => array(
      'name' => t('Walkthrough'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}

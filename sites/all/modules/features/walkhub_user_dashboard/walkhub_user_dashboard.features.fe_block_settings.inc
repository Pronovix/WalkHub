<?php
/**
 * @file
 * walkhub_user_dashboard.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function walkhub_user_dashboard_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-user-account-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-user-account-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'walkhub_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'walkhub_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

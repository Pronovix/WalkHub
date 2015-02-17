<?php
/**
 * @file
 * walkhub_user_dashboard.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function walkhub_user_dashboard_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-user-account-menu.
  $menus['menu-user-account-menu'] = array(
    'menu_name' => 'menu-user-account-menu',
    'title' => 'User account menu',
    'description' => 'This is the menu to controll the user account',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('This is the menu to controll the user account');
  t('User account menu');


  return $menus;
}

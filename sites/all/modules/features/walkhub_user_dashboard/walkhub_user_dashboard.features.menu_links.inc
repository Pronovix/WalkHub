<?php
/**
 * @file
 * walkhub_user_dashboard.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function walkhub_user_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-user-account-menu_add-content:walkthrough/record
  $menu_links['menu-user-account-menu_add-content:walkthrough/record'] = array(
    'menu_name' => 'menu-user-account-menu',
    'link_path' => 'walkthrough/record',
    'router_path' => 'walkthrough/record',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user-account-menu_add-content:walkthrough/record',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-user-account-menu_log-out:user/logout
  $menu_links['menu-user-account-menu_log-out:user/logout'] = array(
    'menu_name' => 'menu-user-account-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user-account-menu_log-out:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-user-account-menu_my-account:<front>',
  );
  // Exported menu link: menu-user-account-menu_my-account:<front>
  $menu_links['menu-user-account-menu_my-account:<front>'] = array(
    'menu_name' => 'menu-user-account-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'My Account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user-account-menu_my-account:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-user-account-menu_my-content:my-content
  $menu_links['menu-user-account-menu_my-content:my-content'] = array(
    'menu_name' => 'menu-user-account-menu',
    'link_path' => 'my-content',
    'router_path' => 'my-content',
    'link_title' => 'My content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user-account-menu_my-content:my-content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-user-account-menu_my-account:<front>',
  );
  // Exported menu link: menu-user-account-menu_my-profile:user
  $menu_links['menu-user-account-menu_my-profile:user'] = array(
    'menu_name' => 'menu-user-account-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-user-account-menu_my-profile:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-user-account-menu_my-account:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Log out');
  t('My Account');
  t('My content');
  t('My profile');


  return $menu_links;
}

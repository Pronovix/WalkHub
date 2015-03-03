<?php
/**
 * @file
 * main_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function main_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_blog:blog
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => 'articles & showcases',
      ),
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact:node/82
  $menu_links['main-menu_contact:node/82'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/82',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'main-menu_contact:node/82',
      'attributes' => array(
        'title' => 'Get connected!',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_documentation:node/3738
  $menu_links['main-menu_documentation:node/3738'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3738',
    'router_path' => 'node/%',
    'link_title' => 'Documentation',
    'options' => array(
      'identifier' => 'main-menu_documentation:node/3738',
      'attributes' => array(
        'title' => 'user & developer guide',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_faq:node/80
  $menu_links['main-menu_faq:node/80'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/80',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_faq:node/80',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: main-menu_for-developers:node/3742
  $menu_links['main-menu_for-developers:node/3742'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3742',
    'router_path' => 'node/%',
    'link_title' => 'For developers',
    'options' => array(
      'identifier' => 'main-menu_for-developers:node/3742',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'main-menu_documentation:node/3738',
  );
  // Exported menu link: main-menu_get-started-now:node/7239
  $menu_links['main-menu_get-started-now:node/7239'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7239',
    'router_path' => 'node/%',
    'link_title' => 'Get started now!',
    'options' => array(
      'identifier' => 'main-menu_get-started-now:node/7239',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'parent_identifier' => 'main-menu_documentation:node/3738',
  );
  // Exported menu link: main-menu_open-source:node/81
  $menu_links['main-menu_open-source:node/81'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/81',
    'router_path' => 'node/%',
    'link_title' => 'Open Source',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_open-source:node/81',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_pricing:node/79
  $menu_links['main-menu_pricing:node/79'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/79',
    'router_path' => 'node/%',
    'link_title' => 'Pricing',
    'options' => array(
      'attributes' => array(
        'title' => 'WalkHub packages',
      ),
      'identifier' => 'main-menu_pricing:node/79',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_resources:node/78
  $menu_links['main-menu_resources:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_resources:node/78',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu_style-guide:node/3740
  $menu_links['main-menu_style-guide:node/3740'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3740',
    'router_path' => 'node/%',
    'link_title' => 'Style guide',
    'options' => array(
      'identifier' => 'main-menu_style-guide:node/3740',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'main-menu_documentation:node/3738',
  );
  // Exported menu link: main-menu_submit-an-issue:https://github.com/Pronovix/WalkHub/issues
  $menu_links['main-menu_submit-an-issue:https://github.com/Pronovix/WalkHub/issues'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://github.com/Pronovix/WalkHub/issues',
    'router_path' => '',
    'link_title' => 'Submit an issue',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_submit-an-issue:https://github.com/Pronovix/WalkHub/issues',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_documentation:node/3738',
  );
  // Exported menu link: main-menu_user-guide:node/3739
  $menu_links['main-menu_user-guide:node/3739'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3739',
    'router_path' => 'node/%',
    'link_title' => 'User guide',
    'options' => array(
      'identifier' => 'main-menu_user-guide:node/3739',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_documentation:node/3738',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Contact');
  t('Documentation');
  t('FAQ');
  t('For developers');
  t('Get started now!');
  t('Open Source');
  t('Pricing');
  t('Resources');
  t('Style guide');
  t('Submit an issue');
  t('User guide');


  return $menu_links;
}

<?php
/**
 * @file
 * walkhub_page_type_faq.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function walkhub_page_type_faq_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__walkhub_faq_page';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__walkhub_faq_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_walkhub_faq_page';
  $strongarm->value = array(
    0 => 'main-menu',
    1 => 'navigation',
  );
  $export['menu_options_walkhub_faq_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_walkhub_faq_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_walkhub_faq_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_walkhub_faq_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_walkhub_faq_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_walkhub_faq_page';
  $strongarm->value = '1';
  $export['node_preview_walkhub_faq_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_walkhub_faq_page';
  $strongarm->value = 0;
  $export['node_submitted_walkhub_faq_page'] = $strongarm;

  return $export;
}

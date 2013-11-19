<?php
/**
 * @file
 * walkthrough_global.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function walkthrough_global_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_cache';
  $strongarm->value = 1;
  $export['block_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache';
  $strongarm->value = 1;
  $export['cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_lifetime';
  $strongarm->value = '0';
  $export['cache_lifetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_add_captcha_description';
  $strongarm->value = 0;
  $export['captcha_add_captcha_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_administration_mode';
  $strongarm->value = 0;
  $export['captcha_administration_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_allow_on_admin_pages';
  $strongarm->value = 0;
  $export['captcha_allow_on_admin_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_challenge';
  $strongarm->value = 'recaptcha/reCAPTCHA';
  $export['captcha_default_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_validation';
  $strongarm->value = '1';
  $export['captcha_default_validation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_enable_stats';
  $strongarm->value = 0;
  $export['captcha_enable_stats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_log_wrong_responses';
  $strongarm->value = 0;
  $export['captcha_log_wrong_responses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_persistence';
  $strongarm->value = '1';
  $export['captcha_persistence'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_placement_map_cache';
  $strongarm->value = array(
    'user_register_form' => array(
      'path' => array(),
      'key' => 'actions',
      'weight' => 99,
    ),
  );
  $export['captcha_placement_map_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_compression_type';
  $strongarm->value = 'min';
  $export['jquery_update_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_admin_version';
  $strongarm->value = '';
  $export['jquery_update_jquery_admin_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_cdn';
  $strongarm->value = 'google';
  $export['jquery_update_jquery_cdn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.8';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_schema_installed';
  $strongarm->value = TRUE;
  $export['metatag_schema_installed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_cache_maximum_age';
  $strongarm->value = '0';
  $export['page_cache_maximum_age'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 1;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_css';
  $strongarm->value = 1;
  $export['preprocess_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_js';
  $strongarm->value = 1;
  $export['preprocess_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_ajax_api';
  $strongarm->value = 0;
  $export['recaptcha_ajax_api'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_nocookies';
  $strongarm->value = 0;
  $export['recaptcha_nocookies'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_private_key';
  $strongarm->value = '6LdHQuoSAAAAAD6ly_KsLi8FxkdUcJdv0YtbrYKK';
  $export['recaptcha_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_public_key';
  $strongarm->value = '6LdHQuoSAAAAACIfyE_MwhzLFTTkr7uBrWpfXOGc';
  $export['recaptcha_public_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_tabindex';
  $strongarm->value = '';
  $export['recaptcha_tabindex'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_theme';
  $strongarm->value = 'red';
  $export['recaptcha_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'WalkHub beta';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 0,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
  );
  $export['theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '0';
  $export['user_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'walkthrough_global_secret_key';
  $strongarm->value = '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';
  $export['walkthrough_global_secret_key'] = $strongarm;

  return $export;
}

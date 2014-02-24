<?php

/**
 * @file
 * Builds placeholder replacement tokens for browser-related data.
 */

/**
 * Implementation of hook_token_info()
 *
 * @param type $info
 */
function browserclass_token_info() {
  $browserclass = array();

  $types['browserclass'] = array(
    'name' => t('Browser classes'),
    'description' => t('Token for browser class.'),
  );
  //Tokens for browser classes token type.
  $browserclass['browser-classes'] = array(
    'name' => t('Browser classes'),
    'description' => t('The current user\'s browser classes.'),
  );

  $browserclass['browser'] = array(
    'name' => t('Browser'),
    'description' => t('Type of the browser.'),
  );

  $browserclass['platform'] = array(
    'name' => t('Platform'),
    'description' => t('Type of the platform.'),
  );

  $browserclass['device'] = array(
    'name' => t('Device'),
    'description' => t('Device info.'),
  );

  $browserclass['hook-classes'] = array(
    'name' => t('Extra classes'),
    'description' => t('Extra hook classes.'),
  );
  //User tokens.
  $user['browserclass'] = array(
    'name' => t('Browser classes'),
    'description' => t('The current user\'s browser classes.'),
    'type' => 'browserclass',
  );
  //Site information tokens.
  $site['browserclass'] = array(
    'name' => t('Browser classes'),
    'description' => t('The current user\'s browser classes.'),
    'type' => 'browserclass',
  );

  return array(
    'types' => $types,
    'tokens' => array(
      'browserclass' => $browserclass,
      'user' => $user,
      'site' => $site,
    ),
  );
}

/**
 * Implementation of hook_tokens()
 *
 * @param type $type
 * @param type $tokens
 * @param type $data
 * @param type $options
 * @return type
 */
function browserclass_tokens($type, $tokens, $data, $options) {
  $replacements = array();
  //Browser class tokens.
  if ($type == 'browserclass') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'browser-classes':
          $browser_classes = implode(' ', browserclass_get_classes());
          $replacements[$original] = check_plain($browser_classes);
          break;
        case 'browser':
          $browser = implode(' ', browserclass_get_classes(BROWSERCLASS_BROWSER));
          $replacements[$original] = check_plain($browser);
          break;
        case 'platform':
          $platform = implode(' ', browserclass_get_classes(BROWSERCLASS_PLATFORM));
          $replacements[$original] = check_plain($platform);
          break;
        case 'device':
          $device = implode(' ', browserclass_get_classes(BROWSERCLASS_MOBILE));
          $replacements[$original] = check_plain($device);
          break;
        case 'hook-classes':
          $hook_classes = implode(' ', browserclass_get_classes(BROWSERCLASS_OTHER_CLASSES));
          $replacements[$original] = check_plain($hook_classes);
          break;
      }
    }
  }
  //User tokens.
  if ($type == 'user') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'browserclass':
          $browser_classes = implode(' ', browserclass_get_classes());
          $replacements[$original] = check_plain($browser_classes);
          break;
      }
    }
    // Chained token relationships.
    if ($browserclass_tokens = token_find_with_prefix($tokens, 'browserclass')) {
      $replacements += token_generate('browserclass', $browserclass_tokens, array(), $options);
    }
  }
  
  //Site information tokens.
  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'browserclass':
          $browser_classes = implode(' ', browserclass_get_classes());
          $replacements[$original] = check_plain($browser_classes);
          break;
      }
    }
    // Chained token relationships.
    if ($browserclass_tokens = token_find_with_prefix($tokens, 'browserclass')) {
      $replacements += token_generate('browserclass', $browserclass_tokens, array(), $options);
    }
  }

  return $replacements;
}

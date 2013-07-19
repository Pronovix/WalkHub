<?php
/**
 * The profile reverts all the features on the first load after site install.
 *
 * Some features cannot be reverted in the same session as they were installed,
 * because of static caching. To circumvent it the profile reverts the features
 * after the first page load.
 *
 * @see walkthrough_exit()
 */

/**
 * Implements hook_exit().
 *
 * Reverts walkthrough features on exit.
 */
function walkthrough_exit() {
  // Exit if content is already imported.
  $features_reverted = variable_get('walkthrough_features_reverted');
  if ($features_reverted) {
    return;
  }

  require_once DRUPAL_ROOT . '/includes/install.inc';
  require_once DRUPAL_ROOT . '/includes/install.core.inc';

  // Make sure site is installed.
  $site_installed = FALSE;
  try {
    install_verify_completed_task();
  } catch(Exception $e) {
    $site_installed = TRUE;
  }

  if ($site_installed) {
    walkthrough_rebuild_features();
    variable_set('walkthrough_features_reverted', TRUE);
    watchdog('walkthrough', t('Reverted all wallkthrough features.'), array(), WATCHDOG_INFO);
  }
}


/**
 * Install callback for rebuilding all features.
 *
 * Features sometimes stuck in overriden phase after installing.
 */
function walkthrough_rebuild_features() {
  module_load_include('inc', 'features', 'features.export');
  module_load_include('install', 'walkthrough');
  features_include();

  $features_to_revert = _walkthrough_get_walkthrough_features();

  foreach ($features_to_revert as $module) {
    if (($feature = feature_load($module, TRUE)) && module_exists($module)) {
      $components = array();
      // Forcefully revert all components of a feature.
      foreach (array_keys($feature->info['features']) as $component) {
        if (features_hook($component, 'features_revert')) {
          $components[] = $component;
        }
      }
    }
    foreach ($components as $component) {
      features_revert(array($module => array($component)));
    }
  }
}


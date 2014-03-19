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
 * Reverts walkthrough overridden features on exit.
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
    watchdog('walkthrough', t('Reverted all walkthrough features.'), array(), WATCHDOG_INFO);
  }
}

/**
 * Install callback for rebuilding all features.
 *
 * Features sometimes stuck in overriden phase after installing.
 */
function walkthrough_rebuild_features() {
  module_load_include('install', 'walkhub');

  $features_to_revert = _walkthrough_get_overridden_features();
  walkhub_features_revert($features_to_revert);
}

/**
 * Get features which stuck in overridden mode after installing.
 *
 * @return array
 *   List of features.
 */
function _walkthrough_get_overridden_features() {
  return array(
    'walkhub',
    'walkhub_branding',
    'walkthrough_global',
    'walkthrough_permissions',
  );
}
/**
 * Hides update form from site install
 */
function walkthrough_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id === 'install_configure_form') {
    $form['update_notifications']['#access'] = FALSE;
  }
}


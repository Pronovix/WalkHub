<?php
/**
 * @file
 *  Admin configuration interface implementations.
 */

/**
 * Admin interface for custom registration endpoint settings.
 */
function walkthrough_global_configuration_form($form, &$form_state) {
  $form['walkthrough_global_public_key'] = array(
    '#type' => 'textarea',
    '#title' => t('Public key'),
    '#default_value' => variable_get('walkthrough_global_public_key', NULL),
  );
  return system_settings_form($form);
}

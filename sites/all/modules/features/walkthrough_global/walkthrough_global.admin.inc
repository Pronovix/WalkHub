<?php
/**
 * @file
 *  Admin configuration interface implementations.
 */

/**
 * Admin interface for custom registration endpoint settings.
 */
function walkthrough_global_configuration_form($form, &$form_state) {
  $form['walkthrough_global_secret_key'] = array(
    '#title' => t('Secret key'),
    '#description' => t('This key is used to identify every request sent by the IOS app.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('walkthrough_global_secret_key', NULL),
  );
  return system_settings_form($form);
}

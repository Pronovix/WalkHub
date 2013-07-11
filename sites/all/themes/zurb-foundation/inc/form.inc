<?php

/**
 * Implements hook_form_alter().
 */
function zurb_foundation_form_alter(&$form, &$form_state, $form_id) {
  // Id's of forms that should be ignored
  // Make this configurable?
  $form_ids = array(
    'node_form',
    'system_site_information_settings',
    'user_profile_form',
    'node_delete_confirm',
  );
  
  // Only wrap in container for certain form
  if (isset($form['#form_id']) && !in_array($form['#form_id'], $form_ids) && !isset($form['#node_edit_form'])) {
    $form['actions']['#theme_wrappers'] = array();
  }
  
  // Sexy submit buttons
  if (!empty($form['actions']) && !empty($form['actions']['submit'])) {
    $form['actions']['submit']['#attributes'] = array('class' => array('secondary', 'button', 'radius'));
  }
}
/**
 * Implements theme_form_element_label()
 */
function zurb_foundation_form_element_label($vars) {
  if (!empty($vars['element']['#title'])) {
    $vars['element']['#title'] = '<label>' . $vars['element']['#title'] . '</label>';
  }
  if (!empty($vars['element']['#description'])) {
    $vars['element']['#description'] = ' <span class="has-tip tip-top radius" data-width="250" title="' . $vars['element']['#description'] . '">' . t('More information?') . '</span>';
  }
  return theme_form_element_label($vars);
}

// /**
 // * Returns HTML for a button form element.
 // */
// function zurb_foundation_button($variables) {
  // $element = $variables['element'];
  // $label = check_plain($element['#value']);
  // element_set_attributes($element, array('id', 'name', 'value', 'type'));
// 
  // $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  // if (!empty($element['#attributes']['disabled'])) {
    // $element['#attributes']['class'][] = 'form-button-disabled';
  // }
// }
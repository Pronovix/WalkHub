<?php

/**
 * @file
 * This is now effectively a light-weight duplicate of FAPE.module, providing
 * just the parts Quick Edit needs.
 */

/**
 * Form constructor; in-place editing form for a (single) Field API field.
 *
 * This isn't a true form. As such it modifies the $form by reference.
 *
 * This leverages http://drupal.org/node/1825844.
 *
 * @see quickedit_field_edit_form_validate()
 * @see quickedit_field_edit_form_submit()
 * @ingroup forms
 */
function quickedit_field_edit_form(&$form, &$form_state, $entity, $field_name) {
  $entity_type = $form_state['entity_type'];
  $langcode = $form_state['langcode'];
  $bundle = $form_state['bundle'];

  // Adds the form elements for only the specified field to the form.
  $options = array(
    'field_name' => $field_name,
    'language' => field_valid_language($langcode),
    'default' => TRUE,
  );
  field_attach_form($entity_type, $entity, $form, $form_state, $langcode, $options);

  $entity->revision = FALSE;
  // @todo make this not node-specific
  if ($entity_type === 'node') {
    $entity->revision = in_array('revision', variable_get('node_options_' . $bundle, array()));
    $entity->log = NULL;
  }

  $form['#validate'][] = 'quickedit_field_edit_form_validate';
  $form['#submit'][] = 'quickedit_field_edit_form_submit';
}

/**
 * Form validation handler for quickedit_field_edit_form().
 *
 * @see quickedit_field_edit_form()
 * @see quickedit_field_edit_form_submit()
 * @see \Drupal\quickedit\Form\EditFieldForm::validate() in Drupal 8.
 */
function quickedit_field_edit_form_validate($form, &$form_state) {
  $entity = _quickedit_build_entity($form, $form_state);
  field_attach_form_validate($form_state['entity_type'], $entity, $form, $form_state, array('field_name' =>  $form_state['field_name']));
}

/**
 * Form submission handler for quickedit_field_edit_form().
 *
 * @see quickedit_field_edit_form()
 * @see quickedit_field_edit_form_validate()
 * @see quickedit_field_edit()
 * @see \Drupal\quickedit\Form\EditFieldForm::submit() in Drupal 8.
 */
function quickedit_field_edit_form_submit(&$form, &$form_state) {
  $entity = _quickedit_build_entity($form, $form_state);

  _quickedit_entity_save_to_tempstore($form_state['entity_type'], $form_state['entity_id'], $entity);
}

/**
 * Returns a cloned entity containing updated field values.
 *
 * Calling code may then validate the returned entity, and if valid, transfer
 * it back to the form state and save it.
 *
 * @see \Drupal\quickedit\Form\QuickEditFieldForm::buildEntity() in Drupal 8.
 */
function _quickedit_build_entity($form, &$form_state) {
  $entity = clone $form_state['entity'];

  // Extract form values. (Renamed to field_attach_extract_form_values() in D8.)
  field_attach_submit($form_state['entity_type'], $entity, $form, $form_state, array('field_name' =>  $form_state['field_name']));

  $instance = field_info_instance($form_state['entity_type'], $form_state['field_name'], $form_state['bundle']);
  _quickedit_entity_set_log($entity, $instance['label']);

  return $entity;
}

/**
 * Sets a revision log message for entities configured to create a new revision.
 */
function _quickedit_entity_set_log(&$entity, $field_name) {
  if ($entity->revision) {
    $entity->log = t('Updated the %field-name field through in-place editing.', array('%field-name' => $field_name));
  }
}

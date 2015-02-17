<?php
/**
 * @file
 * AJAX endpoint to retrieve & save subforms for fields and re-render fields.
 */

/**
 * Page callback: Returns the metadata for a set of fields.
 *
 * Given a list of field quickedit IDs as POST parameters, run access checks on
 * the entity and field level to determine whether the current user may edit
 * them. Also retrieves other metadata.
 *
 * @return
 *   The JSON response.
 *
 * @see Drupal 8's QuickEditController::metadata()
 * @see QuickEditMetadataGenerator
 * @see EditEntityFieldAccessCheck
 * @see QuickEditEditorSelector
 */
function quickedit_metadata() {
  $fields = $_POST['fields'];
  if (!isset($fields)) {
    return MENU_NOT_FOUND;
  }
  $entities = (isset($_POST['entities'])) ? $_POST['entities'] : array();

  module_load_include('php', 'quickedit', 'includes/EditEntityFieldAccessCheck');
  module_load_include('php', 'quickedit', 'includes/QuickEditEditorSelector');
  module_load_include('php', 'quickedit', 'includes/QuickEditMetadataGenerator');
  $accessChecker = new EditEntityFieldAccessCheck();
  $editorSelector = new QuickEditEditorSelector();
  $metadataGenerator = new QuickEditMetadataGenerator($accessChecker, $editorSelector);

  // Build metadata for each field, track all in-place editors.
  $metadata = array();
  $editors = array();
  foreach ($fields as $field) {
    list($entity_type, $entity_id, $field_name, $langcode, $view_mode) = explode('/', $field);

    // Load the entity.
    if (!$entity_type || !entity_get_info($entity_type)) {
      return MENU_NOT_FOUND;
    }
    $entity = entity_load_single($entity_type, $entity_id);
    if (!$entity) {
      return MENU_NOT_FOUND;
    }
    list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

    // Validate the field name and language.
    if (!_quickedit_is_extra_field($entity_type, $field_name)) {
      if (!$field_name || !($instance = field_info_instance($entity_type, $field_name, $bundle))) {
        return MENU_NOT_FOUND;
      }
    }
    else {
      $instance = array('field_name' => $field_name);
    }
    if (!$langcode || (field_valid_language($langcode) !== $langcode)) {
      return MENU_NOT_FOUND;
    }

    // If the entity information for this field is requested, include it.
    $entity_id = $entity_type . '/' . $entity_id;
    if (is_array($entities) && in_array($entity_id, $entities) && !isset($metadata[$entity_id])) {
      $metadata[$entity_id] = $metadataGenerator->generateEntityMetadata($entity_type, $entity, $langcode);
    }

    // Generate metadata for the current field.
    $metadata[$field] = $metadataGenerator->generateFieldMetadata($entity_type, $entity, $instance, $langcode, $view_mode);

    // Track all editors.
    if ($metadata[$field]['access'] !== FALSE) {
      $editors[] = $metadata[$field]['editor'];
    }
  }

  drupal_json_output($metadata);
}

/**
 * Page callback: Returns AJAX commands to load in-place editors' attachments.
 *
 * Given a list of in-place editor IDs as POST parameters, render AJAX
 * commands to load those in-place editors.
 *
 * @return
 *   The Ajax response.
 *
 * @see Drupal 8's QuickEditController::attachments()
 * @see QuickEditEditorSelector
 */
function quickedit_attachments() {
  $editors = $_POST['editors'];
  if (!isset($editors)) {
    return MENU_NOT_FOUND;
  }

  module_load_include('php', 'quickedit', 'includes/QuickEditEditorSelector');
  $editorSelector = new QuickEditEditorSelector();

  // Ensure an AJAX command is generated to load in-place editor attachments.
  $elements['#attached'] = $editorSelector->getEditorAttachments($editors);
  drupal_process_attached($elements);

  return array('#type' => 'ajax', '#commands' => array());
}

/**
 * Renders a field.
 *
 * If the view mode ID is not an Entity Display view mode ID, then the field
 * was rendered using a custom render pipeline (not the Entity/Field API
 * render pipeline).
 *
 * An example could be Views' render pipeline. In that case, the view mode ID
 * would probably contain the View's ID, display and the row index.
 *
 * @param $entity_type
 *   The type of the entity being edited.
 * @param $entity
 *   The entity being edited.
 * @param string $field_name
 *   The name of the field that is being edited.
 * @param string $langcode
 *   The name of the language for which the field is being edited.
 * @param string $view_mode
 *   The view mode the field should be rerendered in. Either an Entity Display
 *   view mode ID, or a custom one. See hook_quickedit_render_field().
 *
 * @return string
 *   Rendered HTML.
 *
 * @see hook_quickedit_render_field()
 */
function _quickedit_render_field($entity_type, $entity, $field_name, $langcode, $view_mode) {
  $entity_info = entity_get_info($entity_type);
  $entity_view_mode_ids = array_keys($entity_info['view modes']);
  if (in_array($view_mode, $entity_view_mode_ids)) {
    if (!_quickedit_is_extra_field($entity_type, $field_name)) {
      $field = field_view_field($entity_type, $entity, $field_name, $view_mode, $langcode);
      $output = drupal_render($field);
    }
    else {
      list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
      $rerender_callback = quickedit_extra_field_info($entity_type, $field_name, 'rerender callback');
      $result = $rerender_callback($entity);
      $output = quickedit_wrap_pseudofield(
        $result['value'],
        "$entity_type/$id/$field_name/$langcode/$view_mode",
        $result['inline']
      );
    }
  }
  else {
    // Each part of a custom (non-Entity Display) view mode ID is separated
    // by a dash; the first part must be the module name.
    $mode_parts = explode('-', $view_mode, 2);
    $module = reset($mode_parts);
    $rendered_field = module_invoke($module, 'quickedit_render_field', $entity_type, $entity, $field_name, $view_mode, $langcode);
    $output = drupal_render($rendered_field);
  }

  return $output;
}

/**
 * Page callback: Returns a single field edit form as an Ajax response.
 *
 * @param $entity_type
 *   The type of the entity being edited.
 * @param $entity_id
 *   The ID of the entity being edited.
 * @param string $field_name
 *   The name of the field that is being edited.
 * @param string $langcode
 *   The name of the language for which the field is being edited.
 * @param string $view_mode
 *   The view mode the field should be rerendered in.
 * @return
 *   The Ajax response.
 *
 * @see Drupal 8's QuickEditController::fieldForm()
 */
function quickedit_field_edit($entity_type, $entity_id, $field_name, $langcode = NULL, $view_mode = NULL) {
  $commands = array();

  // Load entity whose field is to be edited.
  $entity = entity_load_single($entity_type, $entity_id);
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  $latest_entity_timestamp = $entity->changed;

  // Ensure the user is allowed to edit this field.
  module_load_include('php', 'quickedit', 'includes/EditEntityFieldAccessCheck');
  $accessChecker = new EditEntityFieldAccessCheck();
  if (!$accessChecker->accessEditEntityField($entity_type, $entity, $field_name)) {
    return MENU_ACCESS_DENIED;
  }

  // Replace entity with TempStore copy if available and not resetting, init
  // TempStore copy otherwise.
  ctools_include('object-cache');
  $tempstore_id = _quickedit_entity_tempstore_id($entity_type, $entity_id);
  $tempstore_entity = ctools_object_cache_get('quickedit', $tempstore_id);
  if ($tempstore_entity && (!isset($_POST['reset']) || $_POST['reset'] !== 'true')) {
    // @todo: https://drupal.org/node/2158977 implemented content locking only
    // for nodes, because Drupal 7 only implements it for nodes. We may need to
    // disable content locking for other entity types, sadly.
    $tempstore_entity_timestamp = $tempstore_entity->changed;
    $entity = $tempstore_entity;
  }
  else {
    ctools_object_cache_clear('quickedit', $tempstore_id);
    ctools_object_cache_set('quickedit', $tempstore_id, $entity);
  }

  // Determine which subform should be used, initialize form state, build form.
  $subform_id = 'quickedit_field_edit_form';
  if (_quickedit_is_extra_field($entity_type, $field_name)) {
    $subform_id = quickedit_extra_field_info($entity_type, $field_name, 'quickedit subform id');
  }
  $form_state = array(
    'entity_type' => $entity_type,
    'entity_id' => $entity_id,
    'entity' => $entity,
    'field_name' => $field_name,
    'langcode' => $langcode,
    'view_mode' => $view_mode,
    'no_redirect' => TRUE,
    'bundle' => $bundle,
    'subform_id' => $subform_id,
    'build_info' => array(
      'args' => array($entity, $field_name),
    ),
  );
  $form = drupal_build_form('quickedit_field_form', $form_state);


  // Detect an edit conflict if the current entity timestamp is different
  // from the TempStore entity timestamp (whch is a copy from when the
  // editing process started).
  if (!empty($latest_entity_timestamp) && !empty($tempstore_entity_timestamp) && ($latest_entity_timestamp != $tempstore_entity_timestamp)) {
    drupal_set_message(t('The copy of the content being edited is outdated. Reload the page to edit an up-to-date version.'), 'error');

    $commands[] = array(
      'command' => 'quickeditFieldFormValidationErrors',
      'data' => theme('status_messages'),
    );
  }
  else {
    // If the form was successfully submitted (executed), then rerender the field.
    if (!empty($form_state['executed'])) {
      // The form submission saved the entity in TempStore. Return the
      // updated view of the field from the TempStore copy.
      $entity = ctools_object_cache_get('quickedit', $tempstore_id);

      // Re-render the updated field.
      $output = _quickedit_render_field($entity_type, $entity, $field_name, $langcode, $view_mode);

      // Re-render the updated field for other view modes (i.e. for other
      // instances of the same logical field on the user's page).
      $other_view_mode_ids = isset($_POST['other_view_modes']) ? $_POST['other_view_modes'] : array();
      $other_view_modes = array();
      foreach ($other_view_mode_ids as $other_view_mode_id) {
        $other_view_modes[$other_view_mode_id] = _quickedit_render_field($entity_type, $entity, $field_name, $langcode, $other_view_mode_id);
      }

      $commands[] = array(
        'command' => 'quickeditFieldFormSaved',
        'data' => $output,
        'other_view_modes' => $other_view_modes,
      );
    }
    // Otherwise, render the form. (And if it was insuccessfully submitted, there
    // will be form validation errors.)
    else {
      $commands[] = array(
        'command' => 'quickeditFieldForm',
        'data' => drupal_render($form),
      );

      $errors = form_get_errors();
      if (count($errors)) {
        $commands[] = array(
          'command' => 'quickeditFieldFormValidationErrors',
          'data' => theme('status_messages'),
        );
      }
    }
  }

  // When working with a hidden form, we don't want any CSS or JS to be loaded.
  if (isset($_POST['nocssjs']) && $_POST['nocssjs'] === 'true') {
    drupal_static_reset('drupal_add_css');
    drupal_static_reset('drupal_add_js');
  }

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Page callback: Saves an entity into the database, from TempStore.
 *
 * @param $entity_type
 *   The type of the entity being saved.
 * @param $entity_id
 *   The ID of the entity being saved.
 *
 * @return
 *   The Ajax response.
 *
 * @see Drupal 8's QuickEditController::entitySave()
 */
function quickedit_entity_save($entity_type, $entity_id) {
  // Ensure the user is allowed to edit this entity.
  if (!entity_access('update', $entity_type, entity_load_single($entity_type, $entity_id))) {
    return MENU_ACCESS_DENIED;
  }

  // Take the entity from TempStore and save in entity storage. fieldForm()
  // ensures that the TempStore copy exists ahead.
  ctools_include('object-cache');
  $tempstore_id = _quickedit_entity_tempstore_id($entity_type, $entity_id);
  $entity = ctools_object_cache_get('quickedit', $tempstore_id);
  ctools_object_cache_clear('quickedit', $tempstore_id);
  entity_save($entity_type, $entity);

  // Return information about the entity that allows a front end application
  // to identify it.
  $output = array(
    'entity_type' => $entity_type,
    'entity_id' => $entity_id,
  );

  // Respond to client that the entity was saved properly.
  $commands = array();
  $commands[] = array(
    'command' => 'quickeditEntitySaved',
    'data' => $output,
  );
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Page callback: Returns an Ajax response to render a text field without
 * transformation filters.
 *
 * @param $entity
 *   The entity being edited.
 * @param string $field_name
 *   The name of the field that is being edited.
 * @param string $langcode
 *   The name of the language for which the field is being edited.
 * @param string $view_mode
 *   The view mode the field should be rerendered in.
 * @return
 *   The Ajax response.
 *
 * @see Drupal 8's EditorController::getUntransformedText()
 */
function quickedit_ckeditor_get_untransformed_text($entity_type, $entity_id, $field_name, $langcode = NULL, $view_mode = NULL) {
  $commands = array();

  $entity = entity_load_single($entity_type, $entity_id);
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  // Ensure the user is allowed to edit this field.
  module_load_include('php', 'quickedit', 'includes/EditEntityFieldAccessCheck');
  $accessChecker = new EditEntityFieldAccessCheck();
  if (!$accessChecker->accessEditEntityField($entity_type, $entity, $field_name)) {
    return MENU_ACCESS_DENIED;
  }

  // Render the field in our custom display mode; retrieve the re-rendered
  // markup, this is what we're after.
  $field_output = field_view_field($entity_type, $entity, $field_name, 'quickedit-render-without-transformation-filters', $langcode);
  $output = $field_output[0]['#markup'];

  $commands[] = array(
    'command' => 'quickeditCKEditorGetUntransformedText',
    'id' => "$entity_type/$id/$field_name/$langcode/$view_mode",
    'data' => $output,
  );

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Form constructor; in-place editing form for a (single) Field API or "extra"
 * field.
 *
 * For Field API fields, the quickedit_field_edit_form subform will be used. For
 * "extra" fields, the subform indicated in hook_quickedit_extra_fields_info()
 * will be used.
 *
 * @see quickedit_field_edit_form()
 * @ingroup forms
 */
function quickedit_field_form($form, &$form_state, $entity, $field_name) {
  $form['#parents'] = array();

  form_load_include($form_state, 'inc', 'quickedit', 'includes/fape');

  if ($form_state['subform_id'] && function_exists($form_state['subform_id'])) {
    $form_state['subform_id']($form, $form_state, $entity, $field_name);
  }

  // Add a submit button. Give it a class for easy JavaScript targeting.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#attributes' => array('class' => array('quickedit-form-submit')),
  );

  // Remove http://drupal.org/project/metatag form elements.
  // @see http://drupal.org/node/1895142
  unset($form['#metatags']);

  // Tell http://drupal.org/project/redirect to not add form elements.
  // @see http://drupal.org/node/1935676
  $form['redirect'] = array();

  // Simplify it for optimal in-place use.
  quickedit_field_form_simplify($form, $form_state);
  return $form;
}

/**
 * Removes unneeded elements from the field from.
 *
 * @see Drupal 8's QuickEditFieldForm::simplify().
 */
function quickedit_field_form_simplify(&$form, &$form_state) {
  $field_name = $form_state['field_name'];
  $langcode = $form_state['langcode'];

  if (_quickedit_is_extra_field($form_state['entity_type'], $field_name)) {
    $key = quickedit_extra_field_info($form_state['entity_type'], $field_name, 'form simplification element key');
    $widget_element = &$form[$key];
  }
  else {
    $widget_element = &$form[$field_name][$langcode];
  }

  // Hide the field label from displaying within the form, because JavaScript
  // displays the equivalent label that was provided within an HTML data
  // attribute of the field's display element outside of the form. Do this for
  // widgets without child elements (like Option widgets) as well as for ones
  // with per-delta elements. Skip single checkboxes, because their title is
  // key to their UI. Also skip widgets with multiple subelements, because in
  // that case, per-element labeling is informative.
  $num_children = count(element_children($widget_element));
  if ($num_children == 0 && $widget_element['#type'] != 'checkbox') {
    $widget_element['#title_display'] = 'invisible';
  }
  if ($num_children == 1 && isset($widget_element[0]['value'])) {
    // @todo While most widgets name their primary element 'value', not all
    //   do, so generalize this.
    $widget_element[0]['value']['#title_display'] = 'invisible';
  }

  // Adjust textarea elements to fit their content.
  if (isset($widget_element[0]['value']['#type']) && $widget_element[0]['value']['#type'] == 'textarea') {
    $lines = count(explode("\n", $widget_element[0]['value']['#default_value']));
    $widget_element[0]['value']['#rows'] = $lines + 1;
  }
}

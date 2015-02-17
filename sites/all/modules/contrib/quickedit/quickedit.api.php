<?php

/**
 * @file
 * Hooks provided by the Quick Edit module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Declares in-place editor plugins provided by a module.
 *
 * In Drupal 8, we use plugin annotations for this.
 *
 * @return array
 *   An array whose keys are (unique) in-place editor plugin IDs and whose value
 *   is an array of plugin metadata. Plugin metadata arrays contain the
 *   following key-value pairs:
 *   - alternativeTo: an array of in-place editors plugin IDs that have
 *     registered themselves as alternatives to this in-place editor.
 *   - file: the Drupal root-relative file path to the PHP file that should be
 *     loaded to be able to use the in-place editor plugin class
 *   - class: the name of the class that represents this in-place editor.
 *
 * @see Drupal 8's \Drupal\quickedit\Annotation\InPlaceEditor
 * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditorBase
 *
 * @see InPlaceEditors/CKEditor.php
 * @see InPlaceEditors/formEditor.php
 * @see InPlaceEditors/plainTextEditor.php
 */
function hook_quickedit_editor_info() {
  $path = drupal_get_path('module', 'quickedit') . '/InPlaceEditors';

  // The "plain_text" in-place editor only works for text fields without a text
  // format.
  $editors['plain_text'] = array(
    'file' => $path . '/plainTextEditor.php',
    'class' => 'PlainTextEditor',
  );

  // The "ckeditor" in-place editor only works for text fields with a text
  // format, and only those text formats that are configured to use CKEditor.
  if (module_exists('ckeditor')) {
    $editors['ckeditor'] = array(
      // Therefor, the "ckeditor" in-place editor is marked as an alternative to
      // the "plain_text" in-place editor. Thanks to both plugins'
      // implementations of QuickEditInPlaceEditorInterface::isCompatible(), it
      // is ensured that the right in-place editor is used.
      'alternativeTo' => array('plain_text'),
      'file' => $path . '/CKEditor.php',
      'class' => 'CKEditor',
    );
  }

  return $editors;
}

/**
 * Allow modules to alter in-place editor plugin metadata.
 *
 * @param array &$editors
 *   An array of metadata on existing in-place editors.
 */
function hook_quickedit_editor_info_alter(&$editors) {

}

/**
 * Alter a field metadata that is used by the front-end.
 *
 * @param $metadata
 *   Information used by the front-end to make the field in-place editable.
 * @param array $context
 *   An array with the following key-value pairs:
 *     - 'entity_type': the entity type
 *     - 'entity': the entity object
 *     - 'field_name': the field name
 *     - 'field': (not provided for "extra" fields) the field instance as
 *       returned by field_info_instance()
 *     - 'items': (not provided for "extra" fields) the items of this field on
 *       this entity
 */
function hook_quickedit_editor_metadata_alter(&$metadata, $context) {
  // Exclude every node title from in-place editing.
  if ($context['entity_type'] === 'node' && $context['field_name'] === 'title') {
    $metadata['access'] = FALSE;
  }
}

/**
 * Alter the list of attached files for the editor depending on the fields conf.
 *
 * @param $attachments
 *   #attached array returned by the editor attachments callback.
 * @param $editor_id
 *   ID of the currently used editor.
 */
function hook_quickedit_editor_attachments_alter(&$attachments, $editor_id) {
  if ($editor_id === 'ckeditor') {
    $attachments['library'][] = array('mymodule', 'myjslibrary');
  }
}

/**
 * Returns a renderable array for the value of a single field in an entity.
 *
 * To integrate with in-place field editing when a non-standard render pipeline
 * is used (field_view_field() is not sufficient to render back the field
 * following in-place editing in the exact way it was displayed originally),
 * implement this hook.
 *
 * Quick Edit module integrates with HTML elements with data-quickedit-field-id
 * attributes.
 * For example:
 *   data-quickedit-field-id="node/1/<field-name>/und/<module-name>-<custom-id>"
 * After the editing is complete, this hook is invoked on the module with
 * the custom render pipeline identifier (last part of data-quickedit-field-id)
 * to re-render the field. Use the same logic used when rendering the field for
 * the original display.
 *
 * The implementation should take care of invoking the prepare_view steps. It
 * should also respect field access permissions.
 *
 * @param string $entity_type
 *   The type of the entity containing the field to display.
 * @param stdClass $entity
 *   The entity containing the field to display.
 * @param string $field_name
 *   The name of the field to display.
 * @param string $view_mode_id
 *   View mode ID for the custom render pipeline this field view was destined
 *   for. This is not a regular view mode ID for the Entity/Field API render
 *   pipeline and is provided by the renderer module instead. An example could
 *   be Views' render pipeline. In the example of Views, the view mode ID would
 *   probably contain the View's ID, display and the row index. Views would
 *   know the internal structure of this ID. The only structure imposed on this
 *   ID is that it contains dash separated values and the first value is the
 *   module name. Only that module's hook implementation will be invoked. Eg.
 *   'views-...-...'.
 * @param string $langcode
 *   (Optional) The language code the field values are to be shown in.
 *
 * @return
 *   A renderable array for the field value.
 *
 * @see field_view_field()
 */
function hook_quickedit_render_field($entity_type, $entity, $field_name, $view_mode_id, $langcode) {
  return array(
    '#prefix' => '<div class="example-markup">',
    'field' => field_view_field($entity_type, $entity, $field_name, $view_mode_id, $langcode),
    '#suffix' => '</div>',
  );
}

/**
 * @} End of "addtogroup hooks".
 */

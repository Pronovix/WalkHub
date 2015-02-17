<?php

/**
 * @file
 * Defines the "ckeditor" in-place editor.
 *
 * @see Drupal 8's \Drupal\editor\Plugin\InPlaceEditor\Editor.
 */

module_load_include('php', 'quickedit', 'includes/QuickEditInPlaceEditorInterface');

/**
 * Defines the CKEditor in-place editor.
 */
class CKEditor implements QuickEditInPlaceEditorInterface{

  /**
   * Implements QuickEditInPlaceEditorInterface::isCompatible().
   *
   * @see Drupal 8's \Drupal\editor\Plugin\quickedit\editor\Editor::isCompatible().
   */
  public function isCompatible(array $instance, array $items) {
    $field = field_info_field($instance['field_name']);

    // This editor is incompatible with multivalued fields.
    if ($field['cardinality'] != 1) {
      return FALSE;
    }
    // This editor is compatible with processed ("rich") text fields; but only
    // if there is a currently active text format, and that text format has an
    // associated CKEditor profile.
    elseif (!empty($instance['settings']['text_processing'])) {
      $format_id = $items[0]['format'];
      module_load_include('inc', 'ckeditor', 'includes/ckeditor.lib');
      if ($ckeditor_profile = ckeditor_get_profile($format_id)) {
        if ($settings = ckeditor_profiles_compile($format_id)) {
          return ($ckeditor_profile->settings['default'] === 't');
        }
      }

      return FALSE;
    }
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getMetadata().
   *
   * @see Drupal 8's \Drupal\editor\Plugin\quickedit\editor\Editor::getMetadata().
   */
  public function getMetadata(array $instance, array $items) {
    $format_id = $items[0]['format'];
    $metadata['format'] = $format_id;
    $metadata['formatHasTransformations'] = (bool) count(array_intersect(array(FILTER_TYPE_TRANSFORM_REVERSIBLE, FILTER_TYPE_TRANSFORM_IRREVERSIBLE), filter_get_filter_types_by_format($format_id)));

    // This part does not exist in the equivalent Drupal 8 code, because in Drupal
    // 8 we leverage the new Text Editor module, which takes care of all of this
    // for us. We could send this information in the attachments callback (like in
    // Drupal 8), but this makes the metadata for each field nicely contained,
    // which is simpler.
    // @todo Consider moving this to the attachments callback.
    module_load_include('inc', 'ckeditor', 'includes/ckeditor.lib');
    if ($settings = ckeditor_profiles_compile($format_id)) {
      // Clean up a few settings.
      foreach (array('customConfig', 'show_toggle', 'ss', 'contentsCss', 'stylesCombo_stylesSet') as $config_item) {
        unset($settings[$config_item]);
      }

      // CKEditor.module stores the toolbar configuration as a non-standard JSON
      // serialization. In case they one day fix that, we check if it is indeed
      // still serialized.
      // See http://drupal.org/node/1906490.
      if (is_string($settings['toolbar'])) {
        // This bizarre code comes from ckeditor_admin_profile_form_validate().
        $toolbar = $settings['toolbar'];
        $toolbar = str_replace("'", '"', $toolbar);
        $toolbar = preg_replace('/(\w*)\s*\:/', '"${1}":', $toolbar);
        $settings['toolbar'] = json_decode($toolbar);
      }

      // For some reasons when ckeditor is in profiles/libraries ckeditor module
      // defaults to the kama skin that doesn't exists in CKEditor 4 standard.
      // @todo remove? might be too brutal.
      if ($settings['skin'] == 'kama') {
        $settings['skin'] = 'moono';
      }

      //[#1473010]
      // @todo see if this is needed.
      $field = field_info_field($instance['field_name']);
      if (isset($settings['scayt_sLang'])) {
        $settings['scayt_language'] = $settings['scayt_sLang'];
        unset($settings['scayt_sLang']);
      }
      elseif (!empty($field["#language"]) && $field["#language"] != LANGUAGE_NONE) {
        $settings['scayt_language'] = ckeditor_scayt_langcode($field["#language"]);
      }

      // Set the collected metadata.
      $metadata['ckeditorSettings'] = $settings;
    }

    return $metadata;
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getAttachments().
   *
   * @see Drupal 8's \Drupal\editor\Plugin\quickedit\editor\Editor::getAttachments().
   */
  public function getAttachments() {
    return array(
      'library' => array(
        array('quickedit', 'quickedit.inPlaceEditor.ckeditor'),
      ),
      'js' => array(
        array(
          'type' => 'setting',
          'data' => array(
            'quickedit' => array(
              'ckeditor' => array(
                'basePath' =>  ckeditor_library_path('relative') . '/ckeditor/',
              ),
            ),
          ),
        ),
      ),
    );
  }

}

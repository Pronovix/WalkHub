<?php

/**
 * @file
 * Defines the "plain_text" in-place editor.
 *
 * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\PlainTextEditor.
 */

module_load_include('php', 'quickedit', 'includes/QuickEditInPlaceEditorInterface');

/**
 * Defines the plain text in-place editor.
 */
class PlainTextEditor implements QuickEditInPlaceEditorInterface{

  /**
   * Implements QuickEditInPlaceEditorInterface::isCompatible().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\PlainTextEditor::isCompatible().
   */
  public function isCompatible(array $instance, array $items) {
    $field = field_info_field($instance['field_name']);

    // This editor is incompatible with multivalued fields.
    $cardinality_allows = $field['cardinality'] == 1;
    // This editor is incompatible with processed ("rich") text fields.
    $no_text_processing = empty($instance['settings']['text_processing']);

    return $cardinality_allows && $no_text_processing;
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getMetadata().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\PlainTextEditor::getMetadata().
   */
  public function getMetadata(array $instance, array $items) {
    return array();
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getAttachments().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\PlainTextEditor::getAttachments().
   */
  public function getAttachments() {
    return array(
      'library' => array(
        array('quickedit', 'quickedit.inPlaceEditor.plainText'),
      ),
    );
  }

}

<?php

/**
 * @file
 * Defines the "form" in-place editor.
 *
 * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\FormEditor.
 */

module_load_include('php', 'quickedit', 'includes/QuickEditInPlaceEditorInterface');

/**
 * Defines the form in-place editor.
 */
class FormEditor implements QuickEditInPlaceEditorInterface{

  /**
   * Implements QuickEditInPlaceEditorInterface::isCompatible().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\FormEditor::isCompatible().
   */
  public function isCompatible(array $instance, array $items) {
    return TRUE;
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getMetadata().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\FormEditor::getMetadata().
   */
  public function getMetadata(array $instance, array $items) {
    return array();
  }

  /**
   * Implements QuickEditInPlaceEditorInterface::getAttachments().
   *
   * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditor\FormEditor::isCompatible().
   */
  public function getAttachments() {
    return array(
      'library' => array(
        array('quickedit', 'quickedit.inPlaceEditor.form'),
      ),
    );
  }

}

<?php

/**
 * @file
 * Contains Quick Edit's InPlaceEditorInterface.
 *
 * @see Drupal 8's \Drupal\quickedit\Plugin\InPlaceEditorInterface.
 */

/**
 * Defines an interface for in-place editors plugins.
 */
interface QuickEditInPlaceEditorInterface {

  /**
   * Checks whether this in-place editor is compatible with a given field.
   *
   * @param array $instance
   *   The field instance to be in-place edited.
   * @param array $items
   *   The field values to be in-place edited.
   *
   * @return bool
   *   TRUE if it is compatible, FALSE otherwise.
   */
  public function isCompatible(array $instance, array $items);

  /**
   * Generates metadata that is needed specifically for this editor.
   *
   * Will only be called by QuickEditMetadataGeneratorInterface::generate()
   * when the passed in field instance & item values will use this in-place
   * editor.
   *
   * @param array $instance
   *   The field instance to be in-place edited.
   * @param array $items
   *   The field values to be in-place edited.
   *
   * @return array
   *   A keyed array with metadata. Each key should be prefixed with the plugin
   *   ID of the editor.
   */
  public function getMetadata(array $instance, array $items);

  /**
   * Returns the attachments for this editor.
   *
   * @return array
   *   An array of attachments, for use with #attached.
   *
   * @see drupal_process_attached()
   */
  public function getAttachments();

}

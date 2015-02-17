<?php

/**
 * @file
 * Contains Quick Edit's MetadataGeneratorInterface.
 *
 * @see Drupal 8's \Drupal\quickedit\MetadataGeneratorInterface
 */

/**
 * Interface for generating in-place editing metadata for an entity field.
 */
interface QuickEditMetadataGeneratorInterface {

  /**
   * Generates in-place editing metadata for an entity.
   *
   * @param $entity_type
   *   The type of entity being edited.
   * @param $entity
   *   The entity being edited.
   * @param string $langcode
   *   The name of the language for which the field is being edited.
   * @return array
   *   An array containing metadata with the following keys:
   *   - label: the user-visible label for the entity in the given language.
   */
  public function generateEntityMetadata($entity_type, $entity, $langcode);

  /**
   * Generates in-place editing metadata for an entity field.
   *
   * @param $entity_type
   *   The type of entity being edited.
   * @param $entity
   *   The entity being edited.
   * @param arrray $instance
   *   The field instance of the field being edited.
   * @param string $langcode
   *   The name of the language for which the field is being edited.
   * @param string $view_mode
   *   The view mode the field should be rerendered in.
   * @return array
   *   An array containing metadata with the following keys:
   *   - label: the user-visible label for the field.
   *   - access: whether the current user may edit the field or not.
   *   - editor: which editor should be used for the field.
   *   - aria: the ARIA label.
   *   - custom: (optional) any additional metadata that the editor provides.
   */
  public function generateFieldMetadata($entity_type, $entity, array $instance, $langcode, $view_mode);

}

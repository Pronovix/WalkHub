<?php

/**
 * @file
 * Contains Edit's EditEntityFieldAccessCheckInterface.
 *
 * @see Drupal 8's \Drupal\edit\Access\EditEntityFieldAccessCheckInterface.
 */

/**
 * Access check for editing entity fields.
 */
interface EditEntityFieldAccessCheckInterface {

  /**
   * Checks access to edit the requested field of the requested entity.
   */
  public function accessEditEntityField($entity_type, $entity, $field_name);

}

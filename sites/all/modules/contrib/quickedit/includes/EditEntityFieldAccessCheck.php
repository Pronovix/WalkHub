<?php

/**
 * @file
 * Contains Quick Edit's EditEntityFieldAccessCheck.
 *
 * @see Drupal 8's \Drupal\quickedit\Access\EditEntityFieldAccessCheck.
 */

module_load_include('php', 'quickedit', 'includes/EditEntityFieldAccessCheckInterface');

/**
 * Access check for editing entity fields.
 */
class EditEntityFieldAccessCheck implements EditEntityFieldAccessCheckInterface {

  /**
   * Implements EditEntityFieldAccessCheckInterface::accessEditEntityField().
   */
  public function accessEditEntityField($entity_type, $entity, $field_name) {
    $is_extra_field = _quickedit_is_extra_field($entity_type, $field_name);
    $entity_access = entity_access('update', $entity_type, $entity);
    $field_access = $is_extra_field ? TRUE : field_access('edit', $field_name, $entity_type, $entity);
    return $entity_access && $field_access;
  }

}

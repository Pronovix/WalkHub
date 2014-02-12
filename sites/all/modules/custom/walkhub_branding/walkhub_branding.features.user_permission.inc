<?php
/**
 * @file
 * walkhub_branding.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function walkhub_branding_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create branding content'.
  $permissions['create branding content'] = array(
    'name' => 'create branding content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any branding content'.
  $permissions['delete any branding content'] = array(
    'name' => 'delete any branding content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own branding content'.
  $permissions['delete own branding content'] = array(
    'name' => 'delete own branding content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any branding content'.
  $permissions['edit any branding content'] = array(
    'name' => 'edit any branding content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own branding content'.
  $permissions['edit own branding content'] = array(
    'name' => 'edit own branding content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}

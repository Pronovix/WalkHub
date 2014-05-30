<?php
/**
 * @file
 * walkhub_collections.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function walkhub_collections_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:collection:add user'
  $permissions['node:collection:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:administer group'
  $permissions['node:collection:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:approve and deny subscription'
  $permissions['node:collection:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:create branding content'
  $permissions['node:collection:create branding content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:create walkthrough content'
  $permissions['node:collection:create walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:create walkthrough_set content'
  $permissions['node:collection:create walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete any branding content'
  $permissions['node:collection:delete any branding content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete any walkthrough content'
  $permissions['node:collection:delete any walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete any walkthrough_set content'
  $permissions['node:collection:delete any walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete own branding content'
  $permissions['node:collection:delete own branding content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete own walkthrough content'
  $permissions['node:collection:delete own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:delete own walkthrough_set content'
  $permissions['node:collection:delete own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:manage members'
  $permissions['node:collection:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:manage permissions'
  $permissions['node:collection:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:manage roles'
  $permissions['node:collection:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:subscribe'
  $permissions['node:collection:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:collection:subscribe without approval'
  $permissions['node:collection:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collection:unsubscribe'
  $permissions['node:collection:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update any branding content'
  $permissions['node:collection:update any branding content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update any walkthrough content'
  $permissions['node:collection:update any walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update any walkthrough_set content'
  $permissions['node:collection:update any walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update group'
  $permissions['node:collection:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collection:update own branding content'
  $permissions['node:collection:update own branding content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update own walkthrough content'
  $permissions['node:collection:update own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update own walkthrough_set content'
  $permissions['node:collection:update own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}

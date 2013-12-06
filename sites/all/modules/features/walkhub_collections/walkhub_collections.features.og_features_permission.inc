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

  // Exported og permission: 'node:walkthrough_collection:add user'
  $permissions['node:walkthrough_collection:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:administer group'
  $permissions['node:walkthrough_collection:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:approve and deny subscription'
  $permissions['node:walkthrough_collection:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:create branding content'
  $permissions['node:walkthrough_collection:create branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:create walkthrough content'
  $permissions['node:walkthrough_collection:create walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:create walkthrough_set content'
  $permissions['node:walkthrough_collection:create walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:delete any branding content'
  $permissions['node:walkthrough_collection:delete any branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:delete any walkthrough content'
  $permissions['node:walkthrough_collection:delete any walkthrough content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:delete any walkthrough_set content'
  $permissions['node:walkthrough_collection:delete any walkthrough_set content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:delete own branding content'
  $permissions['node:walkthrough_collection:delete own branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:delete own walkthrough content'
  $permissions['node:walkthrough_collection:delete own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:delete own walkthrough_set content'
  $permissions['node:walkthrough_collection:delete own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:manage members'
  $permissions['node:walkthrough_collection:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:manage permissions'
  $permissions['node:walkthrough_collection:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:manage roles'
  $permissions['node:walkthrough_collection:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:subscribe'
  $permissions['node:walkthrough_collection:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:subscribe without approval'
  $permissions['node:walkthrough_collection:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:unsubscribe'
  $permissions['node:walkthrough_collection:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:update any branding content'
  $permissions['node:walkthrough_collection:update any branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:update any walkthrough content'
  $permissions['node:walkthrough_collection:update any walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:update any walkthrough_set content'
  $permissions['node:walkthrough_collection:update any walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:update group'
  $permissions['node:walkthrough_collection:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:update own branding content'
  $permissions['node:walkthrough_collection:update own branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_collection:update own walkthrough content'
  $permissions['node:walkthrough_collection:update own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_collection:update own walkthrough_set content'
  $permissions['node:walkthrough_collection:update own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:add user'
  $permissions['node:walkthrough_public_collection:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:administer group'
  $permissions['node:walkthrough_public_collection:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:approve and deny subscription'
  $permissions['node:walkthrough_public_collection:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:create branding content'
  $permissions['node:walkthrough_public_collection:create branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:create walkthrough content'
  $permissions['node:walkthrough_public_collection:create walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:create walkthrough_set content'
  $permissions['node:walkthrough_public_collection:create walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete any branding content'
  $permissions['node:walkthrough_public_collection:delete any branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete any walkthrough content'
  $permissions['node:walkthrough_public_collection:delete any walkthrough content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete any walkthrough_set content'
  $permissions['node:walkthrough_public_collection:delete any walkthrough_set content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete own branding content'
  $permissions['node:walkthrough_public_collection:delete own branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete own walkthrough content'
  $permissions['node:walkthrough_public_collection:delete own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:delete own walkthrough_set content'
  $permissions['node:walkthrough_public_collection:delete own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:manage members'
  $permissions['node:walkthrough_public_collection:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:manage permissions'
  $permissions['node:walkthrough_public_collection:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:manage roles'
  $permissions['node:walkthrough_public_collection:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:subscribe'
  $permissions['node:walkthrough_public_collection:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:subscribe without approval'
  $permissions['node:walkthrough_public_collection:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:unsubscribe'
  $permissions['node:walkthrough_public_collection:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update any branding content'
  $permissions['node:walkthrough_public_collection:update any branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update any walkthrough content'
  $permissions['node:walkthrough_public_collection:update any walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update any walkthrough_set content'
  $permissions['node:walkthrough_public_collection:update any walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update group'
  $permissions['node:walkthrough_public_collection:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update own branding content'
  $permissions['node:walkthrough_public_collection:update own branding content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update own walkthrough content'
  $permissions['node:walkthrough_public_collection:update own walkthrough content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:walkthrough_public_collection:update own walkthrough_set content'
  $permissions['node:walkthrough_public_collection:update own walkthrough_set content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}

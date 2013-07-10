<?php
/**
 * @file
 * walkthrough_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function walkthrough_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: administer field collections.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(),
    'module' => 'field_collection',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer services.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer uuid.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(),
    'module' => 'uuid',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: create step content.
  $permissions['create step content'] = array(
    'name' => 'create step content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create walkthrough content.
  $permissions['create walkthrough content'] = array(
    'name' => 'create walkthrough content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create walkthrough_set content.
  $permissions['create walkthrough_set content'] = array(
    'name' => 'create walkthrough_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any step content.
  $permissions['delete any step content'] = array(
    'name' => 'delete any step content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any walkthrough content.
  $permissions['delete any walkthrough content'] = array(
    'name' => 'delete any walkthrough content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any walkthrough_set content.
  $permissions['delete any walkthrough_set content'] = array(
    'name' => 'delete any walkthrough_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own step content.
  $permissions['delete own step content'] = array(
    'name' => 'delete own step content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own walkthrough content.
  $permissions['delete own walkthrough content'] = array(
    'name' => 'delete own walkthrough content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own walkthrough_set content.
  $permissions['delete own walkthrough_set content'] = array(
    'name' => 'delete own walkthrough_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any step content.
  $permissions['edit any step content'] = array(
    'name' => 'edit any step content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any walkthrough content.
  $permissions['edit any walkthrough content'] = array(
    'name' => 'edit any walkthrough content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any walkthrough_set content.
  $permissions['edit any walkthrough_set content'] = array(
    'name' => 'edit any walkthrough_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own step content.
  $permissions['edit own step content'] = array(
    'name' => 'edit own step content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own walkthrough content.
  $permissions['edit own walkthrough content'] = array(
    'name' => 'edit own walkthrough content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own walkthrough_set content.
  $permissions['edit own walkthrough_set content'] = array(
    'name' => 'edit own walkthrough_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: get a system variable.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: get any binary files.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: get own binary files.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: perform unlimited index queries.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: save file information.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: set a system variable.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}

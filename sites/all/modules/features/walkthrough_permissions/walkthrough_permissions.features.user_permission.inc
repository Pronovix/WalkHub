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

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add userpoints'.
  $permissions['add userpoints'] = array(
    'name' => 'add userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer Terms and Conditions'.
  $permissions['administer Terms and Conditions'] = array(
    'name' => 'administer Terms and Conditions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer browser class'.
  $permissions['administer browser class'] = array(
    'name' => 'administer browser class',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'browserclass',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer invitations'.
  $permissions['administer invitations'] = array(
    'name' => 'administer invitations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer invite types'.
  $permissions['administer invite types'] = array(
    'name' => 'administer invite types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer message types'.
  $permissions['administer message types'] = array(
    'name' => 'administer message types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'message',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer userpoints'.
  $permissions['administer userpoints'] = array(
    'name' => 'administer userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer walkhub patterns'.
  $permissions['administer walkhub patterns'] = array(
    'name' => 'administer walkhub patterns',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'walkhub',
  );

  // Exported permission: 'administer walkthrough'.
  $permissions['administer walkthrough'] = array(
    'name' => 'administer walkthrough',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'walkhub',
  );

  // Exported permission: 'administer walkthrough client'.
  $permissions['administer walkthrough client'] = array(
    'name' => 'administer walkthrough client',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'walkhub_client',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clone accessible content'.
  $permissions['clone accessible content'] = array(
    'name' => 'clone accessible content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'walkthrough_global',
  );

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'create any invite entities'.
  $permissions['create any invite entities'] = array(
    'name' => 'create any invite entities',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'create blog_entry content'.
  $permissions['create blog_entry content'] = array(
    'name' => 'create blog_entry content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create collection content'.
  $permissions['create collection content'] = array(
    'name' => 'create collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create invite_by_email entity'.
  $permissions['create invite_by_email entity'] = array(
    'name' => 'create invite_by_email entity',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'create messages'.
  $permissions['create messages'] = array(
    'name' => 'create messages',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'message',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create screening content'.
  $permissions['create screening content'] = array(
    'name' => 'create screening content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create walkhub_faq_page content'.
  $permissions['create walkhub_faq_page content'] = array(
    'name' => 'create walkhub_faq_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create walkhub_key_feature content'.
  $permissions['create walkhub_key_feature content'] = array(
    'name' => 'create walkhub_key_feature content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create walkhub_news content'.
  $permissions['create walkhub_news content'] = array(
    'name' => 'create walkhub_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create walkthrough content'.
  $permissions['create walkthrough content'] = array(
    'name' => 'create walkthrough content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create walkthrough_set content'.
  $permissions['create walkthrough_set content'] = array(
    'name' => 'create walkthrough_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any blog_entry content'.
  $permissions['delete any blog_entry content'] = array(
    'name' => 'delete any blog_entry content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any collection content'.
  $permissions['delete any collection content'] = array(
    'name' => 'delete any collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any screening content'.
  $permissions['delete any screening content'] = array(
    'name' => 'delete any screening content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any walkhub_faq_page content'.
  $permissions['delete any walkhub_faq_page content'] = array(
    'name' => 'delete any walkhub_faq_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any walkhub_key_feature content'.
  $permissions['delete any walkhub_key_feature content'] = array(
    'name' => 'delete any walkhub_key_feature content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any walkhub_news content'.
  $permissions['delete any walkhub_news content'] = array(
    'name' => 'delete any walkhub_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any walkthrough content'.
  $permissions['delete any walkthrough content'] = array(
    'name' => 'delete any walkthrough content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any walkthrough_set content'.
  $permissions['delete any walkthrough_set content'] = array(
    'name' => 'delete any walkthrough_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog_entry content'.
  $permissions['delete own blog_entry content'] = array(
    'name' => 'delete own blog_entry content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own collection content'.
  $permissions['delete own collection content'] = array(
    'name' => 'delete own collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own screening content'.
  $permissions['delete own screening content'] = array(
    'name' => 'delete own screening content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own walkhub_faq_page content'.
  $permissions['delete own walkhub_faq_page content'] = array(
    'name' => 'delete own walkhub_faq_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own walkhub_key_feature content'.
  $permissions['delete own walkhub_key_feature content'] = array(
    'name' => 'delete own walkhub_key_feature content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own walkhub_news content'.
  $permissions['delete own walkhub_news content'] = array(
    'name' => 'delete own walkhub_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own walkthrough content'.
  $permissions['delete own walkthrough content'] = array(
    'name' => 'delete own walkthrough content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own walkthrough_set content'.
  $permissions['delete own walkthrough_set content'] = array(
    'name' => 'delete own walkthrough_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in blog_category'.
  $permissions['delete terms in blog_category'] = array(
    'name' => 'delete terms in blog_category',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in userpoints'.
  $permissions['delete terms in userpoints'] = array(
    'name' => 'delete terms in userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any blog_entry content'.
  $permissions['edit any blog_entry content'] = array(
    'name' => 'edit any blog_entry content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any collection content'.
  $permissions['edit any collection content'] = array(
    'name' => 'edit any collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any invite entities'.
  $permissions['edit any invite entities'] = array(
    'name' => 'edit any invite entities',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any screening content'.
  $permissions['edit any screening content'] = array(
    'name' => 'edit any screening content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any walkhub_faq_page content'.
  $permissions['edit any walkhub_faq_page content'] = array(
    'name' => 'edit any walkhub_faq_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any walkhub_key_feature content'.
  $permissions['edit any walkhub_key_feature content'] = array(
    'name' => 'edit any walkhub_key_feature content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any walkhub_news content'.
  $permissions['edit any walkhub_news content'] = array(
    'name' => 'edit any walkhub_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any walkthrough content'.
  $permissions['edit any walkthrough content'] = array(
    'name' => 'edit any walkthrough content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any walkthrough_set content'.
  $permissions['edit any walkthrough_set content'] = array(
    'name' => 'edit any walkthrough_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own blog_entry content'.
  $permissions['edit own blog_entry content'] = array(
    'name' => 'edit own blog_entry content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own collection content'.
  $permissions['edit own collection content'] = array(
    'name' => 'edit own collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own invite entities'.
  $permissions['edit own invite entities'] = array(
    'name' => 'edit own invite entities',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own screening content'.
  $permissions['edit own screening content'] = array(
    'name' => 'edit own screening content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own walkhub_faq_page content'.
  $permissions['edit own walkhub_faq_page content'] = array(
    'name' => 'edit own walkhub_faq_page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own walkhub_key_feature content'.
  $permissions['edit own walkhub_key_feature content'] = array(
    'name' => 'edit own walkhub_key_feature content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own walkhub_news content'.
  $permissions['edit own walkhub_news content'] = array(
    'name' => 'edit own walkhub_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own walkthrough content'.
  $permissions['edit own walkthrough content'] = array(
    'name' => 'edit own walkthrough content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own walkthrough_set content'.
  $permissions['edit own walkthrough_set content'] = array(
    'name' => 'edit own walkthrough_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in blog_category'.
  $permissions['edit terms in blog_category'] = array(
    'name' => 'edit terms in blog_category',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in userpoints'.
  $permissions['edit terms in userpoints'] = array(
    'name' => 'edit terms in userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit userpoints'.
  $permissions['edit userpoints'] = array(
    'name' => 'edit userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'export any walkthrough'.
  $permissions['export any walkthrough'] = array(
    'name' => 'export any walkthrough',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'walkhub',
  );

  // Exported permission: 'export own walkthrough'.
  $permissions['export own walkthrough'] = array(
    'name' => 'export own walkthrough',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'walkhub',
  );

  // Exported permission: 'flag mark_for_screening'.
  $permissions['flag mark_for_screening'] = array(
    'name' => 'flag mark_for_screening',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_content'.
  $permissions['flag subscribe_content'] = array(
    'name' => 'flag subscribe_content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag walkthrough_broken'.
  $permissions['flag walkthrough_broken'] = array(
    'name' => 'flag walkthrough_broken',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'mark any content for screening'.
  $permissions['mark any content for screening'] = array(
    'name' => 'mark any content for screening',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'walkhub_screening_queue',
  );

  // Exported permission: 'mark own content for screening'.
  $permissions['mark own content for screening'] = array(
    'name' => 'mark own content for screening',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'walkhub_screening_queue',
  );

  // Exported permission: 'moderate userpoints'.
  $permissions['moderate userpoints'] = array(
    'name' => 'moderate userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth authorize consumers in walkthrough_selenium_executor'.
  $permissions['oauth authorize consumers in walkthrough_selenium_executor'] = array(
    'name' => 'oauth authorize consumers in walkthrough_selenium_executor',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register consumers in walkthrough_selenium_executor'.
  $permissions['oauth register consumers in walkthrough_selenium_executor'] = array(
    'name' => 'oauth register consumers in walkthrough_selenium_executor',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for invite'.
  $permissions['show format selection for invite'] = array(
    'name' => 'show format selection for invite',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message'.
  $permissions['show format selection for message'] = array(
    'name' => 'show format selection for message',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type'.
  $permissions['show format selection for message_type'] = array(
    'name' => 'show format selection for message_type',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type_category'.
  $permissions['show format selection for message_type_category'] = array(
    'name' => 'show format selection for message_type_category',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership'.
  $permissions['show format selection for og_membership'] = array(
    'name' => 'show format selection for og_membership',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership_type'.
  $permissions['show format selection for og_membership_type'] = array(
    'name' => 'show format selection for og_membership_type',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'unflag mark_for_screening'.
  $permissions['unflag mark_for_screening'] = array(
    'name' => 'unflag mark_for_screening',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_content'.
  $permissions['unflag subscribe_content'] = array(
    'name' => 'unflag subscribe_content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag walkthrough_broken'.
  $permissions['unflag walkthrough_broken'] = array(
    'name' => 'unflag walkthrough_broken',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use text format blog_entry_text_format'.
  $permissions['use text format blog_entry_text_format'] = array(
    'name' => 'use text format blog_entry_text_format',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view Terms and Conditions'.
  $permissions['view Terms and Conditions'] = array(
    'name' => 'view Terms and Conditions',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'view any invite entities'.
  $permissions['view any invite entities'] = array(
    'name' => 'view any invite entities',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own userpoints'.
  $permissions['view own userpoints'] = array(
    'name' => 'view own userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view userpoints'.
  $permissions['view userpoints'] = array(
    'name' => 'view userpoints',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'withdraw own accepted invitations'.
  $permissions['withdraw own accepted invitations'] = array(
    'name' => 'withdraw own accepted invitations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'withdraw own invitations'.
  $permissions['withdraw own invitations'] = array(
    'name' => 'withdraw own invitations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'invite',
  );

  return $permissions;
}

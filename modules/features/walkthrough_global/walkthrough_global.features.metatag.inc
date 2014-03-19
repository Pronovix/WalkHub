<?php
/**
 * @file
 * walkthrough_global.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function walkthrough_global_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:walkthrough.
  $config['node:walkthrough'] = array(
    'instance' => 'node:walkthrough',
    'config' => array(
      'robots' => array(
        'value' => array(
          'index' => 'index',
          'follow' => 'follow',
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
        ),
      ),
      'twitter:creator' => array(
        'value' => '@WalkHub',
      ),
    ),
  );

  // Exported Metatag config instance: node:walkthrough_public_collection.
  $config['node:walkthrough_public_collection'] = array(
    'instance' => 'node:walkthrough_public_collection',
    'config' => array(
      'twitter:creator' => array(
        'value' => '@WalkHub',
      ),
    ),
  );

  return $config;
}

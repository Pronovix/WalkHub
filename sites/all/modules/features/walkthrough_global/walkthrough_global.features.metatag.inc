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
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'og:image' => array(
        'value' => '[node:wt_twitter_screenshot]',
      ),
      'twitter:card' => array(
        'value' => 'photo',
      ),
      'twitter:creator' => array(
        'value' => '@WalkHub',
      ),
      'twitter:creator:id' => array(
        'value' => 1226273473,
      ),
      'twitter:image' => array(
        'value' => '[node:wt_twitter_screenshot]',
      ),
    ),
  );

  return $config;
}

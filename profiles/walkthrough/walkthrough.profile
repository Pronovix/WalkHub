<?php
/**
 * The profile reverts all the features on the first load after site install.
 *
 * Some features cannot be reverted in the same session as they were installed,
 * because of static caching. To circumvent it the profile reverts the features
 * after the first page load.
 *
 * @see walkthrough_exit()
 */

/**
 * Implements hook_exit().
 *
 * Reverts walkthrough overridden features on exit.
 */
function walkthrough_exit() {
  // Exit if content is already imported.
  $features_reverted = variable_get('walkthrough_features_reverted');
  if ($features_reverted) {
    return;
  }

  require_once DRUPAL_ROOT . '/includes/install.inc';
  require_once DRUPAL_ROOT . '/includes/install.core.inc';

  // Make sure site is installed.
  $site_installed = FALSE;
  try {
    install_verify_completed_task();
  } catch(Exception $e) {
    $site_installed = TRUE;
  }

  if ($site_installed) {
    walkthrough_rebuild_features();
    variable_set('walkthrough_features_reverted', TRUE);
    watchdog('walkthrough', t('Reverted all walkthrough features.'), array(), WATCHDOG_INFO);
  }
}

/**
 * Install callback for rebuilding all features.
 *
 * Features sometimes stuck in overriden phase after installing.
 */
function walkthrough_rebuild_features() {
  module_load_include('install', 'walkhub');

  $features_to_revert = _walkthrough_get_overridden_features();
  walkhub_features_revert($features_to_revert);
}

/**
 * Get features which stuck in overridden mode after installing.
 *
 * @return array
 *   List of features.
 */
function _walkthrough_get_overridden_features() {
  return array(
    'walkhub',
    'walkhub_branding',
    'walkthrough_global',
    'walkthrough_permissions',
  );
}
/**
 * Hides update form from site install
 */
function walkthrough_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id === 'install_configure_form') {
    $form['update_notifications']['#access'] = FALSE;
  }
}

/**
 * Get Front Page heading block data for install and update processes.
 *
 * @return array
 *   Front Page heading block data.
 */
function _walkthrough_recreate_front_page_featured_block_contents() {
  $full_html = 'full_html';

  $block_custom_table_values = array(
      'body' => '<div class="small-12 small-centered large-6 large-uncentered columns">
                 <h2>WalkHub is a user guide for the Internet.<br> Created by people like you,<br> free to use &amp; under an open license.</h2>
                 <p>WalkHub is built by a community of documentarians that contribute and maintain Walkthrough tutorials about web pages, forms, blogs, community sites, web applications or generally anything that can be done in a browser*, all over the Internet.</p>
                 <p>Next time you need to explain how to do something online, do so in a Walkthrough tutorial: It’s faster and easier than screenshots or videos. And your work will contribute to humanity’s knowledge of the Internet.</p>
                 </div>
                 <div class="small-12 small-centered large-6 large-uncentered columns">
                 <div class="wt-container">
                 <iframe src="https://docs.google.com/presentation/d/120BUHuPey_Dgdac_QsNilO3lZl1DTP-9iQNtR4brwps/embed?start=false&amp;loop=false&amp;delayms=3000" frameborder="0" width="480" height="320" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-left: auto; margin-right: auto; display: block;"></iframe>
                 </div>
                 </div>',
      'info' => 'Front Page Heading',
      'format' => $full_html
  );
  return $block_custom_table_values;
}

/**
 * Get Front Page featured walkthroughs block data for install and update processes.
 *
 * @return array
 *   Front page featured walkthroughs block data.
 */
function _walkthrough_recreate_front_page_featured_walkthroughs_contents() {
  $full_html = 'full_html';

  $block_custom_table_values = array(
    'body' => '<div class="row">
               <div class="small-12 columns">
               <h3>Featured Walktroughs</h3>
               </div>
               <div class="small-12 large-6 columns">
               <div class="wt-container">
               <iframe id="walkthrough-slideshow-iframe" frameborder="0" width="400" height="300" src="http://walkhub.net/walkthrough/slideshow/3224" allowfullscreen=""> Your browser doesn\'t support iframes.</iframe>
               </div>
               </div>
               <div class="small-12 large-6 columns">
               <div class="wt-container">
               <iframe id="walkthrough-slideshow-iframe" frameborder="0" width="400" height="300" src="http://walkhub.net/walkthrough/slideshow/3352" allowfullscreen=""> Your browser doesn\'t support iframes.</iframe>
               </div>
               </div>
               </div>',
    'info' => 'Sample WT Top',
    'format' => $full_html,
  );
  return $block_custom_table_values;
}

/**
 *  Get 'My walkthroughs' block data with status disabled.
 *
 * @return array
 *   Array of 'My walkthroughs' block data.
 */
function _walkthrough_remove_my_walkthroughs_block_from_left_sidebar() {
  $walkhub_theme = 'walkhub_theme';

  $block = array(
    'module' => 'views',
    'delta' => 'my_walkthroughs-block',
    'theme' => $walkhub_theme,
    'status' => 0,
    'weight' => -3,
    'region' => 'sidebar_first',
    'custom' => 0,
    'visibility' => 0,
    'pages' => 'my-content\\r\\n<front>',
    'title' => '<none>',
    'cache' => -1,
  );

  return $block;
}

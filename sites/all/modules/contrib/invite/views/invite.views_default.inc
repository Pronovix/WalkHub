<?php

/**
 * Implements hook_views_default_views().
 */
function invite_views_default_views() {
  $module_name = 'invite';
  $views = array();
  $path = drupal_get_path('module', $module_name) . '/views';
  $files = drupal_system_listing('/\.view$/', $path, 'name', 0);
  foreach ($files as $file) {
    $view = NULL;
    include_once $file->uri;
    if (!empty($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}


/**
 * Invite entity Views definition.
 */
class InviteViewsController extends EntityDefaultViewsController {
}

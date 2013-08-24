<?php
/**
 * @file
 * walkthrough_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkthrough_global_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

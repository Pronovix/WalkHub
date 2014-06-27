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

/**
 * Implements hook_flag_default_flags().
 */
function walkthrough_global_flag_default_flags() {
  $flags = array();
  // Exported flag: "Walkthrough broken".
  $flags['walkthrough_broken'] = array(
    'entity_type' => 'node',
    'title' => 'Walkthrough broken',
    'global' => 0,
    'types' => array(
      0 => 'walkthrough',
    ),
    'flag_short' => 'Mark walkthrough as broken',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark walkthrough as working',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'walkthrough_global',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function walkthrough_global_image_default_styles() {
  $styles = array();

  // Exported image style: twitter_image_style.
  $styles['twitter_image_style'] = array(
    'name' => 'twitter_image_style',
    'label' => 'Twitter image style',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 442,
        ),
        'weight' => 1,
      ),
      2 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'sites/all/modules/custom/walkhub_tcard/images/icaction_gu_001i.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

<?php
/**
 * @file
 * walkhub_blog.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function walkhub_blog_filter_default_formats() {
  $formats = array();

  // Exported format: Blog entry text format.
  $formats['blog_entry_text_format'] = array(
    'format' => 'blog_entry_text_format',
    'name' => 'Blog entry text format',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_markdown' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}

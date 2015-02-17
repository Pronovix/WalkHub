<?php

/**
 * @file
 * Backport of Drupal 8 filter module improvements.
 */


/**
 * Non-HTML markup language filters that generate HTML.
 */
define('FILTER_TYPE_MARKUP_LANGUAGE', 0);

/**
 * HTML tag and attribute restricting filters.
 */
define('FILTER_TYPE_HTML_RESTRICTOR', 1);

/**
 * Reversible transformation filters.
 */
define('FILTER_TYPE_TRANSFORM_REVERSIBLE', 2);

/**
 * Irreversible transformation filters.
 */
define('FILTER_TYPE_TRANSFORM_IRREVERSIBLE', 3);


/**
 * Implements hook_filter_info_alter().
 *
 * Assigns filter types to Drupal core and contrib modules to allow the Quick
 * Edit module's CKEditor integration to reason about filters.
 */
function quickedit_filter_info_alter(&$info) {
  /* CORE */
  if (module_exists('php')) {
    // php.module
    $info['php_code']['type'] = FILTER_TYPE_MARKUP_LANGUAGE;
  }
  // filter.module
  $info['filter_autop'         ]['type'] = FILTER_TYPE_MARKUP_LANGUAGE;
  $info['filter_url'           ]['type'] = FILTER_TYPE_MARKUP_LANGUAGE;
  $info['filter_html_escape'   ]['type'] = FILTER_TYPE_MARKUP_LANGUAGE;
  $info['filter_html'          ]['type'] = FILTER_TYPE_HTML_RESTRICTOR;
  $info['filter_htmlcorrector' ]['type'] = FILTER_TYPE_HTML_RESTRICTOR;

  /* CONTRIB */
  $contrib_filter_type = array(
    // https://drupal.org/project/biblio
    'biblio_filter_reference' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    'biblio_filter_inline_reference' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/caption_filter
    'caption_filter' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // https://drupal.org/project/ckeditor_link
    'ckeditor_link_filter' => FILTER_TYPE_TRANSFORM_REVERSIBLE,
    // https://drupal.org/project/emptyparagraphkiller
    'emptyparagraphkiller' => FILTER_TYPE_HTML_RESTRICTOR,
    // https://drupal.org/project/footnotes
    'filter_footnotes' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // https://drupal.org/project/commons_hashtags
    'filter_hashtags' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/filter_html_image_secure
    'filter_html_image_secure' => FILTER_TYPE_HTML_RESTRICTOR,
    // https://drupal.org/project/htmlpurifier
    'htmlpurifier_basic' => FILTER_TYPE_HTML_RESTRICTOR,
    'htmlpurifier_advanced' => FILTER_TYPE_HTML_RESTRICTOR,
    // http://drupal.org/project/image_resize_filter
    'image_resize_filter' => FILTER_TYPE_TRANSFORM_REVERSIBLE,
    // http://drupal.org/project/markdown
    'filter_markdown' => FILTER_TYPE_MARKUP_LANGUAGE,
    // https://drupal.org/project/insert_view
    'insert_view' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/mathjax: see http://drupal.org/node/1900436#comment-7198530
    // http://drupal.org/project/media
    'media_filter' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // https://drupal.org/project/node_embed
    'node_embed' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // https://drupal.org/project/oembed
    'oembed' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/pathologic
    'pathologic' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // https://drupal.org/project/smart_paging
    'smart_paging_filter' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    'smart_paging_filter_autop' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/spamspan
    'spamspan' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/typogrify
    'typogrify' => FILTER_TYPE_TRANSFORM_IRREVERSIBLE,
    // http://drupal.org/project/wysiwyg_filter
    'wysiwyg' => FILTER_TYPE_HTML_RESTRICTOR,
  );

  foreach ($contrib_filter_type as $filter => $type) {
    if (empty($info[$filter])) {
      continue;
    }
    $info[$filter]['type'] = $type;
  }
}

/**
 * Identical to check_markup() with the exception of the new ability to *skip*
 * filters that match any filter type in a list of filter types
 *
 * @param array $filter_types_to_skip
 *   (optional) An array of filter types to skip, or an empty array (default)
 *   to skip no filter types. All of the format's filters will be applied,
 *   except for filters of the types that are marked to be skipped.
 *   FILTER_TYPE_HTML_RESTRICTOR is the only type that cannot be skipped.
 *
 * @see quickedit_filter_info_alter()
 */
function check_markup2($text, $format_id = NULL, $langcode = '', $cache = FALSE, $filter_types_to_skip = array()) {
  if (!isset($format_id)) {
    $format_id = filter_fallback_format();
  }
  // If the requested text format does not exist, the text cannot be filtered.
  if (!$format = filter_format_load($format_id)) {
    watchdog('filter', 'Missing text format: %format.', array('%format' => $format_id), WATCHDOG_ALERT);
    return '';
  }

  // Prevent FILTER_TYPE_HTML_RESTRICTOR from being skipped.
  if (in_array(FILTER_TYPE_HTML_RESTRICTOR, $filter_types_to_skip)) {
    $filter_types_to_skip = array_diff($filter_types_to_skip, array(FILTER_TYPE_HTML_RESTRICTOR));
  }

  // When certain filters should be skipped, don't perform caching.
  if ($filter_types_to_skip) {
    $cache = FALSE;
  }

  // Check for a cached version of this piece of text.
  $cache = $cache && !empty($format->cache);
  $cache_id = '';
  if ($cache) {
    $cache_id = $format->format . ':' . $langcode . ':' . hash('sha256', $text);
    if ($cached = cache('filter')->get($cache_id)) {
      return $cached->data;
    }
  }

  // Convert all Windows and Mac newlines to a single newline, so filters only
  // need to deal with one possibility.
  $text = str_replace(array("\r\n", "\r"), "\n", $text);

  // Get a complete list of filters, ordered properly.
  $filters = filter_list_format($format->format);
  $filter_info = filter_get_filters();

  // Give filters the chance to escape HTML-like data such as code or formulas.
  foreach ($filters as $name => $filter) {
    // If necessary, skip filters of a certain type.
    if (in_array($filter_info[$name]['type'], $filter_types_to_skip)) {
      continue;
    }
    if (!empty($filter->status) && isset($filter_info[$name]['prepare callback'])) {
      $function = $filter_info[$name]['prepare callback'];
      $text = $function($text, $filter, $format, $langcode, $cache, $cache_id);
    }
  }

  // Perform filtering.
  foreach ($filters as $name => $filter) {
    // If necessary, skip filters of a certain type.
    if (in_array($filter_info[$name]['type'], $filter_types_to_skip)) {
      continue;
    }
    if (!empty($filter->status) && isset($filter_info[$name]['process callback'])) {
      $function = $filter_info[$name]['process callback'];
      $text = $function($text, $filter, $format, $langcode, $cache, $cache_id);
    }
  }

  // Cache the filtered text. This cache is infinitely valid. It becomes
  // obsolete when $text changes (which leads to a new $cache_id). It is
  // automatically flushed when the text format is updated.
  // @see filter_format_save()
  if ($cache) {
    cache('filter')->set($cache_id, $text);
  }

  return $text;
}

/**
 * Retrieves all filter types that are used in a given text format.
 *
 * @param string $format_id
 *   A text format ID.
 *
 * @return array
 *   All filter types used by filters of a given text format.
 */
function filter_get_filter_types_by_format($format_id) {
  $filter_types = array();

  $filters = filter_list_format($format_id);
  $filters_info = filter_get_filters();
  foreach ($filters as $filter) {
    // Ignore filters that are disabled.
    if (empty($filter->status)) {
      continue;
    }

    if (!isset($filters_info[$filter->name]['type'])) {
      drupal_set_message(t('The filter "!filter" has no type specified! This is required for the Quick Edit module. Please consult Quick Edit module\'s README.', array('!filter' => $filter->name)), 'error');
      continue;
    }

    $filter_types[] = $filters_info[$filter->name]['type'];
  }

  return array_unique($filter_types);
}

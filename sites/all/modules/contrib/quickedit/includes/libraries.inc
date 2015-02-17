<?php

/**
 * @file
 * Logic to nicely integrate with Libraries API.
 */

/**
 * Determines the version of an Quick Edit library.
 *
 * This is used in case different variants of the library are shipped separately
 * and, thus, different variants can contain different versions.
 *
 * @param array $library
 *   An associative array containing all information about the library. The
 *   library is assumed to have the following non-standard keys:
 *   - variant order: An array of variant names, ordered from the most preferred
 *     variant to the least preferred.
 * @param array $options
 *   An associative array with the following keys:
 *   - variants: An array of options for libraries_get_version() keyed by
 *     variant name.
 *
 */
function _quickedit_libraries_get_version(&$library, $options = array()) {
  $versions = array();
  foreach ($library['variant order'] as $variant_name) {
    $variant = $library['version arguments']['variants'][$variant_name];
    // Use the libraries get version function to determine the version string.
    $versions[$variant_name] = libraries_get_version($library, $variant);
  }

  // If no versions could be found for any of the variant, there is no version
  // to return. If different versions have been found, there is no way to
  // determine the correct one. We cannot use the information on the preferred
  // variants because we cannot guarantee that a less preferred variant will not
  // be loaded. Null values are fine. Either that variant file doesn't exist
  // or id doesn't contain version information. As long as the there is no
  // conflicting version information, the check should pass.
  $versions = array_filter($versions, '_quickedit_libraries_filter_null_values');
  $version = array_unique($versions);
  $vcount = count($version);
  if ($vcount == 1) {
    // A version number exists, so suppress any errors that any individual
    // variant might have raised.
    unset($library['error']);
    unset($library['error message']);
    return array_shift($version);
  }
  elseif ($vcount > 1) {
    $output = array();
    foreach ($versions as $name => $v) {
      $output[] = t('@name (@v)', array(
        '@name' => $name,
        '@v' => $v,
      ));
    }

    $library['error'] = 'inconsistent versions';
    $library['error message'] = t('The library\'s variants returned inconsistent versions: @variant_info', array(
      '@variant_info' => implode(', ', $output),
    ));
  }
  // If the version count is zero, then let the error from libraries_get_version
  // propagate through.
}

/**
 * Determines if an item is empty or not.
 *
 * @param string $item
 *   A version number string.
 * @return boolean
 *   Whether the $item's value is empty or not.
 */
function _quickedit_libraries_filter_null_values($item) {
  return !empty($item);
}

/**
 * Libraries API variant callback.
 */
function _quickedit_libraries_variant_exists($library, $variant_name, $required_file) {
  return file_exists($library['library path'] . '/' . $required_file);;
}

/**
 * Converts a libraries module array to a hook_library array.
 *
 * @todo Libraries API should automatically register all libraries in
 *   hook_library(). See https://drupal.org/node/1386368
 *
 * @return Array
 *  Returns a standard Drupal library definition structure.
 */
function _quickedit_convert_libraries_to_library($library, $options = array()) {
  // If the library wasn't installed, don't bother converting it.
  if (!$library['installed']) {
    return array();
  }

  $converted = array();
  $files = array();

  // Get the library files from one of the installed variants.
  if ($name = _quickedit_libraries_get_preferred_variant_name($library)) {
    $files = $library['variants'][$name]['files'];
  }

  // Define the library if files exist for it.
  if (!empty($files)) {
    // This is the basic structure expected by hook_library().
    $converted = array(
      'title' => $library['name'],
      'website' => $library['vendor url'],
      'version' => $library['version'],
    );
    foreach ($files as $type => $paths) {
      foreach($paths as $filename => $data) {
        $converted[$type][$library['library path'] . '/' . $filename] = $options;
      }
    }
  }

  return $converted;
}

/**
 * Returns the variant that should be loaded based on order preference.
 *
 * @param array $library
 *   A libraries module library definition array.
 * @return string
 *   The name of the variant that should be loaded.
 */
function _quickedit_libraries_get_preferred_variant_name($library) {
  if (!empty($library['variant order'])) {
    foreach ($library['variant order'] as $name) {
      if ($variant = $library['variants'][$name]) {
        if ($variant['installed']) {
          return $name;
        }
      }
    }
  }
  return NULL;
}

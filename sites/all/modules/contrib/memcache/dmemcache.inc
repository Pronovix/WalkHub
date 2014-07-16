<?php

/**
 * @file
 * A memcache API for Drupal.
 *
 * This file contains core dmemcache functions required by:
 *   memcache.inc
 *   memcache-lock.inc
 *   memcache-lock-code.inc
 *   memcache-session.inc
 */

global $_dmemcache_stats;
$_dmemcache_stats = array('all' => array(), 'ops' => array());

/**
 * Place an item into memcache.
 *
 * @param string $key
 *   The string with which you will retrieve this item later.
 * @param mixed $value
 *   The item to be stored.
 * @param int $exp
 *   Parameter expire is expiration time in seconds. If it's 0, the item never
 *   expires (but memcached server doesn't guarantee this item to be stored all
 *   the time, it could be deleted from the cache to make place for other
 *   items).
 * @param string $bin
 *   The name of the Drupal subsystem that is making this call. Examples could
 *   be 'cache', 'alias', 'taxonomy term' etc. It is possible to map different
 *   $bin values to different memcache servers.
 * @param object $mc
 *   Optionally pass in the memcache object.  Normally this value is determined
 *   automatically based on the bin the object is being stored to.
 *
 * @return bool
 *   TRUE on succes, FALSE otherwise.
 */
function dmemcache_set($key, $value, $exp = 0, $bin = 'cache', $mc = NULL) {
  $collect_stats = dmemcache_stats_init();

  $full_key = dmemcache_key($key, $bin);

  $rc = FALSE;
  if ($mc || ($mc = dmemcache_object($bin))) {
    if ($mc instanceof Memcached) {
      $rc = $mc->set($full_key, $value, $exp);
    }
    else {
      $rc = $mc->set($full_key, $value, MEMCACHE_COMPRESSED, $exp);
    }
  }

  if ($collect_stats) {
    dmemcache_stats_write('set', $bin, array($full_key => $rc));
  }

  return $rc;
}

/**
 * Add an item into memcache.
 *
 * @param string $key
 *   The string with which you will retrieve this item later.
 * @param mixed $value
 *   The item to be stored.
 * @param int $exp
 *   Parameter expire is expiration time in seconds. If it's 0, the
 *   item never expires (but memcached server doesn't guarantee this item to be
 *   stored all the time, it could be deleted from the cache to make place for
 *   other items).
 * @param string $bin
 *   The name of the Drupal subsystem that is making this call.
 *   Examples could be 'cache', 'alias', 'taxonomy term' etc. It is possible
 *   to map different $bin values to different memcache servers.
 * @param object $mc
 *   Optionally pass in the memcache object.  Normally this value is
 *   determined automatically based on the bin the object is being stored to.
 * @param int $flag
 *   If using the older memcache PECL extension as opposed to the
 *   newer memcached PECL extension, the MEMCACHE_COMPRESSED flag can be set
 *   to use zlib to store a compressed copy of the item.  This flag option is
 *   completely ignored when using the newer memcached PECL extension.
 *
 * @return bool
 *   FALSE if placing the item into memcache failed.
 */
function dmemcache_add($key, $value, $exp = 0, $bin = 'cache', $mc = NULL, $flag = FALSE) {
  $collect_stats = dmemcache_stats_init();

  $full_key = dmemcache_key($key, $bin);

  $rc = FALSE;
  if ($mc || ($mc = dmemcache_object($bin))) {
    if ($mc instanceof Memcached) {
      $rc = $mc->add($full_key, $value, $exp);
    }
    else {
      $rc = $mc->add($full_key, $value, $flag, $exp);
    }
  }

  if ($collect_stats) {
    dmemcache_stats_write('add', $bin, array($full_key => $rc));
  }

  return $rc;
}

/**
 * Retrieve a value from the cache.
 *
 * @param string $key
 *   The key with which the item was stored.
 * @param string $bin
 *   The bin in which the item was stored.
 *
 * @return mixed
 *   The item which was originally saved or FALSE
 */
function dmemcache_get($key, $bin = 'cache', $mc = NULL) {
  $collect_stats = dmemcache_stats_init();

  $result = FALSE;

  $full_key = dmemcache_key($key, $bin);
  if ($mc || $mc = dmemcache_object($bin)) {
    $track_errors = ini_set('track_errors', '1');
    $php_errormsg = '';

    $result = @$mc->get($full_key);

    if (!empty($php_errormsg)) {
      register_shutdown_function('watchdog', 'memcache', 'Exception caught in dmemcache_get: !msg', array('!msg' => $php_errormsg), WATCHDOG_WARNING);
      $php_errormsg = '';
    }
    ini_set('track_errors', $track_errors);
  }

  if ($collect_stats) {
    dmemcache_stats_write('get', $bin, array($full_key => (bool) $result));
  }

  return $result;
}

/**
 * Retrieve multiple values from the cache.
 *
 * @param array $keys
 *   The keys with which the items were stored.
 * @param string $bin
 *   The bin in which the item was stored.
 *
 * @return mixed
 *   The item which was originally saved or FALSE
 */
function dmemcache_get_multi($keys, $bin = 'cache', $mc = NULL) {
  $collect_stats = dmemcache_stats_init();
  $multi_stats = array();

  $full_keys = array();

  foreach ($keys as $key => $cid) {
    $full_key = dmemcache_key($cid, $bin);
    $full_keys[$cid] = $full_key;

    if ($collect_stats) {
      $multi_stats[$full_key] = FALSE;
    }
  }

  $results = array();
  if ($mc || ($mc = dmemcache_object($bin))) {
    if ($mc instanceof Memcached) {
      $results = $mc->getMulti($full_keys);
    }
    elseif ($mc instanceof Memcache) {
      $track_errors = ini_set('track_errors', '1');
      $php_errormsg = '';

      $results = @$mc->get($full_keys);

      if (!empty($php_errormsg)) {
        register_shutdown_function('watchdog', 'memcache', 'Exception caught in dmemcache_get_multi: !msg', array('!msg' => $php_errormsg), WATCHDOG_WARNING);
        $php_errormsg = '';
      }
      ini_set('track_errors', $track_errors);
    }
  }
  // If $results is FALSE, convert it to an empty array.
  if (!$results) {
    $results = array();
  }

  if ($collect_stats) {
    foreach ($multi_stats as $key => $value) {
      $multi_stats[$key] = isset($results[$key]) ? TRUE : FALSE;
    }
  }

  // Convert the full keys back to the cid.
  $cid_results = array();
  $cid_lookup = array_flip($full_keys);
  foreach ($results as $key => $value) {
    $cid_results[$cid_lookup[$key]] = $value;
  }

  if ($collect_stats) {
    dmemcache_stats_write('getMulti', $bin, $multi_stats);
  }

  return $cid_results;
}

/**
 * Deletes an item from the cache.
 *
 * @param string $key
 *   The key with which the item was stored.
 * @param string $bin
 *   The bin in which the item was stored.
 *
 * @return bool
 *   Returns TRUE on success or FALSE on failure.
 */
function dmemcache_delete($key, $bin = 'cache', $mc = NULL) {
  $collect_stats = dmemcache_stats_init();

  $full_key = dmemcache_key($key, $bin);

  $rc = FALSE;
  if ($mc || ($mc = dmemcache_object($bin))) {
    $rc = $mc->delete($full_key, 0);
  }

  if ($collect_stats) {
    dmemcache_stats_write('delete', $bin, array($full_key => $rc));
  }

  return $rc;
}

/**
 * Flush all stored items.
 *
 * Immediately invalidates all existing items. dmemcache_flush doesn't actually
 * free any resources, it only marks all the items as expired, so occupied
 * memory will be overwritten by new items.
 *
 * @param string $bin
 *   The bin to flush. Note that this will flush all bins mapped to the same
 *   server as $bin. There is no way at this time to empty just one bin.
 *
 * @return bool
 *   Returns TRUE on success or FALSE on failure.
 */
function dmemcache_flush($bin = 'cache', $mc = NULL) {
  $collect_stats = dmemcache_stats_init();

  $rc = FALSE;
  if ($mc || ($mc = dmemcache_object($bin))) {
    $rc = memcache_flush($mc);
  }

  if ($collect_stats) {
    dmemcache_stats_write('flush', $bin, array('' => $rc));
  }

  return $rc;
}

/**
 * Retrieves statistics recorded during memcache operations.
 *
 * @param string $stats_bin
 *   The bin to retrieve statistics for.
 * @param string $stats_type
 *   The type of statistics to retrieve when using the Memcache extension.
 * @param bool $aggregate
 *   Whether to aggregate statistics.
 */
function dmemcache_stats($stats_bin = 'cache', $stats_type = 'default', $aggregate = FALSE) {
  $memcache_bins = variable_get('memcache_bins', array('cache' => 'default'));
  // The stats_type can be over-loaded with an integer slab id, if doing a
  // cachedump.  We know we're doing a cachedump if $slab is non-zero.
  $slab = (int) $stats_type;
  $stats = array();

  foreach ($memcache_bins as $bin => $target) {
    if ($stats_bin == $bin) {
      if ($mc = dmemcache_object($bin)) {
        if ($mc instanceof Memcached) {
          $stats[$bin] = $mc->getStats();
        }
        // The PHP Memcache extension 3.x version throws an error if the stats
        // type is NULL or not in {reset, malloc, slabs, cachedump, items,
        // sizes}. If $stats_type is 'default', then no parameter should be
        // passed to the Memcache memcache_get_extended_stats() function.
        elseif ($mc instanceof Memcache) {
          if ($stats_type == 'default' || $stats_type == '') {
            $stats[$bin] = $mc->getExtendedStats();
          }
          // If $slab isn't zero, then we are dumping the contents of a
          // specific cache slab.
          elseif (!empty($slab)) {
            $stats[$bin] = $mc->getStats('cachedump', $slab);
          }
          else {
            $stats[$bin] = $mc->getExtendedStats($stats_type);
          }
        }
      }
    }
  }
  // Optionally calculate a sum-total for all servers in the current bin.
  if ($aggregate) {
    // Some variables don't logically aggregate.
    $no_aggregate = array(
      'pid',
      'time',
      'version',
      'pointer_size',
      'accepting_conns',
      'listen_disabled_num',
    );
    foreach ($stats as $bin => $servers) {
      if (is_array($servers)) {
        foreach ($servers as $server) {
          if (is_array($server)) {
            foreach ($server as $key => $value) {
              if (!in_array($key, $no_aggregate)) {
                if (isset($stats[$bin]['total'][$key])) {
                  $stats[$bin]['total'][$key] += $value;
                }
                else {
                  $stats[$bin]['total'][$key] = $value;
                }
              }
            }
          }
        }
      }
    }
  }
  return $stats;
}

/**
 * Determine which memcache extension to use: memcache or memcached.
 *
 * By default prefer the 'Memcache' PHP extension, though the default can be
 * overridden by setting memcache_extension in settings.php.
 */
function dmemcache_extension() {
  static $extension = NULL;
  if ($extension === NULL) {
    // If an extension is specified in settings.php, use that when available.
    $preferred = variable_get('memcache_extension', NULL);
    if (isset($preferred) && class_exists($preferred)) {
      $extension = ucfirst(strtolower($preferred));
    }
    // If no extension is set, default to Memcache.
    elseif (class_exists('Memcache')) {
      $extension = 'Memcache';
    }
    elseif (class_exists('Memcached')) {
      $extension = 'Memcached';
    }
    else {
      $extension = FALSE;
    }
  }
  return $extension;
}

/**
 * Return a new memcache instance.
 */
function dmemcache_instance() {
  static $error = FALSE;
  $extension = dmemcache_extension();
  if ($extension == 'Memcache') {
    return new Memcache();
  }
  elseif ($extension == 'Memcached') {
    $memcache = new Memcached();
    $default_opts = array(
      Memcached::OPT_COMPRESSION => FALSE,
      Memcached::OPT_DISTRIBUTION => Memcached::DISTRIBUTION_CONSISTENT,
    );
    foreach ($default_opts as $key => $value) {
      $memcache->setOption($key, $value);
    }
    // See README.txt for setting custom Memcache options when using the
    // memcached PECL extension.
    $memconf = variable_get('memcache_options', array());
    foreach ($memconf as $key => $value) {
      $memcache->setOption($key, $value);
    }
    return $memcache;
  }
  else {
    if (!$error) {
      register_shutdown_function('watchdog', 'memcache', 'You must enable the PHP <a href="http://php.net/manual/en/book.memcache.php">memcache</a> (recommended) or <a href="http://php.net/manual/en/book.memcached.php">memcached</a> extension to use memcache.inc.', array(), WATCHDOG_ERROR);
      $error = TRUE;
    }
  }
  return FALSE;
}

/**
 * Initiate a connection to memcache.
 *
 * @param object $memcache
 *   A memcache instance obtained through dmemcache_instance.
 * @param string $server
 *   A server string of the format "localhost:11211" or
 *   "unix:///path/to/socket".
 * @param bool $connection
 *   TRUE or FALSE, whether the $memcache instance already has at least one
 *   open connection.
 *
 * @return bool
 *   TRUE or FALSE if connection was successful.
 */
function dmemcache_connect($memcache, $server, $connection) {
  static $memcache_persistent = NULL;

  $extension = dmemcache_extension();

  list($host, $port) = explode(':', $server);

  if ($extension == 'Memcache') {
    // Allow persistent connection via Memcache extension -- note that this
    // module currently doesn't support persistent connections with the
    // Memcached extension. See http://drupal.org/node/822316#comment-4427676
    // for details.
    if (!isset($memcache_persistent)) {
      $memcache_persistent = variable_get('memcache_persistent', FALSE);
    }

    // Support unix sockets of the format 'unix:///path/to/socket'.
    if ($host == 'unix') {
      // Use full protocol and path as expected by Memcache extension.
      $host = $server;
      $port = 0;
    }

    // When using the PECL memcache extension, we must use ->(p)connect
    // for the first connection.
    if (!$connection) {
      $track_errors = ini_set('track_errors', '1');
      $php_errormsg = '';

      // The Memcache extension requires us to use (p)connect for the first
      // server we connect to.
      if ($memcache_persistent) {
        $rc = @$memcache->pconnect($host, $port);
      }
      else {
        $rc = @$memcache->connect($host, $port);
      }
      if (!empty($php_errormsg)) {
        register_shutdown_function('watchdog', 'memcache', 'Exception caught in dmemcache_object: !msg', array('!msg' => $php_errormsg), WATCHDOG_WARNING);
        $php_errormsg = '';
      }
      ini_set('track_errors', $track_errors);
    }
    else {
      $rc = $memcache->addServer($host, $port, $memcache_persistent);
    }
  }
  elseif ($extension == 'Memcached') {
    // Support unix sockets of the format 'unix:///path/to/socket'.
    if ($host == 'unix') {
      // Strip 'unix://' as expected by Memcached extension.
      $host = substr($server, 7);
      $port = 0;
    }
    $rc = $memcache->addServer($host, $port);
  }
  else {
    $rc = FALSE;
  }
  return $rc;
}

/**
 * Close the connection to the memcache instance.
 */
function dmemcache_close($memcache) {
  $extension = dmemcache_extension();
  if ($extension == 'Memcache' && $memcache instanceof Memcache) {
    $rc = @$memcache->close;
  }
  elseif ($extension == 'Memcached' && $memcache instanceof Memcached) {
    $rc = @$memcache->quit;
  }
  else {
    $rc = FALSE;
  }
  return $rc;
}

/**
 * Return a Memcache object for the specified bin.
 *
 * Note that there is nothing preventing developers from calling this function
 * directly to get the Memcache object. Do this if you need functionality not
 * provided by this API or if you need to use legacy code. Otherwise, use the
 * dmemcache (get, set, delete, flush) API functions provided here.
 *
 * @param string $bin
 *   The bin which is to be used.
 * @param bool $flush
 *   Defaults to FALSE. Rebuild the bin/server/cache mapping.
 *
 * @return mixed
 *   A Memcache object, or FALSE on failure.
 */
function dmemcache_object($bin = NULL, $flush = FALSE) {
  static $memcache_cache = array();
  static $memcache_servers = array();
  static $memcache_bins = array();
  static $failed_connections = array();

  if ($flush) {
    foreach ($memcache_cache as $cluster) {
      memcache_close($cluster);
    }
    $memcache_cache = array();
  }

  $extension = dmemcache_extension();

  if (empty($memcache_cache) || empty($memcache_cache[$bin])) {
    if (empty($memcache_servers)) {
      // Load the variables from settings.php if set.
      $memcache_servers = variable_get('memcache_servers', array('127.0.0.1:11211' => 'default'));
      $memcache_bins = variable_get('memcache_bins', array('cache' => 'default'));
    }

    // If not manually set, default this cluster to 'default'.
    $cluster = empty($memcache_bins[$bin]) ? 'default' : $memcache_bins[$bin];

    // If not manually set, map this bin to 'cache' which maps to the 'default'
    // cluster.
    if (empty($memcache_bins[$bin]) && !empty($memcache_cache['cache'])) {
      $memcache_cache[$bin] = &$memcache_cache['cache'];
    }
    else {
      // Create a new memcache object for each cluster.
      $memcache = dmemcache_instance();

      // Track whether or not we've opened any memcache connections.
      $connection = FALSE;

      // Link all the servers to this cluster.
      foreach ($memcache_servers as $server => $c) {
        if ($c == $cluster && !isset($failed_connections[$server])) {
          $rc = dmemcache_connect($memcache, $server, $connection);
          if ($rc !== FALSE) {
            // We've made at least one successful connection.
            $connection = TRUE;
          }
          else {
            // Memcache connection failure. We can't log to watchdog directly
            // because we're in an early Drupal bootstrap phase where watchdog
            // is non-functional. Instead, register a shutdown handler so it
            // gets recorded at the end of the page load.
            register_shutdown_function('watchdog', 'memcache', 'Failed to connect to memcache server: !server', array('!server' => $server), WATCHDOG_ERROR);
            $failed_connections[$server] = FALSE;
          }
        }
      }
      if ($connection) {
        // Map the current bin with the new Memcache object.
        $memcache_cache[$bin] = $memcache;

        // Now that all the servers have been mapped to this cluster, look for
        // other bins that belong to the cluster and map them too.
        foreach ($memcache_bins as $b => $c) {
          if ($c == $cluster && $b != $bin) {
            // Map this bin and cluster by reference.
            $memcache_cache[$b] = &$memcache_cache[$bin];
          }
        }
      }
    }
  }

  return empty($memcache_cache[$bin]) ? FALSE : $memcache_cache[$bin];
}

/**
 * Prefixes a key and ensures it is url safe.
 *
 * @param string $key
 *   The key to prefix and encode.
 * @param string $bin
 *   The cache bin which the key applies to.
 *
 * @return string
 *   The prefixed and encoded key.
 */
function dmemcache_key($key, $bin = 'cache') {
  $prefix = '';
  if ($prefix = variable_get('memcache_key_prefix', '')) {
    $prefix .= '-';
  }
  // When simpletest is running, emulate the simpletest database prefix here
  // to avoid the child site setting cache entries in the parent site.
  if (isset($GLOBALS['drupal_test_info']['test_run_id'])) {
    $prefix .= $GLOBALS['drupal_test_info']['test_run_id'];
  }
  $full_key = urlencode($prefix . $bin . '-' . $key);

  // Memcache only supports key lengths up to 250 bytes.  If we have generated
  // a longer key, we shrink it to an acceptible length with a configurable
  // hashing algorithm. Sha1 was selected as the default as it performs
  // quickly with minimal collisions.
  if (strlen($full_key) > 250) {
    $full_key = urlencode(hash(variable_get('memcache_key_hash_algorithm', 'sha1'), $prefix . $bin . '-' . $key));
  }

  return $full_key;
}

/**
 * Collect statistics if enabled.
 *
 * Optimized function to determine whether or not we should be collecting
 * statistics. Also starts a timer to track how long individual memcache
 * operations take.
 *
 * @return bool
 *   TRUE or FALSE if statistics should be collected.
 */
function dmemcache_stats_init() {
  static $drupal_static_fast;

  if (!isset($drupal_static_fast)) {
    $drupal_static_fast = &drupal_static(__FUNCTION__, array('variable_checked' => NULL, 'user_access_checked' => NULL));
  }
  $variable_checked = &$drupal_static_fast['variable_checked'];
  $user_access_checked  = &$drupal_static_fast['user_access_checked'];

  // Confirm DRUPAL_BOOTSTRAP_VARIABLES has been reached. We don't use
  // drupal_get_bootstrap_phase() as it's buggy. We can use variable_get() here
  // because _drupal_bootstrap_variables() includes module.inc immediately
  // after it calls variable_initialize().
  if (!isset($variable_checked) && function_exists('module_list')) {
    $variable_checked = variable_get('show_memcache_statistics', FALSE);
  }
  // If statistics are enabled we need to check user access.
  if (!empty($variable_checked) && !isset($user_access_checked) && !empty($GLOBALS['user']) && function_exists('user_access')) {
    // Statistics are enabled and the $user object has been populated, so check
    // that the user has access to view them.
    $user_access_checked = user_access('access memcache statistics');
  }
  // Return whether or not statistics are enabled and the user can access them.
  if ((!isset($variable_checked) || $variable_checked) && (!isset($user_access_checked) || $user_access_checked)) {
    timer_start('dmemcache');
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Save memcache statistics to be displayed at end of page generation.
 *
 * @param string $action
 *   The action being performed (get, set, etc...).
 * @param string $bin
 *   The memcache bin the action is being performed in.
 * @param array $keys
 *   Keyed array in the form (string)$cid => (bool)$success. The keys the
 *   action is being performed on, and whether or not it was a success.
 */
function dmemcache_stats_write($action, $bin, $keys) {
  global $_dmemcache_stats;
  // Determine how much time elapsed to execute this action.
  $time = timer_read('dmemcache');
  // Build the 'all' and 'ops' arrays displayed by memcache_admin.module.
  foreach ($keys as $key => $success) {
    $_dmemcache_stats['all'][] = array(
      number_format($time, 2),
      $action,
      $bin,
      $key,
      $success ? 'hit' : 'miss',
    );
    if (!isset($_dmemcache_stats['ops'][$action])) {
      $_dmemcache_stats['ops'][$action] = array($action, 0, 0, 0);
    }
    $_dmemcache_stats['ops'][$action][1] += $time;
    if ($success) {
      $_dmemcache_stats['ops'][$action][2]++;
    }
    else {
      $_dmemcache_stats['ops'][$action][3]++;
    }
  }
  // Reset the dmemcache timer for timing the next memcache operation.
}

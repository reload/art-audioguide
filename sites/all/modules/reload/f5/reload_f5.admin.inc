<?php

/**
 * @file
 * Admin area for Reload! F5 module.
 */

/**
 * Menu callback to show included settings file's variables.
 */
function reload_f5_view_settings_variables() {
  $settings_files = _reload_f5_get_our_setting_files();
  $renderable = array();
  foreach ($settings_files as $filename => $path) {
    $renderable[] = array(
      '#prefix' => '<h3>' . $path . '</h3></h3><pre>',
      // Exclude the opening PHP tag so we don't have to escape it.
      '#markup' => file_get_contents($path, FALSE, NULL, 6),
      '#suffix' => '</pre>',
    );
  }
  return $renderable;
}

/**
 * Menu callback to display overridden variables.
 *
 * Shows the variables that have different values than the ones we have in our
 * included settings files.
 *
 * @return string
 *   A table showing variables that are overriden in the database.
 */
function reload_f5_overridden_variables_view() {
  $settings_files = _reload_f5_get_our_setting_files();
  $db_vars = array_map('unserialize', db_query('SELECT name, value FROM {variable}')->fetchAllKeyed());

  $rows = array();
  foreach ($settings_files as $filename => $path) {
    // Trickery I know. Keep in mind that the $conf var here is local.
    include $path;
    foreach ($conf as $key => $value) {
      if (isset($db_vars[$key]) && $db_vars[$key] != $value) {
        // FALSE will be shown as nothing, so make the output a little more
        // readable by making it look like what comes out of the DB.
        if (is_bool($value)) {
          $value = $value ? 1 : 0;
        }
        // Use $key as key in the table array as an easy way to get unique
        // array entries reflecting the overrides the files can have too.
        $rows[$key] = array($filename, $key, $value, $db_vars[$key]);
      }
    }
  }

  if (!empty($rows)) {
    $output = '<p>' . t('Variables that can be seen in this page are variables that we have in settings files, but have overrides in the database.') . '</p>';
    return $output . theme('table', array(
      'header' => array(
        t('Filename'),
        t('Variable'),
        t('File value'),
        t('Database value'),
      ),
      'rows' => $rows,
    ));
  }
  return t('There are no variable overrides');
}

/**
 * Helper function to get the settings files we have included in settings.php.
 *
 * @return array
 *   Array containing file paths to settings files.
 */
function _reload_f5_get_our_setting_files() {
  $settings_file = file_get_contents(conf_path() . '/settings.php');
  $matches = array();
  // Get the included settings files from the actual settings file.
  preg_match_all('@^\s?require_once\((\'|")(.*)(\'|")\);@m', $settings_file, $matches);
  $files = array();
  if (!empty($matches[2])) {
    foreach ($matches[2] as $filename) {
      $files[$filename] = conf_path() . '/' . $filename;
    }
  }
  return $files;
}

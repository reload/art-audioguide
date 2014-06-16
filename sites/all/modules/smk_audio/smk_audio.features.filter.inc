<?php
/**
 * @file
 * smk_audio.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function smk_audio_filter_default_formats() {
  $formats = array();

  // Exported format: Strictly HTML.
  $formats['strictly_html'] = array(
    'format' => 'strictly_html',
    'name' => 'Strictly HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 128,
        ),
      ),
    ),
  );

  return $formats;
}

<?php
/**
 * @file
 * smk_base.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function smk_base_filter_default_formats() {
  $formats = array();

  // Exported format: HTML text.
  $formats['html_text'] = array(
    'format' => 'html_text',
    'name' => 'HTML text',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'media_filter' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Strictly HTML.
  $formats['strictly_html'] = array(
    'format' => 'strictly_html',
    'name' => 'Strictly HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
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

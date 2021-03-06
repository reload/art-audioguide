<?php
/**
 * @file
 * smk_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function smk_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function smk_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function smk_base_image_default_styles() {
  $styles = array();

  // Exported image style: full_content_size.
  $styles['full_content_size'] = array(
    'label' => 'Full content size',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large_tile.
  $styles['large_tile'] = array(
    'label' => 'Large tile',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: small_tile.
  $styles['small_tile'] = array(
    'label' => 'Small tile',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function smk_base_node_info() {
  $items = array(
    'frontpage_tile' => array(
      'name' => t('Frontpage tile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'generic_page' => array(
      'name' => t('Embedded content page'),
      'base' => 'node_content',
      'description' => t('These pages are only for embedding lists like "All routes" etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('These pages are basic pages like "About us" or similar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

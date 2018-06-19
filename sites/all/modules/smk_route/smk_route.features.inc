<?php
/**
 * @file
 * smk_route.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function smk_route_ctools_plugin_api($module = NULL, $api = NULL) {
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
function smk_route_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function smk_route_image_default_styles() {
  $styles = array();

  // Exported image style: all_routes_style__80x80_crop.
  $styles['all_routes_style__80x80_crop'] = array(
    'label' => 'All routes (80x80 crop)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function smk_route_node_info() {
  $items = array(
    'route' => array(
      'name' => t('Route'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

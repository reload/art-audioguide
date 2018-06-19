<?php
/**
 * @file
 * smk_piece.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function smk_piece_ctools_plugin_api($module = NULL, $api = NULL) {
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
function smk_piece_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function smk_piece_image_default_styles() {
  $styles = array();

  // Exported image style: all_artworks__55x56.
  $styles['all_artworks__55x56'] = array(
    'label' => 'All artworks (55x56)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 55,
          'height' => 56,
          'upscale' => 1,
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
function smk_piece_node_info() {
  $items = array(
    'artist' => array(
      'name' => t('Artist'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'piece' => array(
      'name' => t('Artwork'),
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

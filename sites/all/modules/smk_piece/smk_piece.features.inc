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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function smk_piece_node_info() {
  $items = array(
    'artist' => array(
      'name' => t('Kunstner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Navn'),
      'help' => '',
    ),
    'piece' => array(
      'name' => t('Værk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}

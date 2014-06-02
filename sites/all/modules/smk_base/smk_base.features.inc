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
 * Implements hook_node_info().
 */
function smk_base_node_info() {
  $items = array(
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
  return $items;
}

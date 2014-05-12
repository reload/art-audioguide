<?php
/**
 * @file
 * smk_audio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function smk_audio_ctools_plugin_api($module = NULL, $api = NULL) {
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
function smk_audio_node_info() {
  $items = array(
    'audio' => array(
      'name' => t('Lyd'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}

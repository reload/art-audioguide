<?php
/**
 * @file
 * smk_route.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function smk_route_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|route|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'route';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_audio_ref',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_audio_ref' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|route|default'] = $ds_layout;

  return $export;
}

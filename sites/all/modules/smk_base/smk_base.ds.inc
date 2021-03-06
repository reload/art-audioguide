<?php
/**
 * @file
 * smk_base.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function smk_base_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|generic_page|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'generic_page';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'attached_block' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|generic_page|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function smk_base_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|generic_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'generic_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_info_panel',
        1 => 'title',
        2 => 'body',
        3 => 'attached_block',
      ),
    ),
    'fields' => array(
      'group_info_panel' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'attached_block' => 'ds_content',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|generic_page|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_video',
        2 => 'field_text_after_image',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_video' => 'ds_content',
      'field_text_after_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|page|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function smk_base_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_result';
  $ds_view_mode->label = 'Search Result';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_result'] = $ds_view_mode;

  return $export;
}

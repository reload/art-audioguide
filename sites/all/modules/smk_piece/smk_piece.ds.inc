<?php
/**
 * @file
 * smk_piece.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function smk_piece_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|artist|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'artist';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'artworks_based_on_artist' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|artist|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|piece|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'piece';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'sounds_on_piece' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'info-panel',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|piece|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|piece|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'piece';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'field_artist' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'artist',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|piece|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|piece|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'piece';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_artist' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'artist',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'thumbnail-wrapper',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_year_of_creation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'year',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|piece|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function smk_piece_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'artworks_based_on_artist';
  $ds_field->label = 'Artworks based on artist';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'artist|*';
  $ds_field->properties = array(
    'block' => 'views|artwork_by_artist-block',
    'block_render' => '3',
  );
  $export['artworks_based_on_artist'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'sounds_on_piece';
  $ds_field->label = 'Sounds on piece';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'piece|*';
  $ds_field->properties = array(
    'block' => 'views|artwork-sounds_on_piece',
    'block_render' => '1',
  );
  $export['sounds_on_piece'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function smk_piece_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|artist|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'artist';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'artworks_based_on_artist',
      ),
    ),
    'fields' => array(
      'artworks_based_on_artist' => 'ds_content',
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
  $export['node|artist|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|piece|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'piece';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'sounds_on_piece',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'sounds_on_piece' => 'ds_content',
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
  $export['node|piece|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|piece|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'piece';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'audio_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'audio_2col_thumbnail' => array(
        0 => 'field_image',
      ),
      'audio_2col_title' => array(
        1 => 'title_field',
      ),
      'audio_2col_content' => array(
        2 => 'field_artist',
        3 => 'field_year_of_creation',
      ),
    ),
    'fields' => array(
      'field_image' => 'audio_2col_thumbnail',
      'title_field' => 'audio_2col_title',
      'field_artist' => 'audio_2col_content',
      'field_year_of_creation' => 'audio_2col_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'audio_2col_thumbnail' => 'div',
      'audio_2col_title' => 'div',
      'audio_2col_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|piece|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|piece|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'piece';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title_field',
        2 => 'group_content',
        3 => 'field_artist',
        4 => 'field_year_of_creation',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title_field' => 'ds_content',
      'group_content' => 'ds_content',
      'field_artist' => 'ds_content',
      'field_year_of_creation' => 'ds_content',
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
  $export['node|piece|teaser'] = $ds_layout;

  return $export;
}

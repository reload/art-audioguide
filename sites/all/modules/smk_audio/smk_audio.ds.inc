<?php
/**
 * @file
 * smk_audio.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function smk_audio_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|audio|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'body_clone' => array(
      'weight' => '20',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:3:{s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:1;s:19:"override_title_text";s:0:"";}s:4:"type";s:9:"node_body";s:7:"subtype";s:9:"node_body";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'content',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'social_media_list' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'share-links',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'sound_piece_id' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'audio-id',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'sound_mediaplayer_metadata' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'sound_piece_image' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'truncated-paragraph',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|audio|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|audio|route_context';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'route_context';
  $ds_fieldsetting->settings = array(
    'sound_duration' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'duration',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'sound_artist' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
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
    'sound_piece_id' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'delta-overlay',
        ),
      ),
    ),
  );
  $export['node|audio|route_context'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|audio|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'sound_duration' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'content',
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
  );
  $export['node|audio|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|audio|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'sound_duration' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'duration',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'sound_artist' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
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
    'sound_piece_id' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
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
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|audio|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function smk_audio_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|audio|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_mediaplayer',
        1 => 'group_info_panel',
        2 => 'sound_mediaplayer_metadata',
        3 => 'group_content',
        4 => 'field_audio_file',
        5 => 'social_media_list',
        6 => 'sound_piece_image',
        7 => 'group_headline',
        8 => 'body',
        9 => 'sound_piece_id',
        10 => 'title_field',
        11 => 'body_clone',
      ),
    ),
    'fields' => array(
      'group_mediaplayer' => 'ds_content',
      'group_info_panel' => 'ds_content',
      'sound_mediaplayer_metadata' => 'ds_content',
      'group_content' => 'ds_content',
      'field_audio_file' => 'ds_content',
      'social_media_list' => 'ds_content',
      'sound_piece_image' => 'ds_content',
      'group_headline' => 'ds_content',
      'body' => 'ds_content',
      'sound_piece_id' => 'ds_content',
      'title_field' => 'ds_content',
      'body_clone' => 'ds_content',
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
  $export['node|audio|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|audio|route_context';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'route_context';
  $ds_layout->layout = 'audio_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'audio_2col_thumbnail' => array(
        0 => 'field_image',
      ),
      'audio_2col_title' => array(
        1 => 'sound_piece_id',
        2 => 'title_field',
      ),
      'audio_2col_content' => array(
        3 => 'sound_artist',
        4 => 'sound_duration',
      ),
    ),
    'fields' => array(
      'field_image' => 'audio_2col_thumbnail',
      'sound_piece_id' => 'audio_2col_title',
      'title_field' => 'audio_2col_title',
      'sound_artist' => 'audio_2col_content',
      'sound_duration' => 'audio_2col_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'audio_2col_thumbnail' => 'div',
      'audio_2col_title' => 'div',
      'audio_2col_content' => 'div',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => 'tokens',
    'layout_link_custom' => '[node:url]?route=[current-page:url:unaliased:args:value:1]',
  );
  $export['node|audio|route_context'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|audio|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title_field',
        2 => 'sound_duration',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title_field' => 'ds_content',
      'sound_duration' => 'ds_content',
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
  $export['node|audio|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|audio|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sound_artist',
        1 => 'field_image',
        2 => 'group_headline',
        3 => 'sound_duration',
        4 => 'sound_piece_id',
        5 => 'title_field',
        6 => 'group_content',
      ),
    ),
    'fields' => array(
      'sound_artist' => 'ds_content',
      'field_image' => 'ds_content',
      'group_headline' => 'ds_content',
      'sound_duration' => 'ds_content',
      'sound_piece_id' => 'ds_content',
      'title_field' => 'ds_content',
      'group_content' => 'ds_content',
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
  $export['node|audio|teaser'] = $ds_layout;

  return $export;
}

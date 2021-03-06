<?php
/**
 * @file
 * smk_audio.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function smk_audio_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|audio|default';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'sound_piece_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'classes' => 'artwork-container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_audio_full_group_content',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|audio|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|audio|teaser';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '4',
    'children' => array(
      0 => 'sound_duration',
      1 => 'sound_artist',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'classes' => 'content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_audio_teaser_group_content',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|audio|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline|node|audio|default';
  $field_group->group_name = 'group_headline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_info_panel';
  $field_group->data = array(
    'label' => 'Headline',
    'weight' => '17',
    'children' => array(
      0 => 'title_field',
      1 => 'sound_piece_id',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Headline',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'h2',
        'attributes' => '',
        'id' => 'node_audio_full_group_headline',
      ),
    ),
  );
  $field_groups['group_headline|node|audio|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline|node|audio|teaser';
  $field_group->group_name = 'group_headline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Headline',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'sound_piece_id',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Headline',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'h2',
        'attributes' => '',
        'id' => 'node_audio_teaser_group_headline',
      ),
    ),
  );
  $field_groups['group_headline|node|audio|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_panel|node|audio|default';
  $field_group->group_name = 'group_info_panel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info panel',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'body_clone',
      2 => 'group_headline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Info panel',
      'instance_settings' => array(
        'classes' => 'info-panel--expandable',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_audio_full_group_info_panel',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_info_panel|node|audio|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mediaplayer|node|audio|default';
  $field_group->group_name = 'group_mediaplayer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mediaplayer',
    'weight' => '0',
    'children' => array(
      0 => 'field_audio_file',
      1 => 'sound_mediaplayer_metadata',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Mediaplayer',
      'instance_settings' => array(
        'classes' => 'mediaplayer',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_audio_full_group_mediaplayer',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_mediaplayer|node|audio|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_container|node|audio|default';
  $field_group->group_name = 'group_video_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audio';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video container',
    'weight' => '3',
    'children' => array(
      0 => 'field_video',
      1 => 'video_headline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Video container',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'foldout videos',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_video_container|node|audio|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Headline');
  t('Info panel');
  t('Mediaplayer');
  t('Video container');

  return $field_groups;
}

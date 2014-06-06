<?php
/**
 * @file
 * smk_route.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function smk_route_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|route|teaser';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'route';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'amount_of_sounds',
      1 => 'sounds_duration',
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
        'id' => 'node_route_teaser_group_content',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content|node|route|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_panel|node|route|default';
  $field_group->group_name = 'group_info_panel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'route';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info panel',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title_field',
      2 => 'body_clone',
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
        'id' => 'node_route_full_group_info_panel',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_info_panel|node|route|default'] = $field_group;

  return $export;
}

<?php
/**
 * @file
 * smk_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function smk_base_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_panel|node|generic_page|full';
  $field_group->group_name = 'group_info_panel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info panel',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Info panel',
      'instance_settings' => array(
        'classes' => 'info-panel',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_generic_page_full_group_info_panel',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_info_panel|node|generic_page|full'] = $field_group;

  return $export;
}

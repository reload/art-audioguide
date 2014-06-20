<?php
/**
 * @file
 * smk_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function smk_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'number_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Number Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_piece_ref_target_id']['id'] = 'field_piece_ref_target_id';
  $handler->display->display_options['relationships']['field_piece_ref_target_id']['table'] = 'field_data_field_piece_ref';
  $handler->display->display_options['relationships']['field_piece_ref_target_id']['field'] = 'field_piece_ref_target_id';
  $handler->display->display_options['relationships']['field_piece_ref_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Number search */
  $handler->display->display_options['filters']['field_piece_id_value']['id'] = 'field_piece_id_value';
  $handler->display->display_options['filters']['field_piece_id_value']['table'] = 'field_data_field_piece_id';
  $handler->display->display_options['filters']['field_piece_id_value']['field'] = 'field_piece_id_value';
  $handler->display->display_options['filters']['field_piece_id_value']['ui_name'] = 'Number search';
  $handler->display->display_options['filters']['field_piece_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['operator_id'] = 'field_piece_id_value_op';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['label'] = 'Inventory ID (field_piece_id)';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['operator'] = 'field_piece_id_value_op';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['identifier'] = 'field_piece_id_value';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Number-search */
  $handler = $view->new_display('page', 'Number-search', 'number_search');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'audio' => 'audio',
  );
  /* Filter criterion: Content: Inventory ID (field_piece_id) */
  $handler->display->display_options['filters']['field_piece_id_value']['id'] = 'field_piece_id_value';
  $handler->display->display_options['filters']['field_piece_id_value']['table'] = 'field_data_field_piece_id';
  $handler->display->display_options['filters']['field_piece_id_value']['field'] = 'field_piece_id_value';
  $handler->display->display_options['filters']['field_piece_id_value']['relationship'] = 'field_piece_ref_target_id';
  $handler->display->display_options['filters']['field_piece_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['operator_id'] = 'field_piece_id_value_op';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['operator'] = 'field_piece_id_value_op';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_piece_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'number-search';
  $translatables['number_search'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Content entity referenced from field_piece_ref'),
    t('Published'),
    t('Inventory ID (field_piece_id)'),
    t('Number-search'),
  );
  $export['number_search'] = $view;

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Title';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_artist_target_id']['id'] = 'field_artist_target_id';
  $handler->display->display_options['relationships']['field_artist_target_id']['table'] = 'field_data_field_artist';
  $handler->display->display_options['relationships']['field_artist_target_id']['field'] = 'field_artist_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Contextual filter: Content: Title (title_field) */
  $handler->display->display_options['arguments']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['arguments']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['arguments']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['arguments']['title_field_value']['relationship'] = 'field_artist_target_id';
  $handler->display->display_options['arguments']['title_field_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title_field_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['title_field_value']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['title_field_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title_field_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title_field_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title_field_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'piece' => 'piece',
  );

  /* Display: Title */
  $handler = $view->new_display('block', 'Title', 'title');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title (title_field) */
  $handler->display->display_options['arguments']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['arguments']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['arguments']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['arguments']['title_field_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title_field_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['title_field_value']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['title_field_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title_field_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title_field_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title_field_value']['limit'] = '0';

  /* Display: Artist */
  $handler = $view->new_display('block', 'Artist', 'artist');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Artist';
  $translatables['search'] = array(
    t('Master'),
    t('Title'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_artist'),
    t('All'),
    t('Artist'),
  );
  $export['search'] = $view;

  return $export;
}

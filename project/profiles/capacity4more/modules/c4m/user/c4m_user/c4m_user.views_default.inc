<?php
/**
 * @file
 * c4m_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_content';
  $view->description = 'Overview of user content.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_c4m_search_nodes';
  $view->human_name = 'My Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'views_access_callback';
  $handler->display->display_options['access']['views_access_callback'] = 'c4m_user_my_content_access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['query']['options']['contextual_filters_or'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* Header: Sorts */
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['id'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['table'] = 'views';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['field'] = 'c4m_views_search_api_sorts';
  $handler->display->display_options['header']['c4m_views_search_api_sorts']['ui_name'] = 'Sorts';
  /* Header: Number of items */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['ui_name'] = 'Number of items';
  $handler->display->display_options['header']['result']['content'] = '@total in total, @start - @end shown';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Indexed Node: Author */
  $handler->display->display_options['arguments']['author']['id'] = 'author';
  $handler->display->display_options['arguments']['author']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['arguments']['author']['field'] = 'author';
  $handler->display->display_options['arguments']['author']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['author']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['author']['title'] = '%1\'s content';
  $handler->display->display_options['arguments']['author']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['author']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['author']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['author']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['author']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['author']['not'] = 0;
  /* Contextual filter: Indexed Node: Contributors */
  $handler->display->display_options['arguments']['c4m_related_user']['id'] = 'c4m_related_user';
  $handler->display->display_options['arguments']['c4m_related_user']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['arguments']['c4m_related_user']['field'] = 'c4m_related_user';
  $handler->display->display_options['arguments']['c4m_related_user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['c4m_related_user']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['c4m_related_user']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['c4m_related_user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['c4m_related_user']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['c4m_related_user']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['c4m_related_user']['not'] = 0;
  /* Filter criterion: Only Event nodes */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Only Event nodes';
  $handler->display->display_options['filters']['type']['operator'] = '<>';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
    'project' => 'project',
  );
  /* Filter criterion: Search form */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_c4m_search_nodes';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['ui_name'] = 'Search form';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'user/%/content';
  $handler->display->display_options['menu']['title'] = 'My content';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['my_content'] = $view;

  return $export;
}
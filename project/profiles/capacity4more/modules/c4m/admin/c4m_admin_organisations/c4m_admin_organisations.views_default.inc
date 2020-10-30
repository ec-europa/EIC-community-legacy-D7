<?php

/**
 * @file
 * c4m_admin_organisations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4m_admin_organisations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'c4m_admin_organisations_export';
  $view->description = '';
  $view->tag = 'C4M Admin';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Organisations - Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Flags: subscribe_c4m_follow_group counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['label'] = 'flag_promote_counter';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'subscribe_c4m_follow_group';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Organisation Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: PURL path */
  $handler->display->display_options['fields']['group_purl']['id'] = 'group_purl';
  $handler->display->display_options['fields']['group_purl']['table'] = 'node';
  $handler->display->display_options['fields']['group_purl']['field'] = 'group_purl';
  $handler->display->display_options['fields']['group_purl']['label'] = 'URL';
  $handler->display->display_options['fields']['group_purl']['element_label_colon'] = FALSE;
  /* Field: : c4m_organisation_type */
  $handler->display->display_options['fields']['c4m_organisation_type']['id'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['table'] = 'field_data_c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['field'] = 'c4m_organisation_type';
  $handler->display->display_options['fields']['c4m_organisation_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['c4m_organisation_type']['alter']['text'] = '[c4m_organisation_type-value]';
  $handler->display->display_options['fields']['c4m_organisation_type']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Creation date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['c4m_og_status']['id'] = 'c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['field'] = 'c4m_og_status';
  $handler->display->display_options['fields']['c4m_og_status']['label'] = 'Organisation Status';
  $handler->display->display_options['fields']['c4m_og_status']['element_label_colon'] = FALSE;
  /* Field: Content: Group admin */
  $handler->display->display_options['fields']['group_admin']['id'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['table'] = 'node';
  $handler->display->display_options['fields']['group_admin']['field'] = 'group_admin';
  $handler->display->display_options['fields']['group_admin']['label'] = 'Organisation owner';
  $handler->display->display_options['fields']['group_admin']['element_label_colon'] = FALSE;
  /* Field: Content: Group moderators */
  $handler->display->display_options['fields']['group_moderators']['id'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['table'] = 'node';
  $handler->display->display_options['fields']['group_moderators']['field'] = 'group_moderators';
  $handler->display->display_options['fields']['group_moderators']['label'] = 'Organisation Administrator(s)';
  $handler->display->display_options['fields']['group_moderators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_moderators']['c4m_admin_groups_group_type'] = 'organisation';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics']['id'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics']['label'] = 'Date of latest activity';
  $handler->display->display_options['fields']['group_metrics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics']['c4m_admin_groups_group_metric'] = 'group::latest_activity';
  /* Field: Field: Topics */
  $handler->display->display_options['fields']['c4m_vocab_topic']['id'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['table'] = 'field_data_c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['field'] = 'c4m_vocab_topic';
  $handler->display->display_options['fields']['c4m_vocab_topic']['label'] = 'Related Topics';
  $handler->display->display_options['fields']['c4m_vocab_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_topic']['type'] = 'term_reference_checked_inline_tree_for_views';
  $handler->display->display_options['fields']['c4m_vocab_topic']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ' - ',
  );
  $handler->display->display_options['fields']['c4m_vocab_topic']['delta_offset'] = '0';
  /* Field: Field: Regions & Countries */
  $handler->display->display_options['fields']['c4m_vocab_geo']['id'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['table'] = 'field_data_c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['field'] = 'c4m_vocab_geo';
  $handler->display->display_options['fields']['c4m_vocab_geo']['label'] = 'Related Regions / Countries';
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['c4m_vocab_geo']['type'] = 'term_reference_checked_inline_tree_for_views';
  $handler->display->display_options['fields']['c4m_vocab_geo']['settings'] = array(
    'link' => 0,
    'separator' => ' > ',
    'glue' => ' - ',
  );
  $handler->display->display_options['fields']['c4m_vocab_geo']['delta_offset'] = '0';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_2']['id'] = 'group_metrics_2';
  $handler->display->display_options['fields']['group_metrics_2']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_2']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_2']['label'] = 'Pages';
  $handler->display->display_options['fields']['group_metrics_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_2']['c4m_admin_groups_group_metric'] = 'group::wiki_page';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_9']['id'] = 'group_metrics_9';
  $handler->display->display_options['fields']['group_metrics_9']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_9']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_9']['label'] = 'News';
  $handler->display->display_options['fields']['group_metrics_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_9']['c4m_admin_groups_group_metric'] = 'group::news';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_3']['id'] = 'group_metrics_3';
  $handler->display->display_options['fields']['group_metrics_3']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_3']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_3']['label'] = 'Documents';
  $handler->display->display_options['fields']['group_metrics_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_3']['c4m_admin_groups_group_metric'] = 'group::document';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_4']['id'] = 'group_metrics_4';
  $handler->display->display_options['fields']['group_metrics_4']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_4']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_4']['label'] = 'Photo albums';
  $handler->display->display_options['fields']['group_metrics_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_4']['c4m_admin_groups_group_metric'] = 'group::photoalbum';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_5']['id'] = 'group_metrics_5';
  $handler->display->display_options['fields']['group_metrics_5']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_5']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_5']['label'] = 'Photos';
  $handler->display->display_options['fields']['group_metrics_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_5']['c4m_admin_groups_group_metric'] = 'group::photo';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_6']['id'] = 'group_metrics_6';
  $handler->display->display_options['fields']['group_metrics_6']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_6']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_6']['label'] = 'Events';
  $handler->display->display_options['fields']['group_metrics_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_6']['c4m_admin_groups_group_metric'] = 'group::event';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_7']['id'] = 'group_metrics_7';
  $handler->display->display_options['fields']['group_metrics_7']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_7']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_7']['label'] = 'Comments';
  $handler->display->display_options['fields']['group_metrics_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_7']['c4m_admin_groups_group_metric'] = 'group::comment';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_1']['id'] = 'group_metrics_1';
  $handler->display->display_options['fields']['group_metrics_1']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_1']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_1']['label'] = 'Content Recommendations';
  $handler->display->display_options['fields']['group_metrics_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_1']['c4m_admin_groups_group_metric'] = 'group::content_recommendations';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = 'Organisation Followers';
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['separator'] = '';
  /* Field: Content: Group metrics */
  $handler->display->display_options['fields']['group_metrics_8']['id'] = 'group_metrics_8';
  $handler->display->display_options['fields']['group_metrics_8']['table'] = 'node';
  $handler->display->display_options['fields']['group_metrics_8']['field'] = 'group_metrics';
  $handler->display->display_options['fields']['group_metrics_8']['label'] = 'Organisations';
  $handler->display->display_options['fields']['group_metrics_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_metrics_8']['c4m_admin_groups_group_metric'] = 'group::organisation';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'organisations_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['permanent_file'] = 1;
  $handler->display->display_options['style_options']['file_path'] = 'private://export/organisations.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = '|';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/c4m/organisations/export/file';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/c4m/organisations/export';
  $handler->display->display_options['segment_size'] = '100';
  $export['c4m_admin_organisations_export'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_organisations_pending';
  $view->description = '';
  $view->tag = 'C4M Admin';
  $view->base_table = 'node';
  $view->human_name = 'Admin : Organisations - Pending';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pending';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pending organisations';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no organisations pending for approval.';
  $handler->display->display_options['empty']['area']['format'] = 'mail';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['created']['reldate'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Group approve link */
  $handler->display->display_options['fields']['group_approve']['id'] = 'group_approve';
  $handler->display->display_options['fields']['group_approve']['table'] = 'node';
  $handler->display->display_options['fields']['group_approve']['field'] = 'group_approve';
  $handler->display->display_options['fields']['group_approve']['label'] = '';
  $handler->display->display_options['fields']['group_approve']['exclude'] = TRUE;
  $handler->display->display_options['fields']['group_approve']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[group_approve] or [edit_node]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (c4m_og_status) */
  $handler->display->display_options['filters']['c4m_og_status_value']['id'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['table'] = 'field_data_c4m_og_status';
  $handler->display->display_options['filters']['c4m_og_status_value']['field'] = 'c4m_og_status_value';
  $handler->display->display_options['filters']['c4m_og_status_value']['value'] = array(
    'pending' => 'pending',
  );
  $handler->display->display_options['filters']['c4m_og_status_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/c4m/organisations/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending';
  $handler->display->display_options['menu']['description'] = 'Administration interface to manage pending organisations.';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['c4m_admin_organisations_pending'] = $view;

  $view = new view();
  $view->name = 'c4m_admin_users_status';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Admin: Users\' status';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'c4m_user_dashboard_id' => 'c4m_user_dashboard_id',
    'c4m_first_name' => 'c4m_first_name',
    'c4m_last_name' => 'c4m_last_name',
    'status' => 'status',
    'c4m_message_from_service' => 'c4m_message_from_service',
    'access' => 'access',
    'login' => 'access',
    'c4m_updated_profile_by_service' => 'c4m_updated_profile_by_service',
    'c4m_updated_profile_by_user' => 'c4m_updated_profile_by_service',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_user_dashboard_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_message_from_service' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'c4m_updated_profile_by_service' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'c4m_updated_profile_by_user' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: User: User Dashboard ID */
  $handler->display->display_options['fields']['c4m_user_dashboard_id']['id'] = 'c4m_user_dashboard_id';
  $handler->display->display_options['fields']['c4m_user_dashboard_id']['table'] = 'field_data_c4m_user_dashboard_id';
  $handler->display->display_options['fields']['c4m_user_dashboard_id']['field'] = 'c4m_user_dashboard_id';
  $handler->display->display_options['fields']['c4m_user_dashboard_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: User: First Name */
  $handler->display->display_options['fields']['c4m_first_name']['id'] = 'c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['fields']['c4m_first_name']['field'] = 'c4m_first_name';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['c4m_last_name']['id'] = 'c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['fields']['c4m_last_name']['field'] = 'c4m_last_name';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Message from service */
  $handler->display->display_options['fields']['c4m_message_from_service']['id'] = 'c4m_message_from_service';
  $handler->display->display_options['fields']['c4m_message_from_service']['table'] = 'field_data_c4m_message_from_service';
  $handler->display->display_options['fields']['c4m_message_from_service']['field'] = 'c4m_message_from_service';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = 'Last access / login';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['access']['reldate'] = '0';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['date_format'] = 'short';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'c4m_long_without_time';
  $handler->display->display_options['fields']['login']['reldate'] = '0';
  /* Field: User: Updated profile by service */
  $handler->display->display_options['fields']['c4m_updated_profile_by_service']['id'] = 'c4m_updated_profile_by_service';
  $handler->display->display_options['fields']['c4m_updated_profile_by_service']['table'] = 'field_data_c4m_updated_profile_by_service';
  $handler->display->display_options['fields']['c4m_updated_profile_by_service']['field'] = 'c4m_updated_profile_by_service';
  $handler->display->display_options['fields']['c4m_updated_profile_by_service']['label'] = 'Updated profile by service / user';
  $handler->display->display_options['fields']['c4m_updated_profile_by_service']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: User: Updated profile by user */
  $handler->display->display_options['fields']['c4m_updated_profile_by_user']['id'] = 'c4m_updated_profile_by_user';
  $handler->display->display_options['fields']['c4m_updated_profile_by_user']['table'] = 'field_data_c4m_updated_profile_by_user';
  $handler->display->display_options['fields']['c4m_updated_profile_by_user']['field'] = 'c4m_updated_profile_by_user';
  $handler->display->display_options['fields']['c4m_updated_profile_by_user']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Filter criterion: User: First Name (c4m_first_name) */
  $handler->display->display_options['filters']['c4m_first_name_value']['id'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['table'] = 'field_data_c4m_first_name';
  $handler->display->display_options['filters']['c4m_first_name_value']['field'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['c4m_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator_id'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['operator'] = 'c4m_first_name_value_op';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['identifier'] = 'c4m_first_name_value';
  $handler->display->display_options['filters']['c4m_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last Name (c4m_last_name) */
  $handler->display->display_options['filters']['c4m_last_name_value']['id'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['table'] = 'field_data_c4m_last_name';
  $handler->display->display_options['filters']['c4m_last_name_value']['field'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['c4m_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['c4m_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator_id'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['operator'] = 'c4m_last_name_value_op';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['identifier'] = 'c4m_last_name_value';
  $handler->display->display_options['filters']['c4m_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Authentication name */
  $handler->display->display_options['filters']['authname']['id'] = 'authname';
  $handler->display->display_options['filters']['authname']['table'] = 'authmap';
  $handler->display->display_options['filters']['authname']['field'] = 'authname';
  $handler->display->display_options['filters']['authname']['operator'] = 'contains';
  $handler->display->display_options['filters']['authname']['group'] = 1;
  $handler->display->display_options['filters']['authname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['authname']['expose']['operator_id'] = 'authname_op';
  $handler->display->display_options['filters']['authname']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['authname']['expose']['operator'] = 'authname_op';
  $handler->display->display_options['filters']['authname']['expose']['identifier'] = 'authname';
  $handler->display->display_options['filters']['authname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  $export['c4m_admin_users_status'] = $view;

  return $export;
}

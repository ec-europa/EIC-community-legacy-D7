<?php

/**
 * @file
 * c4m_features_og_discussions.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_og_discussions_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'og_discussion';
  $path_breadcrumb->name = 'OG - Discussion';
  $path_breadcrumb->path = 'node/%nodeidnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '@C4M_Group_type',
      1 => '%nodeidnumber:og-group-ref:title',
      2 => 'Discussions',
      3 => '%nodeidnumber:title',
    ),
    'paths' => array(
      0 => '@C4M_Group_overview_path',
      1 => 'node/%nodeidnumber:og-group-ref:nid',
      2 => 'discussions',
      3 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'nodeidnumber' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'discussion' => 'discussion',
            ),
          ),
          'context' => 'nodeidnumber',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_is_node_group_content',
          'settings' => NULL,
          'context' => 'nodeidnumber',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -89;
  $export['og_discussion'] = $path_breadcrumb;

  return $export;
}

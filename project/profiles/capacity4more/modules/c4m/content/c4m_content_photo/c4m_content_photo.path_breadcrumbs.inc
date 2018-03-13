<?php

/**
 * @file
 * c4m_content_photo.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_content_photo_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'og_photo';
  $path_breadcrumb->name = 'OG - Photo';
  $path_breadcrumb->path = 'node/%nodeidnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '@C4M_Group_type',
      1 => '%nodeidnumber:og-group-ref:title',
      2 => 'Media',
      3 => '%nodeidnumber:title',
    ),
    'paths' => array(
      0 => '@C4M_Group_overview_path',
      1 => 'node/%nodeidnumber:og-group-ref:nid',
      2 => 'media',
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
              'photo' => 'photo',
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
        2 => array(
          'name' => 'entity_field_value:node:photo:node_gallery_ref_1',
          'settings' => array(
            'node_gallery_ref_1' => array(
              'und' => array(),
            ),
            'node_gallery_ref_1_target_id' => array(),
          ),
          'context' => 'nodeidnumber',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -87;
  $export['og_photo'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'og_photo_in_album';
  $path_breadcrumb->name = 'OG - Photo in album';
  $path_breadcrumb->path = 'node/%nodeidnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '@C4M_Group_type',
      1 => '%nodeidnumber:og-group-ref:title',
      2 => 'Media',
      3 => '%nodeidnumber:node-gallery-ref-1:title',
      4 => '%nodeidnumber:title',
    ),
    'paths' => array(
      0 => '@C4M_Group_overview_path',
      1 => 'node/%nodeidnumber:og-group-ref:nid',
      2 => 'media',
      3 => 'node/%nodeidnumber:node-gallery-ref-1:nid',
      4 => '<none>',
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
              'photo' => 'photo',
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
        2 => array(
          'name' => 'entity_field_value:node:photo:node_gallery_ref_1',
          'settings' => array(
            'node_gallery_ref_1' => array(
              'und' => array(),
            ),
            'node_gallery_ref_1_target_id' => array(),
          ),
          'context' => 'nodeidnumber',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -87;
  $export['og_photo_in_album'] = $path_breadcrumb;

  return $export;
}

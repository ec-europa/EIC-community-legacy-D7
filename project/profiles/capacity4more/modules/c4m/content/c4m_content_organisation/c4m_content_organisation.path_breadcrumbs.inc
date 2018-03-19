<?php

/**
 * @file
 * c4m_content_organisation.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_content_organisation_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations';
  $path_breadcrumb->name = 'Organisations';
  $path_breadcrumb->path = 'organisations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisations',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['organisations'] = $path_breadcrumb;

  return $export;
}

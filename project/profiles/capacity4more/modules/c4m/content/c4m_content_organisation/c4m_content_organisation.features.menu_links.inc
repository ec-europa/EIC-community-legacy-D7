<?php

/**
 * @file
 * c4m_content_organisation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function c4m_content_organisation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_organisations:admin/c4m/organisations.
  $menu_links['management_organisations:admin/c4m/organisations'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/c4m/organisations',
    'router_path' => 'admin/c4m/organisations',
    'link_title' => 'Organisations',
    'options' => array(
      'attributes' => array(
        'title' => 'Administration interface to manage organisations & their status.',
      ),
      'identifier' => 'management_organisations:admin/c4m/organisations',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Organisations');

  return $menu_links;
}

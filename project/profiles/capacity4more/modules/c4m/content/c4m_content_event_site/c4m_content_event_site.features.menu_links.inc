<?php

/**
 * @file
 * c4m_content_event_site.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function c4m_content_event_site_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_event-sites:admin/c4m/event_sites.
  $menu_links['management_event-sites:admin/c4m/event_sites'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/c4m/event_sites',
    'router_path' => 'admin/c4m/event_sites',
    'link_title' => 'Event sites',
    'options' => array(
      'attributes' => array(
        'title' => 'Administration interface to manage event sites & their status.',
      ),
      'identifier' => 'management_event-sites:admin/c4m/event_sites',
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
  t('Event sites');

  return $menu_links;
}

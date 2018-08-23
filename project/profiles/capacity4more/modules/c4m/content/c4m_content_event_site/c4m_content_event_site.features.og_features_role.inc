<?php

/**
 * @file
 * c4m_content_event_site.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function c4m_content_event_site_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:event_site:attendee'.
  $roles['node:event_site:attendee'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'event_site',
    'name' => 'attendee',
  );

  return $roles;
}

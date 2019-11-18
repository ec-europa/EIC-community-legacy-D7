<?php

/**
 * @file
 * c4m_web_services_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_web_services_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer webservice event sites'.
  $permissions['administer webservice event sites'] = array(
    'name' => 'administer webservice event sites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_web_services_events',
  );

  return $permissions;
}

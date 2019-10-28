<?php

/**
 * @file
 * c4m_web_services_user.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_web_services_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer webservice user sites'.
  $permissions['administer webservice user management settings'] = array(
    'name' => 'administer webservice user management settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_web_services_user',
  );

  return $permissions;
}

<?php

/**
 * @file
 * c4m_public_access.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_public_access_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view own project content'.
  $permissions['access authenticated content'] = array(
    'name' => 'access authenticated content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'c4m_public_access',
  );

  return $permissions;
}

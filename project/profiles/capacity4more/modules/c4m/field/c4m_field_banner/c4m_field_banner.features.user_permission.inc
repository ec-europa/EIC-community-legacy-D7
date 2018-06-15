<?php

/**
 * @file
 * c4m_field_banner.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_field_banner_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer manualcrop settings'.
  $permissions['administer manualcrop settings'] = array(
    'name' => 'administer manualcrop settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'manualcrop',
  );

  // Exported permission: 'use manualcrop'.
  $permissions['use manualcrop'] = array(
    'name' => 'use manualcrop',
    'roles' => array(
      'PIWIK administrator' => 'PIWIK administrator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'service-authentication' => 'service-authentication',
    ),
    'module' => 'manualcrop',
  );

  return $permissions;
}

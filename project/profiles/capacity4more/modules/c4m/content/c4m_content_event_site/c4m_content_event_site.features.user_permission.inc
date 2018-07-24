<?php

/**
 * @file
 * c4m_content_event_site.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_content_event_site_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'administrator' => 'administrator',
      'content administrator' => 'content administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'content administrator' => 'content administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'create event_site content'.
  $permissions['create event_site content'] = array(
    'name' => 'create event_site content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event_site content'.
  $permissions['delete any event_site content'] = array(
    'name' => 'delete any event_site content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event_site content'.
  $permissions['delete own event_site content'] = array(
    'name' => 'delete own event_site content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event_site content'.
  $permissions['edit any event_site content'] = array(
    'name' => 'edit any event_site content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event_site content'.
  $permissions['edit own event_site content'] = array(
    'name' => 'edit own event_site content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}

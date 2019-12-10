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

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any article content'.
  $permissions['view any article content'] = array(
    'name' => 'view any article content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any banner content'.
  $permissions['view any banner content'] = array(
    'name' => 'view any banner content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any book content'.
  $permissions['view any book content'] = array(
    'name' => 'view any book content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any discussion content'.
  $permissions['view any discussion content'] = array(
    'name' => 'view any discussion content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any document content'.
  $permissions['view any document content'] = array(
    'name' => 'view any document content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any event content'.
  $permissions['view any event content'] = array(
    'name' => 'view any event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any event_site content'.
  $permissions['view any event_site content'] = array(
    'name' => 'view any event_site content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any featured content'.
  $permissions['view any featured content'] = array(
    'name' => 'view any featured content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any feed content'.
  $permissions['view any feed content'] = array(
    'name' => 'view any feed content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any group content'.
  $permissions['view any group content'] = array(
    'name' => 'view any group content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any inthe_picture content'.
  $permissions['view any inthe_picture content'] = array(
    'name' => 'view any inthe_picture content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any news content'.
  $permissions['view any news content'] = array(
    'name' => 'view any news content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any organisation content'.
  $permissions['view any organisation content'] = array(
    'name' => 'view any organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any page_element content'.
  $permissions['view any page_element content'] = array(
    'name' => 'view any page_element content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any photo content'.
  $permissions['view any photo content'] = array(
    'name' => 'view any photo content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any photoalbum content'.
  $permissions['view any photoalbum content'] = array(
    'name' => 'view any photoalbum content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any project content'.
  $permissions['view any project content'] = array(
    'name' => 'view any project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any share content'.
  $permissions['view any share content'] = array(
    'name' => 'view any share content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any topic content'.
  $permissions['view any topic content'] = array(
    'name' => 'view any topic content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view any wiki_page content'.
  $permissions['view any wiki_page content'] = array(
    'name' => 'view any wiki_page content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own article content'.
  $permissions['view own article content'] = array(
    'name' => 'view own article content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own banner content'.
  $permissions['view own banner content'] = array(
    'name' => 'view own banner content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own book content'.
  $permissions['view own book content'] = array(
    'name' => 'view own book content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own discussion content'.
  $permissions['view own discussion content'] = array(
    'name' => 'view own discussion content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own document content'.
  $permissions['view own document content'] = array(
    'name' => 'view own document content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own event content'.
  $permissions['view own event content'] = array(
    'name' => 'view own event content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own event_site content'.
  $permissions['view own event_site content'] = array(
    'name' => 'view own event_site content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own featured content'.
  $permissions['view own featured content'] = array(
    'name' => 'view own featured content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own feed content'.
  $permissions['view own feed content'] = array(
    'name' => 'view own feed content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own group content'.
  $permissions['view own group content'] = array(
    'name' => 'view own group content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own inthe_picture content'.
  $permissions['view own inthe_picture content'] = array(
    'name' => 'view own inthe_picture content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own news content'.
  $permissions['view own news content'] = array(
    'name' => 'view own news content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own organisation content'.
  $permissions['view own organisation content'] = array(
    'name' => 'view own organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own page_element content'.
  $permissions['view own page_element content'] = array(
    'name' => 'view own page_element content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own photo content'.
  $permissions['view own photo content'] = array(
    'name' => 'view own photo content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own photoalbum content'.
  $permissions['view own photoalbum content'] = array(
    'name' => 'view own photoalbum content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own project content'.
  $permissions['view own project content'] = array(
    'name' => 'view own project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own share content'.
  $permissions['view own share content'] = array(
    'name' => 'view own share content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own topic content'.
  $permissions['view own topic content'] = array(
    'name' => 'view own topic content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  // Exported permission: 'view own wiki_page content'.
  $permissions['view own wiki_page content'] = array(
    'name' => 'view own wiki_page content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_view_permissions',
  );

  return $permissions;
}

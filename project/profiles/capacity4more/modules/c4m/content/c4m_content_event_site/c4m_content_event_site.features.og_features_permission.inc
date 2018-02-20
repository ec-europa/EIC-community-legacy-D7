<?php

/**
 * @file
 * c4m_content_event_site.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_content_event_site_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:event_site:add user'
  $permissions['node:event_site:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:administer group'
  $permissions['node:event_site:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:administer og menu'
  $permissions['node:event_site:administer og menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:administer taxonomy'
  $permissions['node:event_site:administer taxonomy'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:approve and deny subscription'
  $permissions['node:event_site:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:c4m_og_content_depromote'
  $permissions['node:event_site:c4m_og_content_depromote'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:c4m_og_content_promote'
  $permissions['node:event_site:c4m_og_content_promote'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:c4m_og_content_recommend'
  $permissions['node:event_site:c4m_og_content_recommend'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:c4m_og_content_unrecommend'
  $permissions['node:event_site:c4m_og_content_unrecommend'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create discussion content'
  $permissions['node:event_site:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:create document content'
  $permissions['node:event_site:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create event content'
  $permissions['node:event_site:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create news content'
  $permissions['node:event_site:create news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create photo content'
  $permissions['node:event_site:create photo content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create photoalbum content'
  $permissions['node:event_site:create photoalbum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create share content'
  $permissions['node:event_site:create share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:create wiki_page content'
  $permissions['node:event_site:create wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any discussion content'
  $permissions['node:event_site:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any document content'
  $permissions['node:event_site:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any event content'
  $permissions['node:event_site:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any news content'
  $permissions['node:event_site:delete any news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any photo content'
  $permissions['node:event_site:delete any photo content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any photoalbum content'
  $permissions['node:event_site:delete any photoalbum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any share content'
  $permissions['node:event_site:delete any share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete any wiki_page content'
  $permissions['node:event_site:delete any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own discussion content'
  $permissions['node:event_site:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own document content'
  $permissions['node:event_site:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own event content'
  $permissions['node:event_site:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own news content'
  $permissions['node:event_site:delete own news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own photo content'
  $permissions['node:event_site:delete own photo content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own photoalbum content'
  $permissions['node:event_site:delete own photoalbum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own share content'
  $permissions['node:event_site:delete own share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete own wiki_page content'
  $permissions['node:event_site:delete own wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:delete terms'
  $permissions['node:event_site:delete terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:edit terms'
  $permissions['node:event_site:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:invite any user'
  $permissions['node:event_site:invite any user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:invite visitors'
  $permissions['node:event_site:invite visitors'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:manage members'
  $permissions['node:event_site:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:manage permissions'
  $permissions['node:event_site:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:manage roles'
  $permissions['node:event_site:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:manage variables'
  $permissions['node:event_site:manage variables'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:subscribe'
  $permissions['node:event_site:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event_site:subscribe without approval'
  $permissions['node:event_site:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:event_site:unsubscribe'
  $permissions['node:event_site:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update any discussion content'
  $permissions['node:event_site:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any document content'
  $permissions['node:event_site:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any event content'
  $permissions['node:event_site:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any news content'
  $permissions['node:event_site:update any news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any photo content'
  $permissions['node:event_site:update any photo content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any photoalbum content'
  $permissions['node:event_site:update any photoalbum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any share content'
  $permissions['node:event_site:update any share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update any wiki_page content'
  $permissions['node:event_site:update any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update group'
  $permissions['node:event_site:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own discussion content'
  $permissions['node:event_site:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:event_site:update own document content'
  $permissions['node:event_site:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own event content'
  $permissions['node:event_site:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own news content'
  $permissions['node:event_site:update own news content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own photo content'
  $permissions['node:event_site:update own photo content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own photoalbum content'
  $permissions['node:event_site:update own photoalbum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own share content'
  $permissions['node:event_site:update own share content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:update own wiki_page content'
  $permissions['node:event_site:update own wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:event_site:view unpublished group content'
  $permissions['node:event_site:view unpublished group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}

<?php

/**
 * @file
 * Cron related code.
 */

/**
 * Callback for the c4m_content_event_ite cron job.
 */
function _c4m_content_event_site_cron() {
  // Get all the nodes that have the draft c4m_og_state.
  // If they have a Published date that is less that current time, change status to published and save node.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event_site')
    ->fieldCondition('c4m_og_status', 'value', 'draft', '=')
    ->fieldCondition('c4m_publish_date', 'value', date('Y-m-d H:i:s',time()), '<=')
    ->addMetaData('account', user_load(1));

  $result = $query->execute();
  if (!isset($result['node'])) {
    return;
  }
  $event_sites_nids = array_keys($result['node']);
  $event_sites = entity_load('node', $event_sites_nids);

  foreach ($event_sites as $event_site) {
    $event_site->c4m_og_status[LANGUAGE_NONE][0]['value'] = 'published';
    node_save($event_site);
  }
}

<?php

/**
 * @file
 * Cron related code.
 */

/**
 * Callback for the c4m_content_event_ite cron job.
 */
function _c4m_content_event_site_cron() {
  // Run script as Administrator.
  global $user;
  $original_user = $user;
  $old_state = drupal_save_session(FALSE);
  $user = user_load(1);

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

  // Get back to original user state.
  $user = $original_user;
  drupal_save_session($old_state);
}

/**
 * Callback for c4m_event_site_email_subscribers Drupal Queue.
 *
 * @param array $item
 *   Contains one item from the queue.
 */
function _c4m_content_event_site_queue_process_email_subscribers($item) {
  // Get emails from users that are subscribed to a related topic.
  if (!empty($item['tids'])) {
    $query = db_select('field_data_c4m_vocab_topic_expertise', 'vt');
    $query->join('users', 'u', 'u.uid = vt.entity_id');
    $query->fields('u', ['mail'])
      ->condition('vt.c4m_vocab_topic_expertise_tid', $item['tids'], 'IN')
      ->condition('vt.bundle', 'user')
      ->condition('u.status', 1)
      ->distinct();
    $results = $query->execute()->fetchCol();
    if (!empty($results)) {
      // Prepare batch function for sending emails.
    }
  }
}

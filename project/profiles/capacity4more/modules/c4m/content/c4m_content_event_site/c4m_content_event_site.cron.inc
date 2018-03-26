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
  if (empty($item['nid']) || empty($item['tids'])) {
    return;
  }
  // Get emails from users that are subscribed to a related topic.
  $query = db_select('field_data_c4m_vocab_topic_expertise', 'vt');
  $query->join('users', 'u', 'u.uid = vt.entity_id');
  $query->fields('u', ['mail'])
    ->fields('vt', ['c4m_vocab_topic_expertise_tid'])
    ->condition('vt.c4m_vocab_topic_expertise_tid', $item['tids'], 'IN')
    ->condition('vt.bundle', 'user')
    ->condition('u.status', 1)
    ->distinct();
  $results = $query->execute();

  // Make Array as mail=>['tid1', 'tid2'].
  while ($record = $results->fetchAssoc()) {
    $users[$record['mail']][] = $record['c4m_vocab_topic_expertise_tid'];
  }
  if (!empty($users)) {
    // Prepare batch function for sending emails.
    $batch = [
      'operations' => [],
        'finished' => '_c4m_content_event_site_queue_process_email_subscribers_batch_finished', // runs after batch is finished
      'title' => t('Send emails'),
      'init_message' => t('Sending emails started.'),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Sending emails for new Event Site encountered an error.'),
    ];
    $event_site_link = url(drupal_get_path_alias('node/' . $item['nid']), ['absolute'=>TRUE]);
    foreach ($users as $to_email => $tids) {
      $batch['operations'][] = array('_c4m_content_event_site_queue_process_email_subscribers_batch_send_mail', array($to_email, $tids));
    }
    batch_set($batch);
  }
}

function _c4m_content_event_site_queue_process_email_subscribers_batch_send_mail($to_email, $tids, &$context) {
  if (empty($email) || empty($tids)) {
    return;
  }

  $user = user_load($to_email);

  if (empty($user)) {
    return;
  }

  $terms = taxonomy_term_load_multiple($tids);

  if (empty($terms)) {
    return;
  }

  $term_names = '';
  foreach ($terms as $term) {
    $term_names .= $term->name;
  }

  $language = user_preferred_language($user);

  $from = variable_get('site_mail', 'EASME-SME-HELPDESK@ec.europa.eu');

  $params['subject'] = t('See our new Event Site');
  $params['body'] = t('Dear %name, a new Event Site was published related to the topic(s) @topics. Visit now: *event_site.', array(
    '%name' => c4m_user_name($user),
    '@topics' => $term_names,
    '*event_site' => '',
  ));

  $message = drupal_mail('c4m_content_event_site', 'event_site_notification', $to_email, $language, $params = array(), $from, TRUE);
  if ($message['result']) {
    watchdog('c4m_content_event_site', 'Successfully sent email to %recipient', array('%recipient' => $to_email));
  }
}

function _c4m_content_event_site_queue_process_email_subscribers_batch_finished($success, $results, $operations) {
  if ($success) {
    watchdog('c4m_content_event_site', 'Emails were sent with success to all the users that follow topics from the newly published Event Site.');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    watchdog('c4m_content_event_site', $message);
  }
}
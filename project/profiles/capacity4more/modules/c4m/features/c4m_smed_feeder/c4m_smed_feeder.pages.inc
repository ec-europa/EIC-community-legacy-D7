<?php

/**
 * @file
 * c4m_smed_feeder.pages.inc
 */

/**
 * Page callback to synchronise a user to the SMED.
 *
 * @param object $account
 *   The user account to synchronise.
 */
function c4m_smed_feeder_action_sync_user($account) {
  $result = c4m_smed_feeder_request_sync_user($account);
  dpm($result);
  $destination = drupal_get_destination();

  if ($destination['destination'] != current_path()) {
    drupal_goto($destination['destination']);
  }
  return 'Hello';
}

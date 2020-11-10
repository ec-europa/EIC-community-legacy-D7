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
 *
 * @return string
 *   The result message to display if no destination provided.
 */
function c4m_smed_feeder_action_sync_user($account) {
  $result = c4m_smed_feeder_request_sync_user($account);
  $destination = drupal_get_destination();

  switch ($result['response']['response']->code) {
    case 200:
      drupal_set_message(t('User %name has been updated successfully',
        ['%name' => $result['account']->name]
      ));
      break;

    // We consider that anything else than 200 is an error.
    default:
      drupal_set_message(t('An error occured while updating %name user'),
        ['%name' => $result['account']->name]
      );
      break;
  }

  if ($destination['destination'] != current_path()) {
    drupal_goto($destination['destination']);
  }

  return c4m_smed_feeder_format_message_from_service($result['response']);
}

<?php

/**
 * @file
 * List of user statuses provided by the SMED Service.
 */

/**
 * Provides the list of statuses with related label and message.
 *
 * @return array[]
 *   List of statuses in as an array with following keys:
 *   - statuskey
 *     - label: the status label.
 *     - message: the message to shown to the user.
 */
function c4m_smed_feeder_status_list() {
  return [
    'user_invited' => [
      'label' => t('User invited'),
      'message' => t('Please complete your profile at %url_to_smed_user'),
    ],
    'user_approved_incomplete' => [
      'label' => t('User approved incomplete'),
      'message' => t('Welcome %user_firstname %user_lastname, before you can continue please complete your profile at %smed_url'),
    ],
    'user_pending' => [
      'label' => t('User pending'),
      'message' => t('Welcome %user_firstname %user_lastname, your account is pending approval, once approved you will receive a notification e-mail'),
    ],
    'user_approved_complete' => [
      'label' => t('User approved complete'),
      'message' => t('Welcome %user_firstname %user_lastname'),
    ],
    'user_not_bootstrapped' => [
      'label' => t('User not bootstrapped'),
      'message' => t('Please contact us via the %link_to_contactform'),
    ],
    'user_unknown' => [
      'label' => t('User unknown'),
      'message' => t('Please register at %link_to_the_smed'),
    ],
    'user_blocked' => [
      'label' => t('User blocked'),
      'message' => t('Please contact us via the %link_to_contactform'),
    ],
    'user_unsuscribed' => [
      'label' => t('User unsubscribed'),
      'message' => t('Please register at %link_to_the_smed'),
    ],
  ];
}


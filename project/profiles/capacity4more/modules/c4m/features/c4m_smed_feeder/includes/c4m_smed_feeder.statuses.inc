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
 *     - message: the message to show to the user.
 */
function c4m_smed_feeder_status_list() {
  global $user;
  $account = user_load($user->uid);
  $firstname = empty($account->c4m_first_name[LANGUAGE_NONE][O]['value']) ? '' : $account->c4m_first_name[LANGUAGE_NONE][O]['value'];
  $lastname = empty($account->c4m_last_name[LANGUAGE_NONE][O]['value']) ? '' : $account->c4m_last_name[LANGUAGE_NONE][O]['value'];

  // Get the SMED configuration.
  $smed_feeder = variable_get('smed_feeder', []);
  $smed_generic_url = $smed_feeder['smed_generic_url'];

  return [
    'user_profile_in_progress' => [
      'label' => t('User profile in progress'),
      'message' => t('Please complete your profile at %smed_generic_url',
        ['%smed_generic_url ' => l($smed_generic_url, $smed_generic_url)]
      ),
    ],
    'user_pending' => [
      'label' => t('User pending'),
      'message' => t('Welcome %user_firstname %user_lastname, your account is pending approval, once approved you will receive a notification e-mail',
        ['%user_firstname' => $firstname, '%user_lastname' => $lastname]
      ),
    ],
    'user_valid' => [
      'label' => t('User valid'),
      'message' => t('Welcome %user_firstname %user_lastname',
        ['%user_firstname' => $firstname, '%user_lastname' => $lastname]
      ),
    ],
    'user_not_bootstrapped' => [
      'label' => t('User not bootstrapped'),
      'message' => t('Please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form', url('contact')))]
      ),
    ],
    'user_unknown' => [
      'label' => t('User unknown'),
      'message' => t('Please register at %smed_generic_url',
        ['%smed_generic_url ' => l($smed_generic_url, $smed_generic_url)]
      ),
    ],
    'user_blocked' => [
      'label' => t('User blocked'),
      'message' => t('Please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form', url('contact')))]
      ),
    ],
    'user_unsuscribed' => [
      'label' => t('User unsubscribed'),
      'message' => t('If you want to re-activate your account please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form', url('contact')))]
      ),
    ],
  ];
}


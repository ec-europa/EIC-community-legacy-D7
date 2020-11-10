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
function c4m_smed_feeder_status_list($account = NULL) {
  global $user;
  if (empty($account)) {
    $account = user_load($user->uid);
  }

  $firstname = empty($account->c4m_first_name[LANGUAGE_NONE][0]['value']) ? '' : $account->c4m_first_name[LANGUAGE_NONE][0]['value'];
  $lastname = empty($account->c4m_last_name[LANGUAGE_NONE][0]['value']) ? '' : $account->c4m_last_name[LANGUAGE_NONE][0]['value'];

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
      'label' => t('User is pending'),
      'message' => t('Welcome %user_firstname %user_lastname, your account is pending approval, once approved you will receive a notification e-mail',
        ['%user_firstname' => $firstname, '%user_lastname' => $lastname]
      ),
    ],
    'user_valid' => [
      'label' => t('User validated'),
      'message' => t('Welcome %user_firstname %user_lastname',
        ['%user_firstname' => $firstname, '%user_lastname' => $lastname]
      ),
    ],
    'user_not_bootstrapped' => [
      'label' => t('User is not bootstrapped'),
      'message' => t('Please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form'), url('contact'))]
      ),
    ],
    'user_unknown' => [
      'label' => t('User is unknown'),
      'message' => t('Please register at %smed_generic_url',
        ['%smed_generic_url ' => l($smed_generic_url, $smed_generic_url)]
      ),
    ],
    'user_blocked' => [
      'label' => t('The user account is blocked'),
      'message' => t('Please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form'), url('contact'))]
      ),
    ],
    'user_unsuscribed' => [
      'label' => t('User was unsubscribed'),
      'message' => t('If you want to re-activate your account please contact us via the %link_to_contactform',
        ['%link_to_contactform' => l(t('contact form'), url('contact'))]
      ),
    ],
  ];
}


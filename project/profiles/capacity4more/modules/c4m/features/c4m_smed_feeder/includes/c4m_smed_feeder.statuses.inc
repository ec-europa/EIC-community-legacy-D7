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

  $user_inactive_mesage = '';
  if (!empty($account) && $account->status==0) {
    $user_inactive_mesage = '<br>' . t('The account is inactive at the moment.');
  }

  // Get the SMED configuration.
  $smed_feeder = variable_get('smed_feeder', []);
  $smed_generic_url = $smed_feeder['smed_generic_url'];

  return [
    'user_invited' => [
      'label' => t('Is invited to join the community but has not started the process yet.'),
      'message' => t('<h2>Welcome to the EIC community!</h2>
<br/>To get you started please
<div class="register"> @smed_generic_url </div>
<br/><br/>
<p>If you have any questions @link_to_contactform .</p>',
        [ '@link_to_contactform' => l(t('contact us'), url('contact')),
          '@smed_generic_url ' => l("Register", $smed_generic_url)]
      ),
    ],
    'user_draft' => [
      'label' => t('User profile is in progress'),
      'message' => t('<h2>Welcome to the EIC community!</h2>
<br/>Almost there! It look like your registration is in draft.
<div class="register"> @smed_generic_url </div>
<br/><br/>
<p>If you have any questions @link_to_contactform .</p>',
        [ '@link_to_contactform' => l(t('contact us'), url('contact')),
          '@smed_generic_url ' => l("Go to draft", $smed_generic_url)]
      ),
    ],
    'user_pending' => [
      'label' => t('User is pending'),
      'message' => t('<p>Welcome @user_firstname,</p>
<p>Currently your access is under review.</p>
<p>If you do not hear from us in the coming days, please contact us @link_to_contactform</p>',
        [ '@user_firstname' => $firstname,
          '@link_to_contactform' => l(t('contact us'), url('contact')),
          '@smed_generic_url ' => l("Register", $smed_generic_url)]
      ),
    ],
    'user_valid' => [
      'label' => t('User validated'),
      'message' => t('Welcome %user_firstname ' . $user_inactive_mesage,
        ['@user_firstname' => $firstname, '%user_lastname' => $lastname]
      ),
    ],
    'user_unknown' => [
      'label' => t('Current user is unknown'),
      'message' => t('<h2>It looks like you are not a member yet. Interested?</h2>
<br/>
<div class="register"> @smed_generic_url </div>
<br/><br/>
<p>If you have any questions @link_to_contactform .</p>',
        [ '@smed_generic_url' => l("Register", $smed_generic_url),
          '@link_to_contactform' => l(t('contact us'), url('contact'))]
      ),
    ],
    'user_not_bootstrapped' => [
      'label' => t('The user is not bootstrapped'),
      'message' => t('It looks like something went wrong, <br> please @link_to_contactform.',
        ['@link_to_contactform' => l(t('contact us'), url('contact'))]
      ),
    ],

    'user_blocked' => [
      'label' => t('The user account is blocked'),
      'message' => t('It looks like something went wrong, <br> please @link_to_contactform.',
        ['@link_to_contactform' => l(t('contact us'), url('contact'))]
      ),
    ],
    'user_unsuscribed' => [
      'label' => t('User has been unsubscribed'),
      'message' => t('It looks like something went wrong, <br> please @link_to_contactform.',
        ['@link_to_contactform' => l(t('contact us'), url('contact'))]
      ),
    ],
  ];
}


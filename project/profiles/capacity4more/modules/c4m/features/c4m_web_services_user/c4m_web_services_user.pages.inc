<?php

/**
 * @file
 * Implementation of the specific pages for the module.
 */

/**
 * Redirects a user to their profile edit page based on the SMED ID.
 *
 * @param int $smed_id
 *   The SMED ID.
 */
function c4m_web_services_redirect_smed_user_to_profile($smed_id) {
  // filter out bad requests.
  if (!is_numeric($smed_id)) {
     return drupal_access_denied();
  }
  // We don't explicitely deny access for non logged-in users as we want them to
  // hit the existing login workflow.
  $account = c4m_user_profile_load_by_dashboard_id($smed_id);

  // If account not found, deny access.
  if (!$account) {
    return drupal_access_denied();
  }

  // Set a session variable to flag that the user comes from Challenge platform
  // and redirect user to their profile edit page.
  $_SESSION['c4m_edit_profile']['back_to_challenge_platform'] = TRUE;
  drupal_goto('user/' . $account->uid . '/edit');
}

/**
 * Redirects a user to the Chalenge platform based on the SMED ID.
 *
 * @param int $smed_id
 *   The SMED ID.
 */
function c4m_web_services_redirect_smed_user_to_challenge_platform($smed_id = NULL) {
  // Redirect user to the defined page.
  $url = variable_get('capacity4more_url_challenge_platform', 'https://covid-eic.easme-web.eu');
  $url .= '/user/edit/smed';
  drupal_goto($url);
}

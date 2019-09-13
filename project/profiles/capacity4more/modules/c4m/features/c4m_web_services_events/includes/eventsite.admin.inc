<?php

/**
 * @file
 * Implementation of the administration interface for the module.
 */

/**
 * Creates the Event (sites) settings form. This is located under services tab.
 *
 * @return array $form
 */
function webservices_eventsite_admin_settings_general() {
  // Get event site configuration details.
  $webservice_eventsite = variable_get('webservice_eventsite', array());

  $form['webservice_eventsite'] = array(
    '#type' => 'fieldset',
    '#title' => t('Account details'),
    '#description' => t('Enter your Event site information.'),
    '#collapsible' => empty($webservice_eventsite) ? FALSE : TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['webservice_eventsite']['webservice_eventsite_owner_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Event site owner when creating through the webservice and owner is not given.'),
    '#description' => '',
     // t('Event site owner when creating through the webservice and owner is not given'),
    '#default_value' => isset($webservice_eventsite['webservice_eventsite_owner_account']) ? $webservice_eventsite['webservice_eventsite_owner_account'] : '',
    '#required' => FALSE,
  );
  $form['webservice_eventsite']['webservice_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Drupal user that is allowed to create content (eventsites).'),
    '#description' => '',
    '#default_value' => isset($webservice_eventsite['webservice_user']) ? $webservice_eventsite['webservice_user'] : 'dashboard_user',
    '#required' => TRUE,
  );

  $form = system_settings_form($form);

  return $form;

}

function webservices_eventsite_admin_settings_general_validate($form, &$form_state) {
  // Check if user actually exists.
  $user_check = user_load_by_name($form_state['values']['webservice_eventsite']['webservice_eventsite_owner_account']);
  $error_message = "account not found.";
  if (!$user_check) {
    form_set_error('webservice_eventsite_owner_account', $error_message);
  }
}
<?php

/**
 * @file
 * Implementation of the administration interface for the module.
 */

/**
 * Creates the Organisations and members settings form.
 *
 * @return array $form
 */
function c4m_web_services_admin_settings_general() {

  $form['webservice_general_authorization_token_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Authorization token key.'),
    '#description' => '',
    '#default_value' => variable_get('webservice_general_authorization_token_key', ''),
    '#required' => TRUE,
  );  

  $form = system_settings_form($form);

  return $form;

}

<?php

/**
 * @file
 * Implementation of the administration interface for the module.
 */

/**
 * Creates the User Management settings form. This is located under services tab.
 *
 * @return array $form
 */
function webservices_user_managemement_admin_settings_general() {
  // Get user site configuration details.
  $webservice_user = variable_get('webservice_user', array());

  $form['webservice_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Account details'),
    '#description' => t('configuration for the user webservice.'),
    '#collapsible' => empty($webservice_user) ? FALSE : TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['webservice_user']['webservice_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Drupal user that is allowed to create Drupal ECAS users'),
    '#description' => '',
    '#default_value' => isset($webservice_user['webservice_username']) ? $webservice_user['webservice_username'] : 'dashboard_user',
    '#required' => TRUE,
  );
  $form['webservice_user']['authorization_token_name'] = array(
    '#type' => 'textfield',
    '#title' => t('The Authorization token name (not the Basic Authentication one)'),
    '#description' => '',
    '#default_value' => isset($webservice_user['authorization_token_name']) ? $webservice_user['authorization_token_name'] : 'AuthorizationToken',
    '#required' => TRUE,
  );
  $form['webservice_user']['authorization_token_key'] = array(
    '#type' => 'textfield',
    '#title' => t('The Authorization token key'),
    '#description' => '',
    '#default_value' => isset($webservice_user['authorization_token_key']) ? $webservice_user['authorization_token_key'] : '',
    '#required' => TRUE,
  );


  $form = system_settings_form($form);

  return $form;

}
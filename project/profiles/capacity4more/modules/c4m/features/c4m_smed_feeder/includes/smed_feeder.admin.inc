<?php

/**
 * @file
 * Implementation of the administration interface for the module.
 */

/**
 * Creates the Smed Feeder (Webservice) settings form. This is located under services tab.
 *
 * @return array $form
 */
function c4m_smed_feeder_admin_settings_general() {
  // Get the SMED feeder site configuration details.
  $smed_feeder = variable_get('smed_feeder', array());

  $form['smed_feeder'] = array(
    '#type' => 'fieldset',
    '#title' => t('Smed feeder Settings'),
    '#description' => t('Enter the SMED Feeder information.'),
    '#collapsible' => empty($smed_feeder) ? FALSE : TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['smed_feeder']['smed_feeder_endpoint_url'] = array(
    '#type' => 'textfield',
    '#title' => t('the endpoint url for the smed feeder webservice.'),
    '#description' => '',
    '#default_value' => isset($smed_feeder['smed_feeder_endpoint_url']) ? $smed_feeder['smed_feeder_endpoint_url'] : '',
    '#required' => FALSE,
  );
  $form['smed_feeder']['smed_feeder_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('timeout allowed to communitcate with the smed service'),
    '#description' => '',
    '#default_value' => isset($smed_feeder['smed_feeder_timeout']) ? $smed_feeder['smed_feeder_timeout'] : '60',
    '#required' => TRUE,
  );
  $form['smed_feeder']['smed_feeder_basic_authentication_user'] = array(
    '#type' => 'textfield',
    '#title' => t('The SME dashboard basic authentication user.'),
    '#description' => '',
    '#default_value' => isset($smed_feeder['smed_feeder_basic_authentication_user']) ? $smed_feeder['smed_feeder_basic_authentication_user'] : '',
    '#required' => FALSE
  );
  $form['smed_feeder']['smed_feeder_basic_authentication_password'] = array(
    '#type' => 'password',
    '#title' => t('The SME dashboard basic authentication password. (Leave this field blank, unless you want to change the stored password.)'),
    '#description' => '',
    '#default_value' => isset($smed_feeder['smed_feeder_basic_authentication_password']) ? $smed_feeder['smed_feeder_basic_authentication_password'] : '',
    '#required' => FALSE,
    '#attributes'    => array(
      'autocomplete' => 'off',
    ),
  );
  $form['smed_feeder']['smed_feeder_authorization_token_key'] = array(
    '#type' => 'password',
    '#title' => t('smed-feeder Authorization token key. (Leave this field blank, unless you want to change the stored token.)'),
    '#description' => '',
    '#default_value' => isset($smed_feeder['smed_feeder_authorization_token_key']) ? $smed_feeder['smed_feeder_authorization_token_key'] : '',
    '#required' => FALSE,
    '#attributes'    => array(
      'autocomplete' => 'off',
    ),
  );

  $form['#submit'][] = 'c4m_smed_feeder_admin_settings_submit';
  $form = system_settings_form($form);
  return $form;
}

/**
 * Submit handler().
 */

function c4m_smed_feeder_admin_settings_submit($form, &$form_state) {
  // A password field is not shown . So, when a user submit this form without changing the password,
  // the field(s) will be take the stored value(s).
  if (empty($form_state['values']['smed_feeder']['smed_feeder_basic_authentication_password'])) {
    $form_state['values']['smed_feeder']['smed_feeder_basic_authentication_password'] = $form_state["complete form"]["smed_feeder"]["smed_feeder_basic_authentication_password"]["#default_value"];
  }
  if (empty($form_state['values']['smed_feeder']['smed_feeder_authorization_token_key'])) {
    $form_state['values']['smed_feeder']['smed_feeder_authorization_token_key'] = $form_state["complete form"]["smed_feeder"]["smed_feeder_authorization_token_key"]["#default_value"];
  }
}

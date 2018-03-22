<?php

/**
 * @file
 * Admin forms.
 */

/**
 * The admin form.
 */
function c4m_content_organisation_admin_settings($form) {
  $form['c4m_organisation_dashboard_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Organisation's dashboard link"),
    '#description' => t("This link will be used on Organisation's edit page for fields that are managed through the dashboard"),
    '#default_value' => variable_get('c4m_organisation_dashboard_link', ''),
    '#required' => TRUE,
  );

  $form['c4m_user_dashboard_link'] = array(
    '#type' => 'textfield',
    '#title' => t("User's dashboard link"),
    '#description' => t("This link will be used on User's edit page for fields that are managed through the dashboard"),
    '#default_value' => variable_get('c4m_user_dashboard_link', ''),
    '#required' => TRUE,
  );
  $form = system_settings_form($form);
  $form['#validate'][] = 'c4m_content_organisation_admin_settings_validate';
  return $form;
}

/**
 * Form validation handler for the text fields in order to check if they are links.
 */
function c4m_content_organisation_admin_settings_validate($form, &$form_state) {
  $c4m_organisation_dashboard_link = !empty($form_state['values']['c4m_organisation_dashboard_link'])?
    $form_state['values']['c4m_organisation_dashboard_link'] : '';
  if (!valid_url($c4m_organisation_dashboard_link, TRUE)) {
    form_set_error('c4m_organisation_dashboard_link', t("Please enter a valid URL for Organisation's dashboard link."));
  }

  $c4m_user_dashboard_link = !empty($form_state['values']['c4m_user_dashboard_link'])?
    $form_state['values']['c4m_user_dashboard_link'] : '';
  if (!valid_url($c4m_user_dashboard_link, TRUE)) {
    form_set_error('c4m_user_dashboard_link', t("Please enter a valid URL for Users's dashboard link."));
  }
}

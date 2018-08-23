<?php

/**
 * @file
 * c4m_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_account_option';
  $strongarm->value = '0';
  $export['ecas_account_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_default_mail_address';
  $strongarm->value = 'unknown.mail@nomail.nodomain.tld';
  $export['ecas_default_mail_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_login_message';
  $strongarm->value = 'Logged in via EU Login as %ecas_username.';
  $export['ecas_login_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_profile_core_ecas_email_field';
  $strongarm->value = '';
  $export['ecas_profile_core_ecas_email_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_profile_core_enabled';
  $strongarm->value = 1;
  $export['ecas_profile_core_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_profile_core_firstname_field';
  $strongarm->value = 'c4m_first_name';
  $export['ecas_profile_core_firstname_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_profile_core_lastname_field';
  $strongarm->value = 'c4m_last_name';
  $export['ecas_profile_core_lastname_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ecas_warning_message';
  $strongarm->value = 'You are not authorised to access this page. To gain access or for more information please contact us at the following address: <a href="mailto:EASME-SME-HELPDESK@ec.europa.eu">EASME-SME-HELPDESK@ec.europa.eu</a>';
  $export['ecas_warning_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'c4m_user_teaser_list' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_user_teaser_table' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_picture' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_list_global' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_table_global' => array(
        'custom_settings' => TRUE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'user_picture' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'ckeditor' => array(
          'weight' => '12',
        ),
        'mimemail' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '16',
        ),
        'account' => array(
          'weight' => '-100',
        ),
        'timezone' => array(
          'weight' => '10',
        ),
        'contact' => array(
          'weight' => '3',
        ),
        'overlay_control' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'summary' => array(
          'default' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'c4m_user_picture' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '33',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
          'user_picture' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '41',
            'visible' => FALSE,
          ),
          'member_overview' => array(
            'weight' => '47',
            'visible' => FALSE,
          ),
        ),
        'mimemail' => array(
          'c4m_user_teaser_table' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
          'user_picture' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '37',
            'visible' => FALSE,
          ),
          'member_overview' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
        ),
        'masquerade' => array(
          'full' => array(
            'weight' => '44',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '53',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  return $export;
}

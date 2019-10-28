<?php

/**
 * @file
 * c4m_web_services_user.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function c4m_web_services_user_default_services_endpoint() {
  $webservice_user_settings = variable_get('webservice_user', array());
  if (!isset($webservice_user_settings['webservice_username'])) {
    return array();
  }
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'easme_user';
  $endpoint->server = 'c4m_web_services_user';
  $endpoint->path = WS_USER_ENDPOINT;
  $endpoint->authentication = array(
    'c4m_web_services_user' => array(
      'authorization_token_name' => $webservice_user_settings['authorization_token_name'],
      'authorization_token_key' => $webservice_user_settings['authorization_token_key'],
      'webservice_username' => $webservice_user_settings['webservice_username'],
    ),
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'xml' => TRUE,
      'bencode' => FALSE,
      'json' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
    ),
    'parsers' => array(
      'application/xml' => TRUE,
      'application/json' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'user' => array(
      'operations' => array(
        'c4m_update_user' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'c4m_create_user' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['easme_user'] = $endpoint;

  return $export;
}

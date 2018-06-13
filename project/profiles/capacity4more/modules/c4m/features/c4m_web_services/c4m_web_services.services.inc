<?php

/**
 * @file
 * c4m_web_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function c4m_web_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'easme_dashboard';
  $endpoint->server = 'c4m_web_services';
  $endpoint->path = 'easme_dashboard/rest';
  $endpoint->authentication = array(
    'c4m_web_services' => array(
      'authorization_token_name' => 'AuthorizationToken',
      'authorization_token_key' => '',
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
    'node' => array(
      'operations' => array(
        'c4m_update' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'token' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['easme_dashboard'] = $endpoint;

  return $export;
}

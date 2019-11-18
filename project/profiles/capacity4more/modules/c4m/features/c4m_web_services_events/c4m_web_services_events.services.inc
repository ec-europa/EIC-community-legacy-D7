<?php

/**
 * @file
 * c4m_web_services_events.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function c4m_web_services_events_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'easme_events';
  $endpoint->server = 'c4m_web_services_events';
  $endpoint->path = WS_EVENTSITE_ENDPOINT;
  $endpoint->authentication = array(
    'c4m_web_services_events' => array(
      'authorization_token_name' => 'AuthorizationToken',
      'authorization_token_key' => 'dh349fh3Fh48gfdFDhsg23DFdgh',
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
    'eventsite' => array(
      'operations' => array(
        'c4m_update_event' => array(
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
  );
  $endpoint->debug = 0;
  $export['easme_events'] = $endpoint;

  return $export;
}

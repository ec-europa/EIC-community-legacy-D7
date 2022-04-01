<?php

/**
 * @file
 * c4m_web_services_notification.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */

function c4m_web_services_notification_default_services_endpoint() {

  //  $webservice_notification_settings = variable_get('webservice_user', array());
  //  if (!isset($webservice_user_settings['webservice_username'])) {
  //    return array();
  //  }
  $endpoints = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'eismea_notification';
  $endpoint->server = 'c4m_web_services_notification';
  $endpoint->path = "eismea_notification/rest";
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'bencode' => FALSE,
      'json' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => TRUE,
    ),
    'parsers' => array(
      'application/json' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/xml' => TRUE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );

  $endpoint->resources = array(
    'notification' => array(
      'alias' => '',
      'operations' => array(
        'create' => array(
          'enabled' => 0,
        ),
        'retrieve' => array(
          'enabled' => 1,
        ),
        'update' => array(
          'enabled' => 0,
        ),
        'delete' => array(
          'enabled' => 0,
        ),
        'index' => array(
          'enabled' => 0,
        ),
      ),
    ),
  );

  $endpoint->debug = 0;
  $endpoints[] = $endpoint;
  return $endpoints;
}

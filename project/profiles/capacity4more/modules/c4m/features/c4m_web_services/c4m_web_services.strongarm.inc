<?php

/**
 * @file
 * c4m_web_services.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_web_services_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chr_original_http_request_function_value';
  $strongarm->value = 'chr_curl_http_request';
  $export['chr_original_http_request_function_value'] = $strongarm;

  return $export;
}

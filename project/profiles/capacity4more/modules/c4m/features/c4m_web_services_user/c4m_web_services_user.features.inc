<?php

/**
 * @file
 * c4m_web_services_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_web_services_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

<?php

/**
 * @file
 * c4m_public_access.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_public_access_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }

  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

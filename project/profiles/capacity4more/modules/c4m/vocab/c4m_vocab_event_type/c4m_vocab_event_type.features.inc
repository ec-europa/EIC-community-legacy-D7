<?php

/**
 * @file
 * c4m_vocab_event_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_vocab_event_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

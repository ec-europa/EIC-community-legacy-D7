<?php

/**
 * @file
 * c4m_vocab_nace.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_vocab_nace_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

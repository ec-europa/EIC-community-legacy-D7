<?php

/**
 * @file
 * c4m_content_inthe_picture.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_inthe_picture_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_inthe_picture_node_info() {
  $items = array(
    'inthe_picture' => array(
      'name' => t('In the Picture'),
      'base' => 'node_content',
      'description' => t('In the Picture content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

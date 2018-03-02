<?php

/**
 * @file
 * c4m_content_event_site.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_event_site_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_event_site_node_info() {
  $items = array(
    'event_site' => array(
      'name' => t('Event Site'),
      'base' => 'node_content',
      'description' => t('The content type Event Site serves the need for creating event promotion pages/site in an easy and user-friendly way.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

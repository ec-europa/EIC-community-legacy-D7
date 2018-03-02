<?php

/**
 * @file
 * Plugin to show the left side of the Event site page.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Event site page left'),
  'description' => t('Renders the contents of the left side of a event site page.'),
  'category' => t('C4M'),
  'render callback' => 'c4m_content_event_site_page_left_render',
);

/**
 * Run time rendering of the left side of the event site page.
 *
 * @return object
 *   The block definition.
 */
function c4m_content_event_site_page_left_render() {
  $block = new stdClass();
  if ($group = og_context()) {
    if ($node = node_load($group['gid'])) {
      $block->id = 'event_site_page_left';
      $block->title = '';
      $block->content = field_view_field('node', $node, 'c4m_left_column', array('label' => 'hidden'));
    }
  }

  return $block;
}

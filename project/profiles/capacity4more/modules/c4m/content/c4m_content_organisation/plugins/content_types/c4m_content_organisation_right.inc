<?php

/**
 * @file
 * Plugin to show the right side of the organisation page.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Organisation page right'),
  'description' => t('Renders the contents of the right side of a Organisation page.'),
  'category' => t('C4M'),
  'render callback' => 'c4m_content_organisation_page_right_render',
);

/**
 * Run time rendering of the right side of the Organisation page.
 *
 * @return object
 *   The block definition.
 */
function c4m_content_organisation_page_right_render() {
  $block = new stdClass();
  if ($group = og_context()) {
    if ($node = node_load($group['gid'])) {
      $block->id = 'organisation_page_right';
      $block->title = '';
      $block->content = field_view_field('node', $node, 'c4m_right_column', array('label' => 'hidden'));
    }
  }

  return $block;
}

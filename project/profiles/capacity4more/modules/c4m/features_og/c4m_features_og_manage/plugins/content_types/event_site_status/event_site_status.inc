<?php

/**
 * @file
 * Panels plugin to show the event_site status.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Event Site status management dashboard'),
  'description' => t('Renders event_site status management dashboard with edit links and thumbnail image.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_manage_event_site_status_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_manage_event_site_status_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_og_manage';
  $block->title = '';

  $event_site_thumbnail = c4m_features_og_manage_event_site_thumbnail();

  $block->content = theme('c4m_features_og_manage_event_site_status', array('info' => $event_site_thumbnail));

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_manage_event_site_status_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_manage_event_site_status_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_manage_event_site_status'] = array(
    'variables' => array(
      'info' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'event-site-status',
  );
}

<?php

/**
 * @file
 * Panels plugin to show the event_site details.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Event Site details management dashboard'),
  'description' => t('Renders event_site details management dashboard with edit links.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_manage_event_site_details_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_manage_event_site_details_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_og_manage';
  $block->title = '';

  $event_site_details = c4m_features_og_manage_event_site_details();
  $theme = 'c4m_features_og_manage_event_site_details';

  if (!empty($event_site_details['type']) && $event_site_details['type'] == 'programme') {
    $theme = 'c4m_features_og_manage_programme_details';
  }

  $block->content = array(
    '#theme'   => $theme,
    '#details' => $event_site_details,
  );

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_manage_event_site_details_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_manage_event_site_details_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_manage_event_site_details'] = array(
    'variables' => array(
      'details' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'event-site-details',
  );
}

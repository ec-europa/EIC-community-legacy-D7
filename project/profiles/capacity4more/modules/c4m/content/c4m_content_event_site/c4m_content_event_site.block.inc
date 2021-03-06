<?php

/**
 * @file
 * Code for the project blocks.
 */

/**
 * Callback for the c4m_block_create_event_site block.
 */
function _c4m_content_event_site_block_c4m_block_create_event_site() {
  global $user;
  $markup = '';

  $markup = '';
  if ($user->uid) {
    if (user_access('create event_site content')) {
      $markup = l(
        t('Create an event site'),
        'node/add/event-site',
        array('attributes' => array('class' => array('btn', 'btn-primary')))
      );
    }
  }
  else {
    $markup = t(
      '!register or !login to create or join event sites',
      array(
        '!register' => l(
          t('Register'),
          'user/register',
          array(
            'query' => array('destination' => request_path()),
          )
        ),
        '!login' => l(
          t('log in'),
          'user/login',
          array(
            'query' => array('destination' => request_path()),
          )
        ),
      )
    );
  }
  return array(
    'subject' => '',
    'content' => $markup,
  );
}

/**
 * Project Dashboard title redesign.
 *
 * The function handles header title redesign project page.
 */
function _c4m_content_event_site_block_header_name_banner_event_site() {
  // First establish the current project.
  $event_site = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $event_site);
  $markup = '';

  $title = $wrapper->title->value();

  $tagline = $wrapper->c4m_project_tag_line->value();

  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value(
  ) : 'published';

  $label_type = ($status == 'pending') ? "label-danger" : "label-default";
  $options = [
    'attributes' => [
      'class' => ['es-publish-link', 'ecl-button', 'ecl-button--primary'],
    ],
  ];
  $publish_link = ($status != 'published') ?
    l(t('Publish now'), 'c4m/'. $event_site->nid . '/publish_event_site', $options) : '';

  $variables = [
    'title' => check_plain($title),
    'tagline' => check_plain($tagline),
    'type' => 'event site',
    'status' => ucfirst($status),
    'label_type' => $label_type,
    'publish_link' => $publish_link,
  ];
  $markup .= theme('c4m_content_event_site_header_title', $variables);

  // Adding AJAX for notification toggle, which is part of this block.
  drupal_add_library('system', 'drupal.ajax');

  return array(
    'subject' => '',
    'content' => $markup,
  );
}


/**
 * Callback for the c4m_block_event_site_about block.
 */
function _c4m_content_event_site_block_c4m_block_event_site_about() {
  $block = array();
  $block['subject'] = '';

  if ($node = c4m_og_current_group()) {
    // Render it with our custom group_dashboard view mode.
    $node_view = node_view($node, 'group_dashboard');
    $block['content'] = drupal_render($node_view);
  }

  return $block;
}


/**
 * Callback for the c4m_block_event_site_documents block.
 */
function _c4m_content_event_site_block_c4m_block_event_site_documents() {
  $block = array();
  $block['subject'] = '';

  if ($node = c4m_og_current_group()) {
    // Render it with our custom group_dashboard view mode.
    $node_view = node_view($node, 'documents');
    $block['content'] = drupal_render($node_view);
  }

  return $block;
}

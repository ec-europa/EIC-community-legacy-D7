<?php

/**
 * @file
 * Code for the project blocks.
 */

/**
 * Callback for the c4m_block_create_organisation block.
 */
function _c4m_content_organisation_block_c4m_block_create_organisation() {
  global $user;
  $markup = '';

  $markup = '';
  if ($user->uid) {
    if (user_access('create organisation content')) {
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
        '!register' => l(t('Register'), 'user/register'),
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
 * Organisation Dashboard title redesign.
 *
 * The function handles header title redesign project page.
 */
function _c4m_content_organisation_block_header_name_banner_organisation() {
  // First establish the current project.
  $project = c4m_og_current_group();
  $wrapper = entity_metadata_wrapper('node', $project);
  $markup = '';

  $title = $wrapper->title->value();

  $tagline = $wrapper->c4m_project_tag_line->value();

  $status = isset($wrapper->c4m_og_status) ? $wrapper->c4m_og_status->value(
  ) : 'published';

  $label_type = ($status == 'pending') ? "label-danger" : "label-default";

  $variables = [
    'title' => check_plain($title),
    'tagline' => check_plain($tagline),
    'type' => $project->type,
    'status' => $status,
    'label_type' => $label_type,
  ];
  $markup .= theme('c4m_content_organisation_header_title', $variables);

  // Adding AJAX for notification toggle, which is part of this block.
  drupal_add_library('system', 'drupal.ajax');

  return array(
    'subject' => '',
    'content' => $markup,
  );
}


/**
 * Callback for the c4m_block_organisation_about block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_about() {
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
 * Callback for the c4m_block_organisation_as Activity Stream block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_as() {
  $block = array();

  $request = array(
    'group' => c4m_og_current_group()->nid,
    'html' => TRUE,
    // Sort the activity stream by timestamp descending.
    'sort' => '-timestamp',
    'hide_articles' => 1,
    'group_context' => TRUE,
  );

  $activities = c4m_message_get_activities($request);
  // Pass info via Drupal.settings.
  $settings['c4m'] = [
    'csrfToken' => drupal_get_token(\RestfulInterface::TOKEN_VALUE),
    'activities' => $activities,
    'data' => [
      'request' => $request,
      'entity' => ['group' => c4m_og_current_group()->nid],
    ],
  ];
  drupal_add_js($settings, 'setting');
  $block['content'] = theme('c4m_message_activity_stream');
  $block['content'] .= views_embed_view('group_activity_stream');

  return $block;
}

/**
 * Callback for the c4m_block_organisation_groups block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_groups() {
  $block = array();
  $block['subject'] = '';
  $block['content'] = '';

  if ($node = c4m_og_current_group()) {
    // Get uids of all active subscribers of current organisation.
    $uids = _c4m_content_organisation_get_organisation_members($node);
    if (empty($uids)) {
      return $block;
    }
    // Get the nids of Groups that have members in the organisation.
    $group_nids = _c4m_content_organisation_get_groups_of_members($uids);
    if (empty($group_nids)) {
      return $block;
    }
    $group_nids = implode(',', $group_nids);
    // Render the view and pass arguments.
    $block['content'] = views_embed_view('c4m_organisations_groups', 'block', $group_nids);
  }
  return $block;
}

/**
 * Get the uids of members in Organisation.
 *
 * @param object $node
 *   The current node.
 *
 * @return mixed
 *   Uids of members in organisation (if any).
 */
function _c4m_content_organisation_get_organisation_members($node) {
  $uids = [];

  if (empty($node)) {
    return $uids;
  }

  list($id) = entity_extract_ids('node', $node);

  $query = db_select("og_membership", "ogm");
  $query->condition("ogm.gid", $id, "=");
  $query->condition("ogm.group_type", 'node', "=");
  $query->condition("ogm.entity_type", 'user', "=");
  $query->fields("ogm", array("etid"));
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $uids[] = $record['etid'];
  }

  return array_unique($uids);
}

/**
 * Get the nids of Groups that have members in the organisation.
 *
 * @param array $uids
 *   An array of uids that represent the members of the organisation.
 *
 * @return array $nids
 *   Group nids (if any).
 */
function _c4m_content_organisation_get_groups_of_members($uids) {
  $nids = [];

  if (empty($uids)) {
    return $nids;
  }

  $query = db_select("og_membership", "ogm");
  $query->condition("ogm.etid", $uids, "IN");
  $query->condition("ogm.group_type", 'node', "=");
  $query->condition("ogm.entity_type", 'user', "=");
  $query->fields("ogm", array("gid"));
  $query->leftJoin('node', 'node', 'node.nid = ogm.gid');
  $query->condition('node.type', 'group', '=');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $nids[] = $record['gid'];
  }

  return array_unique($nids);
}

/**
 * Callback for the c4m_block_organisation_customers block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_customers() {
    $block = array();

    if ($node = c4m_og_current_group()) {
        $block['subject'] = '';
        $block['content'] = field_view_field(
            'node',
            $node,
            'c4m_customers',
            array('label' => 'hidden')
        );
    }

    return $block;
}

/**
 * Callback for the c4m_block_organisation_partners block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_partners() {
  $block = array();

  if ($node = c4m_og_current_group()) {
    $block['subject'] = '';
    $block['content'] = field_view_field(
      'node',
      $node,
      'c4m_partners',
      array('label' => 'hidden')
    );
  }

  return $block;
}

/**
 * Callback for the c4m_block_organisation_about_us block.
 */
function _c4m_content_organisation_block_c4m_block_organisation_about_us() {
  $block = array();

  if ($node = c4m_og_current_group()) {
    $block['subject'] = '';
    $block['content'] = field_view_field(
      'node',
      $node,
      'field_c4m_about_us',
      array('label' => 'hidden')
    );
  }

  return $block;
}


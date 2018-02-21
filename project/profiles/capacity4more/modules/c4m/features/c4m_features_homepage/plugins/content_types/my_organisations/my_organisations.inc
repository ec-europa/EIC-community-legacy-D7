<?php

/**
 * @file
 * My organisations panels block.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('My organisations'),
  'description' => t("Renders authenticated user's organisations."),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_my_organisations_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_my_organisations_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $organisations = c4m_features_homepage_get_user_organisations_grouped_by_membership($user, TRUE);

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = '';
  if (empty($organisations)) {
    return $block;
  }

  $rendered_organisations = '';
  $count = 0;
  $max_organisations_to_display = 5;
  $total_organisations = 0;

  // Render node views for each organisation.
  foreach ($organisations as $type => $organisation_list) {
    $total_organisations += count($organisation_list);

    if ($count >= $max_organisations_to_display) {
      continue;
    }

    $title = c4m_features_homepage_get_organisation_type_title($type);
    $rendered_organisations .= '<h4>' . $title . '</h4>';

    foreach ($organisation_list as $organisation) {
      if ($count >= $max_organisations_to_display) {
        continue;
      }

      $node_view = node_view($organisation, 'block_list');
      $rendered_organisations .= drupal_render($node_view);

      $count++;
    }
  }

  // When total event_sites are greater than the max event_sites to display then we
  // should display the "show more" button.
  $display_see_more = $total_organisations > $max_organisations_to_display;

  $link_options = array(
    'query' => array(
      'filter' => 'organisations',
    )
  );
  $variables = array(
    'organisations' => $rendered_organisations,
    'link' => url('organisations', $link_options),
    'display_see_more' => $display_see_more,
  );
  $output = '';
  if ($rendered_organisations) {
    $output .= theme('c4m_features_homepage_my_organisations', $variables);
    $renderable_array = c4m_features_homepage_node_creation_button_cta('organisation');
    $output .= render($renderable_array);
  }

  $block->content = $output;
  return $block;
}

/**
 * Returns the title for the type of membership of a organisation.
 *
 * @param string $type
 *   The organisation membership type.
 *
 * @return string
 *   The translated title for the membership type.
 */
function c4m_features_homepage_get_organisation_type_title($type) {
  $titles = array(
    'owner' => t('Owner of the following Organisation(s)'),
    'member' => t("Administrator of the following Organisation(s)"),
    'administrator' => t("Administrator of the following Organisation(s)"),
    'pending' => t('Membership requested in the following Organisation(s)'),
  );

  return $titles[$type];
}

/**
 * Returns the list of organisations of an user.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested organisations (pending status).
 *
 * @returns mixed|null
 *   List of organisations or NULL if the user has no organisations.
 */
function c4m_features_homepage_get_user_organisations($account = NULL, $allow_pending = FALSE) {
  $organisations = c4m_user_og_get_groups($account, 'organisation', NODE_PUBLISHED, TRUE, $allow_pending);
  // Removes organisations where the logged in user has no access.
  $organisations = array_filter($organisations, 'c4m_features_homepage_node_access_view_filter');

  usort($organisations, '_c4m_og_sort_by_status');

  return $organisations;
}

/**
 * Returns the list of organisations of an user, grouped by the membership type.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested organisations (pending status).
 *
 * @returns mixed|null
 *   List of organisations or NULL if the user has no organisations.
 */
function c4m_features_homepage_get_user_organisations_grouped_by_membership($account = NULL, $allow_pending = FALSE) {
  $organisations = c4m_features_homepage_get_user_organisations($account, $allow_pending);

  $grouped_organisations = array(
    'owner' => array(),
    'member' => array(),
  );
  foreach ($organisations as $organisation) {
    $membership = c4m_user_og_get_role_in_group($account, $organisation);
    $grouped_organisations[$membership][$organisation->nid] = $organisation;
  }
  // Remove empty list of organisations so the block is not rendered if there are no
  // organisations.
  foreach ($grouped_organisations as $type => $organisations) {
    if (empty($organisations)) {
      unset($grouped_organisations[$type]);
    }
  }

  return $grouped_organisations;
}

/**
 * Edit form.
 */
function c4m_features_homepage_my_organisations_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_my_organisations_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_my_organisations'] = array(
    'variables' => array(
      'organisations' => NULL,
      'link' => NULL,
      'display_see_more' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-organisations',
  );
}

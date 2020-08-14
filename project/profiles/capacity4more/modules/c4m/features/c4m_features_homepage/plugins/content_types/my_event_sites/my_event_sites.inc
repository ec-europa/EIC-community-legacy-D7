<?php

/**
 * @file
 * My event sites panels block.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('My event sites'),
  'description' => t("Renders authenticated user's event sites."),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_my_event_sites_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_my_event_sites_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $event_sites = c4m_features_homepage_get_user_event_sites_grouped_by_membership($user, TRUE);

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = '';
  if (empty($event_sites)) {
    return $block;
  }

  $rendered_event_sites = '';
  $count = 0;
  $max_event_sites_to_display = 5;
  $total_event_sites = 0;

  // Render node views for each event_site.
  foreach ($event_sites as $type => $event_site_list) {
    $total_event_sites += count($event_site_list);

    if ($count >= $max_event_sites_to_display) {
      continue;
    }

    $title = c4m_features_homepage_get_event_site_type_title($type);
    $rendered_event_sites .= '<h4>' . $title . '</h4>';

    foreach ($event_site_list as $event_site) {
      if ($count >= $max_event_sites_to_display) {
        continue;
      }

      $node_view = node_view($event_site, 'block_list');
      $rendered_event_sites .= drupal_render($node_view);

      $count++;
    }
  }

  // When total event_sites are greater than the max event_sites to display then we
  // should display the "show more" button.
  $display_see_more = $total_event_sites > $max_event_sites_to_display;

  $link_options = array(
    'query' => array(
      'filter' => 'event_sites',
    )
  );
  $variables = array(
    'event_sites' => $rendered_event_sites,
    'link' => url('events', $link_options),
    'display_see_more' => $display_see_more,
  );
  $output = '';
  if ($rendered_event_sites) {
    $output .= theme('c4m_features_homepage_my_event_sites', $variables);
    if (user_is_logged_in() && !drupal_is_front_page()) {
      $renderable_array = c4m_features_homepage_node_creation_button_cta('event-site');
      $output .= render($renderable_array);
    }
  }

  $block->content = $output;
  return $block;
}

/**
 * Returns the title for the type of membership of a event_site.
 *
 * @param string $type
 *   The event_site membership type.
 *
 * @return string
 *   The translated title for the membership type.
 */
function c4m_features_homepage_get_event_site_type_title($type) {
  $titles = array(
    'owner' => t('Owner of the following Event Site(s)'),
    'member' => t("Administrator of the following Event Site(s)"),
    'administrator' => t("Administrator of the following Event Site(s)"),
    'pending' => t('Membership requested in the following Event Site(s)'),
  );

  return $titles[$type];
}

/**
 * Returns the list of event_sites of an user.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested event_sites (pending status).
 *
 * @returns mixed|null
 *   List of event_sites or NULL if the user has no event_sites.
 */
function c4m_features_homepage_get_user_event_sites($account = NULL, $allow_pending = FALSE) {
  $event_sites = c4m_user_og_get_groups($account, 'event_site', NODE_PUBLISHED, TRUE, $allow_pending);
  // Removes event_sites where the logged in user has no access.
  $event_sites = array_filter($event_sites, 'c4m_features_homepage_node_access_view_filter');

  usort($event_sites, '_c4m_og_sort_by_status');

  return $event_sites;
}

/**
 * Returns the list of event_sites of an user, grouped by the membership type.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested event_sites (pending status).
 *
 * @returns mixed|null
 *   List of event_sites or NULL if the user has no event_sites.
 */
function c4m_features_homepage_get_user_event_sites_grouped_by_membership($account = NULL, $allow_pending = FALSE) {
  $event_sites = c4m_features_homepage_get_user_event_sites($account, $allow_pending);

  $grouped_event_sites = array(
    'owner' => array(),
    'member' => array(),
  );
  foreach ($event_sites as $event_site) {
    $membership = c4m_user_og_get_role_in_group($account, $event_site);
    $grouped_event_sites[$membership][$event_site->nid] = $event_site;
  }
  // Remove empty list of event_sites so the block is not rendered if there are no
  // event_sites.
  foreach ($grouped_event_sites as $type => $event_sites) {
    if (empty($event_sites)) {
      unset($grouped_event_sites[$type]);
    }
  }

  return $grouped_event_sites;
}

/**
 * Edit form.
 */
function c4m_features_homepage_my_event_sites_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_my_event_sites_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_my_event_sites'] = array(
    'variables' => array(
      'event_sites' => NULL,
      'link' => NULL,
      'display_see_more' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-event-sites',
  );
}

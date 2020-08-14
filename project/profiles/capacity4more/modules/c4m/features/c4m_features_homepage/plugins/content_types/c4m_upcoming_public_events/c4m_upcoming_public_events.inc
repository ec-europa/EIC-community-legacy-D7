<?php

/**
 * @file
 * Plugin to add the a block to show upcoming event sites (that are managed by internally).
 * Is dependent of the event_site webservice
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Upcoming "event sites"'),
  'description' => t('Renders managed upcoming event_sites'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_c4m_upcoming_public_events_content_type_theme',
  'defaults' => array(
    'title' => FALSE,
    'description' => FALSE,
  ),
);

/**
 * Render callback.
 */
function c4m_features_homepage_c4m_upcoming_public_events_content_type_render($subtype, $conf, $args, $context) {;
  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = '';

  if (module_exists('c4m_public_access') && user_is_anonymous() ) {
    $event_sites = _get_event_sites_for_anonymous_users();
    $rendered_event_sites = '';
    $link_options = array(
      'query' => array(
        'filter' => 'event_sites',
      )
    );

    // Render node views for each event_site.
    foreach ($event_sites as $type => $event_site_list) {
      foreach ($event_site_list as $event_site) {
        $node_view = node_view($event_site, 'block_list_anonymous');
        $rendered_event_sites .= drupal_render($node_view);
      }
    }

    if ($rendered_event_sites) {
      $variables = array(
        'event_sites' => $rendered_event_sites,
        'link' => url('events', $link_options),
      );

      $block->content = theme('c4m_features_homepage_c4m_upcoming_public_events', $variables);
    }


  }


  return $block;
}

/**
 * Returns the list of event_sites that an anonymous user can see.
 * When the public_access module is enabled.
 *
 * @returns mixed|null
 *   List of event_sites or NULL if there no event_sites visible for anonymous users.
 */
function _get_event_sites_for_anonymous_users() {
  $bundle = "event_site";
  $nodes = array();
  $nodeQuery = new EntityFieldQuery;
  $limit = 5;
  // Show only upcoming or ongoing event sites.
  $today_datetime = date_create()->format('Y-m-d H:i:s+0');
  $entities = $nodeQuery->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->fieldCondition('c4m_event_dashboard_id', 'value', '0', '>')
    ->fieldCondition('c4m_og_status', 'value', 'published', '=')
    ->fieldCondition('c4m_datetime_end', 'value2', $today_datetime, '>=')
    ->fieldOrderBy(c4m_datetime_end, 'value2', 'ASC')
    ->pager($limit)
    ->execute();

  //testing unrestricted access.
  $result = db_query("SELECT nid FROM node WHERE type = :nodeType ", array(':nodeType' => $bundle));
  foreach ($result as $obj) {  //<-- change 2
    $nodes[] = $obj->nid;
  }

  if (empty($entities)) {
    return [];
  }
  // Load groups of bundle type.
  $nids = array_keys($entities['node']);
  $event_sites_nodes = node_load_multiple($nids);

  return array($bundle => $event_sites_nodes);
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_c4m_upcoming_public_events_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_c4m_upcoming_public_events'] = array(
    'variables' => array(
      'event_sites' => NULL,
      'link' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'c4m_upcoming_public_events',
  );
}

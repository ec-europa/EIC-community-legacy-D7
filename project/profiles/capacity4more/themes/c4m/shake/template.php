<?php

include_once 'theme/menu.inc';

/**
 * @file
 * Template functions.
 */

function shake_preprocess_page(&$variables) {
  // Determine if the current context is a project.
  $context = og_context();
  if ($context) {
    if (($group_type = c4m_og_get_group_type($context))) {
      // Instruct to use a page template designated for project, event_site and organisation OG type.
      $variables['theme_hook_suggestions'][] = 'page__og__' . $group_type;

      // Don't show the Group membership type Facet on Attendees (Members) page for Event Site.
      if ($group_type == 'event_site' && current_path() == 'members') {
        drupal_set_title('Attendees');
        unset($variables["page"]["sidebar_first"]["facetapi_oPJrsj5t5dR0ObxkordoLaKTO9qn01ha"]);
      }
    }
  }
}

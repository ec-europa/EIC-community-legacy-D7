<?php

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
    }
  }
}
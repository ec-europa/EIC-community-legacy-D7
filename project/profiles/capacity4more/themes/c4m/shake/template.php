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

/**
 * Implements template_menu_link().
 */
function shake_menu_link(&$variables) {
  $element  = ($variables['element'])? $variables['element'] : '';
  $menuName = isset($variables['element']["#original_link"]["menu_name"])?
    $variables['element']["#original_link"]["menu_name"]: '';

  if($menuName == 'main-menu' && !empty($element)) {

    $active_path = FALSE;
    if ($node = menu_get_object()) {
      switch ($node->type) {
        case 'article':
          $active_path = 'articles';
          break;

        case 'event_site':
          $active_path = 'calendar';
          break;

        case 'topic':
          $active_path = 'topics';
          break;
      }
    }
    if (arg(0) == 'user') {
      $active_path = 'people';
    }

    if ($active_path && $element['#href'] == $active_path) {
      $element["#attributes"]['class'][] = 'active';
    }

  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>";
}
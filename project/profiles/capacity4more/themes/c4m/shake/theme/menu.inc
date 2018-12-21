<?php

/**
 * Theme a menu link.
 *
 * @param array $variables
 *   The menu link variables.
 *
 * @return string
 *   The rendered list item.
 */
function shake_menu_link(array &$variables) {
  // Highlight subsection of groups.
  $element = ($variables['element']) ? $variables['element'] : '';
  $menuName = isset($variables['element']["#original_link"]["menu_name"]) ?
    $variables['element']["#original_link"]["menu_name"] : '';

  if ($menuName == 'main-menu' && !empty($element)) {

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

    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>";
  }

  // Discard PURL modifiers for global menus.
  // Group menu's: menu-og-<GID> and book-toc-<GID> (wiki navigation).
  // Discard if not in an og_context.
  if (
    !preg_match(
      "/menu-og|book-toc/i",
      $variables['element']['#original_link']['menu_name']
    )
    || !og_context_is_init()
  ) {
    $element = $variables['element'];
    $options = [
      'purl' => [
        'disabled' => TRUE,
      ],
    ];
    $element['#localized_options'] = $options;

    $variables['element'] = $element;
  }

  return bootstrap_menu_link($variables);
}
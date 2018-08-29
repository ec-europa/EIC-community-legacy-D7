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
    $options = array(
      'purl' => array(
        'disabled' => TRUE,
      ),
    );
    $element['#localized_options'] = $options;

    $variables['element'] = $element;
  }

  if (isset($variables['element']['#title']) && !empty($variables['element']['#wiki_link'])) {
    $element = $variables['element'];
    $sub_menu_wrapper = NULL;
    if ($element['#below']) {
      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
        // Add our own wrapper.
        unset($element['#below']['#theme_wrappers']);

        // Arrow for the dropdown.
        $tag['element'] = array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array('arrow'),
          ),
          '#value' => '',
        );
        $arrow = theme_html_tag($tag);

        // The list to put in the dropdown.
        $tag['element'] = array(
          '#tag' => 'ul',
          // Book links will be rendered by
          // kapablo_menu_link__book_c4m_og_menu().
          '#value' => drupal_render($element['#below']),
        );
        $sub_menu = theme_html_tag($tag);

        // We need a wrapper around submenu to add the arrow.
        $tag['element'] = array(
          '#tag' => 'div',
          '#attributes' => array(
            'class' => array('dropdown-menu', 'bottom'),
          ),
          '#value' => $arrow . $sub_menu,
        );
        $sub_menu_wrapper = theme_html_tag($tag);

        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;

        // Set dropdown trigger element to # to prevent inadvertent page loading
        // when a sub-menu link is clicked.
        $element['#localized_options']['attributes']['data-target'] = '#';
        $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
        $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
        $element['#localized_options']['attributes']['data-disabled'] = 'true';
      }
    }
    // On primary navigation menu, class 'active' is not set on active menu
    // item.
    // @see https://drupal.org/node/1896674
    if (($element['#href'] == current_path() || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))
    ) {
      $element['#attributes']['class'][] = 'active';
    }

    // Set active-trail on the link itself if there.
    if (in_array('active-trail', $element['#attributes']['class'])) {
      $element['#localized_options']['attributes']['class'][] = 'active-trail';
    }

    $element['#attributes']['class'][] = 'og-menu-link ' . preg_replace(
        "/[^A-Za-z0-9 ]/",
        '',
        $element['#original_link']['link_path']
      );

    $output = l(
      $element['#title'],
      $element['#href'],
      $element['#localized_options']
    );

    // @TODO: SET ACTIVE TRAIL/CLASS FOR OG!!!
    return '<li' . drupal_attributes(
        $element['#attributes']
      ) . '>' . $output . $sub_menu_wrapper . "</li>\n";

  }
  else {
    return bootstrap_menu_link($variables);
  }
}
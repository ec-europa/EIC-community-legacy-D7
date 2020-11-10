<?php
/**
 * @file
 * Definition of views_handler_field_user_smed_sync_user.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to synchronise user to the SMED.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_link_smed_sync_user extends views_handler_field_user_link {

  /**
   * @inheritdoc
   */
  public function render_link($data, $values) {
    $uid = $values->{$this->aliases['uid']};
    $this->options['alter']['make_link'] = TRUE;

    $text = t('Synchronise user');

    $this->options['alter']['path'] = "user/$uid/smed-sync";
    $this->options['alter']['query'] = drupal_get_destination();

    return $text;
  }

}

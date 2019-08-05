<?php

/**
 * @file
 * c4m_vocab_event_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_vocab_event_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-event_types-c4m_vocab_smed_event_type_id'.
  $field_instances['taxonomy_term-c4m_event_types-c4m_vocab_smed_event_type_id'] = array(
    'bundle' => 'c4m_event_types',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'c4m_vocab_smed_event_type_id',
    'label' => 'smed event type id',
    'required' => FALSE,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-event_types-c4m_et_allowed_in_event_sites'.
  $field_instances['taxonomy_term-c4m_event_types-c4m_et_allowed_in_event_sites'] = array(
    'bundle' => 'c4m_event_types',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'c4m_et_allowed_in_event_sites',
    'label' => 'Allowed in content type "event sites"',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-event_types-c4m_et_allowed_in_events'.
  $field_instances['taxonomy_term-c4m_event_types-c4m_et_allowed_in_events'] = array(
    'bundle' => 'c4m_event_types',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'c4m_et_allowed_in_events',
    'label' => 'Allowed in content type "events"',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 33,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Allowed in content type "event sites"');
  t('Allowed in content type "events"');
  t('smed event type id');

  return $field_instances;
}

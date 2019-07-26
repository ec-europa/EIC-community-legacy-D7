<?php

/**
 * @file
 * c4m_vocab_event_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_vocab_event_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_smed_event_type_id'.
  $field_bases['c4m_vocab_smed_event_type_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_vocab_smed_event_type_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}

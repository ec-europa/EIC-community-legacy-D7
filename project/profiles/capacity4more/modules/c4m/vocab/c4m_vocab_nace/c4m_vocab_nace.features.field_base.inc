<?php

/**
 * @file
 * c4m_vocab_nace.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_vocab_nace_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_dashboard_key'.
  $field_bases['c4m_dashboard_key'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_dashboard_key',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}

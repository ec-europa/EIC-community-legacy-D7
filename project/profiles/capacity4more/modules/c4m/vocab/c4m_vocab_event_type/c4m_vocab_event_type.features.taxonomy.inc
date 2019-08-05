<?php

/**
 * @file
 * c4m_vocab_event_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4m_vocab_event_type_taxonomy_default_vocabularies() {
  return array(
    'c4m_event_types' => array(
      'name' => 'Event types',
      'machine_name' => 'c4m_event_types',
      'description' => 'Types of events SMED based (via webservice) aswell as created directly in EIC Community',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

<?php
/**
 * @file
 * c4m_content_event_site.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_event_site_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_header_event_site';
  $context->description = 'Context for setting the header inside OG Event Site CT';
  $context->tag = 'cap4more - OG Event Site';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'event_site' => 'event_site',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_event_site-header_name_banner_event_site' => array(
          'module' => 'c4m_content_event_site',
          'delta' => 'header_name_banner_event_site',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the header inside OG Event Site CT');
  t('cap4more - OG Event Site');
  $export['c4m_context_og_header_event_site'] = $context;

  return $export;
}

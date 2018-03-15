<?php

/**
 * @file
 * c4m_content_topic.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_topic_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_topics';
  $context->description = 'Overview page of all Topics';
  $context->tag = 'cap4more - Topics';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_topics:page' => 'c4m_overview_topics:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Topics');
  t('cap4more - Topics');
  $export['c4m_overview_topics'] = $context;

  return $export;
}

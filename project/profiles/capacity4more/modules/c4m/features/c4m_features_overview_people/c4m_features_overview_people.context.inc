<?php

/**
 * @file
 * c4m_features_overview_people.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_people_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_people_list';
  $context->description = 'Overview page of all People, list display';
  $context->tag = 'cap4more - People';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_people:page' => 'c4m_overview_people:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3ea5d2361b53bfac9a8a2c7de319e7ad' => array(
          'module' => 'views',
          'delta' => '3ea5d2361b53bfac9a8a2c7de319e7ad',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'c4m_user-c4m_block_contact_members' => array(
          'module' => 'c4m_user',
          'delta' => 'c4m_block_contact_members',
          'region' => 'sidebar_first_top',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_people-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_people-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-okbRObcVrcftlQAKnMx7ns16BYwkgQpC' => array(
          'module' => 'facetapi',
          'delta' => 'okbRObcVrcftlQAKnMx7ns16BYwkgQpC',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-Bg1WyXIiqObnRZN1Exkukcw9Arm3On07' => array(
          'module' => 'facetapi',
          'delta' => 'Bg1WyXIiqObnRZN1Exkukcw9Arm3On07',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0' => array(
          'module' => 'facetapi',
          'delta' => 'O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-MJe3SI01iJ8jYhG6kFms00hM769g1rl9' => array(
          'module' => 'facetapi',
          'delta' => 'MJe3SI01iJ8jYhG6kFms00hM769g1rl9',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-IWLkW0zcCgq8VdQhLlbJ7YLxOyz4zXTl' => array(
          'module' => 'facetapi',
          'delta' => 'IWLkW0zcCgq8VdQhLlbJ7YLxOyz4zXTl',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all People, list display');
  t('cap4more - People');
  $export['c4m_overview_people_list'] = $context;

  return $export;
}

<?php

/**
 * @file
 * c4m_content_organisation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_organisation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_header_organisation';
  $context->description = 'Context for setting the header inside OG Organisation CT';
  $context->tag = 'cap4more - OG Organisation';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'organisation' => 'organisation',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_organisation-header_name_banner_organisation' => array(
          'module' => 'c4m_content_organisation',
          'delta' => 'header_name_banner_organisation',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the header inside OG Organisation CT');
  t('cap4more - OG Organisation');
  $export['c4m_context_og_header_organisation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_organisations';
  $context->description = 'Overview page of all Organisations';
  $context->tag = 'cap4more - Organisations';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_organisations:page' => 'c4m_overview_organisations:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ef7115aa19b04a910234c06331b00c44' => array(
          'module' => 'views',
          'delta' => 'ef7115aa19b04a910234c06331b00c44',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-pDwQkkFRyuAyJpzVYbF8BA3nQXL5VT1P' => array(
          'module' => 'facetapi',
          'delta' => 'pDwQkkFRyuAyJpzVYbF8BA3nQXL5VT1P',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-KuUeBwgXnNAZL1C4FTlwm6j7gjuavYTy' => array(
          'module' => 'facetapi',
          'delta' => 'KuUeBwgXnNAZL1C4FTlwm6j7gjuavYTy',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-K2D7GVHq40RxVz0IPD6o7IupU9AHGkQ1' => array(
          'module' => 'facetapi',
          'delta' => 'K2D7GVHq40RxVz0IPD6o7IupU9AHGkQ1',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-7AzQiU3dXTkeePI0LKd59q4rhL9dHLg5' => array(
          'module' => 'facetapi',
          'delta' => '7AzQiU3dXTkeePI0LKd59q4rhL9dHLg5',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-3CQPCYa1sRApPJ27ceXsTn0iYqs5r4q6' => array(
          'module' => 'facetapi',
          'delta' => '3CQPCYa1sRApPJ27ceXsTn0iYqs5r4q6',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-MlLMz1yRO5G4gB8gyoi9RVCMPfchd7FN' => array(
          'module' => 'facetapi',
          'delta' => 'MlLMz1yRO5G4gB8gyoi9RVCMPfchd7FN',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-vMMGtBj3zf2hNgMoSddj1CKETgNB2hOj' => array(
          'module' => 'facetapi',
          'delta' => 'vMMGtBj3zf2hNgMoSddj1CKETgNB2hOj',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Organisations');
  t('cap4more - Organisations');
  $export['c4m_overview_organisations'] = $context;

  return $export;
}

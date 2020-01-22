<?php

/**
 * @file
 * c4m_public_access_context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_public_access_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_public_access_sitewide';
  $context->description = 'Sitewide context for anonymous users with publicly accessible sections';
  $context->tag = 'cap4more - Public Access Sitewide';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_features_header-c4m_header_menu' => array(
          'module' => 'c4m_features_header',
          'delta' => 'c4m_header_menu',
          'region' => 'top_menu',
          'weight' => '-83',
        ),
        'c4m_features_footer-c4m_footer_logo' => array(
          'module' => 'c4m_features_footer',
          'delta' => 'c4m_footer_logo',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'c4m_features_footer-c4m_footer_bar' => array(
          'module' => 'c4m_features_footer',
          'delta' => 'c4m_footer_bar',
          'region' => 'footer_top',
          'weight' => '-10',
        ),
        'c4m_features_footer-c4m_footer_menu' => array(
          'module' => 'c4m_features_footer',
          'delta' => 'c4m_footer_menu',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context for anonymous users with publicly accessible sections');
  t('cap4more - Public Access Sitewide');
  $export['c4m_context_public_access_sitewide'] = $context;

  return $export;
}

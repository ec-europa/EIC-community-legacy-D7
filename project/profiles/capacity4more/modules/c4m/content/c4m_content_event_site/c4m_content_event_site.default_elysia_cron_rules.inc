<?php

/**
 * @file
 * c4m_content_event_site.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function c4m_content_event_site_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass();
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'c4m_content_event_site_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['c4m_content_event_site_cron'] = $cron_rule;

  $cron_rule = new stdClass();
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'queue_c4m_event_site_email_subscribers';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['queue_c4m_event_site_email_subscribers'] = $cron_rule;

  return $cron_rules;

}

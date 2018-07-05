<?php

/**
 * @file
 * Drush commands for c4m_web_services module.
 */

/**
 * Implements hook_drush_command().
 */
function c4m_web_services_drush_command() {
  $items = array();

  // Organisation's Taxonomies.
  $items['import-reuters'] = [
    'description' => 'Import reuters codes - c4m_vocab_tr',
    'aliases' => ['ir'],
  ];

  $items['import-topics'] = [
    'description' => 'Import topics - c4m_vocab_topic',
    'aliases' => ['it'],
  ];

  $items['import-naces'] = [
    'description' => 'Import nace codes - c4m_vocab_nace',
    'aliases' => ['in'],
  ];

  $items['import-organisation-types'] = [
    'description' => 'Import organisation types - c4m_vocab_organisation_types',
    'aliases' => ['iot'],
  ];

  $items['import-countries'] = [
    'description' => 'Update keys for countries in Regions & Countries vocabulary - c4m_vocab_geo',
    'aliases' => ['ic'],
  ];

  // User's Taxonomies.
  $items['import-user-types'] = [
    'description' => 'Import user types - c4m_vocab_user_types',
    'aliases' => ['iut'],
  ];

  $items['import-jobtitles'] = [
    'description' => 'Import job titles - c4m_job_titles',
    'aliases' => ['ij'],
  ];

  $items['import-languages'] = [
    'description' => 'Import spoken languages - c4m_vocab_language',
    'aliases' => ['il'],
  ];

  // Import all command.
  $items['import-all'] = [
    'description' => 'Import all taxonomies and Update keys for countries vocabulary.',
    'aliases' => ['iall'],
  ];

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function c4m_web_services_drush_help($section) {
  switch ($section) {
    // Organisation's Taxonomies.
    case 'drush:import-reuters':
      return dt('Import Reuters Codes into Vocabulary Thomson-Reuters codes (c4m_vocab_tr).');
    case 'drush:import-topics':
      return dt('Import Topics into Vocabulary Topics (c4m_vocab_topic).');
    case 'drush:import-naces':
      return dt('Import Nace Codes into Vocabulary NACE codes (c4m_vocab_nace).');
    case 'drush:import-organisation-types':
      return dt('Import Organisation Types into Vocabulary Organisation Types (c4m_vocab_organisation_types).');
    case 'drush:import-countries':
      return dt('Update keys for Countries into Vocabulary Regions & Countries (c4m_vocab_geo).');

    // User's Taxonomies.
    case 'drush:import-user-types':
      return dt('Import User Types into Vocabulary User Type (c4m_vocab_user_types).');
    case 'drush:import-jobtitles':
      return dt('Import Job titles into Vocabulary Job titles (c4m_job_titles).');
    case 'drush:import-languages':
      return dt('Import Spoken languages into Vocabulary Languages (c4m_vocab_language).');

    // Import all command.
    case 'drush:import-all':
      return dt('Import Reuters Codes, Topics, Nace Codes, Organisation Types, Update keys for Countries.');

    default:
      return dt('Import data.');
  }
}

/**
 * General function for running all imports.
 */
function drush_c4m_web_services_import_all() {
  drush_c4m_web_services_import_reuters();
  drush_c4m_web_services_import_topics();
  drush_c4m_web_services_import_naces();
  drush_c4m_web_services_import_organisation_types();
  drush_c4m_web_services_import_countries();
  drush_c4m_web_services_import_user_types();
  drush_c4m_web_services_import_jobtitles();
  drush_c4m_web_services_import_languages();
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_reuters() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/reuters-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_tr');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_topics() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/thematics-topics-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_topic');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_naces() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/naces-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_nace');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_organisation_types() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/organisation-type-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_organisation_types');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_countries() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/iso-3166-countries-en.xml';
  _c4m_web_services_update_countries_keys($file, 'c4m_vocab_geo');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_user_types() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/user-type-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_user_types');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_jobtitles() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/corporate-functions-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_job_titles');
}

/**
 * Remove all old terms and create new terms from XML file.
 */
function drush_c4m_web_services_import_languages() {
  $file = drupal_get_path('module', 'c4m_web_services') . '/import/spoken-languages-en.xml';
  _c4m_web_services_import_vocabulary($file, 'c4m_vocab_language');
}

/**
 * Helper and generic function for importing taxonomy terms from XML file.
 */
function _c4m_web_services_import_vocabulary($file, $vocab_machine_name) {
  // Open XML file.
  $pathInfo = pathinfo($file);
  if ($pathInfo['extension'] != 'xml') {
    throw new Exception('File extension must be XML. Now extension - ' . $pathInfo['extension']);
  }
  $loaded = simplexml_load_file($file) or die("Error: Cannot create object");

  if (empty($loaded->Description->Selector->Group)) {
    if (empty($loaded->Description->Selector->Option)) {
      throw new Exception('The file does not have the right structure');
    }
  }
  // Delete all old terms from c4m_vocab_tr.
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocab_machine_name);
  foreach (taxonomy_get_tree($vocabulary->vid) as $term) {
    taxonomy_term_delete($term->tid);
  }
  drupal_set_message("Vocabulary " . $vocab_machine_name . " was cleared of old terms.");

  $weight = !empty($loaded->Description->Selector->Group)? -count($loaded->Description->Selector->Group) :
    !empty($loaded->Description->Selector->Option)? -count($loaded->Description->Selector->Option): '';
  if (!empty($loaded->Description->Selector->Group)) {
    foreach ($loaded->Description->Selector->Group as $group) {
      if (!empty($group->Value) && !empty($group->Name)) {
        $key = (string)$group->Value;
        $name = (string)$group->Name;
        $parent_object = new stdClass();
        $parent_object->name = $name;
        $parent_object->description = $vocabulary->name . ' ' . $name;
        $parent_object->vid = $vocabulary->vid;
        $parent_object->weight = $weight++;
        $parent_object->c4m_dashboard_key[LANGUAGE_NONE][]['value'] = $key;

        if (taxonomy_term_save($parent_object) &&
          !empty(($option_or_group = $group->Selector->Option) || $option_or_group = $group->Selector->Group)) {
          // Get children aswell.
          c4m_web_services_add_child_term($option_or_group, $parent_object, $vocabulary);
        }
      }
    }
  }
  // Cannot pass the values
  elseif (!empty($loaded->Description->Selector->Option)) {
    foreach ($loaded->Description->Selector->Option as $group) {
      if (!empty($group->Value) && !empty($group->Name)) {
        $key = (string)$group->Value;
        $name = (string)$group->Name;
        $parent_object = new stdClass();
        $parent_object->name = $name;
        $parent_object->description = $vocabulary->name . ' ' . $name;
        $parent_object->vid = $vocabulary->vid;
        $parent_object->weight = $weight++;
        $parent_object->c4m_dashboard_key[LANGUAGE_NONE][]['value'] = $key;
        taxonomy_term_save($parent_object);
      }
    }
  }
  drupal_set_message("Vocabulary " . $vocab_machine_name . " was imported with success.");
}

/**
 * Helper function for adding children recursive.
 */
function c4m_web_services_add_child_term($option_or_group, $parent_object, $vocabulary) {
  foreach ($option_or_group as $child) {
    if (!empty($child->Value) && !empty($child->Name)) {
      $key = (string)$child->Value;
      $name = (string)$child->Name;
      $child_object = new stdClass();
      $child_object->name = $name;
      $child_object->description = $vocabulary->name . ' ' . $name;
      $child_object->vid = $vocabulary->vid;
      $child_object->c4m_dashboard_key[LANGUAGE_NONE][]['value'] = $key;
      $child_object->parent = $parent_object->tid;
      taxonomy_term_save($child_object);
      if (!empty(($option_or_group_child = $child->Selector->Option) || $option_or_group_child = $child->Selector->Group)) {
        c4m_web_services_add_child_term($option_or_group_child, $child_object, $vocabulary);
      }
    }
  }
}

/**
 * Helper function for updating Dashboard Keys for countries.
 */
function _c4m_web_services_update_countries_keys($file, $vocab_machine_name) {
  // Open XML file.
  $pathInfo = pathinfo($file);
  if ($pathInfo['extension'] != 'xml') {
    throw new Exception('File extension must be XML. Now extension - ' . $pathInfo['extension']);
  }
  $loaded = simplexml_load_file($file) or die("Error: Cannot create object");

  if (empty($loaded->Description->Selector->Option)) {
    throw new Exception('The file does not have the right structure');
  }

  $not_found = [];
  $vocab = taxonomy_vocabulary_machine_name_load($vocab_machine_name);
  foreach ($loaded->Description->Selector->Option as $country) {
    $key_dashboard = 'code-3166-1-alpha-3';
    if (!empty($country->$key_dashboard) && !empty($country->Name)) {
      $key = (string)$country->$key_dashboard;
      $name = (string)$country->Name;
      if ($loaded_country = taxonomy_get_term_by_name($name)) {
        foreach ($loaded_country as $tid => $term) {
          if (isset($term->vocabulary_machine_name) && $term->vocabulary_machine_name == $vocab_machine_name) {
            $term->c4m_dashboard_key[LANGUAGE_NONE][0]['value'] = $key;
            taxonomy_term_save($term);
          }
        }
      }
      else {
        $not_found[] = $name;
        $term              = new stdClass();
        $term->name        = $name;
        $term->description = 'Geo: ' . $name;
        $term->vid         =  $vocab->vid;
        $term->weight      = -100;
        $term->c4m_dashboard_key[LANGUAGE_NONE][0]['value'] = $key;
        taxonomy_term_save($term);
      }
    }
  }
  if ($not_found) {
    drupal_set_message(count($not_found) . " countries we're not found in " . $vocab_machine_name . "list" . implode(", ", $not_found));
  }
  else {
    drupal_set_message("Countries vocabulary was updated with success.");
  }
}

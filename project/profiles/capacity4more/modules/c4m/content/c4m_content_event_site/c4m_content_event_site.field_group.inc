<?php

/**
 * @file
 * c4m_content_event_site.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_event_site_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c4m_documents|node|event_site|form';
  $field_group->group_name = 'group_c4m_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '14',
    'children' => array(
      0 => 'c4m_document_agenda',
      1 => 'c4m_document_presentation',
      2 => 'c4m_related_document',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-c4m-documents field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_c4m_documents|node|event_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c4m_medatada|node|event_site|form';
  $field_group->group_name = 'group_c4m_medatada';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '15',
    'children' => array(
      0 => 'c4m_vocab_topic',
      1 => 'c4m_vocab_language',
      2 => 'c4m_vocab_geo',
      3 => 'og_vocabulary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-c4m-medatada field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_c4m_medatada|node|event_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c4m_page_content|node|event_site|form';
  $field_group->group_name = 'group_c4m_page_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page content',
    'weight' => '17',
    'children' => array(
      0 => 'c4m_left_column',
      1 => 'c4m_right_column',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-c4m-page-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_c4m_page_content|node|event_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c4m_related_content|node|event_site|form';
  $field_group->group_name = 'group_c4m_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '16',
    'children' => array(
      0 => 'c4m_related_group',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-c4m-related-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_c4m_related_content|node|event_site|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');
  t('Metadata');
  t('Page content');
  t('Related content');

  return $field_groups;
}

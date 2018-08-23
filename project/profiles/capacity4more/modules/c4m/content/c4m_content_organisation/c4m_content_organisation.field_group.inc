<?php

/**
 * @file
 * c4m_content_organisation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_organisation_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iconbar_comments_views|node|organisation|teaser';
  $field_group->group_name = 'group_iconbar_comments_views';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organisation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icons',
    'weight' => '9',
    'children' => array(
      0 => 'c4m_ds_organisation_members_count',
      1 => 'c4m_ds_group_posts_count',
      2 => 'c4m_ds_group_recommendation_count',
      3 => 'c4m_ds_node_highlight',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Icons',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-iconbar-comments-views field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_iconbar_comments_views|node|organisation|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|organisation|teaser';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organisation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'c4m_looking_for',
      1 => 'c4m_offering',
      2 => 'c4m_qualitative_attributes',
      3 => 'c4m_vocab_topic',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-metadata field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_metadata|node|organisation|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_header_inline|node|organisation|teaser';
  $field_group->group_name = 'group_teaser_header_inline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organisation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header inline',
    'weight' => '0',
    'children' => array(
      0 => 'c4m_og_status',
      1 => 'title',
      2 => 'c4m_ds_organisation_type_icon',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Header inline',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-teaser-header-inline field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_teaser_header_inline|node|organisation|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header inline');
  t('Icons');
  t('Metadata');

  return $field_groups;
}

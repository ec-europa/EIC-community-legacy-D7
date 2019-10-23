<?php

/**
 * @file
 * c4m_user_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_user_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_cv_link'.
  $field_bases['c4m_cv_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_cv_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'c4m_first_name'.
  $field_bases['c4m_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_first_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'c4m_is_deleted'.
  $field_bases['c4m_is_deleted'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_deleted',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'c4m_is_deleted_anonymous'.
  $field_bases['c4m_is_deleted_anonymous'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_deleted_anonymous',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'c4m_is_deleted_by_uid'.
  $field_bases['c4m_is_deleted_by_uid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_deleted_by_uid',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'user',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'c4m_is_invalid_email'.
  $field_bases['c4m_is_invalid_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_invalid_email',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'c4m_is_organisation_user'.
  $field_bases['c4m_is_organisation_user'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_organisation_user',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'c4m_is_spammer'.
  $field_bases['c4m_is_spammer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_is_spammer',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'c4m_last_name'.
  $field_bases['c4m_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_last_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'c4m_linkedin'.
  $field_bases['c4m_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_linkedin',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'c4m_optout_comment'.
  $field_bases['c4m_optout_comment'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_optout_comment',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'discussion' => 'discussion',
          'document' => 'document',
          'event' => 'event',
          'wiki_page' => 'wiki_page',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'c4m_optout_group'.
  $field_bases['c4m_optout_group'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_optout_group',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'group' => 'group',
          'project' => 'project',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'c4m_optout_node'.
  $field_bases['c4m_optout_node'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_optout_node',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'discussion' => 'discussion',
          'document' => 'document',
          'event' => 'event',
          'wiki_page' => 'wiki_page',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'c4m_optout_taxonomy_term'.
  $field_bases['c4m_optout_taxonomy_term'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_optout_taxonomy_term',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'c4m_vocab_category_9' => 'c4m_vocab_category_9',
          'c4m_vocab_category_10' => 'c4m_vocab_category_10',
          'c4m_vocab_category_11' => 'c4m_vocab_category_11',
          'c4m_vocab_category_12' => 'c4m_vocab_category_12',
          'c4m_vocab_category_13' => 'c4m_vocab_category_13',
          'c4m_vocab_category_14' => 'c4m_vocab_category_14',
          'c4m_vocab_category_15' => 'c4m_vocab_category_15',
          'c4m_vocab_category_16' => 'c4m_vocab_category_16',
          'c4m_vocab_category_17' => 'c4m_vocab_category_17',
          'c4m_vocab_category_18' => 'c4m_vocab_category_18',
          'c4m_vocab_category_19' => 'c4m_vocab_category_19',
          'c4m_vocab_category_20' => 'c4m_vocab_category_20',
          'c4m_vocab_category_21' => 'c4m_vocab_category_21',
          'c4m_vocab_category_22' => 'c4m_vocab_category_22',
          'c4m_vocab_category_23' => 'c4m_vocab_category_23',
          'c4m_vocab_category_24' => 'c4m_vocab_category_24',
          'c4m_vocab_category_25' => 'c4m_vocab_category_25',
          'c4m_vocab_category_31' => 'c4m_vocab_category_31',
          'c4m_vocab_date' => 'c4m_vocab_date',
          'c4m_vocab_document_type' => 'c4m_vocab_document_type',
          'c4m_vocab_geo' => 'c4m_vocab_geo',
          'c4m_vocab_language' => 'c4m_vocab_language',
          'c4m_vocab_tag_9' => 'c4m_vocab_tag_9',
          'c4m_vocab_tag_10' => 'c4m_vocab_tag_10',
          'c4m_vocab_tag_11' => 'c4m_vocab_tag_11',
          'c4m_vocab_tag_12' => 'c4m_vocab_tag_12',
          'c4m_vocab_tag_13' => 'c4m_vocab_tag_13',
          'c4m_vocab_tag_14' => 'c4m_vocab_tag_14',
          'c4m_vocab_tag_15' => 'c4m_vocab_tag_15',
          'c4m_vocab_tag_16' => 'c4m_vocab_tag_16',
          'c4m_vocab_tag_17' => 'c4m_vocab_tag_17',
          'c4m_vocab_tag_18' => 'c4m_vocab_tag_18',
          'c4m_vocab_tag_19' => 'c4m_vocab_tag_19',
          'c4m_vocab_tag_20' => 'c4m_vocab_tag_20',
          'c4m_vocab_tag_21' => 'c4m_vocab_tag_21',
          'c4m_vocab_tag_22' => 'c4m_vocab_tag_22',
          'c4m_vocab_tag_23' => 'c4m_vocab_tag_23',
          'c4m_vocab_tag_24' => 'c4m_vocab_tag_24',
          'c4m_vocab_tag_25' => 'c4m_vocab_tag_25',
          'c4m_vocab_tag_31' => 'c4m_vocab_tag_31',
          'c4m_vocab_theme' => 'c4m_vocab_theme',
          'c4m_vocab_topic' => 'c4m_vocab_topic',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'c4m_unsubscribe_hash'.
  $field_bases['c4m_unsubscribe_hash'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_unsubscribe_hash',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'c4m_user_dashboard_id'.
  $field_bases['c4m_user_dashboard_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_user_dashboard_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'c4m_user_types'.
  $field_bases['c4m_user_types'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_user_types',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'c4m_vocab_user_types',
          'parent' => 0,
          'depth' => '',
        ),
      ),
      'options_list_callback' => 'content_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}

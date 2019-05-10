<?php

/**
 * @file
 * c4m_content_organisation.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_content_organisation_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_organisation-comment_body'.
  $field_instances['comment-comment_node_organisation-comment_body'] = array(
    'bundle' => 'comment_node_organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_banner'.
  $field_instances['node-organisation-c4m_banner'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Banner to be used on organisation landing page	',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'c4m_field_media',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_banner',
    'label' => 'Banner Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'banners/organisation',
      'file_extensions' => 'png gif jpg jpeg bmp',
      'max_filesize' => '10 MB',
      'max_resolution' => '',
      'min_resolution' => '940x300',
      'title_field' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_insert' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_2' => 'media_default--media_browser_2',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'upload' => 'upload',
        ),
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 0,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => 0,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
      ),
      'type' => 'media_generic',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_body'.
  $field_instances['node-organisation-c4m_body'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe the organisation	',
    'display' => array(
      'activity_global' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'activity_group' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'c4m_related' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'featured_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'inthe_picture_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'library' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 0,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 200,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 2,
      ),
      'upcoming_event' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_body',
    'label' => 'Teaser',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 0,
          'full_html' => 0,
          'mail' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'summary_display' => 'default',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_label_summary' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_summary' => '',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
        'summary_display' => 'default',
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_contact_persons'.
  $field_instances['node-organisation-c4m_contact_persons'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Manual reference to users which are contact persons for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 22,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'use_content_language' => 1,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_contact_persons',
    'label' => 'Contact persons',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_customers'.
  $field_instances['node-organisation-c4m_customers'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Customers of the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 30,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_customers',
    'label' => 'Customers',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'c4m_paragraph_map' => -1,
        'c4m_paragraph_partner' => 'c4m_paragraph_partner',
        'c4m_paragraph_system_block' => -1,
        'c4m_paragraph_text' => -1,
        'c4m_paragraph_twitter' => -1,
      ),
      'bundle_weights' => array(
        'c4m_paragraph_map' => 2,
        'c4m_paragraph_partner' => 3,
        'c4m_paragraph_system_block' => 4,
        'c4m_paragraph_text' => 5,
        'c4m_paragraph_twitter' => 6,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Customer',
      'title_multiple' => 'Customers',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_date_est'.
  $field_instances['node-organisation-c4m_date_est'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Period in which the organisation is active.',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 23,
      ),
      'group_dashboard' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_date_est',
    'label' => 'Date of establishment',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-200:+1',
      ),
      'type' => 'date_popup',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_email'.
  $field_instances['node-organisation-c4m_email'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Contact email address',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 20,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_facebook'.
  $field_instances['node-organisation-c4m_facebook'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Facebook page for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_facebook',
    'label' => 'Facebook',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '[node:title] Facebook page',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_group_welcome_message'.
  $field_instances['node-organisation-c4m_group_welcome_message'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_group_welcome_message',
    'label' => 'Organisation welcome message',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 'mail',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_icon'.
  $field_instances['node-organisation-c4m_icon'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activity_global' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'activity_group' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'c4m_related' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'c4m_field_media',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'featured_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'inthe_picture_block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'library' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'upcoming_event' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_icon',
    'label' => 'Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/organisation',
      'file_extensions' => 'png gif jpg jpeg bmp',
      'max_filesize' => '10 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_insert' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_2' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'upload' => 'upload',
        ),
        'manualcrop_crop_info' => TRUE,
        'manualcrop_default_crop_area' => TRUE,
        'manualcrop_enable' => FALSE,
        'manualcrop_inline_crop' => FALSE,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => TRUE,
        'manualcrop_keyboard' => TRUE,
        'manualcrop_maximize_default_crop_area' => FALSE,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => FALSE,
      ),
      'type' => 'media_generic',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_left_column'.
  $field_instances['node-organisation-c4m_left_column'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Contents of the left column on the organisation landing page.',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 32,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_left_column',
    'label' => 'Left column content',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'c4m_paragraph_map' => 'c4m_paragraph_map',
        'c4m_paragraph_partner' => -1,
        'c4m_paragraph_system_block' => 'c4m_paragraph_system_block',
        'c4m_paragraph_text' => 'c4m_paragraph_text',
        'c4m_paragraph_twitter' => 'c4m_paragraph_twitter',
      ),
      'bundle_weights' => array(
        'c4m_paragraph_map' => -7,
        'c4m_paragraph_partner' => -6,
        'c4m_paragraph_system_block' => -10,
        'c4m_paragraph_text' => -9,
        'c4m_paragraph_twitter' => -8,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Component',
      'title_multiple' => 'Components',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_link'.
  $field_instances['node-organisation-c4m_link'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Public website for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_link',
    'label' => 'Website',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '[node:title] Website',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_linkedin'.
  $field_instances['node-organisation-c4m_linkedin'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'LinkedIn page for the organisation	',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 13,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_label',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_linkedin',
    'label' => 'LinkedIn',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '[node:title] LinkedIn page',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_location_address'.
  $field_instances['node-organisation-c4m_location_address'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Organisation main location',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 16,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_location_address',
    'label' => 'Location Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          'address' => 'address',
          'name-oneline' => 'name-oneline',
          'address-optional' => 'address-optional',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_location_map'.
  $field_instances['node-organisation-c4m_location_map'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Map corresponding to the organisations address	',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'geofield',
        'settings' => array(
          'data' => 'full',
        ),
        'type' => 'geofield_wkt',
        'weight' => 17,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'leaflet',
        'settings' => array(
          'height' => 200,
          'icon' => array(
            'html' => '',
            'htmlClass' => '',
            'iconAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'iconImageStyle' => '',
            'iconSize' => array(
              'x' => '',
              'y' => '',
            ),
            'iconType' => 'marker',
            'iconUrl' => '',
            'popupAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowUrl' => '',
          ),
          'leaflet_map' => 'OSM Mapnik',
          'popup' => array(
            'show' => 0,
            'text' => '',
          ),
          'vector_display' => array(
            'clickable' => 0,
            'color' => '',
            'dashArray' => '',
            'fill' => 0,
            'fillColor' => '',
            'fillOpacity' => '',
            'opacity' => '',
            'stroke' => 0,
            'stroke_override' => 0,
            'weight' => '',
          ),
          'zoom' => array(
            'initialZoom' => 16,
            'maxZoom' => 18,
            'minZoom' => 1,
            'scrollWheelZoom' => 1,
          ),
        ),
        'type' => 'geofield_leaflet',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_location_map',
    'label' => 'Location Map',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geocoder',
      'settings' => array(
        'delta_handling' => 'default',
        'geocoder_field' => 'c4m_location_address',
        'geocoder_handler' => 'openstreetmap_nominatim',
        'handler_settings' => array(
          'google' => array(
            'all_results' => 0,
            'biasing' => array(
              'bounds' => '',
              'components' => '',
              'region' => '',
            ),
            'geometry_type' => 'point',
            'reject_results' => array(
              'APPROXIMATE' => 0,
              'GEOMETRIC_CENTER' => 0,
              'RANGE_INTERPOLATED' => 0,
              'ROOFTOP' => 0,
            ),
          ),
        ),
      ),
      'type' => 'geocoder',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_looking_for'.
  $field_instances['node-organisation-c4m_looking_for'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Services and Products looking for ',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 27,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'c4m_content_topic',
        'settings' => array(
          'display' => 'all',
          'glue' => ', ',
          'link' => 0,
          'link_organisations' => 1,
          'separator' => ', ',
          'wrap' => 'none',
        ),
        'type' => 'term_reference_checked_inline_tree',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_looking_for',
    'label' => 'Looking for',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_media'.
  $field_instances['node-organisation-c4m_media'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Small image used in lists',
    'display' => array(
      'block_list' => array(
        'label' => 'hidden',
        'module' => 'c4m_field_media',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'thumbnail',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'c4m_field_media',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'c4m_field_media',
        'settings' => array(
          'image_link' => 'purl_og_dashboard',
          'image_style' => 'c4m_image_medium',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_media',
    'label' => 'Thumbnail image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/organisation',
      'file_extensions' => 'png gif jpg jpeg bmp',
      'max_filesize' => '10 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_insert' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_2' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'upload' => 'upload',
        ),
        'manualcrop_crop_info' => TRUE,
        'manualcrop_default_crop_area' => TRUE,
        'manualcrop_enable' => FALSE,
        'manualcrop_inline_crop' => FALSE,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => TRUE,
        'manualcrop_keyboard' => TRUE,
        'manualcrop_maximize_default_crop_area' => FALSE,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => FALSE,
      ),
      'type' => 'media_generic',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_offering'.
  $field_instances['node-organisation-c4m_offering'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Services and Products offered',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 26,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'c4m_content_topic',
        'settings' => array(
          'display' => 'all',
          'glue' => ', ',
          'link' => 0,
          'link_organisations' => 1,
          'separator' => ', ',
          'wrap' => 'none',
        ),
        'type' => 'term_reference_checked_inline_tree',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_offering',
    'label' => 'Offering',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_og_status'.
  $field_instances['node-organisation-c4m_og_status'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 'pending',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_list' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_og_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_organisation_dashboard_id'.
  $field_instances['node-organisation-c4m_organisation_dashboard_id'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The unique ID of the organisation in the SME Dashboard',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_organisation_dashboard_id',
    'label' => 'Dashboard ID',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 'mail',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_organisation_size'.
  $field_instances['node-organisation-c4m_organisation_size'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicate the size of the organisation	',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'group_dashboard' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_organisation_size',
    'label' => 'Organisation size',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_organisations_type'.
  $field_instances['node-organisation-c4m_organisations_type'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicate the type(s) of the organisation	',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_organisations_type',
    'label' => 'Organisation type(s)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_partners'.
  $field_instances['node-organisation-c4m_partners'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Partners of the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 31,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_partners',
    'label' => 'Partners',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'c4m_paragraph_map' => -1,
        'c4m_paragraph_partner' => 'c4m_paragraph_partner',
        'c4m_paragraph_system_block' => -1,
        'c4m_paragraph_text' => -1,
        'c4m_paragraph_twitter' => -1,
      ),
      'bundle_weights' => array(
        'c4m_paragraph_map' => 2,
        'c4m_paragraph_partner' => 3,
        'c4m_paragraph_system_block' => 4,
        'c4m_paragraph_text' => 5,
        'c4m_paragraph_twitter' => 6,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Partner',
      'title_multiple' => 'Partners',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_phone'.
  $field_instances['node-organisation-c4m_phone'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'One or more phone numbers for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 21,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'telephone',
        'settings' => array(
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_phone',
    'label' => 'Phone',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_product_service_type'.
  $field_instances['node-organisation-c4m_product_service_type'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicate whether the product/service offered is B2C and/or B2B',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_product_service_type',
    'label' => 'Product/service type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_project_tag_line'.
  $field_instances['node-organisation-c4m_project_tag_line'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 34,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_project_tag_line',
    'label' => 'Tag line',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 'mail',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_qualitative_attributes'.
  $field_instances['node-organisation-c4m_qualitative_attributes'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Labels, credits, awards, prizes, etc.',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 29,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 0,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 200,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_qualitative_attributes',
    'label' => 'Qualitative attributes',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 'mail',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_right_column'.
  $field_instances['node-organisation-c4m_right_column'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Contents of the right column on the organisation landing page.',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 33,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_right_column',
    'label' => 'Right column content',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'c4m_paragraph_map' => 'c4m_paragraph_map',
        'c4m_paragraph_partner' => -1,
        'c4m_paragraph_system_block' => 'c4m_paragraph_system_block',
        'c4m_paragraph_text' => 'c4m_paragraph_text',
        'c4m_paragraph_twitter' => 'c4m_paragraph_twitter',
      ),
      'bundle_weights' => array(
        'c4m_paragraph_map' => -7,
        'c4m_paragraph_partner' => -6,
        'c4m_paragraph_system_block' => -10,
        'c4m_paragraph_text' => -9,
        'c4m_paragraph_twitter' => -8,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Component',
      'title_multiple' => 'Components',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_target_markets'.
  $field_instances['node-organisation-c4m_target_markets'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Select the target market(s) for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 25,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_target_markets',
    'label' => 'Target markets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_twitter'.
  $field_instances['node-organisation-c4m_twitter'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Twitter profile for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 11,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_label',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_twitter',
    'label' => 'Twitter',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '[node:title] Twitter stream',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_vocab_geo'.
  $field_instances['node-organisation-c4m_vocab_geo'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Country(ies) the organisation is based in',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_vocab_geo',
    'label' => 'Countries based in',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_vocab_geo_selling'.
  $field_instances['node-organisation-c4m_vocab_geo_selling'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Country(ies) the organisation is selling to',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 19,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_vocab_geo_selling',
    'label' => 'Countries selling to',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_vocab_topic'.
  $field_instances['node-organisation-c4m_vocab_topic'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Topics',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 28,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'c4m_vocab_widget',
        'settings' => array(),
        'type' => 'term_reference_tree_hierarchical',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'c4m_content_topic',
        'settings' => array(
          'display' => 'all',
          'glue' => ', ',
          'link' => 0,
          'link_organisations' => 1,
          'separator' => ', ',
          'wrap' => 'none',
        ),
        'type' => 'term_reference_checked_inline_tree',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_vocab_topic',
    'label' => 'Topic(s)',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'c4m_vocab_widget',
      'settings' => array(),
      'type' => 'c4m_taxonomy_reference',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-organisation-c4m_youtube'.
  $field_instances['node-organisation-c4m_youtube'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'YouTube channel for the organisation',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 12,
      ),
      'group_dashboard' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'c4m_youtube',
    'label' => 'YouTube',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '[node:title] YouTube channel',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-organisation-field_c4m_about_us'.
  $field_instances['node-organisation-field_c4m_about_us'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_c4m_about_us',
    'label' => 'About us',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -50,
            ),
            'full_html' => array(
              'weight' => -49,
            ),
            'mail' => array(
              'weight' => -47,
            ),
            'plain_text' => array(
              'weight' => -48,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-organisation-field_c4m_cities_based_in'.
  $field_instances['node-organisation-field_c4m_cities_based_in'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_c4m_cities_based_in',
    'label' => 'Cities based in',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'mail' => 'mail',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'mail' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-organisation-group_group'.
  $field_instances['node-organisation-group_group'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Determine if this is an OG group.',
    'display' => array(
      'block_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(
          'field_name' => FALSE,
        ),
        'type' => 'og_group_subscribe',
        'weight' => 5,
      ),
      'group_dashboard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'display_label' => 1,
    'entity_type' => 'node',
    'field_name' => 'group_group',
    'label' => 'Group',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_group_subscribe',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_group_subscribe',
      ),
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'og_hide' => TRUE,
      ),
      'type' => 'options_onoff',
      'weight' => 37,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Banner Image');
  t('Banner to be used on organisation landing page	');
  t('Cities based in');
  t('Comment');
  t('Contact email address');
  t('Contact persons');
  t('Contents of the left column on the organisation landing page.');
  t('Contents of the right column on the organisation landing page.');
  t('Countries based in');
  t('Countries selling to');
  t('Country(ies) the organisation is based in');
  t('Country(ies) the organisation is selling to');
  t('Customers');
  t('Customers of the organisation');
  t('Dashboard ID');
  t('Date of establishment');
  t('Describe the organisation	');
  t('Determine if this is an OG group.');
  t('Email');
  t('Facebook');
  t('Facebook page for the organisation');
  t('Group');
  t('Icon');
  t('Indicate the size of the organisation	');
  t('Indicate the type(s) of the organisation	');
  t('Indicate whether the product/service offered is B2C and/or B2B');
  t('Labels, credits, awards, prizes, etc.');
  t('Left column content');
  t('LinkedIn');
  t('LinkedIn page for the organisation	');
  t('Location Address');
  t('Location Map');
  t('Looking for');
  t('Manual reference to users which are contact persons for the organisation');
  t('Map corresponding to the organisations address	');
  t('Offering');
  t('One or more phone numbers for the organisation');
  t('Organisation main location');
  t('Organisation size');
  t('Organisation type(s)');
  t('Organisation welcome message');
  t('Partners');
  t('Partners of the organisation');
  t('Period in which the organisation is active.');
  t('Phone');
  t('Product/service type');
  t('Public website for the organisation');
  t('Qualitative attributes');
  t('Right column content');
  t('Select the target market(s) for the organisation');
  t('Services and Products looking for ');
  t('Services and Products offered');
  t('Small image used in lists');
  t('Status');
  t('Tag line');
  t('Target markets');
  t('Teaser');
  t('The unique ID of the organisation in the SME Dashboard');
  t('Thumbnail image');
  t('Topic(s)');
  t('Topics');
  t('Twitter');
  t('Twitter profile for the organisation');
  t('Website');
  t('YouTube');
  t('YouTube channel for the organisation');

  return $field_instances;
}

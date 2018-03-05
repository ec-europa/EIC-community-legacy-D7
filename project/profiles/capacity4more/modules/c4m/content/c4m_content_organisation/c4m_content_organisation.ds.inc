<?php

/**
 * @file
 * c4m_content_organisation.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_organisation_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|organisation|block_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'organisation';
  $ds_fieldsetting->view_mode = 'block_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_og_dashboard',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Owned by',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'text-muted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_organisation_type_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|organisation|block_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|organisation|group_dashboard';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'organisation';
  $ds_fieldsetting->view_mode = 'group_dashboard';
  $ds_fieldsetting->settings = array(
    'c4m_field_location_city_country' => array(
      'weight' => '11',
      'label' => 'above',
      'format' => 'in @city (@country)',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Location',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
          'lbw-cl' => 'label-above',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_contact_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_date_est' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h3',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'date clearfix',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-facebook"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-social-media-item',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-link"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-social-media-item',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_linkedin' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-linkedin"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-social-media-item',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_looking_for' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_offering' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_organisation_size' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_organisations_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_product_service_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'lbw-el' => 'h3',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_qualitative_attributes' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_target_markets' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_twitter' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-twitter"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-social-media-item',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_vocab_geo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_geo_selling' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Topics',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_youtube' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<i class="fa fa-youtube"></i>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-social-media-item',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|organisation|group_dashboard'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|organisation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'organisation';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'user',
    ),
    'c4m_ds_type_insert_action' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|organisation|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_organisation_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|organisation|block_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'organisation';
  $ds_layout->view_mode = 'block_list';
  $ds_layout->layout = 'c4m_ds_3_9_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'c4m_ds_organisation_type_icon',
        2 => 'title',
        3 => 'c4m_og_status',
        4 => 'c4m_user_first_and_last_name',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'c4m_ds_organisation_type_icon' => 'right',
      'title' => 'right',
      'c4m_og_status' => 'right',
      'c4m_user_first_and_last_name' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|organisation|block_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|organisation|group_dashboard';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'organisation';
  $ds_layout->view_mode = 'group_dashboard';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_link',
        1 => 'c4m_facebook',
        2 => 'c4m_twitter',
        3 => 'c4m_youtube',
        4 => 'c4m_linkedin',
        5 => 'c4m_phone',
        6 => 'c4m_email',
        7 => 'c4m_contact_persons',
        8 => 'c4m_organisation_size',
        9 => 'c4m_organisations_type',
        10 => 'c4m_date_est',
        11 => 'c4m_field_location_city_country',
        12 => 'c4m_location_map',
        13 => 'c4m_vocab_geo',
        14 => 'c4m_vocab_geo_selling',
        15 => 'c4m_product_service_type',
        16 => 'c4m_target_markets',
        17 => 'c4m_offering',
        18 => 'c4m_looking_for',
        19 => 'c4m_vocab_topic',
        20 => 'c4m_qualitative_attributes',
      ),
    ),
    'fields' => array(
      'c4m_link' => 'ds_content',
      'c4m_facebook' => 'ds_content',
      'c4m_twitter' => 'ds_content',
      'c4m_youtube' => 'ds_content',
      'c4m_linkedin' => 'ds_content',
      'c4m_phone' => 'ds_content',
      'c4m_email' => 'ds_content',
      'c4m_contact_persons' => 'ds_content',
      'c4m_organisation_size' => 'ds_content',
      'c4m_organisations_type' => 'ds_content',
      'c4m_date_est' => 'ds_content',
      'c4m_field_location_city_country' => 'ds_content',
      'c4m_location_map' => 'ds_content',
      'c4m_vocab_geo' => 'ds_content',
      'c4m_vocab_geo_selling' => 'ds_content',
      'c4m_product_service_type' => 'ds_content',
      'c4m_target_markets' => 'ds_content',
      'c4m_offering' => 'ds_content',
      'c4m_looking_for' => 'ds_content',
      'c4m_vocab_topic' => 'ds_content',
      'c4m_qualitative_attributes' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|organisation|group_dashboard'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|organisation|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'organisation';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_2col_icon_left_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'c4m_user_first_and_last_name',
        1 => 'title',
        2 => 'c4m_ds_type_insert_action',
        3 => 'c4m_ds_content_type_icon',
        4 => 'c4m_ds_content_type_label',
      ),
      'right' => array(
        5 => 'c4m_media',
        6 => 'c4m_email',
        7 => 'c4m_offering',
        8 => 'c4m_looking_for',
        9 => 'c4m_vocab_topic',
        10 => 'c4m_qualitative_attributes',
      ),
    ),
    'fields' => array(
      'c4m_user_first_and_last_name' => 'header',
      'title' => 'header',
      'c4m_ds_type_insert_action' => 'header',
      'c4m_ds_content_type_icon' => 'header',
      'c4m_ds_content_type_label' => 'header',
      'c4m_media' => 'right',
      'c4m_email' => 'right',
      'c4m_offering' => 'right',
      'c4m_looking_for' => 'right',
      'c4m_vocab_topic' => 'right',
      'c4m_qualitative_attributes' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|organisation|teaser'] = $ds_layout;

  return $export;
}

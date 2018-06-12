<?php

/**
 * @file
 * c4m_user_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_user_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|full';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'c4m_user_author_thumb_image',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'user_with_icon',
    ),
    'c4m_user_contact_link' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_user_my_groups' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_user_my_event_sites' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
          'lb' => 'Regions',
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics',
        ),
      ),
    ),
    'c4m_vocab_topic_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics & subtopics',
        ),
      ),
    ),
  );
  $export['user|user|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_user_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|full';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
        1 => 'group_user_meta',
        3 => 'group_user_interests',
        4 => 'group_user_data',
        5 => 'c4m_vocab_topic',
        6 => 'group_user_expertise',
        7 => 'c4m_vocab_geo',
        8 => 'c4m_user_first_and_last_name',
        9 => 'group_user_about',
        10 => 'c4m_vocab_topic_expertise',
        12 => 'c4m_user_types',
        13 => 'c4m_body',
        14 => 'c4m_vocab_language',
        15 => 'c4m_facebook',
        16 => 'c4m_twitter',
        17 => 'c4m_linkedin',
        18 => 'c4m_cv_link',
        19 => 'c4m_user_contact_link',
      ),
      'right' => array(
        2 => 'c4m_ds_user_my_event_sites',
        11 => 'c4m_ds_user_my_groups',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'group_user_meta' => 'left',
      'c4m_ds_user_my_event_sites' => 'right',
      'group_user_interests' => 'left',
      'group_user_data' => 'left',
      'c4m_vocab_topic' => 'left',
      'group_user_expertise' => 'left',
      'c4m_vocab_geo' => 'left',
      'c4m_user_first_and_last_name' => 'left',
      'group_user_about' => 'left',
      'c4m_vocab_topic_expertise' => 'left',
      'c4m_ds_user_my_groups' => 'right',
      'c4m_user_types' => 'left',
      'c4m_body' => 'left',
      'c4m_vocab_language' => 'left',
      'c4m_facebook' => 'left',
      'c4m_twitter' => 'left',
      'c4m_linkedin' => 'left',
      'c4m_cv_link' => 'left',
      'c4m_user_contact_link' => 'left',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['user|user|full'] = $ds_layout;

  return $export;
}

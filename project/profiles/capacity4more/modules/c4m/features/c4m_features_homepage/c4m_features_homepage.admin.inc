<?php

/**
 * @file
 * Admin forms.
 */

/**
 * The admin form.
 */
function c4m_features_homepage_admin_settings($form) {
  $form['c4m_features_homepage_title'] = array(
    '#title' => t('Video block title'),
    '#type' => 'textfield',
    '#default_value' => variable_get('c4m_features_homepage_title', 'You\'re not yet a member of any group.'),
    '#required' => 1,
    '#description' => t('Title of the video.'),
  );

  $form['c4m_features_homepage_description'] = array(
    '#title' => t('Video block description'),
    '#type' => 'textfield',
    '#default_value' => variable_get('c4m_features_homepage_description', 'Learn how to learn and share knowledge by joining a group'),
    '#required' => 1,
    '#description' => t('Description of the video.'),
  );

  $form['c4m_features_homepage_video'] = array(
    '#title' => t('Video URL'),
    '#type' => 'textfield',
    '#default_value' => variable_get('c4m_features_homepage_video', 'http://youtu.be/ISNcUnbQkVQ'),
    '#required' => 1,
    '#description' => t('Provide the "Share" url of the video you want to embed.'),
  );

  $form = system_settings_form($form);
  $form['#validate'][] = 'c4m_features_homepage_admin_settings_validate';
  return $form;
}

/**
 * Form validation handler for the text fields in order to check if video is link.
 */
function c4m_features_homepage_admin_settings_validate($form, &$form_state) {
  $video_link = !empty($form_state['values']['c4m_features_homepage_video'])?
    $form_state['values']['c4m_features_homepage_video'] : '';
  if (!valid_url($video_link, TRUE)) {
    form_set_error('c4m_features_homepage_video', t("Please enter a valid URL for Video URL."));
  }
}

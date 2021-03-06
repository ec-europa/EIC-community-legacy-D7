<?php

/**
 * @file
 * Ctools plugin definition for weekly interval.
 */

$plugin = array(
  'title' => t('Weekly'),
  'description' => t('Send Message via weekly digest.'),
  'class' => 'MessageDigestWeek',
  'view_modes' => array(
    'message_notify_weekly_digest' => array('label' => t('Notify - Weekly digest')),
  ),
);

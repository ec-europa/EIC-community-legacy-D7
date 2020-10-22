<?php

/**
 * @file
 * Plugin to add the embedded code for the twitter feed in panels.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Twitter embed feed'),
  'description' => t('Renders the embedded code for the twitter feed'),
  'category' => t('C4M'),
  'defaults' => array(
    'title' => FALSE,
    'description' => FALSE,
    'twitter_url'  => "https://twitter.com/EUeic?ref_src=twsrc%5Etfw",
    'twitter_limit' => "5",
    'twitter_width' => "600",
  ),
);

/**
 * Render callback.
 */
function c4m_features_homepage_twitter_feed_content_type_render($subtype, $conf, $args, $context) {;
  $block = new stdClass();
  $block->title = '';
  $block->module = 'c4m_features_homepage';
  $block->content =   '<a class="twitter-timeline"  data-width="'.$conf['twitter_width'].'" data-tweet-limit="'.$conf['twitter_limit'].'" href="'.$conf['twitter_url'].'">Tweets by EUeic</a> <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>';

  return $block;
}

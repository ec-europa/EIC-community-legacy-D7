<?php
/**
 * @file
 * Migrate class to create group photos and attach them to an album.
 */

/**
 * Class C4mDemoContentCreatePhotos
 */
class C4mDemoContentCreatePhotos extends C4mDemoContentCreateOgContent {
  public $bundle = 'photo';

  /**
   * CSV column mapping.
   *
   * @var array
   */
  public $csvColumns = array(
    array('id', 'ID'),
    array('gallery', 'Album'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('image', 'Image'),
    array('group_map', 'Group'),
    array('group_type', 'Group Type'),
    array('uid', 'UID'),
  );

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();

    $this->dependencies[] = 'C4mDemoContentCreatePhotoalbums';

    $this->addFieldMapping('c4m_body', 'body');

    $this->addFieldMapping('node_gallery_ref_1', 'gallery')
      ->sourceMigration('C4mDemoContentCreatePhotoalbums');

    $this->addFieldMapping('c4m_media', 'image')
      ->separator(';');
    $this->addFieldMapping('c4m_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('c4m_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'c4m_demo_content') . '/images');
    $this->addFieldMapping('c4m_media:destination_dir', 'destination');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
  }
}
<?php
/**
 * @file
 * Prints out a list of all the public event sites.
 */
?>
<?php
$classes = ' pane--more';
?>

<div class="sidebarblock my-projects<?php print $classes; ?>">
  <h2 class="sidebarblock__title closely">
      <?php print t('Upcoming Events')  ?>
  </h2>
  <?php print $event_sites; ?>

  <div class="sidebarblock__viewmore">
    <a class="see-more-link" href="<?php print $link; ?>">
      <?php print t('Show more') ?> <i class="fa fa-chevron-right"></i>
    </a>
  </div>
</div>

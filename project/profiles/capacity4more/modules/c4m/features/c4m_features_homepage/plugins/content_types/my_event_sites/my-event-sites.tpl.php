<?php
/**
 * @file
 * Prints out a list of all the groups the user is member of.
 */
?>
<?php
$classes = '';
if ($display_see_more) {
  $classes = ' pane--more';
}
?>

<div class="sidebarblock my-projects<?php print $classes; ?>">
  <h2 class="sidebarblock__title closely">
    <?php if (user_is_logged_in()): ?>
      <?php print t('My Event Sites') ?>
    <?php else: ?>
      <?php print t('Public Event Sites')  ?>
    <?php endif; ?>
  </h2>
  <?php print $event_sites; ?>

  <?php if ($display_see_more): ?>
    <div class="sidebarblock__viewmore">
      <a class="see-more-link" href="<?php print $link; ?>">
        <?php print t('Show more') ?> <i class="fa fa-chevron-right"></i>
      </a>
    </div>
  <?php endif; ?>
</div>

<?php

/**
 * @file
 * Template to show a welcome message to anonymous users, with a link to log in
 * using EU Login.
 *
 * Available variables:
 *
 * Available variables:
 * - $variables['header']: Message to show in an h1 to visitors.
 * - $variables['cta_1']: Call-to-action to accompany the welcome text.
 * - $variables['cta-2']: Call-to-action to accompany the welcome text.
 *
 * @see kapablo_preprocess_page()
 * @ingroup themeable
 */
?>

<div class="anonymous-welcome">
  <?php if ($variables['warning_message']): ?>
    <?php print $variables['warning_message']; ?>
  <?php else: ?>
    <?php if ($variables['header']): ?>
      <h1><?php print $variables['header']; ?></h1>
    <?php endif; ?>
    <?php if ($variables['sub_header']): ?>
      <?php print $variables['sub_header']; ?>
    <?php endif; ?>
  <?php endif; ?>

  <div class="cta">
    <?php if ($variables['cta_1']): ?>
      <?php print $variables['cta_1']; ?>
    <?php endif; ?>
    <?php if ($variables['cta_2']): ?>
      <?php print $variables['cta_2']; ?>
    <?php endif; ?>
  </div>
</div>

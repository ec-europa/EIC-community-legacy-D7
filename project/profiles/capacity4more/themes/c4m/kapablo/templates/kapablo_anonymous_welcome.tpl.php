<?php

/**
 * @file
 * Template to show a welcome message to anonymous users, with a link to log in
 * using EU Login.
 *
 * Available variables:
 *
 * Available variables:
 * - $variables['welcome_message']: Message to show in heading 1 to visitors.
 * - $variables['cta']: Call-to-action to accompany the welcome text.
 *
 * @see kapablo_preprocess_page()
 * @ingroup themeable
 */
?>

<?php if ($variables['warning_message']): ?>
  <h1><?php print $variables['warning_message']; ?></h1>

  <?php else: ?>

  <?php if ($variables['welcome_message']): ?>
        <h1><?php print $variables['welcome_message']; ?></h1>
  <?php endif; ?>

<?php endif; ?>

<?php if ($variables['cta']): ?>
  <div class="welcome-cta"><?php print $variables['cta']; ?></div>
<?php endif; ?>

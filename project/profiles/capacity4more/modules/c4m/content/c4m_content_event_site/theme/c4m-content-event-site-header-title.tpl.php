<?php

/**
 * @file
 * Template for presenting additional information fields.
 */
?>
<div class="project-indications">
  <?php if ($type): ?>
    <span class="top-buffer indication label label-default project-type"><?php print $type; ?></span>
  <?php endif; ?>

  <?php if ($status): ?>
    <span class="top-buffer indication label project-status <?php print (!empty($label_type)) ? $label_type : ''; ?>"><?php print $status; ?></span>
  <?php endif; ?>
</div>

<?php if ($title): ?>
  <h1 class="project-title">
    <?php print $title; ?>
  </h1>
<?php endif; ?>

<?php if ($tagline): ?>
  <h2 class="project-subtitle">
    <?php print $tagline; ?>
  </h2>
<?php endif; ?>


<?php if ($publish_link): ?>
    <div class="publish-link">
      <span> <?php print $publish_link; ?></span>
    </div>
<?php endif; ?>

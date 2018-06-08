<?php

/**
 * @file
 * Template for presenting additional information fields.
 */
?>
<div class="project-indications">
  <?php if ($type): ?>
    <span class="top-buffer indication label label-default project-type <?php print (!empty($publish_link)) ? 'es-right' : ''; ?>"><?php print $type; ?></span>
  <?php endif; ?>

  <?php if ($status): ?>
    <?php if ($publish_link): ?>
      <div class="btn-group">
          <button type="button" class="btn btn-danger dropdown-toggle status-controller" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            <?php print $status; ?> <span class="caret"></span>
          </button>
            <ul class="dropdown-menu">
                <li><?php print $publish_link; ?></li>
            </ul>
      </div>
    <?php else:?>
      <?php if ($status): ?>
          <span class="top-buffer indication label project-status label-default "><?php print $status; ?></span>
      <?php endif; ?>
    <?php endif; ?>
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

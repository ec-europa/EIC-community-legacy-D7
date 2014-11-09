<?php

/**
 * @file
 * Display a node in "Activity stream" view mode.
 *
 * @see node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);

    ?>
  </div>
  <div class="row">
    <div class="col-sm-4">
      <?php print $image; ?>
    </div>
    <div class="col-sm-8">
      <?php print $description; ?>
    </div>
  </div>

</div>

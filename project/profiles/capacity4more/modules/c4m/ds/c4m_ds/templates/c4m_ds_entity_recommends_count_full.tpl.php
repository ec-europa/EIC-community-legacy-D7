<?php

/**
 * @file
 * Template to output the comment count in the entity stats.
 *
 * Available variables:
 * - $count : the comment count.
 */
?>

<span class="row-entity-count count-recommends">
   <?php if ($link): ?>
     <?php print $link;?>
   <?php else: ?>
       <i class="fa fa-thumbs-o-up"></i>
   <?php endif; ?>
  <?php print $text; ?>
</span>

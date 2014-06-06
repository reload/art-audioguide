<?php
/**
 * @file
 * Template for the fold out boxes found on the site.
 *
 *  Available variables:
 *
 * - $title: The title of the box.
 * - $content: The content in the box.
 */
?>
<div class="foldout">
  <h2 class="foldout-toggle"><?php print $title; ?><br /><i class="icon--angle-down"></i></h2>

  <div class="foldout-content">
    <?php print $content; ?>
  </div>
</div>

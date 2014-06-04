<?php
/**
 * @file
 * Display Suite Audio 2 col template.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <?php /* Needed to activate contextual links */ ?>
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $audio_2col_thumbnail_wrapper; ?> class="thumbnail-wrapper<?php print $audio_2col_thumbnail_classes; ?>">
      <?php print $audio_2col_thumbnail; ?>
    </<?php print $audio_2col_thumbnail_wrapper; ?>>

    <h2 class="audio-title<?php print $audio_2col_title_classes; ?>">
      <?php print $audio_2col_title; ?>
    </h2>

    <<?php print $audio_2col_content_wrapper; ?> class="content<?php print $audio_2col_content_classes; ?>">
      <?php print $audio_2col_content; ?>
    </<?php print $audio_2col_content_wrapper; ?>>

</<?php print $layout_wrapper ?>>

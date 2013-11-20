<?php
/**
 * @file
 * Base template for slideshow iframe.
 */
?>
<div class="wt-container">
  <iframe id="walkthrough-slideshow-iframe" frameborder="0" width="<?php echo $width; ?>" height="<?php echo $height; ?>" src="<?php echo $source ?>" allowfullscreen=""> <?php echo t('Your browser doesn\'t support iframes.'); ?></iframe>
</div>
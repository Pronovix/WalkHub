<?php
/**
 * Override the default walkthrough step field collection edit form layout.
 *
 * Available variables:
 * - $form: This variable contains a walkthrough step field collection form elements
 */
?>
<div class="walkthrough-step-edit" id="walkthrough-step-edit-step-<?php print ($stepnumber); ?>">
  <div class="step-title button clearfix">
    <h3><b><?php print t ('Walkthrough'); ?> <?php print ($stepnumber); ?></b> - <?php print ($steplabel); ?></h3>
  </div>
  <div class="walkthrough-step-container clearfix">
    <?php echo drupal_render_children($form)?>
  </div>
</div>

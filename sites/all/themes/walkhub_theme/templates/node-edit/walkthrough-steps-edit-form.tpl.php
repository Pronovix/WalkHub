<?php
/**
 * Override the default walkthrough step field collection edit form layout.
 *
 * Available variables:
 * - $form: This variable contains a walkthrough step field collection form elements
 */
?>
<div class="walkthrough-step-edit">
  <h3 class="step-title button"><?php print ($form['label']); ?></h3>
  <div class="walkthrough-step-container clearfix">
    <div class="le">
      <?php if (!empty($form['field_fc_step_show_title'])): ?>
        <?php print render($form['field_fc_step_show_title']); ?>
      <?php endif; ?>
      <?php if (!empty($form['field_fc_step_description'])): ?>
        <?php print render($form['field_fc_step_description']); ?>
      <?php endif; ?>
    </div>



    <div class="ri">
      <?php echo drupal_render_children($form)?>
    </div>
  </div>

</div>

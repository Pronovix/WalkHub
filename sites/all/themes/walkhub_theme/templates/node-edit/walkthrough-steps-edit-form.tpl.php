<?php
/**
 * Override the default walkthrough step field collection edit form layout.
 *
 * Available variables:
 * - $form: This variable contains a walkthrough step field collection form elements
 */
?>
<div id="walkthrough-step-edit">
  <div id="left-column">
    <?php if (!empty($form['field_fc_step_show_title'])): ?>
      <?php print render($form['field_fc_step_show_title']); ?>
    <?php endif; ?>

    <?php if (!empty($form['field_fc_step_description'])): ?>
      <?php print render($form['field_fc_step_description']); ?>
    <?php endif; ?>
  </div>
  <div id="right-column">
  </div>

  <?php echo drupal_render_children($form)?>
</div>

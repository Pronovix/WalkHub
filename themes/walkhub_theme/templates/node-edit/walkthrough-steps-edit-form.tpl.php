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
    <h3>
      <b><?php print t ('Step'); ?><?php print ($stepnumber); ?></b> - <?php print ($steplabel); ?>
    </h3>
  </div>
  <div class="walkthrough-step-container clearfix">
    <div class="le">
      <?php if (!empty($form['field_fc_step_show_title'])): ?>
        <?php print render($form['field_fc_step_show_title']); ?>
      <?php endif; ?>
      <?php if (!empty($form['field_fc_step_name'])): ?>
        <?php print render($form['field_fc_step_name']); ?>
      <?php endif; ?>
      <?php if (!empty($form['field_fc_step_description'])): ?>
        <?php print render($form['field_fc_step_description']); ?>
      <?php endif; ?>
      <?php if (!empty($form['field_fc_step_highlight'])): ?>
        <?php print render($form['field_fc_step_highlight']); ?>
      <?php endif; ?>
    </div>
    <div class="ri">
      <?php echo drupal_render_children($form)?>
    </div>
  </div>

</div>

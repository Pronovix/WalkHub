<?php
/**
 * Override the walkthrough node edit form markup.
 *
 * Available variables:
 * - $form: This variable contains every field widget and every necessary node edit form elements.
 */
?>
<div id="walkthrough-node-edit-form">
  <?php print render($form['title']); ?>
  <?php print render($form['body']); ?>
  <div id="ad-set">
    <div class="le">
      </div>
    <div class="ri">
      <?php print render($form['additional_settings']); ?>
    </div>
  </div>
  <?php print drupal_render_children($form); ?>
</div>

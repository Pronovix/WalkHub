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
  <div id="wrapper-fg" class="clearfix">
    <div id="field_tags-col">
      <?php print render($form['field_tags']); ?>
    </div>

    <div id="group-col">
      <?php print render($form['og_group_ref']); ?>
    </div>
  </div>
  <div id="ad-set">
    <div class="le">
      </div>
    <div class="ri">
      <?php print render($form['additional_settings']); ?>
    </div>
  </div>
  <hr>
  <?php print drupal_render_children($form); ?>
</div>

<?php
/**
 * Override the walkthrough node edit form markup.
 *
 * Available variables:
 * - $form: This variable contains every field widget and every necessary node edit form elements.
 */
?>
<div id="walkthrough-set-node-edit-form">
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
  <h3><?php print t ('Set images'); ?></h3>
  <div class="clearfix" id="image-edit-cont">
    <?php print render($form['field_logo']); ?>
    <?php print render($form['field_icon']); ?>
    <?php print render($form['field_detail_image']); ?>
  </div>
  <hr>
  <button id="callopse" class="small"><i class="icon-folder-open-alt"></i> <?php print t ('Open/Close all'); ?></button>
  <button id="parameters" class="small"><i class="icon-cog"></i> <?php print t ('Proxy Warning/Parameters'); ?></button>
  <div id="adv-sett-proxy-param" class="clearfix">
    <?php print render($form['field_proxy_warning_message']); ?>
    <?php print render($form['field_parameters']); ?>
  </div>
  <?php print drupal_render_children($form); ?>
</div>

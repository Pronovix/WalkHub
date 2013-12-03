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
  <div class="button-holder">
    <a class="button small open" id="parameters"><?php print t ('Parameters/Proxy Warning'); ?></a>
    <a class="button small open" id="img-set-trigger"><?php print t ('Walkthrough set branding'); ?></a>
    <a class="button small open" id="advset"><?php print t ('Advanced Settings'); ?></a>
  </div>
  <div class="clearfix">
    <div class="ri">
      <div id="add-set-hide">
        <?php print render($form['additional_settings']); ?>
      </div>
      <div id="image-edit-cont-hide">
        <hr>
        <h4><?php print t ('Walkthrough set branding'); ?></h4>
        <div class="clearfix" id="image-edit-cont">
          <?php print render($form['field_logo']); ?>
          <?php print render($form['field_icon']); ?>
          <?php print render($form['field_detail_image']); ?>
        </div>
      </div>
      <div id="adv-sett-proxy-param" class="clearfix">
        <?php print render($form['field_proxy_warning_message']); ?>
        <?php print render($form['field_parameters']); ?>
      </div>
    </div>
  </div>
    <hr>
  <button id="callopse" class="small"><i class="icon-folder-open-alt"></i> <?php print t ('Open/Close all'); ?></button>
  <?php print drupal_render_children($form); ?>
</div>

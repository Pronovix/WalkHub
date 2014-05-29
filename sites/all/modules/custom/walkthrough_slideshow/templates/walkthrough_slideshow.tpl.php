<?php
/**
 * @file
 * Page template for slideshows.
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
  <title><?php echo t('Walkthrough Slideshow'); ?></title>
  <meta http-equiv="content-type" content="text/html; charset=UTF-8"/>
  <link rel="stylesheet"
        href="<?php echo $GLOBALS['base_url'] . '/' . libraries_get_path('reveal.js'); ?>/css/reveal.min.css"
        type="text/css" media="screen"/>
  <link rel="stylesheet"
        href="<?php echo $GLOBALS['base_url'] . '/' . drupal_get_path('module', 'walkthrough_slideshow'); ?>/walkthrough_slideshow.css"
        type="text/css" media="screen"/>
  <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.6.1/jquery.min.js"></script>
  <script type="text/javascript"
          src="<?php echo $GLOBALS['base_url'] . '/' . libraries_get_path('reveal.js'); ?>/js/reveal.min.js"></script>
  <script type="text/javascript"
          src="<?php echo $GLOBALS['base_url'] . '/' . drupal_get_path('module', 'walkthrough_slideshow'); ?>/js/walkthrough_slideshow.js"></script>
  <script type="text/javascript">
          src="<?php print drupal_get_path('module', 'browserclass') . '/browserclass.js'; ?>"
  </script>
</head>
<body class="<?php print implode(' ', browserclass_get_classes()); ?>">
<!--Title Bar-->
<div class="reveal">
  <div class="slides">
    <?php foreach($images as $key => $image): ?>

      <section data-background="<?php if (isset($image->image)) { echo $image->image; } ?>">
        <?php if (!isset($image->image)): ?>
          <table>
            <tr>
              <td class="action-icon">
                <i class="action icon-action-<?php echo $image->action; ?>"></i>
              </td>
              <td class="action-description">
                <p><?php echo $image->description; ?></p>
              </td>
            </tr>
          </table>
        <?php endif; ?>
      </section>
    <?php endforeach; ?>
  </div>
</div>
<div id="title-bar" class="cf">
  <div class="cont">
    <div class="title">
      <h2><?php echo $link; ?></h2>
    </div>
    <div class="start-button">
      <a id="startWT" href="<?php echo $start_url; ?>" target="_blank">
        <?php echo t('Start Walkthrough'); ?><i class="icon-play-circle"></i>
      </a>
    </div>
  </div>
</div>
<div id="hidden-center">
<!--Embed code-->
  <?php if ($share_dialog && $embed_code): ?>
    <div id="embed-code">
    <button id="close"><i class="icon-remove-sign"></i></button>
    <?php echo $embed_code; ?>
    <div class="share">
      <h4><?php echo t('Share this Walkthrough:'); ?></h4>
      <a href="https://plus.google.com/share?url=<?php echo $start_url; ?>" target="_blank" alt="Share on Google Plus" rel="nofollow">
        <i class="icon-google-plus-sign"></i>
      </a>
      <a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php echo $start_url; ?>" target="_blank" alt="Share on Linkedin" rel="nofollow">
        <i class="icon-linkedin-sign"></i>
      </a>
      <a href="http://www.facebook.com/share.php?u=<?php echo $start_url; ?>" target="_blank" alt="Share on Facebook" rel="nofollow">
        <i class="icon-facebook-sign"></i>
      </a>
      <a href="http://twitter.com/home?status=<?php echo $start_url; ?>" target="_blank" alt="Share on Twitter" rel="nofollow">
        <i class="icon-twitter-sign"></i>
      </a>
      <a href="http://pinterest.com/pin/create/button/?url=<?php echo $start_url; ?>" alt="Share on Pinterest" target="_blank" rel="nofollow">
        <i class="icon-pinterest-sign"></i>
      </a>
      <a href="http://www.tumblr.com/share?v=3&u=<?php echo $start_url; ?>" alt="Share on Tumblr" target="_blank" rel="nofollow">
        <i class="icon-tumblr-sign"></i>
      </a>
    </div>
  </div>
  <?php endif; ?>
</div>
<!--Control Bar-->
<div id="controls-wrapper">
  <div id="controls" class="cf">
    <a id="walkhub" class="float-left" href="http://walkhub.net/" target="_blank">
      <?php t('Walkhub | Special Service'); ?>
    </a>
    <!--Arrow Navigation-->
    <div id="navigation-buttons">
      <a id="firstslide" class="load-item">
        <i class="icon-double-angle-left"></i>
      </a>
      <a id="prevslide" class="load-item navigate-left">
        <i class="icon-angle-left"></i>
      </a>
      <a id="nextslide" class="load-item navigate-right">
        <i class="icon-angle-right"></i>
      </a>
      <a id="lastslide" class="load-item">
        <i class="icon-double-angle-right"></i>
      </a>
    </div>
    <div class="button-wrapper float-right">
      <?php if ($share_dialog && $embed_code): ?>
        <a id="share">
        <i class="icon-share"></i>
      </a>
      <?php endif; ?>
      <a id="fullscreen">
        <i class="icon-fullscreen"></i>
      </a>
    </div>
  </div>
</div>
<script>
  Reveal.initialize({
    controls: false,
    progress: false,
    slideNumber: false,
    history: false,
    keyboard: true,
    overview: false,
    center: true,
    touch: true,
    loop: false,
    rtl: false,
    fragments: true,
    embedded: false,
    autoSlide: 0,
    autoSlideStoppable: true,
    mouseWheel: false,
    hideAddressBar: true,
    previewLinks: false,
    transition: 'none',
    transitionSpeed: 'default',
    backgroundTransition: 'none',
    viewDistance: 3,
    parallaxBackgroundImage: '',
    parallaxBackgroundSize: '',
    width: 1000,
    height: 640,
    margin: 0.1,
    minScale: 0.2,
    maxScale: 100.0
  });
</script>
</body>
</html>

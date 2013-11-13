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
        href="/<?php echo drupal_get_path('module', 'walkthrough_slideshow'); ?>/walkthrough_slideshow.css"
        type="text/css" media="screen"/>

  <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.6.1/jquery.min.js"></script>
  <script type="text/javascript" src="/<?php echo libraries_get_path('bigscreen'); ?>/bigscreen.min.js"></script>
  <script type="text/javascript"
          src="/<?php echo libraries_get_path('supersized'); ?>/slideshow/js/jquery.easing.min.js"></script>
  <script type="text/javascript"
          src="/<?php echo libraries_get_path('supersized'); ?>/slideshow/js/supersized.3.2.7.min.js"></script>
  <script type="text/javascript"
          src="/<?php echo drupal_get_path('module', 'walkthrough_slideshow'); ?>/js/supersized.shuttered.js"></script>

  <script type="text/javascript">
    jQuery(function ($) {
      $(document).ready(function () {
        var timer = setInterval(hideOverlays);

        // Hide overlays.
        function hideOverlays() {
          $('#title-bar, #controls-wrapper').addClass('hide').fadeOut();
        }

        // Show overlays.
        function displayOverlays() {
          $('#title-bar, #controls-wrapper').removeClass('hide').fadeIn();
        }

        // Hover on overlays.
        function cursorOver(timer) {
          clearInterval(timer);
          if ($('#title-bar').hasClass('hide') && $('#controls-wrapper').hasClass('hide')) {
            displayOverlays();
          }
        }

        // Out from overlay.
        function cursorOut() {
          timer = setInterval(hideOverlays);
        }

        // Hover.
        $('#hidden-controls-wrapper, #hidden-title-bar, #title-bar, #controls-wrapper').hover(function () {
          cursorOver(timer);
        }, cursorOut);

        // Full screen.
        $('#fullscreen').click(function () {
          if (BigScreen.enabled) {
            BigScreen.toggle();
          }
        });

        // Supersized.
        $.supersized({
          // Functionality
          slideshow: 1,			// Slideshow on/off
          autoplay: 0,			// Slideshow starts playing automatically
          start_slide: 1,			// Start slide (0 is random)
          stop_loop: 1,			// Pauses slideshow on last slide
          random: 0,			// Randomize slide order (Ignores start slide)
          slide_interval: 3000,		// Length between transitions
          transition: 1, 			// 0-None, 1-Fade, 2-Slide Top, 3-Slide Right, 4-Slide Bottom, 5-Slide Left, 6-Carousel Right, 7-Carousel Left
          transition_speed: 100,		// Speed of transition
          new_window: 1,			// Image links open in new window/tab
          pause_hover: 0,			// Pause slideshow on hover
          keyboard_nav: 1,			// Keyboard navigation on/off
          performance: 1,			// 0-Normal, 1-Hybrid speed/quality, 2-Optimizes image quality, 3-Optimizes transition speed // (Only works for Firefox/IE, not Webkit)
          image_protect: 1,			// Disables image dragging and right click with Javascript

          // Size & Position
          min_width: 0,			// Min width allowed (in pixels)
          min_height: 0,			// Min height allowed (in pixels)
          vertical_center: 1,			// Vertically center background
          horizontal_center: 1,			// Horizontally center background
          fit_always: 0,			// Image will never exceed browser width or height (Ignores min. dimensions)
          fit_portrait: 1,			// Portrait images will not exceed browser height
          fit_landscape: 0,			// Landscape images will not exceed browser width

          // Components
          slide_links: false,	// Individual links for each slide (Options: false, 'num', 'name', 'blank')
          thumb_links: 0,			// Individual thumb links for each slide
          thumbnail_navigation: 0,			// Thumbnail navigation
          slides:    <?php echo $slides_json; ?>,

          // Theme Options
          progress_bar: 0,			// Timer for each slide
          mouse_scrub: 0
        });
      });
    });
  </script>
</head>

<body>

<!--Thumbnail Navigation-->
<div id="prevthumb"></div>
<div id="nextthumb"></div>


<div id="thumb-tray" class="load-item">
  <div id="thumb-back"></div>
  <div id="thumb-forward"></div>
</div>

<!--Title Bar-->
<div id="hidden-title-bar"></div>
<div id="title-bar" class="cf">
  <div class="title float-left">
    <h2><?php echo $link; ?></h2>

  </div>
  <div class="start-button float-right">
    <a id="startWT" href="<?php echo $start_url; ?>" target="_blank">
      <?php echo t('Start Walkthrough'); ?><i class="icon-play-circle"></i>
    </a>
  </div>

</div>

<!--Embed code-->
<div id="embed-code">
  <?php echo $embed_code; ?>
</div>

<!--Control Bar-->
<div id="hidden-controls-wrapper"></div>
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
      <a id="prevslide" class="load-item">
        <i class="icon-angle-left"></i>
      </a>
      <a id="nextslide" class="load-item">
        <i class="icon-angle-right"></i>
      </a>
      <a id="lastslide" class="load-item">
        <i class="icon-double-angle-right"></i>
      </a>

    </div>

    <div class="button-wrapper float-right">
      <a id="share">
        <i class="icon-share"></i>
      </a>
      <a id="fullscreen">
        <i class="icon-fullscreen"></i>
      </a>
    </div>
  </div>
</div>

</body>
</html>

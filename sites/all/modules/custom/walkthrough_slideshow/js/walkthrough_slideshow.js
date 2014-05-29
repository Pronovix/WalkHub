jQuery(function ($) {
  "use strict";

  var timer;

  $(document).ready(function () {
    // Toggle Source Code
    $('#share').click(function () {
      $('#embed-code').toggle();
      $('.reveal').toggleClass("faded").fadeIn(0);
      return false;
    });

    // Toggle Source Code
    $('#close').click(function () {
      $('#embed-code').hide();
      $('.reveal').removeClass("faded");
      return false;
    });


    // Hide overlays.
    function hideOverlays() {
      $('#title-bar, #controls-wrapper').addClass('hide').fadeOut();
    }

    // Show overlays.
    function displayOverlays() {
      $('#title-bar, #controls-wrapper').removeClass('hide').fadeIn(0);
    }

    // Hover on overlays.
    function cursorOut(timer) {
      clearInterval(timer);
      if ($('#title-bar').hasClass('hide') && $('#controls-wrapper').hasClass('hide')) {
        displayOverlays();
      }
    }

    // Out from overlay.
    function cursorOver() {
      timer = setInterval(hideOverlays, 1000);
    }

    // Hover.
    $('#hidden-center').hover(cursorOver, function () {
      cursorOut(timer);
    });

    // Full screen.
    $('#fullscreen').click(function () {
      // Disable Fullscreen mode on <IE11.
      var fullscreenAPI_supported_browser = !($('body').is('ie') && !$('body').is('ie11'));
      if (fullscreenAPI_supported_browser) {
        Reveal.enterFullscreen();
      } else {
        // If Fullsreen API is not supported, lets show a popup.
        var window_options, popup;

        window_options = 'height=' + (screen.height) + ','
          + 'width=' + (screen.width) + ','
          + 'fullscreen=1,'
          + 'menubar=0,'
          + 'resizable=0,'
          + 'status=0,'
          + 'titlebar=0,'
          + 'location=0,'
          + 'toolbar=0';
        popup = window.open(location.href, 'Walkthrough', window_options);
        if (window.focus) {
          popup.focus();
        }
      }
    });

    // Navigation.
    $("#firstslide").click(function() {
      Reveal.slide(0);
    });

    $("#lastslide").click(function() {
      Reveal.slide(Number.MAX_VALUE);
    });

  });

  // Progress to next slide on clicking the image.
  $('#hidden-center').click(function() {
    Reveal.next();
  });
});

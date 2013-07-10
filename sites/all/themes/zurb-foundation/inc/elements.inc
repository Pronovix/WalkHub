<?php
/**
 * Override drupal core messages with zurb foundation alert-box messages.
 * Customize the colors within the _settings.scss file
 *
 * http://foundation.zurb.com/docs/elements.php#panelEx
 */
function zurb_foundation_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'error' => t('Error message'),
    'status' => t('Status message'),
    'warning' => t('Warning message'),
  );
  $status_mapping = array(
    'error' => 'alert',
    'success' => 'success',
    'warning' => 'secondary'
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    if (isset($status_mapping[$type])) {
      $output .= "<div class=\"alert-box $status_mapping[$type]\">\n";
    }
    else {
      $output .= "<div class=\"alert-box\">\n";
    }

    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  // Enable Modal Status Messages
  /*
  if ($output != '') {
    drupal_add_js("jQuery(document).ready(function() { jQuery('#status-messages').reveal();
            });", array('type' => 'inline', 'scope' => 'footer'));
    $output = '<div id="status-messages" class="reveal-modal expand" >'. $output;
    $output .= '<a class="close-reveal-modal">&#215;</a>';
    $output .= "</div>\n";
  }
  //*/
  return $output;
}
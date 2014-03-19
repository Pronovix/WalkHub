<?php

/**
 * Apple Touch Icons
 */
function walkhub_theme_preprocess(&$vars, $hook) {
  global $theme;
  global $base_url;
  $path = drupal_get_path('theme', $theme);
  $path_walkhub_theme = drupal_get_path('theme', 'walkhub_theme');

  //http://api.drupal.org/api/drupal/includes--theme.inc/function/template_preprocess_html/7
  $vars['walkhub_theme_poorthemers_helper'] = "";
  //For third-generation iPad with high-resolution Retina display
  $appletouchicon = '<link rel="apple-touch-icon" sizes="152x152" href="' . $base_url .'/'. $path . '/apple-touch-icon-152x152-precomposed.png">'. "\n";
  //For third-generation iPad with high-resolution Retina display
  $appletouchicon = '<link rel="apple-touch-icon" sizes="144x144" href="' . $base_url .'/'. $path . '/apple-touch-icon-144x144-precomposed.png">'. "\n";
  //For iPhone with high-resolution Retina display
  $appletouchicon .= '<link rel="apple-touch-icon" sizes="120x120" href="' . $base_url .'/'. $path . '/apple-touch-icon-120x120-precomposed.png">'. "\n";
  //For iPhone with high-resolution Retina display
  $appletouchicon .= '<link rel="apple-touch-icon" sizes="114x114" href="' . $base_url .'/'. $path . '/apple-touch-icon-114x114-precomposed.png">'. "\n";
  //For iPhone with high-resolution Retina display
  $appletouchicon .= '<link rel="apple-touch-icon" sizes="76x76" href="' . $base_url .'/'. $path . '/apple-touch-icon-76x76-precomposed.png">'. "\n";
  //For first- and second-generation iPad:
  $appletouchicon .= '<link rel="apple-touch-icon" sizes="72x72" href="' . $base_url .'/'.  $path . '/apple-touch-icon-72x72-precomposed.png">' . "\n";
  //For first- and second-generation iPad:
  $appletouchicon .= '<link rel="apple-touch-icon" sizes="57x57" href="' . $base_url .'/'.  $path . '/apple-touch-icon-57x57-precomposed.png">' . "\n";
  //For non-Retina iPhone, iPod Touch, and Android 2.1+ devices
  $appletouchicon .=  '<link rel="apple-touch-icon" href="' . $base_url .'/'.  $path . '/apple-touch-icon-57x57-precomposed.png">' . "\n";
  //Startup image for iPhone 3GS, 2011 iPod Touch
  $appletouchicon .=  '<link rel="apple-touch-startup-image" href="' . $base_url .'/'.  $path . '/apple-startup-320x460.png" media="screen and (max-device-width : 320px)">' . "\n";
  //Startup image for iPhone 4, 4S and 2011 iPod Touch
  $appletouchicon .=  '<link rel="apple-touch-startup-image" href="' . $base_url .'/'.  $path . '/apple-startup-640x920.png" media="(max-device-width : 480px) and (-webkit-min-device-pixel-ratio : 2)">' . "\n";
  //Startup image for iPhone 5 and 2012 iPod Touch
  $appletouchicon .=  '<link rel="apple-touch-startup-image" href="' . $base_url .'/'.  $path . '/apple-startup-640x1096.png" media="(max-device-width : 548px) and (-webkit-min-device-pixel-ratio : 2)">' . "\n";
  //Startup image for iPad landscape
  $appletouchicon .=  '<link rel="apple-touch-startup-image" href="' . $base_url .'/'.  $path . '/apple-startup-1024x748.png" media="screen and (min-device-width : 481px) and (max-device-width : 1024px) and (orientation : landscape)">' . "\n";
  //Startup image for iPad Portrait
  $appletouchicon .=  '<link rel="apple-touch-startup-image" href="' . $base_url .'/'.  $path . '/apple-startup-768x1004.png" media="screen and (min-device-width : 481px) and (max-device-width : 1024px) and (orientation : portrait)">' . "\n";

  if ( $hook == "html" ) {
    // =======================================| HTML |========================================

    //get the path for the site
    $vars['walkhub_theme_path'] = $base_url .'/'. $path_walkhub_theme;
    $vars['appletouchicon'] = $appletouchicon;
  }
}

/**
 * Implements hook_html_head_alter().
 */
function walkhub_theme_html_head_alter(&$head_elements) {
  // HTML5 charset declaration.
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );

  // Old mobile dec
  $head_elements['mobileoptimized'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'MobileOptimized',
      'content' => 'width',
    ),
  );

  // Old mobile dec
  $head_elements['handheldfriendly'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'HandheldFriendly',
      'content' => 'true',
    ),
  );

  // Optimize mobile viewport.
  $head_elements['rating'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'rating',
      'content' => 'global',
    ),
  );

  // Global Rating SEO.
  $head_elements['mobile_viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );

  // ClearType
  $head_elements['cleartype'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'cleartype',
      'content' => 'on',
    ),
  );

  // Force IE to use Chrome Frame if installed.
  $head_elements['chrome_frame'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'x-ua-compatible',
      'content' => 'ie=edge, chrome=1',
    ),
  );

  // Remove image toolbar in IE.
  $head_elements['ie_image_toolbar'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'ImageToolbar',
      'content' => 'false',
    ),
  );
}

/**
 * Implements hook_form_FORM_ID_alter()
 * Override the step edit form theme function.
 * Implements html_head_alter().
 */
function walkhub_theme_form_walkthrough_node_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form['field_fc_steps'][LANGUAGE_NONE])) {
    foreach (element_children($form['field_fc_steps'][LANGUAGE_NONE]) as $key) {
      $form['field_fc_steps'][LANGUAGE_NONE][$key]['#theme'] = 'walkthrough_steps_edit_form';
    }
  }
}
function walkhub_theme_form_walkthrough_set_node_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form['field_walkthroughs'][LANGUAGE_NONE])) {
    foreach (element_children($form['field_walkthroughs'][LANGUAGE_NONE]) as $key) {
      $form['field_walkthroughs'][LANGUAGE_NONE][$key]['#theme'] = 'walkthrough_set_steps_edit_form';
    }
  }
}

/**
 * Implements hook_theme().
 */
function walkhub_theme_theme() {
  return array(
    'walkthrough_node_form' => array(
      'render element' => 'form',
      'template' => 'walkthrough-node-form',
      'path' => drupal_get_path('theme', 'walkhub_theme') . '/templates/node-edit',
    ),
    'walkthrough_steps_edit_form' => array(
      'render element' => 'form',
      'template' => 'walkthrough-steps-edit-form',
      'path' => drupal_get_path('theme', 'walkhub_theme') . '/templates/node-edit',
    ),
    'walkthrough_set_node_form' => array(
      'render element' => 'form',
      'template' => 'walkthrough-set-node-form',
      'path' => drupal_get_path('theme', 'walkhub_theme') . '/templates/node-edit',
    ),
    'walkthrough_set_steps_edit_form' => array(
      'render element' => 'form',
      'template' => 'walkthrough-set-steps-edit-form',
      'path' => drupal_get_path('theme', 'walkhub_theme') . '/templates/node-edit',
    ),
  );
}

/**
 * Implements hook_css_alter().
 */
function walkhub_theme_css_alter(&$css) {
  // Always remove base theme CSS.
  $theme_path = drupal_get_path('theme', 'zurb_foundation');

  foreach($css as $path => $values) {
    if(strpos($path, $theme_path) === 0) {
      unset($css[$path]);
    }
  }

  // Remove system css
  unset($css[drupal_get_path('module','system').'/system.menus.css']);
  unset($css[drupal_get_path('module','field_collection').'/field_collection.theme.css']);
  unset($css[drupal_get_path('module','system').'/system.theme.css']);
}

/**
 * Implements hook_js_alter().
 */
function walkhub_theme_js_alter(&$js) {
  // Always remove base theme JS.
  $theme_path = drupal_get_path('theme', 'zurb_foundation');

  foreach($js as $path => $values) {
    if(strpos($path, $theme_path) === 0) {
      unset($js[$path]);
    }
  }
}

/**
 * Implements template_preprocess_node()
 */
function walkhub_theme_preprocess_node(&$vars) {
  $node = $vars['node'];
  $contenttype = $vars['type'];
  $view_mode = $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__'. $view_mode;
  $vars['theme_hook_suggestions'][] = 'node__'. $contenttype . '__' . $view_mode;
}


/**
 * Implements template_preprocess_page()
 */
function walkhub_theme_preprocess_page(&$vars) {
  $path = drupal_get_path('theme', 'walkhub_theme');

  if (arg(0) == 'field-collection') {
    drupal_add_js($path . '/js/page/field-collection-step-edit.js');
  }

  if (drupal_is_front_page() == TRUE) {
  }

  if (isset($vars['node'])) {
    $node = $vars['node'];
    $vars['theme_hook_suggestions'][] = "page__" .  $node->type;

    if ( $node->type == 'walkhub_faq_page') {
      drupal_add_js($path . '/js/page/faq.js');
    }
  }

  // Blog Date Format
  if (isset($vars['node'])) {
    $node = $vars['node'];
    $node_type = $node->type;
    $vars['theme_hook_suggestions'][] = "page__" . $node_type;

    if ($node_type == 'blog_entry') {
      $vars['date'] = format_date($vars['node']->created, 'custom', 'F j');
    }

  }
}

/**
 * Implements hook_preprocess_walkthrough_steps_edit_form().
 */
function walkhub_theme_preprocess_walkthrough_steps_edit_form(&$vars) {
  $title = isset($vars['form']['field_fc_step_name'][LANGUAGE_NONE][0]['value']['#value']) ? $vars['form']['field_fc_step_name'][LANGUAGE_NONE][0]['value']['#value'] : '';
  $description = isset($vars['form']['field_fc_step_description'][LANGUAGE_NONE][0]['value']['#value']) ? $vars['form']['field_fc_step_description'][LANGUAGE_NONE][0]['value']['#value'] : '';
  $label = "$title - $description";

  $vars['stepnumber'] = (isset($vars['form']['#delta']) ? $vars['form']['#delta'] : 0) + 1;

  if (empty($title)) {
    $label = "{$vars['stepnumber']}. step";
  }

  $vars['steplabel'] = $label;
}

/**
 * Implements hook_preprocess_walkthrough_set_steps_edit_form().
 */
function walkhub_theme_preprocess_walkthrough_set_steps_edit_form(&$vars) {
  $title = isset($vars['form']['field_fc_step_name'][LANGUAGE_NONE][0]['value']['#value']) ? $vars['form']['field_fc_step_name'][LANGUAGE_NONE][0]['value']['#value'] : '';
  $description = isset($vars['form']['field_fc_step_description'][LANGUAGE_NONE][0]['value']['#value']) ? $vars['form']['field_fc_step_description'][LANGUAGE_NONE][0]['value']['#value'] : '';
  $label = "$title - $description";

  $vars['stepnumber'] = (isset($vars['form']['#delta']) ? $vars['form']['#delta'] : 0) + 1;

  if (empty($title)) {
    $label = "{$vars['stepnumber']}. Walkthrough";
  }

  $vars['steplabel'] = $label;
}


/**
 * Implements hook_preprocess_walkthrough_node_form().
 */
function walkhub_theme_preprocess_walkthrough_node_form($vars) {
  $path = drupal_get_path('theme', 'walkhub_theme');
  drupal_add_js($path . '/js/page/node-walkthrough-form-edit.js');
}

/**
 * Implements hook_preprocess_walkthrough_set_node_form().
 */
function walkhub_theme_preprocess_walkthrough_set_node_form($vars) {
  $path = drupal_get_path('theme', 'walkhub_theme');
  drupal_add_js($path . '/js/page/node-walkthrough-set-form-edit.js');
}
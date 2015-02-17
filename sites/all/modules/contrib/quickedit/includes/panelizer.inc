<?php

/**
 * @file
 * Implements Quick Edit module hooks on behalf of panelizer.module.
 */

/**
 * Implements hook_ctools_render_alter().
 *
 * Sets data-quickedit-entity-id attribute in case of a panelized, full-page
 * entity view.
 *
 * @see quickedit_preprocess_panelizer_view_mode()
 * @see quickedit_preprocess_node()
 */
function quickedit_ctools_render_alter(&$info, &$page, &$context) {
  if ($context['task']['task type'] == 'page') {
    foreach ($context['contexts'] as $page_context) {
      if ($page_context->type[1] === 'entity') {
        $entity_id = $context['args'][0];
        $entity_type = $page_context->type[2];
        $prefix = '<div data-quickedit-entity-id="' . $entity_type . '/' . $entity_id . '">';
        $suffix = '</div>';
        $info['content'] = $prefix . $info['content'] . $suffix;

        // Detect when an entity is being rendered by page_manager, and then set
        // a global (GASP!) variable. This is necessary, because page manager
        // has an incorrectly applied "contextual-links-region" class: it's set
        // on the wrong element (by ctools_context_handler_render_handler(),
        // hence breaking Quick Edit module's JS in the process. The worst part:
        // it is *impossible* to override it in a sane way.
        // As always, there is a work-around in Drupal, but it's not pretty:
        // detect here whether an entity is being rendered by page manager, set
        // a global variable, and then let quickedit_page_build() perform string
        // manipulation on the final $page renderable array.
        global $quickedit_workaround_for_fundamentally_broken_page_manager;
        $quickedit_workaround_for_fundamentally_broken_page_manager = TRUE;
        break;
      }
    }
  }
}

/**
 * Implements hook_preprocess_panelizer_view_mode().
 *
 * Sets data-quickedit-entity-id attribute in case of a panelized, non-full-page
 * entity view.
 *
 * @see quickedit_ctools_render_alter()
 * @see quickedit_preprocess_node()
 */
function quickedit_preprocess_panelizer_view_mode(&$variables) {
  $entity_type = $variables['element']['#entity_type'];
  $entity = $variables['element']['#' . $entity_type];
  $entity_id = entity_id($entity_type, $entity);

  // Set data-quickedit-entity-id attribute.
  $variables['attributes_array']['data-quickedit-entity-id'] = $entity_type . '/' . $entity_id;

  // If the entity has a title, set data-quickedit-field-id attribute.
  if (!empty($entity->title)) {
    $language = !empty($entity->language) ? $entity->language : LANGUAGE_NONE;
    $view_mode = _panelizer_generate_quickedit_viewmode($entity);
    $variables['title_attributes_array']['data-quickedit-field-id'] = "$entity_type/$entity_id/title/$language/$view_mode";
  }
}

/**
 * Helper function to transform the "panelizer view mode" into a "Quick Edit
 * view mode ID", to make Edit use Panelizer's render pipeline to re-render
 * fields after they've been edited.
 *
 * @see panelizer_quickedit_render_field()
 */
function _panelizer_generate_quickedit_viewmode($entity) {
  // Ensure Panelizer view mode property exists.
  if (!isset($entity->panelizer_view_mode)) {
    return '0';
  }

  // @see includes/panelizer.inc/panelizer_panelizer_pre_render_alter()
  $key = $entity->panelizer_view_mode;
  $panelizer_entity = $entity->panelizer[$key];
  return implode('-', array('panelizer', $panelizer_entity->view_mode));
}

/**
 * Implements hook_quickedit_render_field().
 *
 * @see _panelizer_generate_quickedit_viewmode()
 */
function panelizer_quickedit_render_field($entity_type, $entity, $field_name, $view_mode_id, $langcode) {
  ctools_include('plugins', 'panels');
  ctools_include('content', 'ctools');

  list($module, $panelizer_view_mode) = explode('-', $view_mode_id);

  // Now render the given field (which resides in the given pane ID) through
  // Panels' render pipeline.
  $args = array(entity_id($entity_type, $entity));
  // @see panelizer_panelizer_task_render()
  $entity_handler = panelizer_entity_plugin_get_handler($entity_type);
  // @see PanelizerEntityDefault.class.php::render_entity().
  $panelizer = $entity->panelizer[$panelizer_view_mode];

  // Special case: the title.
  // Note: it is technically impossible to determine what should be rendered
  // exactly, because it is determined by a subset of a template. Hence we do a
  // best-effort approximation.
  // @see panelizer-view-mode.tpl.php
  if ($field_name === 'title') {
    $entity_id = entity_id($entity_type, $entity);
    // @see PanelizerEntityDefault::preprocess_panelizer_view_mode()
    $title_element = 'h2';
    if (!empty($panelizer->title_element)) {
      $title_element = $panelizer->title_element;
    }
    $entity_url = NULL;
    if (!empty($panelizer->link_to_entity)) {
      $bits = explode('/', $entity_handler->plugin['entity path']);
      foreach ($bits as $count => $bit) {
        if (strpos($bit, '%') === 0) {
          $bits[$count] = $entity_id;
        }
      }
      $entity_url = url(implode('/', $bits));
    }
    // Immediately return the rendered title pseudo-field.
    $quickedit_id = "$entity_type/$entity_id/title/$langcode/$view_mode_id";
    $prefix = '<' . $title_element . ' data-quickedit-field-id="' . $quickedit_id .'">';
    $suffix . '</' . $title_element . '>';
    if (isset($entity_url)) {
      $markup = $prefix . '<a href="' . $entity_url . '">' . $entity->title . '</a>' . $suffix;
    }
    else {
      $markup =  $prefix . $entity->title . $suffix;
    }
    return array('#markup' => $markup);
  }

  // @see PanelizerEntityDefault.class.php::render_entity().
  $display = $panelizer->display;
  $display->context = $entity_handler->get_contexts($panelizer, $entity);
  $display->args = $args;
  $display->css_id = $panelizer->css_id;
  $renderer = panels_get_renderer_handler($panelizer->pipeline, $display);
  // Find the ID of the pane where the given field resides; it's impossible to
  // know which pane ID the field is being rendered in when the
  // data-quickedit-field-id attribute gets set in quickedit_preprocess_field(),
  // so sadly we have to resort to this work-around. This *will* break down if
  // the same field is rendered multiple times.
  $pane_id = NULL;
  foreach ($display->content as $id => $pane) {
    if ($pane->type === 'entity_field' && $pane->subtype === $entity_type . ':'. $field_name) {
      $pane_id = $id;
      break;
    }
  }
  // @see panels_renderer_standard::render_panes()
  $pane = $display->content[$pane_id];
  // @see panels_renderer_standard::render_pane()
  module_invoke_all('panels_pane_prerender', $pane);
  $pane_content = $renderer->render_pane_content($pane);

  // Finally, return the renderable array containing the field.
  return $pane_content->content;
}

<?php
/**
 * @file
 * walkhub_comments.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function walkhub_comments_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'steps_for_walkthrough';
  $view->description = 'This view needs to be fixed, it returns an empty set on purpose.';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Steps for walkthrough';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_fc_screenshots_step_target_id']['id'] = 'field_fc_screenshots_step_target_id';
  $handler->display->display_options['relationships']['field_fc_screenshots_step_target_id']['table'] = 'field_data_field_fc_screenshots_step';
  $handler->display->display_options['relationships']['field_fc_screenshots_step_target_id']['field'] = 'field_fc_screenshots_step_target_id';
  $handler->display->display_options['relationships']['field_fc_screenshots_step_target_id']['required'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_fc_screenshots_step_target_id';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_fc_step_name']['id'] = 'field_fc_step_name';
  $handler->display->display_options['fields']['field_fc_step_name']['table'] = 'field_data_field_fc_step_name';
  $handler->display->display_options['fields']['field_fc_step_name']['field'] = 'field_fc_step_name';
  $handler->display->display_options['fields']['field_fc_step_name']['relationship'] = 'field_fc_screenshots_step_target_id';
  /* Contextual filter: Field: Default Parameters (field_parameters:revision_id) */
  $handler->display->display_options['arguments']['field_parameters_revision_id']['id'] = 'field_parameters_revision_id';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['table'] = 'field_data_field_parameters';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['field'] = 'field_parameters_revision_id';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['default_argument_options']['argument'] = '-1';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parameters_revision_id']['summary_options']['items_per_page'] = '25';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_fc_step_name' => 'field_fc_step_name',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['steps_for_walkthrough'] = $view;

  return $export;
}

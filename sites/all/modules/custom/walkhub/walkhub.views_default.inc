<?php
/**
 * @file
 * walkhub.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function walkhub_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'step_list';
  $view->description = 'Create a list of given walkthrough\'s steps.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Step list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_steps_target_id']['id'] = 'field_steps_target_id';
  $handler->display->display_options['relationships']['field_steps_target_id']['table'] = 'field_data_field_steps';
  $handler->display->display_options['relationships']['field_steps_target_id']['field'] = 'field_steps_target_id';
  $handler->display->display_options['relationships']['field_steps_target_id']['label'] = 'Referenced entity';
  $handler->display->display_options['relationships']['field_steps_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Command 1 */
  $handler->display->display_options['fields']['field_command_1']['id'] = 'field_command_1';
  $handler->display->display_options['fields']['field_command_1']['table'] = 'field_data_field_command_1';
  $handler->display->display_options['fields']['field_command_1']['field'] = 'field_command_1';
  $handler->display->display_options['fields']['field_command_1']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['field_command_1']['label'] = 'field_command_1';
  $handler->display->display_options['fields']['field_command_1']['element_label_colon'] = FALSE;
  /* Field: Content: Command 2 */
  $handler->display->display_options['fields']['field_command_2']['id'] = 'field_command_2';
  $handler->display->display_options['fields']['field_command_2']['table'] = 'field_data_field_command_2';
  $handler->display->display_options['fields']['field_command_2']['field'] = 'field_command_2';
  $handler->display->display_options['fields']['field_command_2']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['field_command_2']['label'] = 'field_command_2';
  $handler->display->display_options['fields']['field_command_2']['element_label_colon'] = FALSE;
  /* Field: Content: Command 3 */
  $handler->display->display_options['fields']['field_command_3']['id'] = 'field_command_3';
  $handler->display->display_options['fields']['field_command_3']['table'] = 'field_data_field_command_3';
  $handler->display->display_options['fields']['field_command_3']['field'] = 'field_command_3';
  $handler->display->display_options['fields']['field_command_3']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['field_command_3']['label'] = 'field_command_3';
  $handler->display->display_options['fields']['field_command_3']['element_label_colon'] = FALSE;
  /* Field: Content: Step Highlight */
  $handler->display->display_options['fields']['field_step_highlight']['id'] = 'field_step_highlight';
  $handler->display->display_options['fields']['field_step_highlight']['table'] = 'field_data_field_step_highlight';
  $handler->display->display_options['fields']['field_step_highlight']['field'] = 'field_step_highlight';
  $handler->display->display_options['fields']['field_step_highlight']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['field_step_highlight']['label'] = 'step_highlight';
  $handler->display->display_options['fields']['field_step_highlight']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_steps_target_id';
  $handler->display->display_options['fields']['body']['label'] = 'description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'numeric';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'walkthrough' => 'walkthrough',
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $export['step_list'] = $view;

  $view = new view();
  $view->name = 'walkthrough_list';
  $view->description = 'Create a list of walkthroughs.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Walkthrough list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Walkthroughs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  /* Field: Content: Raw input */
  $handler->display->display_options['fields']['field_raw_input']['id'] = 'field_raw_input';
  $handler->display->display_options['fields']['field_raw_input']['table'] = 'field_data_field_raw_input';
  $handler->display->display_options['fields']['field_raw_input']['field'] = 'field_raw_input';
  /* Field: Content: Steps */
  $handler->display->display_options['fields']['field_steps']['id'] = 'field_steps';
  $handler->display->display_options['fields']['field_steps']['table'] = 'field_data_field_steps';
  $handler->display->display_options['fields']['field_steps']['field'] = 'field_steps';
  $handler->display->display_options['fields']['field_steps']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_steps']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'walkthrough' => 'walkthrough',
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['walkthrough_list'] = $view;

  return $export;
}

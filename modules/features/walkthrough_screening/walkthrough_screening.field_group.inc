<?php
/**
 * @file
 * walkthrough_screening.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function walkthrough_screening_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_screening_result|node|screening|form';
  $field_group->group_name = 'group_screening_result';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'screening';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Result',
    'weight' => '3',
    'children' => array(
      0 => 'field_screening_fc_screenshots',
      1 => 'field_screening_result',
      2 => 'field_screening_time',
      3 => 'field_screening_junit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-screening-result field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_screening_result|node|screening|form'] = $field_group;

  return $export;
}

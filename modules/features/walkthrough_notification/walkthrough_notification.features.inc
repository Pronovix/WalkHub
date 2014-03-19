<?php
/**
 * @file
 * walkthrough_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function walkthrough_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function walkthrough_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function walkthrough_notification_flag_default_flags() {
  $flags = array();
  // Exported flag: "Subscribe Content".
  $flags['subscribe_content'] = array(
    'entity_type' => 'node',
    'title' => 'Subscribe Content',
    'global' => 0,
    'types' => array(
      0 => 'walkthrough',
    ),
    'flag_short' => 'Subscribe',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'entity_reference' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'walkthrough_notification',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function walkthrough_notification_default_message_type() {
  $items = array();
  $items['walkthrough_flagged_as_broken'] = entity_import('message_type', '{
    "name" : "walkthrough_flagged_as_broken",
    "description" : "Walkthrough flagged as broken",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Walkthrough flagged as broken",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EWalkthrough flagged as broken\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hi [message:field-broken-author:name],\\r\\n\\r\\nYour walkthrough has been flagged as broken. You can check it out and fix the error at [message:field-broken-walkthrough:url:absolute].\\r\\n\\r\\nThank you,\\r\\nThe WalkHub Team",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EHi [message:field-broken-author:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYour walkthrough has been flagged as broken. You can check it out and fix the error at [message:field-broken-walkthrough:url:absolute].\\u003C\\/p\\u003E\\n\\u003Cp\\u003EThank you,\\u003Cbr \\/\\u003E\\nThe WalkHub Team\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['walkthrough_has_been_updated'] = entity_import('message_type', '{
    "name" : "walkthrough_has_been_updated",
    "description" : "Walkthrough has been updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Walkthrough has been updated",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EWalkthrough has been updated\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hi [message:field-updated-walkthrough:author:name],\\r\\n\\r\\nThe [message:field-broken-walkthrough:title] has been updated.\\r\\n[message:field-updated-walkthrough:url:absolute]\\r\\n\\r\\nThank you,\\r\\nThe WalkHub Team",
          "format" : "full_html",
          "safe_value" : "Hi [message:field-updated-walkthrough:author:name],\\n\\nThe [message:field-broken-walkthrough:title] has been updated.\\n[message:field-updated-walkthrough:url:absolute]\\n\\nThank you,\\nThe WalkHub Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

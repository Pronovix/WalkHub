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
  return $items;
}

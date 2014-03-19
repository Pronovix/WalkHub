<?php
/**
 * @file
 * walkthrough_notification.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function walkthrough_notification_default_rules_configuration() {
  $items = array();
  $items['rules_log_broken_walkthroughs'] = entity_import('rules_config', '{ "rules_log_broken_walkthroughs" : {
      "LABEL" : "Log broken walkthroughs",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "message_notify", "flag" ],
      "ON" : { "flag_flagged_walkthrough_broken" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "walkthrough_flagged_as_broken",
              "param_user" : [ "flagging-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-broken-walkthrough" ],
            "value" : [ "flagged-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-broken-author" ],
            "value" : [ "flagged-node:author" ]
          }
        },
        { "message_notify_process" : {
            "message" : [ "entity-created" ],
            "mail" : "[entity-created:field-broken-author:mail]"
          }
        }
      ]
    }
  }');
  $items['rules_log_updated_walkthroughs'] = entity_import('rules_config', '{ "rules_log_updated_walkthroughs" : {
      "LABEL" : "Log updated walkthroughs",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "message_notify" ],
      "ON" : { "node_update--walkthrough" : { "bundle" : "walkthrough" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "walkthrough_has_been_updated",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-updated-walkthrough" ],
            "value" : [ "node" ]
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "node:flag-subscribe-content-user" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "message_notify_process" : { "message" : [ "entity-created" ], "mail" : "[list-item:mail]" } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}

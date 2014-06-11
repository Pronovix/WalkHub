<?php

/**
 * @file invite.api.php
 * Hooks provided by the Invite module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow other modules to act on invite's withdrawn
 *
 * @param Invite $invite
 */
function hook_invite_withdraw($invite) {
  // Delete notifications when user withdrawn invitation.
  db_delete('invite_notifications')
    ->condition('iid', $invite->iid)
    ->execute();
}

/**
 * Allow other modules to act when invite accepted.
 *
 * @param Invite $invite
 */
function hook_invite_accept($invite) {
  global $user;

  // Add message, when user accepts invite.
  $message = array(
    'iid' => $invite->iid,
    'uid' => $invite->uid,
    'inviter' => $invite->uid,
    'invitee' => $invite->invitee,
    'message_type' => 'inviter_notification',
  );

  drupal_write_record('invite_notifications', $message);
}

/**
 * Alters target roles for user.
 *
 * Used when needed to add/change resulting roles for user.
 *
 * @param array $targets
 *   Array of roles which will be added to invited user account.
 * @param Invite $invite
 *   Invite's object
 * @param object $account
 *   Invited user account object.
 */
function hook_invite_target_roles_alter($targets, $invite, $account) {
  // Add 'friday invited' role if user registering on Friday
  if (date("N", time()) == 5) {
    $targets[ROLE_FRIDAY_INVITED] = ROLE_FRIDAY_INVITED;
  }
}

/**
 * Defines the module as being an invite sending controller.
 *
 * @return
 *   An array of settings containing the keys:
 *   - label: A human readable, translated label for the controller.
 */
function hook_invite_sending_controller() {
  return array(
    'label' => t('My module invitation controller'),
  );
}

/**
 * Sends the invitation.
 *
 * Called by the Invite::sendInvite() method.
 *
 * @param Invite $invite
 *   The invitation to send.
 */
function hook_invite_send($invite) {
  if (!empty($invite->type_details()->invite_sending_controller['my_module'])) {
    global $language;
    $entity = entity_metadata_wrapper('invite', $invite);
    $params = array('invite' => $invite, 'wrapper' => $entity);
    $from = $entity->inviter->mail->value();
    drupal_mail('my_module', 'invite', $entity->invitee->mail->value(), $language, $params, $from, TRUE);
  }
}

/**
 * @} End of "addtogroup hooks".
 */

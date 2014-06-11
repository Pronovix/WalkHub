<?php

/**
 * Invte view callback.
 *
 * @param Invite $invite
 * @return bool
 */
function invite_view($invite) {
  drupal_set_title(entity_label('invite', $invite));
  return entity_view('invite', array(entity_id('invite', $invite) => $invite), 'full');
}

/**
 * Invitation accept callback.
 *
 * @param Invite $invite
 */
function invite_accept($invite) {
  global $user;

  $redirect = '<front>';
  $message = '';

  if ($user->uid == $invite->uid) {
    $message = t('You could not use own invite.');
    $redirect = '<front>';
  }
  elseif (!$user->uid && (empty($invite->invitee)) && $invite->status() == INVITE_VALID) {
    // Process new user invitation.
    $_SESSION[INVITE_SESSION_CODE] = $invite->reg_code;
    $redirect = variable_get('invite_registration_path', 'user/register');
  }
  elseif (!empty($user->uid) && ($invite->status() == INVITE_VALID)) {
    $invite->invitee = $user->uid;
    $invite->joined = REQUEST_TIME;
    entity_save('invite', $invite);

    unset($_SESSION[INVITE_SESSION_CODE]);
    $inviter = $invite->inviter();
    $message = t('You have accepted the invitation from !user', array('!user' => theme('username', array('account' => $inviter))));
    $redirect = 'user';
  }
  elseif (empty($user->uid) && !empty($invite->invitee) && ($invite->status() == INVITE_VALID)) {
    $_SESSION[INVITE_SESSION_CODE] = $invite->reg_code;
    $message = t('You should login first to accept invite.');
    $redirect = 'user/login';
  }
  else {
    switch ($invite->status()) {
      case INVITE_WITHDRAWN:
        $message = t('This invitation has been withdrawn.');
        break;

      case INVITE_USED:
        $message = t('This invitation has already been used.');
        break;

      case INVITE_EXPIRED:
        $message = t('This invitation has expired.');
        break;

      default:
        $redirect = 'user';
    }
  }

  if (!empty($message)) {
    drupal_set_message($message);
  }
  drupal_goto($redirect);
}

/**
 * Menu callback; resend an expired invite.
 *
 * @param Invite $invite
 *   An invitate object.
 *
 * @return Array
 *   renderable array, representing a page.
 */
function invite_resend($invite) {
  global $user;

  // Inviter must match current user and invitation must have expired.
  if ($invite->uid == $user->uid && $invite->expiry < REQUEST_TIME && $invite->joined == 0 && $invite->canceled == 0) {
    $invite->sendInvite();
  }
  else {
    return MENU_ACCESS_DENIED;
  }

  return array(
    'message' => t('Invite was sucessfuly resended.'),
    'invite' => entity_view('invite', array(entity_id('invite', $invite) => $invite), 'full'),
  );
}

/**
 * Menu callback; display confirm form to withdraw an invitation.
 *
 * @param $form
 * @param $form_state
 * @param Invite $invite
 *   Invite object.
 * @return array
 */
function invite_withdraw_form($form, &$form_state, $invite) {
  global $user;

  $form['invite'] = array(
    '#type' => 'value',
    '#value' => $invite,
  );
  $description = (!$invite->joined && $invite->expiry > REQUEST_TIME) ? t("The invitee won't be able to register any more using this invitation !invite<br/>", array('!invite' => drupal_render(entity_view('invite', array(entity_id('invite', $invite) => $invite), 'full')))) . ' ' : '';
  $redirect = !empty($_REQUEST['destination']) ? $_REQUEST['destination'] : '<front>';

  return confirm_form(
    $form,
    t('Are you sure you want to withdraw the invitation?'),
    $redirect,
    $description . t('This action cannot be undone.'),
    t('Withdraw'),
    t('Cancel')
  );
}

/**
 * Submit handler to withdraw an invitation.
 *
 * @param $form
 * @param $form_state
 */
function invite_withdraw_form_submit($form, &$form_state) {
  $invite = $form_state['values']['invite'];

  db_update('invite')
    ->fields(array(
    'canceled' => 1,
  ))
    ->condition('reg_code', $invite->reg_code)
    ->execute();

  drupal_set_message(t('!invite has been withdrawn.', array('!invite' => l('Invitation', 'invite/' . $invite->iid))));

  // Notify other modules.
  module_invoke_all('invite_withdraw', $invite);
  if (module_exists('rules')) {
    rules_invoke_event('invite_withdraw', $invite);
  }
  drupal_goto('<front>');
}


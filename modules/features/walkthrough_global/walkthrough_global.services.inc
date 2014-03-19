<?php
/**
 * @file
 *  Custom services endpoint implementations.
 */

/**
 * Create a user based on the received information.
 */
function _walkthrough_global_resource_registration($username, $mail, $password, $token) {
  // Load the required includes for saving profile information
  // with drupal_form_submit().
  module_load_include('inc', 'user', 'user.pages');

  // register a new user
  $form_state['values'] = array(
    'name' => $username,
    'mail' => $mail,
    'legal_accept' => 1,
    'extras-1' => 1,
    'status' => 1,
    'pass' => array(
      'pass1' => $password,
      'pass2' => $password,
    ),
  );

  // execute the register form
  drupal_form_submit('user_register_form', $form_state);
  // find and store the new user into the form_state
  if(isset($form_state['values']['uid'])) {
    $form_state['user'] = user_load($form_state['values']['uid']);
  }

  // Error if needed.
  if ($errors = form_get_errors()) {
    return services_error(implode(" ", $errors), 406, array('form_errors' => $errors));
  }
  else {
    $user = array('uid' => $form_state['user']->uid);
    if ($uri = services_resource_uri(array('user', $user['uid']))) {
      $user['uri'] = $uri;
    }
    return $user;
  }
}

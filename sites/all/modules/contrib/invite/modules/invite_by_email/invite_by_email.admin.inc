<?php

/**
 * Settings form for Invite By Mail
 *
 * @return array
 */
function invite_by_email_settings_form() {
  $form['invite_message_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Editable subject'),
    '#description' => t('Choose whether users should be able to customize the subject.'),
    '#default_value' => variable_get('invite_message_editable', FALSE),
  );

  $form['invite_default_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('invite_default_mail_subject', t('[invite:inviter:name] has sent you an invite!')),
    '#description' => t('Type the default subject of the invitation e-mail.') . ' ' . t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#required' => TRUE,
  );

  $form['invite_default_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Mail template'),
    '#default_value' => variable_get('invite_default_mail_body', ''),
    '#required' => TRUE,
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
  );

  $form['invite_default_replace_tokens'] = array(
    '#type' => 'checkbox',
    '#title' => t('Apply token replacements'),
    '#default_value' => variable_get('invite_default_replace_tokens', TRUE),
    '#description' => t('Whether token replacement patterns should be applied.'),
  );

  if (module_exists('token')) {
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['token_help']['help'] = array(
      '#markup' => theme('token_tree', array('token_types' => array('user', 'profile', 'invite'))),
    );
  }

  $form['invite_use_users_email'] = array(
    '#type' => 'radios',
    '#title' => t('<em>From</em> e-mail address'),
    '#description' => t('Choose which e-mail address will be in the From: header for the invitation mails sent; <em>site</em> or <em>inviter</em>. <em>Site</em> will use the default e-mail address of the site, whereas <em>inviter</em> will use the e-mail address of the user who is sending the invitation. Alternatively, you can set this value manually by clicking on <em>advanced settings</em> below.'),
    '#options' => array(t('Site'), t('Inviter')),
    '#default_value' => variable_get('invite_use_users_email', 0),
  );

  $form['invite_use_users_email_replyto'] = array(
    '#type' => 'radios',
    '#title' => t('<em>Reply-To</em> e-mail address'),
    '#description' => t('Choose which e-mail address will be in the Reply-To: header for the invitation mails sent; <em>site</em> or <em>inviter</em>. <em>Site</em> will use the default e-mail address of the site, whereas <em>inviter</em> will use the e-mail address of the user who is sending the invitation. Alternatively, you can set this value manually by clicking on <em>advanced settings</em> below.'),
    '#options' => array(t('Site'), t('Inviter')),
    '#default_value' => variable_get('invite_use_users_email_replyto', 0),
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('<strong>Note:</strong> The addresses defined here will replace the site e-mail, if it is selected above.'),
  );

  $form['advanced']['invite_manual_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Manually override <em>From</em> e-mail address'),
    '#default_value' => variable_get('invite_manual_from', ''),
    '#description' => t('The e-mail address the invitation e-mail is sent from.'),
  );

  $form['advanced']['invite_manual_reply_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Manually override <em>Reply-To</em> e-mail address'),
    '#default_value' => variable_get('invite_manual_reply_to', ''),
    '#description' => t('The e-mail address you want recipients to reply to.'),
  );

  return system_settings_form($form);

}

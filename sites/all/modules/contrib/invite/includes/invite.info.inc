<?php

/**
 * Extend the defaults for Invite content type.
 */
class InviteMetadataController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The invite type.'),
      'type' => 'invite_type',
    ) + $properties['type'];

    unset($properties['arguments']);
    // Unset the uid and invitee properties, as it is available via the user anyway.
    unset($properties['uid']);
    unset($properties['invitee']);

    $properties['inviter'] = array(
      'label' => t("Inviter"),
      'type' => 'user',
      'description' => t("The user who sent invitation."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'schema field' => 'uid',
      'required' => TRUE,
    );

    $properties['invitee'] = array(
      'label' => t("Invitee"),
      'type' => 'user',
      'description' => t("The user registered with invitation."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'schema field' => 'invitee',
      'required' => TRUE,
    );

    $properties['created'] = array(
      'label' => t('Date created'),
      'type' => 'date',
      'description' => t('The date the invite was created.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer invite entities',
      'schema field' => 'created',
    );

    $properties['changed'] = array(
      'label' => t('Date changed'),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t('The date the node was most recently updated.'),
    );

    $properties['expiry'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time invite will be expired.'),
    ) + $properties['expiry'];

    $properties['joined'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time user have joined.'),
    ) + $properties['joined'];

    $properties['invite_accept_link'] = array(
      'label' => t('Invite action link: accept'),
      'description' => t('Displays link for invite accepting.'),
      'getter callback' => 'invite_metadata_entity_get_properties',
      'type' => 'uri',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['invite_withdraw_link'] = array(
      'label' => t('Invite action link: withdrawn'),
      'description' => t('Displays link for invite withdrawn.'),
      'getter callback' => 'invite_metadata_entity_get_properties',
      'type' => 'uri',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['invite_resend_link'] = array(
      'label' => t('Invite action link: resend'),
      'description' => t('Displays link for invite resending.'),
      'getter callback' => 'invite_metadata_entity_get_properties',
      'type' => 'uri',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['status'] = array(
      'label' => t('Status'),
      'description' => t('Display human-readable status.'),
      'getter callback' => 'invite_metadata_entity_get_properties',
      'type' => 'text',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    return $info;
  }
}

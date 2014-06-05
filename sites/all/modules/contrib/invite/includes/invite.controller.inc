<?php

/**
 * Validity constants.
 */
define('INVITE_VALID', 1);
define('INVITE_WITHDRAWN', 2);
define('INVITE_USED', 3);
define('INVITE_EXPIRED', 4);


class InviteController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'created' => REQUEST_TIME,
      'expiry' => REQUEST_TIME + variable_get('invite_default_expiry_time', 30) * 24 * 60 * 60,
      'uid' => $user->uid,
      'invitee' => 0,
      'reg_code' => invite_generate_code(),
      'data' => array(),
    );
    return parent::create($values);
  }

  /**
   * @param Invite $entity
   * @param string $view_mode
   * @param null $langcode
   * @param array $content
   * @return mixed
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $account = user_load($entity->uid);
    $content['author'] = array(
      '#prefix' => '<div>',
      '#suffix' => '</div>',
      '#markup' => t('Created by: <strong>!author</strong>', array('!author' => theme('username', array('account' => $account))))
    );
    $content['status'] = array(
      '#prefix' => '<div>',
      '#suffix' => '</div>',
      '#markup' => t('Status: <strong>!status</strong>', array('!status' => $entity->status(TRUE)))
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}

class InviteTypeController extends EntityAPIControllerExportable {
  public function create(array $values = array()) {
    $values += array(
      'label' => '',
      'description' => '',
      'data' => array(),
    );
    return parent::create($values);
  }

  /**
   * Save Invite Type.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    // Rebuild menu registry. We do not call menu_rebuild directly, but set
    // variable that indicates rebuild in the end.
    // @see _http://drupal.org/node/1399618
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
 * UI controller for Task Type.
 */
class InviteTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage Invite types.';
    return $items;
  }
}

/**
 * Invite class.
 */
class Invite extends Entity {
  /**
   * The user id of the profile owner.
   *
   * @var integer
   */
  public $uid;

  public function type_details() {
    return invite_get_types($this->type);
  }

  /**
   * Returns the user owning this profile.
   */
  public function inviter() {
    return user_load($this->uid);
  }

  /**
   * Returns the user owning this profile.
   */
  public function invitee() {
    if (!empty($this->invitee)) {
      return user_load($this->invitee);
    }
    else {
      return FALSE;
    }
  }

  public function joinLink() {
    return url('invite/accept/' . $this->reg_code, array('absolute' => TRUE));
  }

  public function sendInvite() {
    $result = FALSE;
    if (!empty($this->sendNotification)) {
      // Notify other modules.
      entity_get_controller('invite')->invoke('send', $this);
      $result = TRUE;
    }
    else {
      $result = TRUE;
    }

    return $result;
  }

  /**
   * Sets a new user owning this profile.
   *
   * @param $account
   *   The user account object or the user account id (uid).
   */
  public function setUser($account) {
    $this->uid = is_object($account) ? $account->uid : $account;
  }

  public function __construct($values = array()) {
    if (isset($values['inviter'])) {
      $this->setUser($values['inviter']);
      unset($values['inviter']);
    }
    if (!isset($values['label']) && isset($values['type']) && $type = invite_get_types($values['type'])) {
      // Initialize the label with the type label, so newly created profiles
      // have that as interim label.
      $values['label'] = $type->label;
    }
    $this->sendNotification = TRUE;

    parent::__construct($values, 'invite');
  }

  public function status($readable = FALSE) {
    if (!$this || $this->canceled != 0) {
      return $readable ? t('withdrawn') : INVITE_WITHDRAWN;
    }
    elseif ($this->joined != 0) {
      return $readable ? t('used') : INVITE_USED;
    }
    elseif ($this->expiry < REQUEST_TIME) {
      return $readable ? t('expired') : INVITE_EXPIRED;
    }
    else {
      return $readable ? t('valid') : INVITE_VALID;
    }
  }

  protected function defaultLabel() {
    $entity = entity_metadata_wrapper('invite', $this);
    return t('Invitation #@number', array('@number' => $this->identifier()));
  }

  protected function defaultUri() {
    return array('path' => 'invite/' . $this->identifier());
  }

  public function save() {
    return parent::save();
  }

}

/**
 * Invite Type class.
 */
class InviteType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  /**
   * Array with the argument keys.
   *
   * This is used to allow creation of entity metadata properties based
   * on the argument keys.
   *
   * @see InviteMetadataController::entityPropertyInfo()
   *
   * @var array
   */
  public $argument_keys = array();

  public $argument = array();

  public $invite_sending_controller = array();

  public function __construct($values = array()) {
    parent::__construct($values, 'invite_type');
    $controllers = db_select('invite_sending_controller', 'isc')
      ->fields('isc')
      ->condition('type', array($this->type))
      ->execute();
    $this->invite_sending_controller = array();
    foreach ($controllers as $controller) {
      $this->invite_sending_controller[$controller->name] = $controller->name;
    }
  }

  function hasSendingController($controller_name) {
    $result = FALSE;
    if (!empty($this->invite_sending_controller[$controller_name])) {
      $result = TRUE;
    }
    return $result;
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

  public function save() {
    parent::save();
    $controllers = array();
    // Remove old controller entries.
    db_delete('invite_sending_controller')
      ->condition('type', $this->type)
      ->execute();
    // Add controllers.
    foreach ($this->invite_sending_controller as $controller_name) {
      $module = !empty($this->module) ? $this->module : '';
      if (!in_array($controller_name, $controllers)) {
        $controllers[] = $controller_name;
        db_insert('invite_sending_controller')
          ->fields(array(
            'type' => $this->type,
            'module' => $module,
            'name' => $controller_name,
          ))
          ->execute();
      }
    }
  }

  public function delete() {
    parent::delete();
    db_delete('invite_sending_controller')
      ->condition('type', $this->type)
      ->execute();
  }
}

/**
 * Generates a unique tracking code.
 *
 * @return string
 *   An 10-digit unique tracking code.
 */
function invite_generate_code() {
  do {
    $reg_code = user_password(10);
    $result = (bool) db_query_range('SELECT reg_code FROM {invite} WHERE reg_code = :regcode', 0, 1, array(':regcode' => $reg_code))->fetchField();
  } while ($result);

  return $reg_code;
}

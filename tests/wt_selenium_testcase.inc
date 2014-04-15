<?php
/**
 * @file
 * Selenium base file.
 *
 * Set settings for your environment in selenium_settings.inc!
 */

require_once 'vendor/autoload.php';

// @Todo Check for drupal error messages on page load.

/**
 * Default Drupal roles.
 */
define('PX_SELENIUM_ROLE_ANONYMOUS_USER', 1);
define('PX_SELENIUM_ROLE_AUTHENTICATED_USER', 2);
define('PX_SELENIUM_BROWSER', 'firefox');

/**
 * Singleton class for storing environment variables about the selenium
 * instance.
 */
class LocalSeleniumSettings {
  protected $base_url = '';
  protected $admin_username = '';
  protected $admin_password = '';
  protected $browser = 'firefox';

  /**
   * @return string
   */
  public function getAdminPassword() {
    return $this->admin_password;
  }

  /**
   * @return string
   */
  public function getAdminUsername() {
    return $this->admin_username;
  }

  /**
   * @return string
   */
  public function getBaseUrl() {
    return $this->base_url;
  }

  /**
   * @return string
   */
  public function getBrowser() {
    return $this->browser;
  }

  private static $instance;

  /**
   * Get local settings instance.
   */
  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new self();
    }

    return self::$instance;
  }

  /**
   * Constructor.
   *
   * Read selenium settings from selenium_settings.inc.
   */
  public function __construct() {
    include 'selenium_settings.inc';

    $this->base_url = SELENIUM_SETTINGS_BASE_URL;
    $this->admin_username = SELENIUM_SETTINGS_ADMIN_USERNAME;
    $this->admin_password = SELENIUM_SETTINGS_ADMIN_PASSWORD;
    $this->browser = SELENIUM_SETTINGS_BROWSER;
  }
}

abstract class WalkhubSeleniumTestCase extends Sauce\Sausage\WebDriverTestCase {
  protected $settings;

  public static $browsers = array(
    array(
      'browserName' => PX_SELENIUM_BROWSER,
    ),
  );

  public function setUp() {
    parent::setUp();
    $this->setSeleniumServerRequestsTimeout(120000);
  }

  /**
   * Constructor
   *
   * Initialize environment variables.
   * @see LocalSeleniumSettings
   */
  public function __construct($name = NULL, array $data = array(), $dataName = '') {
    parent::__construct($name, $data, $dataName);

    $this->settings = LocalSeleniumSettings::getInstance();

    $this->setBrowserUrl($this->settings->getBaseUrl());
  }

  /**
   * Overrides url() function to support base_url.
   */
  public function url($url) {
    return parent::url($this->settings->getBaseUrl() ? "{$this->settings->getBaseUrl()}/{$url}" : $url);
  }

  public function isElementExists(PHPUnit_Extensions_Selenium2TestCase_Element $element) {
    return $this->waitUntil(function (PHPUnit_Extensions_Selenium2TestCase $test) use ($element) {
      try {
        return $element && $element->displayed();
      } catch (\Exception $e) {
        $test->log($e->getMessage());
        return false;
      }
    });
  }

  public function assertElementNotPresent(PHPUnit_Extensions_Selenium2TestCase_Element $element, $message = '') {
    $this->assertFalse($this->isElementExists($element), $message);
  }

  public function assertElementPresent(PHPUnit_Extensions_Selenium2TestCase_Element $element, $message = '') {
    $this->assertTrue($this->isElementExists($element), $message);
  }

  /**
   * Helper function to log in as admin.
   */
  protected function adminLogin() {
    $this->login($this->settings->getAdminUsername(), $this->settings->getAdminPassword());
  }

  /**
   * Creates a Drupal user account with the specified roles.
   *
   * @param array $roles
   *   (Optional) Drupal role ids.
   *   @see PX_SELENIUM_ROLE_AUTHENTICATED_USER
   *
   * @param array $groups
   *   (Optional) Drupal group names.
   *
   * @return object
   *   Account object.
   *   - username
   *   - email
   *   - password
   *   - roles
   *   - groups
   */
  protected function createUser(array $roles = array(), array $groups = array()) {
    $account = new stdClass();
    $account->username = $this->randomString();
    $account->first_name = $this->randomString();
    $account->surname = $this->randomString();
    $account->email = "{$account->username}@test.test";
    $account->password = $this->randomString();
    $account->roles = $roles;
    $account->groups = $groups;

    $this->adminLogin();

    // Create new user with all the roles available.
    $this->url('admin/people/create');
    if ($this->isElementExists($this->byId('edit-name'))) {
      mock($this->byId('edit-name'))->value($account->username);
    }
    mock($this->byId('edit-mail'))->value($account->email);
    mock($this->byId('edit-pass-pass1'))->value($account->password);
    mock($this->byId('edit-pass-pass2'))->value($account->password);

    mock($this->byId('edit-field-profile-first-name-und-0-value'))->value($account->first_name);
    mock($this->byId('edit-field-profile-surname-und-0-value'))->value($account->surname);

    // Add roles.
    if (!empty($roles)) {
      foreach ($roles as $rid) {
        mock($this->byId("edit-roles-{$rid}"))->click();
      }
    }

    // Add groups.
    if (!empty($groups)) {
      foreach ($groups as $group) {
        $this->select($this->byId('edit-og-user-node-und-0-default'), 'label', $group);
      }
    }

    mock($this->byId('edit-submit'))->click();

    return $account;
  }

  /**
   * Helper function to log in to Drupal.
   *
   * @param string $username
   *   Drupal username.
   * @param string $password
   *   Password.
   */
  protected function login($username, $password) {
    $this->url('user/logout');
    $this->url('user/login');

    $user = mock($this->byId('edit-name'));
    $user->click();
    $user->value($username);

    $pass = mock($this->byId('edit-pass'));
    $pass->click();
    $pass->value($password);

    mock($this->byId('edit-submit'))->click();
  }

  /**
   * Get a random string.
   *
   * @see user_password()
   *
   * @param int $length
   *   Length of the random string to generate.
   *
   * @return string
   *   Random string.
   */
  protected function randomString($length = 10) {
    // This variable contains the list of allowable characters for the
    // password. Note that the number 0 and the letter 'O' have been
    // removed to avoid confusion between the two. The same is true
    // of 'I', 1, and 'l'.
    $allowable_characters = 'abcdefghijkmnopqrstuvwxyzABCDEFGHJKLMNPQRSTUVWXYZ23456789';

    // Zero-based count of characters in the allowable list:
    $len = strlen($allowable_characters) - 1;

    // Declare the password as a blank string.
    $pass = '';

    // Loop the number of times specified by $length.
    for ($i = 0; $i < $length; $i++) {

      // Each iteration, pick a random character from the
      // allowable string and append it to the password:
      $pass .= $allowable_characters[mt_rand(0, $len)];
    }

    return $pass;
  }

  /**
   * Implement pause command.
   *
   * This command is not availible in selenium RC.
   * @see https://groups.google.com/forum/?fromgroups=#!topic/selenium-users/bxStWltjBcU
   */
  protected function pause($milliseconds) {
    sleep($milliseconds/1000);
  }

  /**
   * Get the relative url of the page.
   *
   * @return string|bool
   */
  protected function getRelativeUrl() {
    $location = $this->getBrowserUrl();
    $base_url = preg_quote($this->settings->getBaseUrl(), '#');
    return preg_replace("#^{$base_url}#", '', $location);
  }

  /**
   * Fills in a file upload form.
   *
   * To properly generate the file needed for uploading the selenium server and
   * the running environment has to be on the same server.
   * This restriction does not apply for files existing on the test
   * environment.
   *
   * @param PHPUnit_Extensions_Selenium2TestCase_Element $element
   * @param string $extension
   *   File extension (without dot).
   * @param string $filename
   *   (Optional) File name to upload.
   *   If not given it will be automatically generated.
   * @internal param string $selector Selenium selector.*   Selenium selector.
   */
  protected function fileUpload(PHPUnit_Extensions_Selenium2TestCase_Element $element, $extension, $filename = NULL) {
    if ($filename === NULL) {
      $filename = $this->randomString();
    }

    $full_filepath = sys_get_temp_dir() . '/' . $filename . '.' . $extension;

    if (!file_exists($full_filepath)) {
      touch($full_filepath);
    }

    $element->value($full_filepath);
    $this->pause(1000);
  }

  public function verifyTextPresent($text, $message = '') {
    $source = $this->source();
    $text_present = (strpos($source, $text) !== FALSE);

    return $this->assertTrue($text_present, $message);
  }

  public function verifyTextNotPresent($text, $message = '') {
    $source = $this->source();
    $text_present = (strpos($source, $text) !== FALSE);

    return $this->assertFalse($text_present, $message);
  }
}

function mock($obj) {
  return new Mocker($obj);
}

/**
 * Class Mocker
 *
 * Some commonly used methods to avoid false negative warnings with static type checkers.
 * @method value()
 * @method click()
 * @method text()
 */
class Mocker {
  protected $obj;

  public function __construct($obj) {
    $this->obj = $obj;
  }

  public function __toString() {
    if ($this->obj === NULL) {
      return "NULL";
    }
    if (is_object($this->obj)) {
      return get_class($this->obj);
    }
    if (is_scalar($this->obj)) {
      return (string) $this->obj;
    }

    return "Unkown value";
  }

  public function __call($name, $arguments) {
    if ($this->obj && is_object($this->obj) && (method_exists($this->obj, $name) || method_exists($this->obj, '__call'))) {
      return call_user_func_array(array($this->obj, $name), $arguments);
    }
    else {
      throw new PHPUnit_Framework_ExpectationFailedException("Method {$name} does not exists on {$this}.");
    }
  }
}

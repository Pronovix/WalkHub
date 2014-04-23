<?php
/**
 * @file
 * Test Walkthrough walkhub site install process.
 */

require_once './vendor/autoload.php';
require_once './wt_selenium_testcase.inc';

class WalkthroughSiteInstall extends WalkhubSeleniumTestCase {

  /**
   * Tests that Walkthrough features are not overridden after site install.
   */
  public function testFeaturesNotOverridden() {
    // @Todo find visible "Overridden" text.
    // verifyTextNotPresent() is not enough, because the "Overridden" text is always visible.
  }

  /**
   * Tests that Walkthrough features are not disabled after site install.
   */
  public function testFeaturesNotDisabled() {
    $this->walkthroughFeaturesAdminPage();

    // @Todo find visible "Disabled" text.
    // verifyTextNotPresent() is not enough, because the "Overridden" text is always visible.
    // Make sure no features are disabled.
    // $this->verifyTextNotPresent('Disabled');
  }

  /**
   * Tests that there are no errors on the file-system settings admin page.
   *
   * Note that wiatForPageToLoad() cecks for drupal warnings and errors, where
   * an error message would be written if the file system is wrongly
   * configured.
   * @see PxSeleniumTestCase::waitForPageToLoad()
   */
  public function testFileSystemSettings() {
    $this->adminLogin();

    $this->url('admin/config/media/file-system');

    // Save file system settings.
    $this->byId('edit-submit')->click();
  }

  /**
   * Go to the Walkthroguh features admin page.
   */
  protected function walkthroughFeaturesAdminPage() {
    $this->adminLogin();

    $this->url("admin/structure/features");
    $this->byLinkText('Walkthrough')->click();
    // Pause for 10 seconds, so the feature statuses are loaded.
    $this->pause(10000);
  }

  /**
   * Checks that roles are present after site install.
   *
   * Roles:
   * - anonymous user
   * - authenticated user
   */
  public function testRolesCreated() {
    $this->adminLogin();

    $this->url("admin/people/permissions/roles");

    $roles = array(
      'anonymous user',
      'authenticated user',
    );

    foreach ($roles as $role) {
      $this->verifyTextPresent($role);
    }
  }

  /**
   * Test that the Walkthrough theme is set up after site install.
   */
  public function testTheme() {
    $this->adminLogin();

    $this->url("admin/appearance");

    $this->verifyTextPresent("Walkhub  (default theme)");
  }

  /**
   * Tests that the admin page is not accessible for anonymous users.
   */
  public function testAdminPageIsInaccessibleForAnonymous() {
    $this->url('user/logout');

    $this->url('admin');
    $this->assertSiteTitle('Access denied');
  }
}

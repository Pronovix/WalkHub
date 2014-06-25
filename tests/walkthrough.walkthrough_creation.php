<?php
/**
 * @file
 * Test Walkthrough creation processes.
 */

require_once './vendor/autoload.php';
require_once './wt_selenium_testcase.inc';

class WalkthroughCreation extends WalkhubSeleniumTestCase {

  public function testEmptyWalkthroughCreation() {
    $this->adminLogin();

    $this->url("/node/add/walkthrough");
    $this->byId('edit-title')->value('Test empty walkthrough');
    $this->byId('edit-field-severity-of-the-change-und')->value();
    $this->select($this->byId('edit-field-severity-of-the-change-und'))->selectOptionByLabel('does not change anything (tour)');

    $this->byId("edit-submit")->click();

    $title = $this->byId('page-title')->text();
    $this->assertEquals("Test empty walkthrough", $title);
  }

  /**
   * Test walkthrough prerequisites.
   */
  public function testWalkthroughPrerequisites() {
    $this->adminLogin();

    // Create an empty walkthrough.
    $this->testEmptyWalkthroughCreation();

    $title = $this->randomString();
    // Explode the newly created node's url, to get the node nid.
    $exploded_url = explode('/', $this->getRelativeUrl());
    if (!empty($exploded_url[2]) && is_numeric($exploded_url[2])) {
      $nid = $exploded_url[2];
      // Create a walkthrough
      $this->url("/node/add/walkthrough");
      $this->byId('edit-value')->value($title);

      // Set the prerequisite field to point at the previously created walkthrough.
      $this->byId("edit-field-prerequisites-und-0-target-id")->value("Test empty Walkthrough ({$nid})");
      $this->select($this->byId('edit-field-severity-of-the-change-und'))->selectOptionByLabel('does not change anything (tour)');
      $this->click("id=edit-submit");

      $title = $this->byId('page-title')->text();
      $this->assertEquals($title, $title);

      $this->byLinkText('Start walkthrough')->click();
      sleep(2);

      $this->verifyTextPresent("Test empty walkthrough");
    }
  }
}


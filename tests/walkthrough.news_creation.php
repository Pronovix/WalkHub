<?php
/**
 * @file
 * Test News creation process.
 */

require_once './vendor/autoload.php';
require_once './wt_selenium_testcase.inc';


class CreateNews extends WalkhubSeleniumTestCase {

  /**
   * Recorded steps.
   */
  public function testCreateNews() {
    $this->adminLogin();
    $test = $this; // Workaround for anonymous function scopes in PHP < v5.4.
    $session = $this->prepareSession(); // Make the session available.

    $title = $this->randomString();

    // get
    $this->url("/node/add/walkhub-news");
    // setElementText
    $element = $this->byId("edit-title");
    $element->click();
    $element->clear();
    $element->value($title);

    // @Todo Add screening target

    // clickElement
    $this->byId("edit-submit")->click();
    $this->assertSiteTitle($title);
  }
}

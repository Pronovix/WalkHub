<?php
/**
 * @file
 * Test Walkthrough walkhub site install process.
 */

require_once './vendor/autoload.php';
require_once './wt_selenium_testcase.inc';

class CreateBlog extends WalkhubSeleniumTestCase {

  /**
   * Recorded steps.
   */
  public function testCreateBlog() {
    $this->adminLogin();
    $test = $this; // Workaround for anonymous function scopes in PHP < v5.4.
    $session = $this->prepareSession(); // Make the session available.

    $title = $this->randomString();
    $body = $this->randomString(10, WALKHUB_SELENIUM_EXPECT_XSS);
    $subtitle = $this->randomString();

    // get
    $this->url("/node/add/blog-entry");
    // setElementText
    $element = $this->byId("edit-title");
    $element->click();
    $element->clear();
    $element->value($title);

    // setElementText
    $element = $this->byId("edit-field-subtitle-und-0-value");
    $element->click();
    $element->clear();
    $element->value($subtitle);

    // setElementSelected
    $element = $this->byId("edit-field-blog-category-und-8");
    if (!$element->selected()) {
      $element->click();
    }

    // setElementText
    $element = $this->byId("edit-body-und-0-value");
    $element->click();
    $element->clear();
    $element->value($body);

    // clickElement
    $this->byId("edit-submit")->click();

    $this->assertSiteTitle($title);
  }
}

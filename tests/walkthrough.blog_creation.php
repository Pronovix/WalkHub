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

    $title = $this->randomString();
    $body = $this->randomString(10, WALKHUB_SELENIUM_EXPECT_XSS);
    $subtitle = $this->randomString();

    $this->url("/node/add/blog-entry");
    $this->byId("edit-title")->value($title);

    $this->byId("edit-field-subtitle-und-0-value")->value($subtitle);

    $element = $this->byId("edit-field-blog-category-und-8");
    if (!$element->selected()) {
      $element->click();
    }

    $this->byId("edit-body-und-0-value")->value($body);

    $this->byId("edit-submit")->click();

    $this->assertSiteTitle($title);
  }
}

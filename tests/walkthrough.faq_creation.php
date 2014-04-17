<?php
/**
 * @file
 * Test FAQ creation process.
 */

require_once './vendor/autoload.php';
require_once './wt_selenium_testcase.inc';

class CreateFaq extends WalkhubSeleniumTestCase {

  /**
   * Recorded steps.
   */
  public function testCreateFaq() {
    $this->adminLogin();
    $test = $this; // Workaround for anonymous function scopes in PHP < v5.4.
    $session = $this->prepareSession(); // Make the session available.

    $title = $this->randomString();

    // get
    $this->url("/node/add/walkhub-faq-page");
    // setElementText
    $element = $this->byId("edit-title");
    $element->click();
    $element->clear();
    $element->value($title);

    // setElementText
    $element = $this->byId("edit-field-walkhub-questions-und-0-field-walkhub-faq-questions-und-0-value");
    $element->click();
    $element->clear();
    $element->value("test question");

    // setElementText
    $element = $this->byId("edit-field-walkhub-questions-und-0-field-walkhub-faq-answer-und-0-value");
    $element->click();
    $element->clear();
    $element->value("test answer");

    $this->byId("edit-submit")->click();
    $this->assertSiteTitle($title);
  }
}

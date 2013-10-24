(function ($, Drupal) {

  Drupal.behaviors.walkhubTheme = {
    attach: function (context, settings) {
      var allPanels = $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-answer').hide();
      console.log('processed');
      $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-questions').click(function() {
        allPanels.slideUp();
        $(this).next().slideDown();
        return false;
      });
    }
  };
})(jQuery, Drupal);

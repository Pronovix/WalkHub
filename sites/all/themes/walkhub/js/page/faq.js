(function ($, Drupal) {

  Drupal.behaviors.walkhubTheme = {
    attach: function (context, settings) {
      var allAns = $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-answer').hide();
      var allQuest = $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-questions');
      console.log('processed');
      $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-questions').click(function() {
        allAns.slideUp();
        allQuest.removeClass("active");
        $(this).addClass("active");
        $(this).next().slideDown();
        return false;
      });
    }
  };
})(jQuery, Drupal);

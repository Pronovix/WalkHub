(function ($, Drupal) {

  Drupal.behaviors.walkhubTheme = {
    attach: function (context, settings) {
      var $faq = $('.field-name-field-walkhub-questions .field-item', context);

      $faq.once('node-type-walkhub-faq-page', function () {
        console.log('processed');
        var $this = $(this);
        var $allQuestions = $this.find('.field-name-field-walkhub-faq-questions');

          $('.field-name-field-walkhub-faq-questions', this).click(function () {
            $('.field-name-field-walkhub-faq-answer').not($('.field-name-field-walkhub-faq-answer', $(this).parent())).slideUp();
            $('.field-name-field-walkhub-faq-answer', $(this).parent()).slideToggle();
            allQuestions.not($(this)).removeClass('open');
            $(this).toggleClass('open');
        });
      });
    }
  };

})(jQuery, Drupal);

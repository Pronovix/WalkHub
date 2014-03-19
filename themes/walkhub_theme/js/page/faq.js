(function ($, Drupal) {

  Drupal.behaviors.walkhubThemeFaq = {
    attach: function (context, settings) {
      Drupal.walkhubThemeFaq.faqClickAnimation(context, settings);
    }
  };

  Drupal.walkhubThemeFaq = {
    faqClickAnimation : function(context, settings) {
      var $allAns = $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-answer', context).hide();
      var $allQuest = $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-questions', context);

      $('.field-collection-item-field-walkhub-questions .field-name-field-walkhub-faq-questions').click(function() {
        var $this = $(this);
        $allAns.slideUp();
        $allQuest.removeClass("active");
        $this.addClass("active");
        $this.next().slideDown();
        return false;
      });
    }
  };

})(jQuery, Drupal);

(function ($, Drupal) {

  Drupal.behaviors.walkhubStepEdit = {
    attach: function (context, settings) {
      Drupal.walkhubStepEdit.makeBackButton(context, settings);
      Drupal.walkhubStepEdit.ifChecked(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    makeBackButton : function(context, settings) {
      $('.radius.form-submit').before('<a class="back button" href="javascript: history.go(-1)"><i class="icon-chevron-left"></i> Back</a>')
    },

    ifChecked : function(context, settings) {
      $('#edit-field-fc-step-show-title-und').click(function() {
        if( $(this).is(':checked')) {
          $("#edit-field-fc-step-name").show(200);
        } else {
          $("#edit-field-fc-step-name").hide(200);
        }
      });
    }
  }


})(jQuery, Drupal);

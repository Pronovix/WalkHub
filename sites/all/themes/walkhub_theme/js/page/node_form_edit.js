/**
 * Created with JetBrains PhpStorm.
 * User: Peter
 * Date: 2013.11.12.
 * Time: 15:46
 * To change this template use File | Settings | File Templates.
 */
(function ($, Drupal) {

  Drupal.behaviors.walkhubFormEdit = {
    attach: function (context, settings) {
      Drupal.walkhubStepEdit.makeButton(context, settings);
      Drupal.walkhubStepEdit.makeBackButton(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    makeButton : function(context, settings) {
      $('#ad-set .le')
        .append('<a class="button small open"><i class="icon-cog"></i> Advanced Settings</a>')
        .click(function(){
          $("#ad-set .ri").toggle( "200" );
          return false;
        });
    },
    makeBackButton : function(context, settings) {
      $('#edit-submit').before('<a class="back button" href="javascript: history.go(-1)"><i class="icon-chevron-left"></i> Back</a>')
    }
  }


})(jQuery, Drupal);

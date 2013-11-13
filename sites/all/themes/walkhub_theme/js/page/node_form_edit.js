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
      Drupal.walkhubStepEdit.insertIcon(context, settings);
      Drupal.walkhubStepEdit.stepHideShow(context, settings);
      Drupal.walkhubStepEdit.openAll(context, settings);
      Drupal.walkhubStepEdit.closeAll(context, settings);
      Drupal.walkhubStepEdit.parameters(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    makeButton : function(context, settings) {
      $('#ad-set .le').append('<a class="button small open"><i class="icon-cog"></i> Advanced Settings</a>')
        .click(function(){
          $("#ad-set .ri").toggle( "200" );
          return false;
        });
    },
    makeBackButton : function(context, settings) {
      $('#edit-submit').before('<a class="back button" href="javascript: history.go(-1)"><i class="icon-chevron-left"></i> Back</a>')
    },

    insertIcon : function(context, settings) {
      $('#edit-delete').prepend('<i class="icon-trash"></i> ');
      $('#edit-submit').prepend('<i class="icon-upload"></i> ');
      $('#edit-preview').prepend('<i class="icon-browser"></i> ');
      $('#edit-preview-changes').prepend('<i class="icon-eye"></i> ');
      $('#edit-field-fc-steps-und-add-more--2').prepend('<i class="icon-plus"></i> ');
    },


    stepHideShow : function(context, settings) {
      $('.step-title.button').click(function(){
          $('.walkthrough-step-container').toggle( "200" );
          return false;
        });
    },

    openAll : function(context, settings) {
      $('#open-all').click(function(){
        $('.walkthrough-step-container').show( "200" );
        return false;
      });
    },

    closeAll : function(context, settings) {
      $('#callopse-all').click(function(){
        $('.walkthrough-step-container').hide( "200" );
        return false;
      });
    },

    parameters : function(context, settings) {
      $('#parameters').click(function(){
        $('#edit-field-parameters').toggle( "200" );
        return false;
      });
    }
  }


})(jQuery, Drupal);

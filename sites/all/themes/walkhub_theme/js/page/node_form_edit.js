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
      Drupal.walkhubStepEdit.callopse(context, settings);
      Drupal.walkhubStepEdit.parameters(context, settings);
      Drupal.walkhubStepEdit.checkBox(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    makeButton : function(context, settings) {
      $('#ad-set .le', context).once('makeButton', function() {
        var $this = $(this);
        $this.append('<a class="button small open"><i class="icon-cog"></i>' + Drupal.t("Advanced Settings") + '</a>').click(function() {
            $("#ad-set .ri").toggle( "200" );
            return false;
          });
      })
    },

    makeBackButton : function(context, settings) {
      $('#edit-submit', context).once('makeBackButton', function() {
        var $this = $(this);
        $this.before('<a class="back button" href="javascript: history.go(-1)"><i class="icon-chevron-left"></i>' + Drupal.t("Back") + '</a>');
      });
    },


    insertIcon : function(context, settings) {
      $('#edit-delete', context).once('delete-button', function() {
        var $this = $(this);
        $this.prepend('<i class="icon-trash"></i> ');
      });

      $('#edit-submit', context).once('submit-button', function() {
        var $this = $(this);
        $this.prepend('<i class="icon-upload"></i> ');
      });

      $('#edit-preview', context).once('preview-button', function() {
        var $this = $(this);
        $this.prepend('<i class="icon-browser"></i> ');
      });

      $('#edit-preview-changes', context).once('preview-changes-button', function() {
        var $this = $(this);
        $this.prepend('<i class="icon-eye"></i> ');
      });

      $('#edit-field-fc-steps-und-add-more--2', context).once('field-fc-steps-und-add-more--2-button', function() {
        var $this = $(this);
        $this.prepend('<i class="icon-plus"></i> ');
      });
    },

    stepHideShow : function(context, settings) {
      $('.step-title.button', context).click(function() {
        var $this = $(this);
        var $container = $this.parent();
        $('.walkthrough-step-container', $container).toggle( "200" );
          return false;
        });
    },

    callopse : function(context, settings) {
      $('#callopse', context).click(function(){
        $('.walkthrough-step-container', context).toggle( "200" );
        return false;
      });
    },

    parameters : function(context, settings) {
      $('#parameters', context).click(function(){
        $('#edit-field-parameters', context).toggle( "200" );
        return false;
      });
    },

    checkBox : function(context, settings) {
      $('.field-name-field-fc-step-show-title input', context).click(function(){
        if( $(this).is(':checked')) {
          $(".field-name-field-fc-step-name", context).show(200);
        }
        else {
          $(".field-name-field-fc-step-name", context).hide(200);
        }
      });
    }
  }


})(jQuery, Drupal);

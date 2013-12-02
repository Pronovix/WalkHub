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
      Drupal.walkhubStepEdit.advSettings(context, settings);
      Drupal.walkhubStepEdit.imgSet(context, settings);
      Drupal.walkhubStepEdit.makeBackButton(context, settings);
      Drupal.walkhubStepEdit.insertIcon(context, settings);
      Drupal.walkhubStepEdit.stepHideShow(context, settings);
      Drupal.walkhubStepEdit.callopse(context, settings);
      Drupal.walkhubStepEdit.parameters(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    /**
     * Drupal base settings container
     *
     * @param context
     * @param settings
     */
    advSettings : function(context, settings) {
      $('#advset', context).once(function() {
        var $this = $(this);
        $this.click(function() {
          $('#add-set-hide', context).slideToggle( "200" );
          return false;
        });
      })
    },

    /**
     * Walkthrough set branding container
     *
     * @param context
     * @param settings
     */
    imgSet : function(context, settings) {
      $('#img-set-trigger', context).once(function() {
        var $this = $(this);
        $this.click(function() {
          $('#image-edit-cont-hide', context).slideToggle( "200" );
          return false;
        });
      })
    },

    /**
     * Backbutton make and function
     *
     * @param context
     * @param settings
     */
    makeBackButton : function(context, settings) {
      $('#edit-submit', context).once('makeBackButton', function() {
        var $this = $(this);
        $this.before('<a class="back button" href="javascript: history.go(-1)"><i class="icon-chevron-left"></i>' + Drupal.t("Back") + '</a>');
      });
    },

    /**
     * Insert icons the bottom of the editor page
     *
     * @param context
     * @param settings
     */
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

    /**
     * Open/Close functionality for one Step
     *
     * @param context
     * @param settings
     */
    stepHideShow : function(context, settings) {
      $('.step-title.button', context).once(function() {
        var $this = $(this);
        var $container = $this.parent();
        $this.click(function() {
          $('.walkthrough-step-container', $container).slideToggle( "200" );
          return false;
          });
        })
    },

    /**
     * Open/Close functionality for all of the
     * Steps in one button
     *
     * @param context
     * @param settings
     */
    callopse : function(context, settings) {
      $('#callopse', context).once(function() {
        var $this = $(this);
        var $container = $this.parent();
        $this.click(function() {
          $('.walkthrough-step-container', $container).slideToggle( "200" );
          return false;
        });
      })
    },

    /**
     * Parameters/Proxy Warning button function, slideToggle
     * the respective div
     *
     * @param context
     * @param settings
     */
    parameters : function(context, settings) {
      $('#parameters', context).once(function() {
        var $this = $(this);
        $this.click(function() {
          $('#adv-sett-proxy-param', context).slideToggle( "200" );
          return false;
        });
      })
    }
  }
})(jQuery, Drupal);

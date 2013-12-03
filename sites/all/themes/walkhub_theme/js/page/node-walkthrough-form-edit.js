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
      Drupal.walkhubStepEdit.advsettings(context, settings);
      Drupal.walkhubStepEdit.makeBackButton(context, settings);
      Drupal.walkhubStepEdit.insertIcon(context, settings);
      Drupal.walkhubStepEdit.stepHideShow(context, settings);
      Drupal.walkhubStepEdit.callopse(context, settings);
      Drupal.walkhubStepEdit.parameters(context, settings);
      Drupal.walkhubStepEdit.initShowTitleTextfieldStates(context, settings);
      Drupal.walkhubStepEdit.showTitleStateChange(context, settings);
    }
  };

  Drupal.walkhubStepEdit = {
    /**
     * Drupal base settings container
     *
     * @param context
     * @param settings
     */
    advsettings : function(context, settings) {
      $('#advset', context).once(function() {
        var $this = $(this);
        $this.click(function() {
          $('#ad-set .ri', context).slideToggle( "200" );
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
    },

    /**
    * Go through every walkthrough step and set the Title field visibility
    * according to the value of the Show title checkbox.
    *
    * @param context
    * @param settings
    */
    initShowTitleTextfieldStates : function(context, settings) {
      $('.field-name-field-fc-step-show-title', context).each(function() {
        var $this = $(this);
        var $titleContainer = $this.siblings(".field-name-field-fc-step-name", context);
        if ($('input[type="checkbox"]', $this).is(':checked')) {
          $titleContainer.show(200);
        }
        else {
          $titleContainer.hide(200);
        }
      });
    },

    /**
    * Handle the Show title checkbox click event.
    *
    * @param context
    * @param settings
    */
    showTitleStateChange: function(context, settings) {
      $('.field-name-field-fc-step-show-title input[type="checkbox"]').click(function() {
        Drupal.walkhubStepEdit.initShowTitleTextfieldStates(context, settings);
      });
    }

  }


})(jQuery, Drupal);

/**
 * @file
 * A Backbone View that provides an interactive modal.
 */
(function ($, Backbone, Drupal) {

  "use strict";

  Drupal.quickedit.ModalView = Backbone.View.extend({

    message: null,
    buttons: null,
    callback: null,
    $elementsToHide: null,

    events: {
      'click button': 'onButtonClick'
    },

    /**
     * {@inheritdoc}
     *
     * @param Object options
     *   An object with the following keys:
     *   - String message: a message to show in the modal.
     *   - Array buttons: a set of buttons with 'action's defined, ready to be
     *     passed to Drupal.theme.quickeditButtons().
     *   - Function callback: a callback that will receive the 'action' of the
     *     clicked button.
     *
     * @see Drupal.theme.quickeditModal()
     * @see Drupal.theme.quickeditButtons()
     */
    initialize: function (options) {
      this.message = options.message;
      this.buttons = options.buttons;
      this.callback = options.callback;
    },

    /**
     * {@inheritdoc}
     */
    render: function () {
      this.setElement(Drupal.theme('quickeditModal', {}));
      this.$el.appendTo('body');
      // Template.
      this.$('.main p').html(this.message);
      var $actions = $(Drupal.theme('quickeditButtons', { 'buttons' : this.buttons}));
      this.$('.actions').append($actions);

      // Show the modal with an animation.
      var that = this;
      setTimeout(function () {
        that.$el.removeClass('quickedit-animate-invisible');
      }, 0);
    },

    /**
     * Passes the clicked button action to the callback; closes the modal.
     *
     * @param jQuery event
     */
    onButtonClick: function (event) {
      event.stopPropagation();
      event.preventDefault();

      // Remove after animation.
      var that = this;
      this.$el
        .addClass('quickedit-animate-invisible')
        .on(Drupal.quickedit.util.constants.transitionEnd, function (e) {
          that.remove();
        });

      var action = $(event.target).attr('data-quickedit-modal-action');
      return this.callback(action);
    }

  });

})(jQuery, Backbone, Drupal);

/**
 * @file
 * CKEditor-based in-place editor for processed text content in Drupal.
 */
(function ($, _, Drupal, drupalSettings, debounce) {

  "use strict";

  // This value needs to be set before ckeditor.js is loaded (when ckeditor.js
  // is loaded dynamically and when using jQuery <1.9).
  // @see http://bugs.jquery.com/ticket/11795#comment:20
  window.CKEDITOR_BASEPATH = Drupal.settings.quickedit.ckeditor.basePath;

  Drupal.quickedit.editors.ckeditor = Drupal.quickedit.EditorView.extend({

    // The CKEditor settings for this field's text format.
    ckeditorSettings: null,

    // Indicates whether this text format has transformations.
    textFormatHasTransformations: null,

    // Stores the textual DOM element that is being in-place edited.
    $textElement: null,

    /**
     * {@inheritdoc}
     */
    initialize: function (options) {
      Drupal.quickedit.EditorView.prototype.initialize.call(this, options);

      var metadata = Drupal.quickedit.metadata.get(this.fieldModel.get('fieldID'), 'custom');
      // @todo use Drupal.settings.quickedit.ckeditor.editorSettings[this.textFormat] ???
      this.ckeditorSettings = metadata.ckeditorSettings;
      this.textFormatHasTransformations = metadata.formatHasTransformations;

      // Store the actual value of this field. We'll need this to restore the
      // original value when the user discards his modifications.
      this.$textElement = this.$el.find('.field-item:first');
      this.model.set('originalValue', this.$textElement.html());
    },

    /**
     * {@inheritdoc}
     */
    getEditedElement: function () {
      return this.$textElement;
    },

    /**
     * {@inheritdoc}
     */
    stateChange: function (fieldModel, state) {
      var editorModel = this.model;
      var from = fieldModel.previous('state');
      var to = state;
      switch (to) {
        case 'inactive':
          break;

        case 'candidate':
          // Detach the text editor when entering the 'candidate' state from one
          // of the states where it could have been attached.
          if (from !== 'inactive' && from !== 'highlighted') {
            this._ckeditor_detach(this.$textElement.get(0), 'unload');
          }
          if (from === 'invalid') {
            this.removeValidationErrors();
          }
          break;

        case 'highlighted':
          break;

        case 'activating':
          // When transformation filters have been been applied to the processed
          // text of this field, then we'll need to load a re-processed version of
          // it without the transformation filters.
          if (this.textFormatHasTransformations) {
            var $textElement = this.$textElement;
            this._getUntransformedText(function (untransformedText) {
              $textElement.html(untransformedText);
              fieldModel.set('state', 'active');
            });
          }
          // When no transformation filters have been applied: start WYSIWYG
          // editing immediately!
          else {
            // Defer updating the model until the current state change has
            // propagated, to not trigger a nested state change event.
            _.defer(function () {
              fieldModel.set('state', 'active');
            });
          }
          break;

        case 'active':
          var textElement = this.$textElement.get(0);
          var toolbarView = fieldModel.toolbarView;
          this._ckeditor_attachInlineEditor(
            textElement,
            this.ckeditorSettings,
            toolbarView.getMainWysiwygToolgroupId(),
            toolbarView.getFloatedWysiwygToolgroupId()
          );
          // Set the state to 'changed' whenever the content has changed.
          this._ckeditor_onChange(textElement, function (htmlText) {
            editorModel.set('currentValue', htmlText);
            fieldModel.set('state', 'changed');
          });
          break;

        case 'changed':
          break;

        case 'saving':
          if (from === 'invalid') {
            this.removeValidationErrors();
          }
          this.save();
          break;

        case 'saved':
          break;

        case 'invalid':
          this.showValidationErrors();
          break;
      }
    },

    /**
     * {@inheritdoc}
     */
    getQuickEditUISettings: function () {
      return { padding: true, unifiedToolbar: true, fullWidthToolbar: true, popup: false };
    },

    /**
     * {@inheritdoc}
     */
    revert: function () {
      this.$textElement.html(this.model.get('originalValue'));
    },

    /**
     * Loads untransformed text for this field.
     *
     * More accurately: it re-processes processed text to exclude transformation
     * filters used by the text format.
     *
     * @param Function callback
     *   A callback function that will receive the untransformed text.
     *
     * @see \Drupal\editor\Ajax\GetUntransformedTextCommand
     */
    _getUntransformedText: function (callback) {
      var fieldID = this.fieldModel.get('fieldID');

      // Create a Drupal.ajax instance to load the form.
      var textLoaderAjax = new Drupal.ajax(fieldID, this.$el, {
        url: Drupal.quickedit.util.buildUrl(fieldID, drupalSettings.quickedit.ckeditor.getUntransformedTextURL),
        event: 'quickedit-internal.quickedit-ckeditor',
        submit: { nocssjs : true },
        progress: { type : null } // No progress indicator.
      });

      // Work-around for https://drupal.org/node/2019481 in Drupal 7.
      textLoaderAjax.commands = {};
      // Implement a scoped quickeditCKEditorGetUntransformedText AJAX command:
      // calls the callback.
      textLoaderAjax.commands.quickeditCKEditorGetUntransformedText = function (ajax, response, status) {
        callback(response.data);
      };

      // This will ensure our scoped quickeditGetUntransformedText AJAX command
      // gets called.
      this.$el.trigger('quickedit-internal.quickedit-ckeditor');
    },

    // @see Drupal 8's Drupal.editors.ckeditor.attachInlineEditor().
    _ckeditor_attachInlineEditor: function (element, ckeditorSettings, mainToolbarId, floatedToolbarId) {
      this._ckeditor_loadExternalPlugins(ckeditorSettings);

      var settings = $.extend(true, {}, ckeditorSettings);

      // If a toolbar is already provided for "true WYSIWYG" (in-place editing),
      // then use that toolbar instead: override the default settings to render
      // CKEditor UI's top toolbar into mainToolbar, and don't render the bottom
      // toolbar at all. (CKEditor doesn't need a floated toolbar.)
      if (mainToolbarId) {
        var settingsOverride = {
          removePlugins: 'floatingspace,elementspath',
          sharedSpaces: {
            top: mainToolbarId
          }
        };

        // Find the "Source" button, if any, and replace it with "Sourcedialog".
        // (The 'sourcearea' plugin only works in CKEditor's iframe mode.)
        var sourceButtonFound = false;
        for (var i = 0; !sourceButtonFound && i < settings.toolbar.length; i++) {
          if (settings.toolbar[i] !== '/') {
            for (var j = 0; !sourceButtonFound && j < settings.toolbar[i].length; j++) {
              if (settings.toolbar[i][j] === 'Source') {
                sourceButtonFound = true;
                // Swap sourcearea's "Source" button for sourcedialog's.
                settings.toolbar[i][j] = 'Sourcedialog';
                settingsOverride.extraPlugins += ',sourcedialog';
                settingsOverride.removePlugins += ',sourcearea';
              }
            }
          }
        }

        settings.extraPlugins += ',' + settingsOverride.extraPlugins;
        settings.removePlugins += ',' + settingsOverride.removePlugins;
        settings.sharedSpaces = settingsOverride.sharedSpaces;
      }

      // CKEditor requires an element to already have the contentEditable
      // attribute set to "true", otherwise it won't attach an inline editor.
      element.setAttribute('contentEditable', 'true');

      return !!CKEDITOR.inline(element, settings);
    },

    // @see Drupal 8's Drupal.editors.ckeditor.detach().
    _ckeditor_detach: function (element, trigger) {
      var editor = CKEDITOR.dom.element.get(element).getEditor();
      if (editor) {
        if (trigger === 'serialize') {
          editor.updateElement();
        }
        else {
          editor.destroy();
          element.removeAttribute('contentEditable');
        }
      }
      return !!editor;
    },

    // @see Drupal 8's Drupal.editors.ckeditor.onChange().
    //
    _ckeditor_onChange: function (element, callback) {
      var editor = CKEDITOR.dom.element.get(element).getEditor();
      if (editor) {
        editor.on('change', debounce(function () {
          callback(editor.getData());
        }, 400));
      }
      return !!editor;
    },

    // @see Drupal 8's Drupal.editors.ckeditor._loadExternalPlugins().
    _ckeditor_loadExternalPlugins: function(ckeditorSettings) {
      if (ckeditorSettings.loadPlugins) {
        if (typeof ckeditorSettings.extraPlugins === 'undefined') {
          ckeditorSettings.extraPlugins = '';
        }
        for (var pluginName in ckeditorSettings.loadPlugins) {
          if (ckeditorSettings.loadPlugins.hasOwnProperty(pluginName)) {
            var name = ckeditorSettings.loadPlugins[pluginName].name;
            ckeditorSettings.extraPlugins += (ckeditorSettings.extraPlugins) ? ',' + name : name;
            CKEDITOR.plugins.addExternal(pluginName,  ckeditorSettings.loadPlugins[pluginName].path);
          }
        }
      }
    },

  });

})(jQuery, _, Drupal, Drupal.settings, Drupal.quickedit.util.debounce);

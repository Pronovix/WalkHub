(function ($, Drupal) {

  Drupal.walkhubTheme = {
    initSelect2: function (context, settings) {
      var $selectElements = {};

      // React properly to context.
      // Make sure only select elements inside #content are affected.
      if (context instanceof jQuery && !!context.hasAncestor('#content').length) {
        $selectElements = $('select', context);
      } else {
        $selectElements = $('main select', context);
      }

      // Default options, common to all Select2 calls.
      // See http://ivaynberg.github.com/select2/#documentation for details.
      var defaultSelect2Options = {
        // Inhibit syncing of classes from original element to new.
        adaptContainerCssClass: function (syncClass) {
          return null;
        },
        minimumResultsForSearch: 50,
        width: function () {
          var selectIconRMargin = Number($('html.js .select2-container .select2-choice span').css('margin-right').replace(/px$/, ''));
          return this.element.outerWidth(false) === 0 ? 'auto' : this.element.outerWidth(false) + selectIconRMargin + 'px';
        }
      };

      // Apply Select2 on single selects.
      $selectElements.not('[multiple]').each(function () {
        var $this = $(this);
        $this.select2(defaultSelect2Options);
      });

      // Apply Select2 on multiple selects.
      $selectElements.filter('[multiple]').each(function () {
        var $this = $(this);
        var multipleSelectSettings = $.extend(true, {}, defaultSelect2Options, {
          width: 'resolve'
        });

        $this.select2(multipleSelectSettings);
      });
    }
  };

})(jQuery, Drupal);

(function ($) {

  /**
   * Redirect the user to the language chooser page if a cookie is not set.
   * Once on the page, then set the cookie for the language that the user
   * chooses.
   */
  Drupal.behaviors.checkLanguage = {
    attach: function (context, settings) {
      // Add click handler to both the "burger menu items" and the actual
      // language page links.
      $('.page-choose-lang .language-link, .language-switcher-locale-url .language-link').click(function() {
        $.cookie('ag-language', $(this).attr('lang'), { expires: 7, path: '/' });
      });
    }
  }

})(jQuery);

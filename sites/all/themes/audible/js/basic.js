(function ($) {

  /**
   * Handles the menu-toggle functionality.
   */
  Drupal.behaviors.menuToggle = {
    attach: function (context, settings) {

      // Check if the menu is checked.
      $('#menu-toggle').change(function(){
        // The menu selector.
        var menu = $('.page-header .block-menu', context);
        // Check if the "burger" is checked.
        if (this.checked) {
          menu.show();
        } else {
          menu.hide();
        }
      });

    }
  }

})(jQuery);

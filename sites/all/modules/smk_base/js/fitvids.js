(function ($) {

  /**
   * Responsive youtube videos.
   */
  Drupal.behaviors.fitVids = {
    attach: function (context, settings) {

      $('.videos', context).fitVids();
    }
  }

})(jQuery);

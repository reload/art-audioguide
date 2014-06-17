(function ($) {

  /**
   * Responsive youtube videos.
   */
  Drupal.behaviors.fitVids = {
    attach: function (context, settings) {

      $('.embedded-video', context).fitVids();
    }
  }

})(jQuery);

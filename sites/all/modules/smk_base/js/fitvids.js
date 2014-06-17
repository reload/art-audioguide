(function ($) {

  /**
   * Responsive youtube videos.
   */
  Drupal.behaviors.fitVids = {
    attach: function (context, settings) {
      var video = $('.embedded-video', context);
      // If there's any embedded videos on the page.
      if (video.get(0)) {
        // Init "FitVids" library.
        video.fitVids();
        // Display the foldout-videos container.
        $('.videos', context).show();
      }
    }
  }

})(jQuery);

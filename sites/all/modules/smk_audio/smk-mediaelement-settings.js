(function ($) {

  /**
   * The MediaElement player.
   */
  Drupal.behaviors.mediaelement = {
    attach: function (context, settings) {
      // Selectors.
      var audio = $('audio', context);


      // Add "skin class" to the player.
      audio.addClass('mejs-smk');

      // Init the player.
      audio.mediaelementplayer({
        audioWidth: '100%',
        startVolume: 1,
        features: ['playpause', 'progress', 'current', 'duration']
      });

      // To gain control over the width of the mediaelement player, who sets its own
      // width on pageload, we are instead controlling the width of the player's parent
      // element. Screwy, I know.
      function setMediaelementWidth() {
        if( $(window).width() < 800 ) {
          $('.mediaelement-audio', context).width( $(window).width() - 24 );
        }
      }

      $(document).ready(function($) {
        setMediaelementWidth();
      });

      $(window).resize(function(){
        setMediaelementWidth();
      });

    }
  }

})(jQuery);

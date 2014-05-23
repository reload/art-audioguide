(function ($) {

  /**
   * The MediaElement player.
   */
  Drupal.behaviors.mediaelement = {
    attach: function (context, settings) {

      $('audio', context).addClass('mejs-smk');

      $('audio', context).mediaelementplayer({
        // width of audio player
        audioWidth: '100%',
        // height of audio player
        audioHeight: 30,
        // initial volume when the player starts
        startVolume: 1, // default: 0.8.
        // audio volume direction (horizontal / vertical).
        audioVolume: 'vertical',
        // useful for <audio> player loops
        loop: false,
        // enables Flash and Silverlight to resize to content size
        enableAutosize: true,
        // the order of controls you want on the control bar (and other plugins below)
        features: ['current', 'playpause','progress','duration'],
        // Hide controls when playing and mouse is not over the video
        alwaysShowControls: false,
        // force iPad's native controls
        iPadUseNativeControls: false,
        // force iPhone's native controls
        iPhoneUseNativeControls: false,
        // force Android's native controls
        AndroidUseNativeControls: false,
        // forces the hour marker (##:00:00)
        alwaysShowHours: false,
        // show framecount in timecode (##:00:00:00)
        showTimecodeFrameCount: false,
        // turns keyboard support on and off for this instance
        enableKeyboard: true,
        // when this player starts, it will pause other players
        pauseOtherPlayers: true,
        // array of keyboard commands
        keyActions: []
      });

    }
  }

})(jQuery);

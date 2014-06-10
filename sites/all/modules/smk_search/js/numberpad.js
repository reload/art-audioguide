(function ($) {

  /**
   * Number pad.
   */
  Drupal.behaviors.numberPadHeight= {
    attach: function (context, settings) {
      // Make the keys take up the entire height of the screen
      function setKeyHeight() {
        var keyElement = $('.number-pad .key');
        var viewportHeight = $(window).height() - $('.page-header').outerHeight() - $('.number-pad .display').outerHeight() - $('.number-pad .help').outerHeight();

        // Make sure we have a minimum height
        if( viewportHeight / 4 > 42 ) {
          $(keyElement).height(viewportHeight / 4);
        }
      }

      // Rezise on page load
      setKeyHeight();

      // Resize when window width changes
      $(window).resize(function(){
        setKeyHeight();
      });
    }
  };

  Drupal.behaviors.numberPadTouch = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.page-number-search', context);
      var form = $('form', page);
      var input = $('input[name="id"]', form);
      var numberPad = $('.number-pad', page);
      var display = $('div.audio-id-value', numberPad);
      var clear = $('.clear', numberPad);

      // If there's any results on the page.
      if ($('.views-row', context).get(0)) {
        // Hide the numberPad.
        numberPad.hide();
      }

      // Function: Add number.
      function numberPadAddNumber(value) {
        // Add to hidden input field.
        input.attr('value', input.attr('value') + value );

        // Add to display.
        display.append(value);
      }

      // Function: Remove number (one at a time).
      function numberPadRemoveNumber() {
        // Remove from hidden input field.
        input.attr('value', input.attr('value').slice(0, -1) );

        // Remove from display.
        display.text( display.text().slice(0, -1) );
      }

      // Function: Clear display.
      function numberPadClear() {
        // Clear hidden input field.
        input.attr('value', '');

        // Clear display.
        display.text('');
      }

      // Run a "clear" when loading the page.
      // This is to prevent "adding" to the previous number
      // after someone already submitted.
      numberPadClear();

      // When a number key is clicked.
      $('.key-number', numberPad).click( function(e){
        e.preventDefault();
        var value = $(this).text();
        numberPadAddNumber(value);
      });

      // When backspace is clicked.
      $('.key-backspace', numberPad).click( function(){
        numberPadRemoveNumber();
      });

      // When clear is clicked.
      clear.click( function(){
        numberPadClear();
      });

      // Toggle placeholder and clear.
      $('.key, .clear', numberPad).click( function(e){
        e.preventDefault();

        if( display.html() ) {
          // Hide placeholder if display has content.
          $('.placeholder', numberPad).hide();

          // Show clear button if display has content.
          clear.show();

        } else {
          // Add placeholder if display has no content.
          $('.placeholder', numberPad).show();

          // Hide clear button if display has no content.
          clear.hide();
        }
      });

      // Submit form.
      $('.key-submit', numberPad).click(function() {
        form.submit();
      });
    }
  }

})(jQuery);

// Make sure the function exists before we try to execute it.
if (typeof handleClicks == 'function') {
  // Init "Touche.js".
  Touche(document.querySelectorAll('.key')).on('click', handleClicks);
}

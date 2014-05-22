(function ($) {

  /**
   * Handles the menu-toggle functionality.
   */
  Drupal.behaviors.menuToggle = {
    attach: function (context, settings) {

      // Check if the menu is checked.
      $('#menu-toggle').change(function(){
        // The menu selector.
        var menu = $('.delta-toggle-menu', context);
        $('.delta-toggle-menu').toggleClass('open');
        // Check if the "burger" is checked.
        if (this.checked) {
          menu.show();
        } else {
          menu.hide();
        }
      });

    }
  }

  /**
   * Tiles.
   */
  Drupal.behaviors.tiles = {
    attach: function (context, settings) {

      // Selectors.
      var page = $('.front', context);
      var itemsString = '#content .menu li';
      var items = $(itemsString, page);
      var largeTileString = '.tile--large';
      var largeTile = $(itemsString, page);

      /**
       * Tile height.
       */
      // Make the height equal width of tiles.
      function setTileHeight(tileSelector) {
        var tileElement = $(tileSelector, page);
        var tileWidth = $(tileElement).width();
        $(tileElement).height(tileWidth);
      }
      // Rezise on page load.
      setTileHeight(itemsString);

      // Resize when window width changes.
      $(window).resize(function(){
        setTileHeight(itemsString);
      });

      /**
       * Alter the List-items.
       */
      // Move menu-icon classes to the list-item.
      items.each(function() {
        // Selector.
        var link = $(this).find('a');

        // Move the "menu_icon" class to the list-item instead of the link.
        $(this).addClass('menu_icon');
        link.removeClass('menu_icon');

        // Move the "menu-xxx" class that contains the background-image
        // to the parent list-item.
        var classes = link.attr('class').split(/\s+/);
        for (var i = 0; i < classes.length; i++) {
          if (classes[i].indexOf('menu-') != -1) {
            $(this).addClass(classes[i]);
//            link.removeClass(classes[i]);
          }
        }
      });

      // Make entire tile clickable.
      items.click(function(){
        window.location = $(this).find('a').attr('href');
      });

      // Make entire large tile clickable.
      $(largeTileString).click(function(){
        window.location = $(this).find('a').attr('href');
      });
    }
  }

})(jQuery);

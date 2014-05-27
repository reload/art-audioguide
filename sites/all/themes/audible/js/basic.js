(function ($) {

  /**
   * Handles the menu-toggle functionality.
   */
  Drupal.behaviors.menuToggle = {
    attach: function (context, settings) {

      // Check if someone wants to change the menu.
      $('#menu-toggle', context).change(function(){
        // Toggle the icon (change it to a cross).
        $('label[for="menu-toggle"]', context).toggleClass('active');
        // Toggle the menu (open/close).
        $('.delta-toggle-menu', context).toggleClass('open');
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
       * Create an image-tag with the "Menu icon" modules image.
       *
       * NB! This is a bit tricky. Our <a> tags have some background styling,
       * so the background-image is being overwritten.
       * If we move the class holding the image/styling to the parent list-item,
       * then we can get the src of the image and append it to a new a new <img>.
       */
      // Move menu-icon classes to the list-item.
      items.each(function() {
        // Selector.
        var link = $(this).find('a');

        // Move the "menu_icon" class to the list-item instead of the link.
        link.removeClass('menu_icon');

        // Move the "menu-xxx" class that contains the background-image
        // to the parent list-item, create an <img> and remove the class again.
        // ------
        // Get the link's classes and split it.
        var classes = link.attr('class').split(/\s+/);
        // For each class:
        for (var i = 0; i < classes.length; i++) {
          // If the link had a class named "menu-...":
          if (classes[i].indexOf('menu-') != -1) {
            // Add the "menu-..." class to the list-item.
            $(this).addClass(classes[i]);
            // Get the background-image path and remove css' url() around the path/src.
            var src = $(this).css('background-image').replace('url(','').replace(')', '');
            // Remove the "menu-..." class completely.
            $(this).removeClass(classes[i]);
            link.removeClass(classes[i]);
            // Append an image-tag with the new source.
            $(this).append($('<img>', {src: src}));
          }
        }
      });

      /**
       * Make the tiles clickable.
       */
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

  /**
   * Clickable list (views-lists).
   */
  Drupal.behaviors.compactList = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.node-type-generic-page', context);
      var items = $('.views-row, .compact-list__item', page);

      /**
       * Make compact list item clickable.
       */
      items.click(function(){
        window.location = $(this).find('a').attr('href');
      });
    }
  }

  /**
   * Compact list item title and content truncation (Routes).
   */
  Drupal.behaviors.compactListTruncation = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.node-type-generic-page .view-routes', context);
      var items = $('.views-row, .compact-list__item', page);

      /**
       * Compact list item title and content truncation.
       * ------
       * The truncation is made with CSS, but doing this requires a set width for the
       * list item. Therefore we set the width dynamically.
       */
      function setCompactListItemContentWidth() {
        var compactListItemWidth = items.outerWidth() - 100;
        items.find('h2, div').width(compactListItemWidth);
      }
      // Execute truncation on init.
      setCompactListItemContentWidth();

      // Execute truncation on resize.
      $(window).resize(function(){
        setCompactListItemContentWidth();
      });
    }
  }

  /**
   * Vertically center thumbnails in list (search results & artworks/pieces).
   */
  Drupal.behaviors.verticallyAlignThumbs = {
    attach: function (context, settings) {

      // Function to vertically align thumbnails.
      function verticalAlignThumbs() {
        var page = $('.node-type-generic-page .view-artworks', context);
        var images = $('.thumbnail-wrapper img', page);

        images.each( function() {
          // Calculating offset that will vertically center the thumb
          // NOTE: 56 is the maximum thumb height in pixels
          var thumbHeight = $(this).height();
          var verticalOffset = (56 - thumbHeight) / 2;

          if( $(this).height() < 56 ) {
            $(this).css('margin-top', verticalOffset + 'px');
          }
        });
      }

      // Execute the function when the window is loaded.
      $(window).load(function() {
        verticalAlignThumbs();
      });

    }
  }

})(jQuery);

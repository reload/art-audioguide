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
  };

  /**
   * Tiles.
   */
  Drupal.behaviors.tiles = {
    attach: function (context, settings) {
      // Determine if the tile is a "lefty" or a "righty". This is mainly
      // done instead of CSS' pseudo selectors odd/even, because we cannot
      // guarantee that the editors won't set up the menu in the wrong order.
      $('.front .views-row .small_tile', context).each(function(index) {
        // Define the previous element.
        var prev = $(this).parent().prev().children('.small_tile');

        // If it's the first element.
        if (prev.length == 0) {
          $(this).addClass('left');
        }
        // If the previous tile is a large tile.
        else if (prev.hasClass('large_tile')) {
          $(this).addClass('left');
        }
        // If the previous tile is a "lefty".
        else if (prev.hasClass('left')) {
          $(this).addClass('right');
        }
        // If the previous tile is a "righty".
        else if (prev.hasClass('right')) {
          $(this).addClass('left');
        }
      });
    }
  };

  /**
   * Clickable list (views-lists).
   */
  Drupal.behaviors.compactList = {
    attach: function (context, settings) {
      // Prepare the search-page for this effect.
      if ($('.page-search').get(0)) {
        // Move the content of the nested views to the "main view.
        // Afterwards we remove the old container to remove empty spaces.
        var container = $('.page-search .view-string-search > .view-content', context);
        $('.node-artist', container).each(function() {
          $(this).find('.views-row').appendTo(container);
          $(this).parent().remove();
        });
      }

      /**
       * Make compact list item clickable.
       * ------
       * We convert the div-tags into a-tags instead of using a "on click"
       * event. This is due to the fact that you couldn't scroll with mobile
       * devices without triggering the effect.
       */
      // we want this to happen on all pages except the front page.
      if (!$('.front').get(0)) {
        $('.view .views-row, .node.node-teaser', context).each(function(){
          $(this).replaceWith( $('<a>', {
            href: $(this).find('a').attr('href'),
            html: $(this).html(),
            class: $(this).attr('class')
          }));
        });
      }
    }
  };

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
  };

  /**
   * Vertically center thumbnails in list (search results & artworks/pieces).
   */
  Drupal.behaviors.verticallyAlignThumbs = {
    attach: function (context, settings) {

      // Function to vertically align thumbnails.
      function verticalAlignThumbs() {
        var page = $('.node-type-generic-page .view-artworks, .page-search .view-string-search', context);
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
  };

  /**
   * Track numbers.
   */
  Drupal.behaviors.trackNumbers = {
    attach: function (context, settings) {
      // Selectors.
      var images = $('.delta-overlay');

      // Append span-element to contain track-numbers.
      images.append($('<span>', {class: 'track-number'}));

      // Loop through each track-number.
      var i = 1;
      $('.track-number', images).each(function() {
        // Set track-index.
        $(this).html(i);
        i++;
        // Adjust each track number, vertically.
        $(this).css('margin-left', '-' + $(this).outerWidth() / 2 + 'px' );
      });
    }
  };

  /**
   * Info panel (expandability).
   */
  Drupal.behaviors.expandability = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.node-type-route, .node-type-audio', context);
      var infoPanel = $('.info-panel--expandable', page);
      var infoPanelContent = $('.content', infoPanel);
      var infoPanelSummary = $('.info-panel--expandable > .truncated-paragraph', page);

      // Hide the main-content of the info-panel.
      infoPanelContent.hide();

      // We "clone" the body field in Drupal, as a dynamic field.
      // Because we do this, the copied field also get the class
      // "truncated paragraph".
      // To fix this, we take the content and move it to the parent.
      var content = infoPanelContent.find('.truncated-paragraph').html();
      infoPanelContent.html(content);

      // Add toggle button.
      infoPanelContent.after($('<a>', {href: '#', class: 'toggle'}));
      var button = $('.toggle', infoPanel);

      // When the panel is clicked.
      infoPanel.click(function(e) {
        // If the panel is closed.
        if (!$(this).hasClass('open')) {
          // Open the panel.
          infoPanelSummary.toggle();
          infoPanelContent.toggle();
          // Set toggle-state.
          button.toggleClass('open');
          infoPanel.toggleClass('open');
        }
      });

      // When the button is clicked.
      button.click(function(e) {
        // Prevent link from redirecting.
        e.preventDefault();
        // Stop parent from executing.
        e.stopPropagation();
        // Open/close the panel.
        infoPanelSummary.toggle();
        infoPanelContent.toggle();
        // Set toggle-state.
        $(this).toggleClass('open');
        infoPanel.toggleClass('open');
      });
    }
  };

  /**
   * Fold out box toggle content.
   */
  Drupal.behaviors.foldoutBox = {
    attach: function (context, settings) {
      var foldout = $('.foldout', context);
      // Toggle the state of the "foldout" box.
      foldout.click(function (e) {
        // Prevent link from redirecting.
        e.preventDefault();
        // Toggle classes and show/hide content.
        $(this).toggleClass('open');
        $('.foldout-content', this).toggle();
      });

      // Allows links inside the foldout to execute/redirect by
      // "overruling" the parents action.
      $('a', foldout).click(function(e) {
        // Stop parent from executing.
        e.stopPropagation();
      });
    }
  };

  /**
   * This script will make all social media icons on the sound
   * page show in a popup window, instead of redirecting them.
   * ---
   * This can handle multiple icons by defining them in the "icons"
   * variable, but it only handles the Facebook icon atm.
   */
  Drupal.behaviors.socialMediaPopup = {
    attach: function (context, settings) {
      // Select icons
      var icons = $('.node-type-audio .share-links .icon--facebook-2', context);

      // When an icon is being clicked.
      icons.click(function(event) {
        // Prevent default behaviour.
        event.preventDefault();
        event.stopPropagation();
        // Make the link create a pop-up window instead.
        window.open(
          this.href,
          'popUpWindow',
          'height=325,' +
            'width=500,' +
            'left=200,' +
            'top=200,' +
            'resizable=no,' +
            'scrollbars=yes,' +
            'toolbar=yes,' +
            'menubar=no,' +
            'location=no,' +
            'status=yes'
        );
      });
    }
  };

  /**
   * Make the mediaplayer-title "toggle" between list-items.
   */
  Drupal.behaviors.mediaplayerTitle = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.node-type-audio', context);
      var player = $('.mediaplayer', page);
      var title = $('.audio-title li', player);

      // Toggle the player-title.
      setInterval(function(){
        title.toggleClass('switched');
      }, 3500);
    }
  };

  /**
   * Move the search-form inside the info-panel.
   */
  Drupal.behaviors.moveSearchForm = {
    attach: function (context, settings) {
      // Selectors.
      var page = $('.page-search', context);
      // Move the form.
      $('form', page).appendTo($('.search-panel', page));
    }
  }

})(jQuery);

<?php
/**
 * @file
 * Theming functions for audible.
 */

/**
 * Override theme_menu_link().
 */
function audible_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // If the link is a nolink one (see hook_menu() in reload_f5.module), then
  // do some extra stuff and overwrite $output.
  if (preg_match('{<nolink>}', $element['#href'])) {
    $output = '<span>' . strip_tags($output) . '</span>';
    $element['#attributes']['class'][] = 'nolink';
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_page().
 */
function audible_preprocess_page(&$variables) {
  drupal_add_js(libraries_get_path('fastclick') .'/fastclick.js', 'file');
}

/**
 * Implements hook_preprocess_html().
 */
function audible_preprocess_html(&$vars) {
  // Get rid of the toolbar on the front end. It's messy for this theme.
  if (isset($vars['page']['page_top']['toolbar'])) {
    unset($vars['page']['page_top']['toolbar']);
  }

  // Viewport.
  $metatags['viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no',
    ),
  );

  // HTML shiv.
  $metatags['html5shiv'] = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => '//html5shim.googlecode.com/svn/trunk/html5.js',
    ),
    '#prefix' => '<!--[if lte IE 8]>',
    '#suffix' => '</script><![endif]-->',
  );

  // Default favicon for: iOS 2.0+ and Android 2.1+
  $metatags['apple_touch_icon_precomposed'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'rel' => 'apple-touch-icon-precomposed',
      'href' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-152x152.png',
    ),
  );

  // Specify image for each Apple-size (since Jacques made different
  // favicons for the differente sizes).
  $apple_touch_sizes = array('57x57', '72x72', '114x114', '120x120', '144x144', '152x152');
  // Set each size/metatag.
  foreach ($apple_touch_sizes as $size){
    $metatags['apple_touch_icon_' . $size] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon-precomposed',
        'href' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-' . $size . '.png',
        'sizes' => $size,
      ),
    );
  }

  // Internet Explorer Metro default favicon.
  $metatags['ms_tile_image'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileImage',
      'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-144x144.png',
    ),
  );
  // Internet Explorer Metro default color.
  $metatags['ms_tile_color'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileColor',
      'content' => '#000',
    ),
  );
  // Internet Explorer Metro default name.
  $metatags['application_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'application-name',
      'content' => t('Statens Museum for Kunst'),
    ),
  );

  // Microsoft tiles sizes (aka favicons).
  $explorer[] = array(
    'name' => 'msapplication-square70x70logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-70x70.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-square150x150logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-150x150.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-wide310x150logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-310x150.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-square310x310logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon-310x310.png',
  );
  foreach ($explorer as $version) {
    $metatags[$version['name']] = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => $version['name'],
        'content' => $version['content'],
      ),
    );
  }

  // Run each metatag.
  foreach ($metatags as $key => $tag) {
    drupal_add_html_head($tag, $key);
  }
}

/**
 * Overrides hook_preprocess_block().
 */
function audible_preprocess_block(&$variables) {
  // Add the delta to the classes array. The block template in this theme rips
  // out #id, so this is the (better) substitute.
  $variables['classes_array'][] = drupal_html_class('delta-' . $variables['block']->delta);
}

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

  // HTML shiv
  $metatags['html5shiv'] = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => '//html5shim.googlecode.com/svn/trunk/html5.js',
    ),
    '#prefix' => '<!--[if lte IE 8]>',
    '#suffix' => '</script><![endif]-->',
  );

  // Apple touch icon.
  $metatags['apple_touch_icon'] = array(
    '#type' => 'html_tag',
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'apple-touch-icon-precomposed',
      'href' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon152.png',
    ),
  );

  // Windows 8 tile.
  $metatags['ms_tile_image'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileImage',
      'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon144.png',
    ),
  );
  // Windows 8 color.
  $metatags['ms_tile_color'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileColor',
      'content' => '#204D5D',
    ),
  );
  // Windows 8 name.
  $metatags['application_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'application-name',
      'content' => 'Engineer The Future',
    ),
  );

  // IE11 tiles.
  $explorer[] = array(
    'name' => 'msapplication-square70x70logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon70.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-square150x150logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon150.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-wide310x150logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon310x150.png',
  );
  $explorer[] = array(
    'name' => 'msapplication-square310x310logo',
    'content' => drupal_get_path('theme', 'audible') . '/images/favicons/favicon310x310.png',
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

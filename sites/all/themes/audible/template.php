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
 *
 * Get rid of the toolbar on the front end. It's messy for this theme.
 */
function audible_preprocess_html(&$vars) {
  if (isset($vars['page']['page_top']['toolbar'])) {
    unset($vars['page']['page_top']['toolbar']);
  }
}

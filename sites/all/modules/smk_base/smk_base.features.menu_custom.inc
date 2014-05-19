<?php
/**
 * @file
 * smk_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function smk_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-front-page-menu.
  $menus['menu-front-page-menu'] = array(
    'menu_name' => 'menu-front-page-menu',
    'title' => 'Front page menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Front page menu');


  return $menus;
}

<?php
/**
 * @file
 * smk_base.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function smk_base_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: html_text
  $profiles['html_text'] = array(
    'format' => 'html_text',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Format' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'theme',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'p,h2',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
  );

  return $profiles;
}

<?php
/**
 * @file
 * smk_audio.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function smk_audio_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:audio.
  $config['node:audio'] = array(
    'instance' => 'node:audio',
    'disabled' => FALSE,
    'config' => array(
      'og:image' => array(
        'value' => '[node:piece-image]',
      ),
    ),
  );

  return $config;
}

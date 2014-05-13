<?php
/**
 * @file
 * smk_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function smk_base_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  return $roles;
}

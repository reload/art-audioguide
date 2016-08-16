<?php

$databases = array(
  'default' => array(
    'default' => array(
      'driver' => 'mysql',
      'database' => getenv('DB_ENV_MYSQL_DATABASE'),
      'username' => getenv('DB_ENV_MYSQL_USER'),
      'password' => getenv('DB_ENV_MYSQL_PASSWORD'),
      'host' => 'db',
      'prefix' => '',
      'collation' => 'utf8_general_ci',
    ),
  ),
);

$conf['cron_key'] = 'staticcronkey';

$conf['file_private_path'] = 'sites/default/files/private';
$conf['file_public_path'] = 'sites/default/files';

$conf['restrict_by_ip_header'] = NULL;
$conf['restrict_by_ip_login_range'] = NULL;
// Disable restrictions.
$conf['restrict_by_ip_role_' . md5('administrator')] = '';
$conf['tfa_basic_roles_require'] = [];
$conf['error_level'] = 2;

if (file_exists(DRUPAL_ROOT . '/sites/default/local.settings.php')) {
    require DRUPAL_ROOT . '/sites/default/local.settings.php';
}

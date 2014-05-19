<?php

$aliases['common'] = array(
  'remote-host' => 'dev.reload.dk',
  'remote-user' => 'reload',
  'path-aliases' => array(
    '%dump-dir' => '/var/tmp',
  ),
);

$aliases['dev'] = array(
  'parent' => '@common',
  'uri' => 'smk.dev.reload.dk',
  'root' => '/var/www/smk',
  'deployotron' => array(
    'branch' => 'develop',
  ),
);


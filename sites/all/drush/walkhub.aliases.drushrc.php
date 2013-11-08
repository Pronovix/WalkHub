<?php

$aliases['live'] = array (
  'site' => 'walkhub',
  'uri' => 'walkhub.net',
  'root' => '/var/www/walkhub.net',
  'remote-host' => 'production.pronovix.net',
);

$aliases['staging'] = array(
  'parent' => '@live',
  'uri' => 'staging.walkhub.net',
  'root' => '/var/www/staging.walkhub.net',
);

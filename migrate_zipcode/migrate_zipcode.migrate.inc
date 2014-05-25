<?php

function migrate_zipcode_migrate_api() {
  $api = array(

    // api: the version of Migrate your code supports (currently 2 is the only supported version).
    'api' => 2,

    // groups: an array keyed by group machine names, with arrays of arguments (including in particular 'title',
    // the user-visible name of the group
    'groups' => array(
      'zipcode' => array(
        'title' => 'My Customer Migrations'
      ),
    ),

    // migrations: an array keyed by migration machine names, with arrays of arguments (including in particular
    // 'class_name', the name of the Migration class you've implemented).
    'migrations' => array(
      'ZipcodeNode' => array(
        'class_name' => 'ZipcodeNodeMigration',
        'group_name' => 'zipcode',
      ),
    ),
  );

  return $api;
}
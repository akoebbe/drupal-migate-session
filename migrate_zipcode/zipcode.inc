<?php

class ZipcodeNodeMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Set up our data source. Could be SQL, JSON, CSV...
    $this->source = new MigrateSourceCSV(__DIR__.'/USZIPcodes.csv',array(),array('header_rows'=>1));

    // Set up our data destination. Could be any entity based on the Class used.
    $this->destination = new MigrateDestinationNode('zip');

    // Set up our unique identifier in the source and destination
    $this->map = new MigrateSQLMap($this->machineName,
      // Source key
      array(
        'ZIP' => array('type' => 'varchar',
          'length' => 8,
          'not null' => TRUE,)
      ),
      // destination key. Easy shortcut...
      MigrateDestinationNode::getKeySchema()
    );

    // Set up field mappings parameters are destination field first, source field second.
    $this->addFieldMapping('title', 'ZIP');
    $this->addFieldMapping('body', 'PONAME');
  }
}
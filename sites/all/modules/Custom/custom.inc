<?php
/**
 * Custom entity class for My Custom Entity.
 */
class MyCustomEntity extends Entity {
    public $id;
    public $name;

    /**
     * Constructor.
     */
    public function __construct(array $values = array()) {
        parent::__construct($values, 'my_custom_entity');
    }

    /**
     * Default label function for this entity type.
     */
    protected function defaultLabel() {
        return $this->name;
    }
}

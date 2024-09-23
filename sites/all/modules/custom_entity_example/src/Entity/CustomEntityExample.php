<?php

namespace Drupal\custom_entity_example\Entity;

use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\user\EntityOwnerInterface;
use Drupal\user\UserInterface;

/**
 * Defines the Custom Entity Example entity.
 *
 * @ContentEntityType(
 *   id = "custom_entity_example",
 *   label = @Translation("Custom Entity Example"),
 *   base_table = "custom_entity_example",
 *   entity_keys = {
 *     "id" = "id",
 *     "uuid" = "uuid",
 *     "label" = "name",
 *     "uid" = "user_id",
 *   },
 *   handlers = {
 *     "storage" = "Drupal\Core\Entity\Sql\SqlContentEntityStorage",
 *     "list_builder" = "Drupal\Core\Entity\EntityListBuilder",
 *     "form" = {
 *       "default" = "Drupal\Core\Entity\ContentEntityForm",
 *       "add" = "Drupal\Core\Entity\ContentEntityForm",
 *       "edit" = "Drupal\Core\Entity\ContentEntityForm",
 *       "delete" = "Drupal\Core\Entity\ContentEntityDeleteForm"
 *     },
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/custom_entity_example/{custom_entity_example}",
 *     "add-form" = "/admin/structure/custom_entity_example/add",
 *     "edit-form" = "/admin/structure/custom_entity_example/{custom_entity_example}/edit",
 *     "delete-form" = "/admin/structure/custom_entity_example/{custom_entity_example}/delete",
 *     "collection" = "/admin/structure/custom_entity_example"
 *   }
 * )
 */
class CustomEntityExample extends ContentEntityBase implements EntityOwnerInterface {

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields = parent::baseFieldDefinitions($entity_type);

    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Name'))
      ->setRequired(TRUE)
      ->setSettings([
        'max_length' => 255,
      ]);

    $fields['user_id'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Author'))
      ->setSetting('target_type', 'user')
      ->setDefaultValueCallback('Drupal\node\Entity\Node::getCurrentUserId');

    return $fields;
  }

}

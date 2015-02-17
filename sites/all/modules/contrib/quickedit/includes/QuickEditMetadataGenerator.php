<?php

/**
 * @file
 * Contains Quick Edit's metadata generator.
 *
 * @see Drupal 8's \Drupal\quickedit\MetadataGenerator.
 */

module_load_include('php', 'quickedit', 'includes/EditEntityFieldAccessCheckInterface');
module_load_include('php', 'quickedit', 'includes/QuickEditEditorSelectorInterface');
module_load_include('php', 'quickedit', 'includes/QuickEditMetadataGeneratorInterface');

/**
 * Generates in-place editing metadata for an entity field.
 */
class QuickEditMetadataGenerator implements QuickEditMetadataGeneratorInterface {

  /**
   * An object that checks if a user has access to edit a given entity field.
   *
   * @var EditEntityFieldAccessCheckInterface
   */
  protected $accessChecker;

  /**
   * An object that determines which editor to attach to a given field.
   *
   * @var EditEditorSelectorInterface
   */
  protected $editorSelector;

  /**
   * Constructs a new EditMetadataGenerator.
   *
   * @param EditEntityFieldAccessCheckInterface $access_checker
   *   An object that checks if a user has access to edit a given field.
   * @param QuickEditEditorSelectorInterface $editor_selector
   *   An object that determines which editor to attach to a given field.
   */
  public function __construct(EditEntityFieldAccessCheckInterface $access_checker, QuickEditEditorSelectorInterface $editor_selector) {
    $this->accessChecker = $access_checker;
    $this->editorSelector = $editor_selector;
  }

  /**
   * Implements QuickEditMetadataGeneratorInterface::generateEntityMetadata().
   */
  public function generateEntityMetadata($entity_type, $entity, $langcode) {
    return array(
      'label' => $entity->title,
    );
  }

  /**
   * Implements QuickEditMetadataGeneratorInterface::generateFieldMetadata().
   */
  public function generateFieldMetadata($entity_type, $entity, array $instance, $langcode, $view_mode) {
    $field_name = $instance['field_name'];

    // Early-return if user does not have access.
    $access = $this->accessChecker->accessEditEntityField($entity_type, $entity, $field_name);
    if (!$access) {
      return array('access' => FALSE);
    }

    // Early-return if no editor is available.
    if (!_quickedit_is_extra_field($entity_type, $field_name)) {
      $display = field_get_display($instance, $view_mode, $entity);
      $formatter_type = field_info_formatter_types($display['type']);
      $items = field_get_items($entity_type, $entity, $field_name, $langcode);
      $items = ($items === FALSE) ? array() : $items;
      $editor_id = $this->editorSelector->getEditor($formatter_type, $instance, $items);
    }
    else {
      // @see hook_quickedit_extra_fields_info()
      $extra = quickedit_extra_field_info($entity_type, $field_name);
      if (isset($extra['view mode dependent editor'][$view_mode])) {
        $editor_id = $extra['view mode dependent editor'][$view_mode];
      }
      else {
        $editor_id = $extra['default editor'];
      }
    }
    if (!isset($editor_id)) {
      return array('access' => FALSE);
    }

    // Gather metadata, allow the editor to add additional metadata of its own.
    if (!_quickedit_is_extra_field($entity_type, $field_name)) {
      $label = $instance['label'];
    }
    else {
      $label = quickedit_extra_field_info($entity_type, $field_name, 'label');
    }
    list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
    $metadata = array(
      'label' => check_plain($label),
      'access' => TRUE,
      'editor' => $editor_id,
      'aria' => t('Entity @type @id, field @field', array('@type' => $entity_type, '@id' => $id, '@field' => $label)),
    );
    $alter_hook_context = array(
      'entity_type' => $entity_type,
      'entity' => $entity,
      'field_name' => $field_name,
    );
    if (!_quickedit_is_extra_field($entity_type, $field_name)) {
      $editor_plugin = _quickedit_get_editor_plugin($editor_id);
      $attachments[$editor_id] = $editor_plugin->getAttachments();
      $custom_metadata = $editor_plugin->getMetadata($instance, $items);
      if (count($custom_metadata)) {
        $metadata['custom'] = $custom_metadata;
      }

      $alter_hook_context += array(
        'field' => $instance,
        'items' => $items,
      );
    }

    // Allow the metadata to be altered.
    drupal_alter('quickedit_editor_metadata', $metadata, $alter_hook_context);

    return $metadata;
  }

}

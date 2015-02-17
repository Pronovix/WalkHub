<?php

/**
 * @file
 * Contains' Quick Edit's EditorSelector.
 *
 * @see Drupal 8's \Drupal\quickedit\EditorSelector.
 */

module_load_include('php', 'quickedit', 'includes/QuickEditEditorSelectorInterface');

/**
 * Selects an in-place editor (an Editor plugin) for a field.
 */
class QuickEditEditorSelector implements QuickEditEditorSelectorInterface {

  /**
   * A list of alternative editor plugin IDs, keyed by editor plugin ID.
   *
   * @var array
   */
  protected $alternatives;

  /**
   * Constructs a new QuickEditEditorSelector.
   */
  public function __construct() {
  }

  /**
   * Implements QuickEditEditorSelectorInterface::getEditor().
   */
  public function getEditor($formatter_type, array $instance, array $items) {
    $editors = quickedit_editor_list();

    // Build a static cache of the editors that have registered themselves as
    // alternatives to a certain editor.
    if (!isset($this->alternatives)) {
      foreach ($editors as $alternative_editor_id => $editor) {
        if (isset($editor['alternativeTo'])) {
          foreach ($editor['alternativeTo'] as $original_editor_id) {
            $this->alternatives[$original_editor_id][] = $alternative_editor_id;
          }
        }
      }
    }

    // Check if the formatter defines an appropriate in-place editor. For
    // example, text formatters displaying untrimmed text can choose to use the
    // 'plain_text' editor. If the formatter doesn't specify, fall back to the
    // 'form' editor, since that can work for any field. Formatter definitions
    // can use 'disabled' to explicitly opt out of in-place editing.
    $formatter_settings = $formatter_type['settings'];
    $editor_id = $formatter_settings['quickedit']['editor'];
    if ($editor_id === 'disabled') {
      return;
    }
    elseif ($editor_id === 'form') {
      return 'form';
    }

    // No early return, so create a list of all choices.
    $editor_choices = array($editor_id);
    if (isset($this->alternatives[$editor_id])) {
      $editor_choices = array_merge($editor_choices, $this->alternatives[$editor_id]);
    }

    // Make a choice.
    foreach ($editor_choices as $editor_id) {
      $editor_plugin = _quickedit_get_editor_plugin($editor_id);
      if ($editor_plugin->isCompatible($instance, $items)) {
        return $editor_id;
      }
    }

    // We still don't have a choice, so fall back to the default 'form' editor.
    return 'form';
  }

  /**
   * Implements QuickEditEditorSelectorInterface::getEditorAttachments().
   */
  public function getEditorAttachments(array $editor_ids) {
    $attachments = array();
    $editor_ids = array_unique($editor_ids);

    // Editor plugins' attachments.
    foreach ($editor_ids as $editor_id) {
      $editor_plugin = _quickedit_get_editor_plugin($editor_id);
      $attachments[$editor_id] = $editor_plugin->getAttachments();
      // Allows contrib to declare additional dependencies for the editor.
      drupal_alter('quickedit_editor_attachments', $attachments[$editor_id], $editor_id);
    }

    return drupal_array_merge_deep_array($attachments);
  }

}

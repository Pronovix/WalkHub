Description
-----------
This module makes it possible to edit fields in-place.

Like Drupal 8's implementation of in-place editing, IE>=9 is supported.


Installation
------------
1. Install like any other Drupal module.
2. Download Underscore 1.5.x and Backbone 1.x from http://underscorejs.org/ and
   http://backbonejs.org/, respectively and put them in sites/all/libraries, in
   a "underscore" and a "backbone" subdirectory, respectively. Either the
   development or production version will work. Edit module will automatically
   use the production (minified) version if it's available, because it's more
   efficient.
3. Grant the 'Access in-place editing' permission to relevant roles.
4. Contextual links on nodes will now have a 'Quick edit' link. Clicking it will
   start in-place editing of that node!

If you're using Panels, then you'll want to apply a patch that fixes a bug in
Panels which prevents Quick Edit from working: https://drupal.org/node/2169571.


In-place WYSIWYG editing using CKEditor
---------------------------------------
1. Download and install the latest stable release (version 1.13 or newer) of the
   CKEditor module from http://drupal.org/project/ckeditor.
   Note that *only* the CKEditor module is supported, not any other module, like
   the "Wysiwyg" module (http://drupal.org/project/wysiwyg).
2. Download this Quick Edit-optimized build of CKEditor:
   http://download.cksource.com/CKEditor%20for%20Drupal/edit/ckeditor_4.3.2_edit.zip
   Alternatively, go to http://ckeditor.com/builder, choose any preset you like,
   then add the "Shared Space" plugin to the list of "Selected plugins". Then
   click the "Download" button.
   Only version 4.2 or newer of CKEditor is supported.
   NOTE: If you use the "Source" button, also add the "Source Dialog" plugin to
   the list of "Selected plugins".
3. Extract the downloaded package to sites/all/libraries/ckeditor. For maximum
   security, it is recommended to delete the included "samples" directory at
   sites/all/libraries/ckeditor/samples.
4. Go to admin/config/content/ckeditor/, enable one of the CKEditor profiles for
   each text format where you want to use CKEditor. Or create a new CKEditor
   profile.
   e.g. Enable the default "Advanced" profile for Drupal's "Filtered HTML" text
   format.
5. Find a node that uses e.g. the "Filtered HTML" text format for its body,
   click the "Quick edit" link, then click the node's body, and you should see
   CKEditor's in-place editing!


FAQ
---
Q: I can't see any contextual links, what now?
A: Your theme is probably stripping them. Your theme's templates must always
   print "$title_suffix".
   See https://drupal.org/documentation/modules/contextual.
Q: Quick Edit breaks my node titles!
A: This probably means you're using a theme that inappropriately uses the node
   title as a "title" attribute as well, without stripping any HTML used in the
   title. Within an attribute, HTML is pointless and potentially harmful.
   So if your theme's node.tpl.php does something like this:
     title="<?php print $title ?>"
   then please replace it with this:
     title="<?php print filter_xss($title, array()) ?>"
   This ensures that any HTML tags are stripped from the title.
   See http://drupal.org/node/1913964#comment-7231462 for details.
Q: Why does Quick Edit add attributes to my HTML even for users that don't have
   the permission to use in-place editing?
A: First: precisely because these are just small bits of metadata, there is no
   harm; there is no security risk involved.
   Second: it is by design, this metadata is always added, to not break Drupal's
   render cache.
Q: The status report says "Quick Edit's attributes on entities are missing" or
   "Quick Edit's attributes on fields are missing.". How do I fix these?
A: Your theme is probably stripping them. Your theme's templates must always
   print "$attributes" for entities and fields. This implies that a wrapper for
   each field is a requirement. If you're not using a wrapper yet for e.g. your
   fields, you'll want to do something like this:
     -<?php print render($items); ?>
     +<div <?php print $attributes; ?>>
     +  <?php print render($items); ?>
     +</div>
Q: The status report says "The content region class is missing". How do I
   fix this?
A: Your theme is stripping either just the "region-content" class on the
   "content" region wrapper, or it is stripping that wrapper entirely. Edit
   depends on this.
   E.g. the Zen theme does this by default. Drupal user loopduplicate has posted
   a work-around, see https://drupal.org/comment/8310077#comment-8310077 and
   https://drupal.org/comment/8310093#comment-8310093.
Q: Why do I get a 'The filter "<filter name>" has no type specified!' error?
A: For Quick Edit module to allow for in-place editing of "processed text"
   fields (i.e. text passed through Drupal's filter system, via check_markup()),
   it needs to know about each filter what type of filter it is. For simpler
   text formats (i.e. with simpler filters), the unfiltered original may not
   have to be retrieved from the server. See http://drupal.org/node/1817474 for
   details.
Q: I want to disable in-place editing for a field.
A: Any field that has the #skip_quickedit property set on it will not be made
   in-place editable. You can add this property through
   hook_field_attach_view_alter(). e.g.:
     function MYMODULE_field_attach_view_alter(&$output, $context) {
       // Disable in-place editing for 'body' fields on 'node' entities.
       if ($context['entity_type'] === 'node' && isset($output['body'])) {
         $output['body']['#skip_quickedit'] = TRUE;
       }
     }
Q: Why do contextual links now appear on node pages?
A: Quick Edit module indeed enables contextual links on node pages as well, to
   allow users to in-place edit not only "teaser" nodes, but also "full" nodes.
   If you want to disable this behavior (which also means disabling in-place
   editing on node pages!), then you can undo the changes made by
   quickedit_node_view_alter() in another module, by either implementing
   hook_node_view_alter() yourself, or by implementing
   hook_module_implements_alter() to prevent quickedit_node_view_alter() from
   being executed.


Drupal 8 to Drupal 7 backporting considerations
-----------------------------------------------
From a Drupal 8 perspective.
1.  Use the Libraries API module to depend on Underscore and Backbone.
2.  Drupal 8's build of CKEditor already includes the sharedspace plugin, in
    Drupal 7 we must ask users to create a custom CKEditor build.
3.  Analogously for the sourcedialog CKEditor plugin, except that is only
    necessary when one of the CKEditor module profiles is configured to use the
    "Source" button.
4.  `drupalSettings` is called `Drupal.settings`. The code was kept the same by
    aliasing `Drupal.settings` to `drupalSettings` in the file-level closures.
5.  `Drupal.ajax.prototype.commands` is fundamentally broken in Drupal 7, see
    https://drupal.org/node/2019879 and https://drupal.org/node/2019481 for an
    explanation plus work-around. That work-around is used in this codebase.
    See https://drupal.org/comment/7532741#comment-7532741 for details.
6.  Related: the equivalent of calling `Drupal.AjaxCommands.prototype.insert` in
    Drupal 8 is calling `Drupal.ajax.prototype.commands.insert` in Drupal 7.
7.  Drupal 7 does not ship with a modal dialog, so stick to Edit's own, that was
    removed in Drupal 8 in commit 690e51d5458aa770099412d4563ad4e38b35fa74.
8.  The CKEditor integration is directly included with Edit module and depends
    on ckeditor.module, whereas in Drupal 8 the Text Editor module
    (editor.module) provides a generic integration with Edit module, which
    Drupal 8's CKEditor module then uses to integrate with Edit without Edit-
    specific code. Such abstraction is unfortunately infeasible in Drupal 7.
9.  `Drupal.debounce()` only exists in Drupal 8. It is duplicated in
    `Drupal.edit.util` and then injected into the closure like in Drupal 8.
10. The `Drupal.url()` function does not exist in Drupal 7, so we must generate
    the AJAX URLs on the server side and pass them to the JS through
    Drupal.settings.
11. Drupal 8 introduced `hook_entity_view_alter()` to be able to add attributes
    to all entity types at once. That doesn't exist in Drupal 7, so we're
    condemned to simulate this on a per-entity type basis:
    `hook_preprocess_node()`, etc.
    See https://drupal.org/node/2018597.
12. Drupal 7 only has two response content types: HTML and AJAX. To create a
    JSON response in 7, one must use `drupal_json_output()`, and no delivery
    callbacks.
13. Apparently it's impossible to #attach assets directly to the `$page` render
    array in `hook_page_build()` in Drupal 7: such attached assets are ignored.
    One must attach them to one of the block regions. As a consequence, we must
    enable block.module in tests.
14. Drupal 7 ships with jQuery UI Position 1.8.7; Edit needs 1.10. Requiring an
    updated jQuery UI causes a lot of compatibility problems in general, so Edit
    ships with a monkey-patched version of it. See js/ducktape.position.js.
15. Contextual links have a different structure in Drupal 7 versus 8. Various
    selectors were adjusted.
16. There's a bizarre bug in jQuery 1.4.4 (the version of jQuery that Drupal 7
    ships with) where calling `.removeAttr('contentEditable')` fails and calling
    `.removeAttr('contenteditable')` works. So changed to the latter.
    See http://bugs.jquery.com/ticket/7792.
17. Hooks and internal functions that can pass only `EntityInterface $entity`
    in Drupal 8 need to pass `string $entity_type, stdClass $entity` in Drupal 7.
18. Only `WebTestBase`-based tests were backported from Drupal 8 to Drupal 7,
    since `DrupalUnitTestBase` does not exist in Drupal 7. This does cover the majority of Edit's functionality though!
19. The Ajax command classes like `AppendCommand` etc. in Drupal 8 don't exist
    in Drupal 7: array structures are used instead.
    See https://drupal.org/node/1843212.
20. The `Unicode` class from Drupal 8 does not exist in Drupal 7, hence
    `Unicode::substr()` doesn't exist either; in Drupal 7 we must use
    `drupal_substr()` instead.
21. When calling `field_view_field()` with custom display settings automatically
    generates a view mode ID called '_custom' in Drupal 8, but '_custom_display'
    in Drupal 7.
22. The concurrent editing prevention from Drupal 8 is impossible to backport to
    Drupal 7. See https://drupal.org/node/1901100#comment-7794939 and
    http://drupalcode.org/project/drupal.git/commitdiff/36a7dd83bbdd5912023122fcce0e1c55ccb5d3e3.
23. To support Panels, and particularly the embedding of an existing node in a
    Panels Pane (which renders nodes using the default render pipeline), it was
    necessary to introduce a new "data-edit-contextual-region-for-entity" data-
    attribute, to allow the contextual links not to be set on the node entity
    DOM element itself, but on the Panels Pane. This has been forward-ported, to
    also allow the future Drupal 8 contrib version of Panels to do this.

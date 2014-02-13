<?php
/**
 * @file
 * walkhub_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function walkhub_blog_taxonomy_default_vocabularies() {
  return array(
    'blog_category' => array(
      'name' => 'Blog category',
      'machine_name' => 'blog_category',
      'description' => 'Blog categories',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

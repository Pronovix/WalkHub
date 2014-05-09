<?php

/**
* @file
* Default simple view template to display a list of rows.
*
* @ingroup views_templates
*/
?>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php if ($id % 4 == 0): ?>
    <div class="row">
  <?php endif; ?>
    <?php if ($id % 2 == 0): ?>
      <div class="small-12 large-6 columns nopad">
    <?php endif; ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php if ($id % 2 == 1): ?>
      </div>
    <?php endif; ?>
  <?php if ($id % 4 == 3): ?>
    </div>
  <?php endif; ?>
<?php endforeach; ?>

<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php
    global $theme_path;
  ?>
  <link rel="apple-touch-icon" href="<?php print $theme_path; ?>/apple-touch-icon-precomposed.png"/>
  <link rel="apple-touch-icon" sizes="72x72" href="<?php print $theme_path; ?>/apple-touch-icon-72x72-precomposed.png" />
  <link rel="apple-touch-icon" sizes="114x114" href="<?php print $theme_path; ?>/apple-touch-icon-114x114-precomposed.png" />
  <link rel="apple-touch-icon" sizes="144x144" href="<?php print $theme_path; ?>/apple-touch-icon-144x144-precomposed.png" />
  <link rel="logo" type="image/svg" href="<?php print $theme_path; ?>/walkhub-logo.svg"/>
  <meta name="publisher" content="walkhub.com"> 
  <meta name="robots" content="Index, Follow, All" />
  <meta name="rating" content="global" />
  <meta name="revisit-after" content="3 days" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>

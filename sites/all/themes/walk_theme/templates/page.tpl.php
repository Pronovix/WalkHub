<header id="navbar" role="banner" class="navbar navbar-fixed-top">
  <div class="navbar-inner">
    <div class="container">
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>

      <div id="logo-region" class="span4">
        <?php if (!empty($logo)): ?>
          <!-- Logo region -->
          <a class="logo pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="/<?php print $GLOBALS['theme_path'] ?>/images/walkhub-logo-light.svg" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
      </div>

      <?php if (!empty($page['header_menu'])): ?>
        <!-- Header menu region -->
        <div id="header-menu-region" class="span6">
          <?php print render($page['header_menu']); ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($page['search'])): ?>
        <!-- Search region -->
        <div id="search-region" class="span2">
          <?php print render($page['search']); ?>
        </div>
      <?php endif; ?>

    </div>
  </div>
</header>



<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  

    <section class="<?php print _bootstrap_content_span($columns); ?>">  
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <div class="well"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<footer>

  <?php
    global $theme_path;
  ?>

  <div class="copyright">
    <div class="container">
<div class="row-fluid">
            <div class="span2">
              <h2>Heading</h2>
               <ul class="menu">
                 <li>teszt1</li>
                 <li>teszt2</li>
                 <li>teszt3</li>
                 <li>teszt4</li>
                 <li>teszt5</li>
               </ul>
            </div><!--/span-->
            <div class="span2">
              <h2>Heading</h2>
               <ul class="menu">
                 <li>teszt1</li>
                 <li>teszt2</li>
                 <li>teszt3</li>
                 <li>teszt4</li>
                 <li>teszt5</li>
               </ul>
            </div><!--/span-->
            <div class="span2">
              <h2>Heading</h2>
              <ul class="menu">
                <li>teszt1</li>
                <li>teszt2</li>
                <li>teszt3</li>
                <li>teszt4</li>
                <li>teszt5</li>
              </ul>
            </div><!--/span-->
            <div class="span2">
              <h2>Heading</h2>
                <ul class="menu">
                  <li>teszt1</li>
                  <li>teszt2</li>
                  <li>teszt3</li>
                  <li>teszt4</li>
                  <li>teszt5</li>
                </ul>
            </div><!--/span-->
            <div class="span4 right">
<object data="<?php print $theme_path; ?>/walkhub-logo.svg" type="image/svg+xml" width="220" height="106" class="logo">
  <img src="<?php print $theme_path; ?>/images/walkhub-logo.png" class="logo" />
</object>


            </div><!--/span-->
          </div>
    </div>
  </div>

  </div>
  <div class="footer">
  <div class="container">
    <div class="row-fluid show-grid">
      <div class="span6">
        <ul class="menu line">
          <li>teszt1</li>
          <li>teszt2</li>
          <li>teszt3</li>
          <li>teszt4</li>
          <li>teszt5</li>
        </ul>
      </div>
      <div class="span6 right">2013 © PRONOVIX, All rights reserved.</div>
  </div>

 <?php print render($page['footer']); ?>
  </div>
  <div>
</footer>
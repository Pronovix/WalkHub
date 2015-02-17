<!--.page -->
<div role="document" class="page">

  <?php if (!empty($page['header'])): ?>
  <div class="login-container">
  <div class="row">
    <?php
    print render($page['header']);
    ?>
    </div>
    </div>
  <?php endif; ?>

  <!--.l-header region -->
  <header role="banner" class="l-header" id="main-header">

    <?php if ($top_bar): ?>
      <!--.top-bar -->
      <?php if ($top_bar_classes): ?>
      <div class="<?php print $top_bar_classes; ?>">
      <?php endif; ?>
        <nav class="top-bar clearfix"<?php print $top_bar_options; ?>>
          <a href="<?php print $front_page; ?>" title="<?php print $site_name; ?>" id="main_logo_link">
            <img src="<?php $path = $GLOBALS['base_url'].'/'.path_to_theme();  echo $path; ?>/images/orange-theme-images/placeholders/walkhub.jpg">
          </a>
          <ul class="title-area">
            <li class="toggle-topbar menu-icon"><a href="#"><span><?php print $top_bar_menu_text; ?></span></a></li>
          </ul>
          <section class="top-bar-section">
            <?php if ($top_bar_main_menu) :?>
              <?php print $top_bar_main_menu; ?>
            <?php endif; ?>
          </section>
        </nav>
      <?php if ($top_bar_classes): ?>
      </div>
      <?php endif; ?>
      <!--/.top-bar -->
    <?php endif; ?>

    <!-- Title, slogan and menu -->
    <?php if ($alt_header): ?>
    <section class="row <?php print $alt_header_classes; ?>">

      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php if ($site_name): ?>
        <?php if ($title): ?>
          <div id="site-name" class="element-invisible"'>
            <strong>
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </strong>
          </div>
        <?php else: /* Use h1 when the content title is empty */ ?>
          <h1 id="site-name"'>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h2 title="<?php print $site_slogan; ?>" class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>

      <?php if ($alt_main_menu): ?>
        <nav id="main-menu" class="navigation" role="navigation">
          <?php print ($alt_main_menu); ?>
        </nav> <!-- /#main-menu -->
      <?php endif; ?>
    </section>
    <?php endif; ?>
    <!-- End title, slogan and menu -->

    <?php /*if (!empty($page['header'])): ?>
      <!--.l-header-region -->
      <section class="l-header-region row">
        <div class="large-12 columns">
          <?php print render($page['header']); ?>
        </div>
      </section>
      <!--/.l-header-region -->
    <?php endif;*/ ?>

  </header>
<?php if($is_front): ?>
<h2 class="main-slogen">Walkthrough tutorials designed for web applications and websites.</h2>
<?php endif; ?>
  <!--/.l-header -->

  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section id="featured">
      <div class="row">
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <?php if (!empty($page['news'])): ?>
    <!--/.featured -->
    <section id="news">
      <div class="row">
        <div class="large-12 columns">
          <?php print render($page['news']); ?>
        </div>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>



  <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="large-12 columns">
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <?php if (!empty($breadcrumb)): ?>
    <section id="breadcrumb">
      <div class="row">
        <div class="large-8 medium-8 small-12 columns">
          <?php print render($breadcrumb); ?>
        </div>
        <div class="large-4 medium-4 small-12 columns">
          <ul class="share">
            <li>
              <a class="gl" href="https://plus.google.com/share?url=http%3A%2F%2Fwalkhub.net<?php print url($_GET['q']); ?>">
                <i class="fa fa-2x fa-google-plus-square"></i>
              </a>
            </li>
            <li>
              <a class="li" href="http://www.linkedin.com/shareArticle?mini=true&amp;url=http%3A%2F%2Fwalkhub.net<?php print url($_GET['q']); ?>">
                <i class="fa fa-2x fa-linkedin-square"></i>
              </a>
            </li>
            <li>
              <a class="fb" href="http://www.facebook.com/share.php?u=http%3A%2F%2Fwalkhub.net<?php print url($_GET['q']); ?>">
                <i class="fa fa-2x fa-facebook-square"></i>
              </a>
            </li>
            <li>
              <a class="tw" href="http://twitter.com/home?status=http%3A%2F%2Fwalkhub.net<?php print url($_GET['q']); ?>">
                <i class="fa fa-2x fa-twitter-square"></i>
              </a>
            </li>
          </ul>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <main role="main" class="row l-main">
    <div class="<?php print $main_grid; ?> main columns">
      <?php if ($messages && !$zurb_foundation_messages_modal): ?>
        <!--/.l-messages -->
        <section class="l-messages">
          <div class="large-12 columns">
            <?php if ($messages): print $messages; endif; ?>
          </div>
        </section>
        <!--/.l-messages -->
      <?php endif; ?>

      <a id="main-content"></a>

      <?php if ($title && !$is_front): ?>
        <?php print render($title_prefix); ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      <?php endif; ?>

      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
        <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>

      <?php print render($page['content']); ?>
    </div>
    <!--/.main region -->

    <?php if (!empty($page['sidebar_first'])): ?>
      <!--.sidebar_first -->
        <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first columns sidebar">
          <?php print render($page['sidebar_first']); ?>
        </aside>
      <!--/.sidebar_first -->
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <!--.sidebar_second -->
      <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
      <!--/.sidebar_second -->
    <?php endif; ?>
  </main>
  <!--/.main-->
<!--/.call-to-action-first-->
<?php if (!empty($page['call-to-action-first'])): ?>
  <section id="call-to-action-first">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['call-to-action-first']); ?>
      </div>
    </div>
  </section>
<?php endif; ?>
<!--/.call-to-action-first-->
<!--/.tweets-->
<?php if (!empty($page['tweets'])): ?>
  <section id="tweets">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['tweets']); ?>
      </div>
    </div>
  </section>
<?php endif; ?>
<!--/.tweets-->
<!--/.portfolio-->
<?php if (!empty($page['portfolio'])): ?>
  <section id="portfolio">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['portfolio']); ?>
      </div>
    </div>
  </section>
<?php endif; ?>
<!--/.portfolio-->
<?php if (!empty($page['news-bottom'])): ?>
  <!--/.news-bottom -->
  <section id="news-bottom">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['news-bottom']); ?>
      </div>
    </div>
  </section>
  <!--/.news-bottom -->
<?php endif; ?>

<?php if (!empty($page['content-bottom'])): ?>
  <!--/.content-bottom-->
  <section id="content-bottom">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['content-bottom']); ?>
      </div>
    </div>
  </section>
  <!--/.content-bottom -->
<?php endif; ?>
<?php if (!empty($page['trusted-by'])): ?>
  <!--/.call-to-action-bottom-->
  <section id="trusted-by">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['trusted-by']); ?>
      </div>
    </div>
  </section>
  <!--/.call-to-action-bottom-->
<?php endif; ?>
<?php if (!empty($page['call-to-action'])): ?>
  <!--/.call-to-action-bottom-->
  <section id="call-to-action">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['call-to-action']); ?>
      </div>
    </div>
  </section>
  <!--/.call-to-action-bottom-->
<?php endif; ?>

<?php if (!empty($page['signup'])): ?>
  <!--.signup -->
  <section id="signup">
    <div class="row">
      <div class="large-12 columns">
        <?php print render($page['signup']); ?>
      </div>
    </div>
  </section>
  <!--/.signup -->
<?php endif; ?>

  <!--.l-footer-->
  <footer id="footermain" role="contentinfo" class="clearfix">

    <div id="footer" class="row">
      <div class="container">

        <div class="large-8 medium-8 small-12 columns">

          <nav id="footer-nav" class="clearfix">
            <?php if (!empty($page['footer'])): ?>
                <?php print render($page['footer']); ?>
            <?php endif; ?>
          </nav>
          <!-- end #footer-nav -->

          <ul class="contact-info">
            <li class="address">H-6724 Szeged, Zoltán str. 6. Hungary<br>B-9940 Sleidinge, Akkerken 6. Belgium</li>
            <li class="phone">+36 62 648 005</li>
            <li class="email"><a href="mailto:kata@pronovix.com">Help: kata@pronovix.com </a><br>
              <a href="mailto:kristof@pronovix.com">Sales: kristof@pronovix.com </a></li>
          </ul>
          <!-- end .contact-info -->

        </div>
        <!-- end .three-fourth -->

        <div class="large-4 medium-4 small-12 columns">

          <span class="title">Stay connected</span>

          <ul class="social-links">
            <li><a href="https://twitter.com/WalkHub"><i class="fa fa-twitter"></i></a></li>
            <li><a href="https://www.facebook.com/pages/Walkhub/158797744276184 "><i class="fa fa-facebook"></i></a>
            </li>
            <li><a href="https://plus.google.com/108444039431065611518/posts "><i class="fa fa-google-plus"></i></a>
            </li>
            <li><a href="https://www.youtube.com/channel/UCEGmDgCVSF0ZzQTU_Ho1Pzg "><i
                  class="fa fa-youtube"></i></a></li>
            <li>
              <a href="http://pronovix.us6.list-manage.com/subscribe?u=5756ad9696bad5dc41c7b93f9&id=adc4e7fe0d "><i
                  class="fa fa-envelope-o"></i></a></li>
            <li><a href="https://github.com/kvantomme/Walkthrough/wiki "><i class="fa fa-github"></i></a></li>
          </ul>
          <!-- end .social-links -->

        </div>
        <!-- end .one-fourth.last -->

      </div>
    </div>
  </footer>
  <footer id="footer-bottom" class="clearfix">

  <div class="row">

    <ul>
      <li>WalkHub &copy; 2014</li>
      <li><a href="#">Terms &amp; conditions</a></li>
    </ul>

  </div>
  <!-- end .container -->

</footer>
  <!--/.footer-->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->

<!--.page -->
<div role="document" class="page">

  <?php if (!empty($page['header'])): ?>
    <?php
      print render($page['header']);
    ?>
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
            <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" version="1.1" x="0px" y="0px" width="90px" height="44.252px" viewBox="0 0 152.964 75.201" enable-background="new 0 0 152.964 75.201" xml:space="preserve" id="main_logo_svg"><style>.style0{stop-color:	#474747;}.style1{stop-color:	#474747;}.style10{fill:	url(#SVGID_9_);}.style11{fill:	url(#SVGID_10_);}.style12{fill:	url(#SVGID_11_);}.style13{fill:	url(#SVGID_12_);}.style14{fill:	url(#SVGID_13_);}.style15{fill:	url(#SVGID_14_);}.style16{fill:	url(#SVGID_15_);}.style17{fill:	url(#SVGID_16_);}.style18{fill:	url(#SVGID_17_);}.style19{fill:	url(#SVGID_18_);}.style2{fill:	url(#SVGID_1_);}.style20{fill:	url(#SVGID_19_);}.style3{fill:	url(#SVGID_2_);}.style4{fill:	url(#SVGID_3_);}.style5{fill:	url(#SVGID_4_);}.style6{fill:	url(#SVGID_5_);}.style7{fill:	url(#SVGID_6_);}.style8{fill:	url(#SVGID_7_);}.style9{fill:	url(#SVGID_8_);}</style><g id="main_logo"><g><g><linearGradient id="SVGID_1_" gradientUnits="userSpaceOnUse" x1="18.4" y1="4.2" x2="18.4" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M2.157 50.645c-0.273-0.814-0.771-1.041-1.587-1.041h-0.588V46.93h1.584 c2.176 0 2.9 0.4 3.6 2.539l4.666 14.45c0.359 1.1 0.7 2.4 0.7 2.446h0.09c0 0 0.365-1.359 0.728-2.446 l5.571-16.897h3.08l5.573 16.897c0.36 1.1 0.7 2.4 0.7 2.446h0.091c0 0 0.271-1.313 0.633-2.446l4.712-14.45 c0.68-2.13 1.403-2.539 3.578-2.539h1.586v2.674h-0.633c-0.771 0-1.313 0.227-1.587 1.041l-6.522 19.073h-3.397L19.144 53.5 c-0.363-1.132-0.682-2.448-0.682-2.448h-0.089c0 0-0.316 1.316-0.726 2.448l-5.526 16.218H8.679L2.157 50.645z" class="style2"/><linearGradient id="SVGID_2_" gradientUnits="userSpaceOnUse" x1="48.4" y1="4.2" x2="48.4" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M51.737 55.676h1.267v-0.274c0-4.757-1.722-6.432-5.889-6.432c-1.134 0-4.44 0.317-4.44 2 v1.45h-2.943v-2.174c0-3.17 5.436-3.852 7.429-3.852c7.202 0 8.9 3.9 8.9 8.745v10.916c0 0.7 0.4 1 1 1 h1.903v2.672h-3.127c-1.948 0-2.717-0.86-2.717-2.718c0-0.996 0.046-1.679 0.046-1.679h-0.091c0.045 0-1.857 4.939-7.565 4.9 c-3.808 0-7.749-2.221-7.749-6.751C37.781 55.9 47.8 55.7 51.7 55.676z M46.027 67.634c4.349 0 6.977-4.531 6.977-8.474 v-1.039H51.69c-3.579 0-10.735 0.089-10.735 5.21C40.955 65.5 42.6 67.6 46 67.634z" class="style3"/><linearGradient id="SVGID_3_" gradientUnits="userSpaceOnUse" x1="64.3" y1="4.2" x2="64.3" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M62.709 41.538c0-0.634-0.362-0.995-0.996-0.995h-1.902v-2.672h3.216 c1.948 0 2.8 0.8 2.8 2.762v25.414c0 0.7 0.4 1 1 0.999h1.902v2.672h-3.216c-1.95 0-2.765-0.816-2.765-2.764 V41.538z" class="style4"/><linearGradient id="SVGID_4_" gradientUnits="userSpaceOnUse" x1="80.2" y1="4.2" x2="80.2" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M72.591 41.538c0-0.634-0.36-0.995-0.994-0.995h-1.905v-2.672h3.216 c1.948 0 2.8 0.7 2.8 2.626v15.132h2.358c0.859 0 1.947-0.271 2.582-1.087l5.844-7.612h3.761l-6.569 8.3 c-1.134 1.402-1.722 1.631-1.722 1.631v0.089c0 0 0.7 0.3 1.4 1.678l4.123 7.383c0.405 0.8 0.9 1 2.1 0.999h1.223 v2.672h-2.13c-2.267 0-2.9-0.362-3.941-2.266l-4.529-8.153c-0.5-0.907-1.586-0.998-2.4-0.998H75.67v11.417h-3.079V41.538z" class="style5"/></g><g><linearGradient id="SVGID_5_" gradientUnits="userSpaceOnUse" x1="106.1" y1="4.2" x2="106.1" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M102.35 64.025c0.327-0.051 0.703-0.091 1.131-0.121c0.429-0.03 0.962-0.047 1.604-0.047 c0.561 0 1.1 0 1.6 0.138c0.499 0.1 0.9 0.2 1.3 0.466c0.371 0.2 0.7 0.5 0.9 0.9 c0.215 0.4 0.3 0.8 0.3 1.373c0 0.327-0.048 0.629-0.146 0.909c-0.095 0.281-0.226 0.525-0.39 0.7 c-0.162 0.21-0.345 0.383-0.549 0.519c-0.205 0.139-0.413 0.225-0.627 0.254c0.232 0 0.5 0.1 0.8 0.2 c0.285 0.1 0.6 0.3 0.8 0.496c0.244 0.2 0.4 0.5 0.6 0.849c0.162 0.3 0.2 0.8 0.2 1.3 c0 0.66-0.125 1.203-0.374 1.625c-0.251 0.425-0.585 0.758-1.01 1.002c-0.423 0.244-0.91 0.412-1.465 0.5 c-0.557 0.091-1.141 0.138-1.752 0.138c-0.468 0-0.93-0.013-1.389-0.038s-0.979-0.074-1.56-0.145V64.025z M105.238 68.5 c0.255 0 0.492-0.021 0.711-0.067c0.22-0.047 0.41-0.128 0.573-0.245c0.162-0.116 0.29-0.275 0.382-0.474 c0.093-0.198 0.138-0.45 0.138-0.757c0-0.295-0.055-0.537-0.16-0.726c-0.108-0.188-0.245-0.335-0.413-0.443 c-0.168-0.107-0.356-0.178-0.566-0.215c-0.208-0.033-0.414-0.052-0.618-0.052c-0.283 0-0.523 0.016-0.718 0.046v2.933H105.238z M104.566 73.346c0.144 0 0.3 0 0.5 0.045c0.188 0 0.4 0 0.5 0.018c0.215 0 0.437-0.021 0.672-0.063 c0.234-0.041 0.453-0.12 0.657-0.236c0.204-0.117 0.372-0.28 0.504-0.489s0.199-0.482 0.199-0.818 c0-0.314-0.052-0.577-0.153-0.787c-0.101-0.207-0.247-0.375-0.437-0.503c-0.187-0.127-0.411-0.216-0.67-0.267 c-0.26-0.052-0.549-0.077-0.863-0.077h-0.918V73.346z" class="style6"/><linearGradient id="SVGID_6_" gradientUnits="userSpaceOnUse" x1="114.8" y1="4.2" x2="114.8" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M111.564 64.041h6.233c0.061 0.3 0.1 0.6 0.1 0.932c0 0.336-0.03 0.657-0.091 1 h-4.003v2.383h3.178c0.062 0.3 0.1 0.6 0.1 0.947c0 0.326-0.031 0.647-0.093 0.963h-3.178v2.903h4.11 c0.062 0.3 0.1 0.6 0.1 0.933c0 0.335-0.03 0.655-0.092 0.963h-6.341V64.041z" class="style7"/><linearGradient id="SVGID_7_" gradientUnits="userSpaceOnUse" x1="122.9" y1="4.2" x2="122.9" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M121.817 65.936h-2.735c-0.062-0.306-0.092-0.627-0.092-0.963c0-0.315 0.03-0.626 0.092-0.932 h7.717c0.06 0.3 0.1 0.6 0.1 0.932c0 0.336-0.03 0.657-0.09 0.963h-2.735v9.092c-0.183 0.02-0.368 0.036-0.55 0.1 c-0.183 0.017-0.363 0.022-0.535 0.022c-0.174 0-0.359-0.005-0.557-0.015c-0.2-0.01-0.401-0.03-0.604-0.061V65.936z" class="style8"/><linearGradient id="SVGID_8_" gradientUnits="userSpaceOnUse" x1="131.1" y1="4.2" x2="131.1" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M129.823 64.041c0.216-0.031 0.418-0.054 0.611-0.07c0.193-0.013 0.407-0.021 0.642-0.021 c0.203 0 0.4 0 0.6 0.021c0.194 0 0.4 0 0.6 0.07l3.438 10.986c-0.418 0.061-0.825 0.091-1.223 0.1 c-0.387 0-0.763-0.03-1.131-0.091l-0.611-2.2h-3.637l-0.625 2.2c-0.366 0.061-0.72 0.091-1.056 0.1 c-0.376 0-0.747-0.03-1.114-0.091L129.823 64.041z M132.268 70.978L131 66.363l-1.329 4.614H132.268z" class="style9"/></g><g><linearGradient id="SVGID_9_" gradientUnits="userSpaceOnUse" x1="91.6" y1="4.2" x2="91.6" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="91.6" cy="20" r="3.2" class="style10"/><linearGradient id="SVGID_10_" gradientUnits="userSpaceOnUse" x1="139.3" y1="4.2" x2="139.3" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="139.3" cy="54.1" r="4.5" class="style11"/><linearGradient id="SVGID_11_" gradientUnits="userSpaceOnUse" x1="140.3" y1="4.2" x2="140.3" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="140.3" cy="13.5" r="4.5" class="style12"/><linearGradient id="SVGID_12_" gradientUnits="userSpaceOnUse" x1="103.3" y1="4.2" x2="103.3" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="103.3" cy="6" r="4.7" class="style13"/><linearGradient id="SVGID_13_" gradientUnits="userSpaceOnUse" x1="138.8" y1="4.2" x2="138.8" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="138.8" cy="31.5" r="3.2" class="style14"/><linearGradient id="SVGID_14_" gradientUnits="userSpaceOnUse" x1="148.7" y1="4.2" x2="148.7" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="148.7" cy="41.5" r="3.2" class="style15"/><linearGradient id="SVGID_15_" gradientUnits="userSpaceOnUse" x1="121.8" y1="4.2" x2="121.8" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M122.912 39.012c0-0.955-0.477-1.405-1.487-1.405c-0.327 0-0.56 0.026-0.806 0.108v2.771h0.438 C122.448 40.5 122.9 40 122.9 39.012z" class="style16"/><linearGradient id="SVGID_16_" gradientUnits="userSpaceOnUse" x1="119.2" y1="4.2" x2="119.2" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><circle cx="119.2" cy="12.9" r="3.2" class="style17"/><linearGradient id="SVGID_17_" gradientUnits="userSpaceOnUse" x1="113.8" y1="4.2" x2="113.8" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M113.796 59.016c9.838 0 17.813-7.976 17.813-17.813c0-9.837-7.976-17.813-17.813-17.813 s-17.813 7.976-17.813 17.813C95.984 51 104 59 113.8 59.016z M118.517 36.91c0.627-0.328 1.666-0.547 2.894-0.547 c2.472 0 3.6 1.1 3.6 2.498c0 1.229-0.928 1.884-1.678 2.074v0.028c0.846 0.2 1.9 1 1.9 2.3 c0 1.869-1.446 2.729-3.78 2.729c-1.297 0-2.307-0.19-3.003-0.545V36.91z M110.555 36.5h2.225v6.607 c0 0.8 0.5 1.3 1.1 1.256s1.118-0.424 1.118-1.27V36.5h2.048v6.62c0 1.789-1.378 2.922-3.262 2.9 c-1.871 0-3.263-1.12-3.263-2.922V36.5z M102.292 36.5h2.225v3.877h2.376V36.5h2.225v9.392h-2.225v-4.068h-2.376v4.068h-2.225 V36.5z" class="style18"/><linearGradient id="SVGID_18_" gradientUnits="userSpaceOnUse" x1="121.9" y1="4.2" x2="121.9" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M123.09 43.216c0-1.119-0.52-1.665-2.034-1.665h-0.438v3.017 c0.219 0.1 0.5 0.1 0.8 0.136C122.489 44.7 123.1 44.3 123.1 43.216z" class="style19"/><linearGradient id="SVGID_19_" gradientUnits="userSpaceOnUse" x1="120.2" y1="4.2" x2="120.2" y2="71.1"><stop offset="0" class="style0"/><stop offset="1" class="style1"/></linearGradient><path d="M106.704 59.945l2.604 0.794c1.234 0.3 2.5 0.4 3.8 0.489l2.724-0.069 c0.979-0.099 1.929-0.294 2.861-0.528l2.613-0.845c1.333-0.542 2.599-1.217 3.772-2.02l2.134-1.706 c1.47-1.331 2.738-2.87 3.764-4.578l2.765 1.298c-0.097 0.416-0.159 0.843-0.159 1.286c0 3.1 2.6 5.7 5.7 5.7 s5.703-2.56 5.703-5.704s-2.559-5.702-5.703-5.702c-1.724 0-3.251 0.783-4.297 1.994l-2.755-1.295 c0.753-1.757 1.255-3.645 1.476-5.618l10.938-0.226c0.655 1.6 2.2 2.7 4 2.658c2.387 0 4.328-1.941 4.328-4.327 c0-2.387-1.941-4.328-4.328-4.328c-2.022 0-3.711 1.399-4.185 3.276l-10.637 0.221c-0.041-1.699-0.294-3.344-0.734-4.913 l2.636-1.273l-0.043-0.088c0.79 0.8 1.9 1.4 3.1 1.37c2.388 0 4.329-1.942 4.329-4.328c0-2.387-1.941-4.328-4.329-4.328 c-2.386 0-4.328 1.941-4.328 4.328c0 0.2 0 0.4 0.1 0.638l-0.021-0.043l-2.358 1.1 c-0.877-2.016-2.086-3.848-3.54-5.455l8.642-9.444c0.884 0.6 1.9 0.9 3 0.9c3.146 0 5.704-2.558 5.704-5.704 c0-3.145-2.559-5.702-5.704-5.702c-3.145 0-5.701 2.558-5.701 5.702c0 1 0.3 2 0.8 2.841l-0.018-0.014l-8.71 9.5 c-2.306-1.942-5.059-3.36-8.074-4.11l0.964-4.565c2.183-0.219 3.899-2.046 3.899-4.285c0-2.386-1.942-4.328-4.329-4.328 s-4.328 1.942-4.328 4.328c0 1.6 0.8 2.9 2.1 3.69l-0.984 4.668c-0.707-0.075-1.424-0.119-2.149-0.119 c-1.501 0-2.958 0.179-4.367 0.492l-3.351-10.257c1.95-1.001 3.301-3.011 3.301-5.351c0-3.328-2.706-6.035-6.034-6.035 c-3.327 0-6.035 2.707-6.035 6.035s2.708 6 6 6.035c0.03 0 0.06-0.008 0.09-0.008l3.387 10.4 c-2.363 0.881-4.513 2.189-6.36 3.84l-4.873-4.46c0.244-0.541 0.388-1.139 0.388-1.771c0-2.386-1.942-4.328-4.329-4.328 c-2.386 0-4.327 1.942-4.327 4.328c0 2.4 1.9 4.3 4.3 4.329c0.762 0 1.467-0.214 2.089-0.562l4.813 4.4 c-2.994 3.504-4.814 8.042-4.814 13.003C93.735 49.8 99.1 57.1 106.7 59.945z M139.3 48.9 c2.845 0 5.2 2.3 5.2 5.158c0 2.846-2.314 5.16-5.159 5.16c-2.846 0-5.159-2.314-5.159-5.16 C134.141 51.2 136.5 48.9 139.3 48.908z M148.654 37.767c2.086 0 3.8 1.7 3.8 3.784c0 2.085-1.698 3.783-3.784 3.8 s-3.784-1.698-3.784-3.783C144.87 39.5 146.6 37.8 148.7 37.767z M138.833 27.703c2.087 0 3.8 1.7 3.8 3.8 c0 2.087-1.698 3.784-3.785 3.784c-2.086 0-3.784-1.697-3.784-3.784C135.048 29.4 136.7 27.7 138.8 27.703z M135.183 13.519c0-2.844 2.313-5.158 5.157-5.158c2.846 0 5.2 2.3 5.2 5.158c0 2.846-2.314 5.16-5.16 5.2 C137.497 18.7 135.2 16.4 135.2 13.519z M103.345 11.518c-3.028 0-5.491-2.464-5.491-5.491 c0-3.028 2.463-5.491 5.491-5.491c3.027 0 5.5 2.5 5.5 5.491C108.835 9.1 106.4 11.5 103.3 11.518z M91.647 23.8 c-2.086 0-3.783-1.698-3.783-3.785c0-2.085 1.697-3.783 3.783-3.783c2.087 0 3.8 1.7 3.8 3.8 C95.431 22.1 93.7 23.8 91.6 23.812z M115.375 12.902c0-2.087 1.697-3.784 3.784-3.784c2.086 0 3.8 1.7 3.8 3.8 s-1.699 3.784-3.785 3.784C117.072 16.7 115.4 15 115.4 12.902z M113.796 22.423c10.355 0 18.8 8.4 18.8 18.8 c0 10.356-8.424 18.78-18.779 18.78s-18.779-8.424-18.779-18.78C95.017 30.8 103.4 22.4 113.8 22.423z" class="style20"/></g></g></g></svg>
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
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

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

            <ul>
              <li><a href="index.html">Home</a></li>
              <li><a href="contact-us.html">Contact</a></li>
            </ul>

          </nav>
          <!-- end #footer-nav -->

          <ul class="contact-info">
            <li class="address">H-6724 Szeged, Zoltán str. 6. Hungary<br>B-9940 Sleidinge, Akkerken 6. Belgium</li>
            <li class="phone">+36 62 648 005</li>
            <li class="email"><a href="mailto:contact@companyname.com">Help: kata@pronovix.com </a><br>
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
      <li><a href="#">Legal Notice</a></li>
      <li><a href="#">Terms</a></li>
    </ul>

  </div>
  <!-- end .container -->

</footer>
  <!--/.footer-->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->

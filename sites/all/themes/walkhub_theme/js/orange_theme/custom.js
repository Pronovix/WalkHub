// If JavaScript is enabled remove 'no-js' class and give 'js' class
jQuery('html').removeClass('no-js').addClass('js');

// When DOM is fully loaded
jQuery(document).ready(function($) {

	/* ---------------------------------------------------------------------- */
	/*	Custom Functions
	/* ---------------------------------------------------------------------- */

	// Fixed scrollHorz effect
	$.fn.cycle.transitions.fixedScrollHorz = function($cont, $slides, opts) {

		$('.image-gallery-slider-nav a').on('click', function(e) {
			$cont.data('dir', '')
			if( e.target.className.indexOf('prev') > -1 ) $cont.data('dir', 'prev');
		});
		
		$cont.css('overflow', 'hidden');
		opts.before.push($.fn.cycle.commonReset);
		var w = $cont.width();
		opts.cssFirst.left = 0;
		opts.cssBefore.left = w;
		opts.cssBefore.top = 0;
		opts.animIn.left = 0;
		opts.animOut.left = 0-w;

		if( $cont.data('dir') === 'prev' ) {
			opts.cssBefore.left = -w;
			opts.animOut.left = w;
		}

	};

	// Slide effects for #portfolio-items-filter
	$.fn.slideHorzShow = function( speed, easing, callback ) { this.animate( { marginLeft : 'show', marginRight : 'show', paddingLeft : 'show', paddingRight : 'show', width : 'show' }, speed, easing, callback ); };
	$.fn.slideHorzHide = function( speed, easing, callback ) { this.animate( { marginLeft : 'hide', marginRight : 'hide', paddingLeft : 'hide', paddingRight : 'hide', width : 'hide' }, speed, easing, callback ); };

	// Test whether argument elements are parents of the first matched element
	$.fn.hasParent = function(objs) {
		objs = $(objs);
		var found = false;
		$(this[0]).parents().andSelf().each(function() {
			if ($.inArray(this, objs) != -1) {
				found = true;
				return false;
			}
		});
		return found;
	};

	/* end Custom Functions */

	/* ---------------------------------------------------------------------- */
	/*	Detect touch device
	/* ---------------------------------------------------------------------- */

	(function() {

		if( Modernizr.touch )
			$('body').addClass('touch-device');

	})();

	/* end Detect touch device */

	/* ---------------------------------------------------------------------- */
	/*	Main Navigation
	/* ---------------------------------------------------------------------- */
	
	(function() {

		var $mainNav    = $('#main-nav').children('ul'),
			optionsList = '<option value="" selected>Navigate...</option>';
		
		// Regular nav
		$mainNav.on('mouseenter', 'li', function() {
			var $this    = $(this),
				$subMenu = $this.children('ul');
			if( $subMenu.length ) $this.addClass('hover');
			$subMenu.hide().stop(true, true).fadeIn(200);
		}).on('mouseleave', 'li', function() {
			$(this).removeClass('hover').children('ul').stop(true, true).fadeOut(50);
		});

		// Responsive nav
		$mainNav.find('li').each(function() {
			var $this   = $(this),
				$anchor = $this.children('a'),
				depth   = $this.parents('ul').length - 1,
				indent  = '';

			if( depth ) {
				while( depth > 0 ) {
					indent += ' - ';
					depth--;
				}
			}

			optionsList += '<option value="' + $anchor.attr('href') + '">' + indent + ' ' + $anchor.text() + '</option>';
		}).end()
		  .after('<select class="responsive-nav">' + optionsList + '</select>');

		$('.responsive-nav').on('change', function() {
			window.location = $(this).val();
		});
		
	})();

	/* end Main Navigation */

	/* ---------------------------------------------------------------------- */
	/*	Min-height
	/* ---------------------------------------------------------------------- */

	(function() {

		// Set minimum height so footer will stay at the bottom of the window, even if there isn't enough content
		function setMinHeight() {

			$('#content').css('min-height',
				$(window).outerHeight(true)
				- ( $('body').outerHeight(true)
				- $('body').height() )
				- $('#header').outerHeight(true)
				- ( $('#content').outerHeight(true) - $('#content').height() )
				+ ( $('.page-title').length ? Math.abs( parseInt( $('.page-title').css('margin-top') ) ) : 0 )
				- $('#footer').outerHeight(true)
				- $('#footer-bottom').outerHeight(true)
			);
		
		}

		// Init
		setMinHeight();

		// Window resize
		$(window).on('resize', function() {

			var timer = window.setTimeout( function() {
				window.clearTimeout( timer );
				setMinHeight();
			}, 30 );

		});

	})();

	/* end Min-height */

	/* ---------------------------------------------------------------------- */
	/*	Fancybox
	/* ---------------------------------------------------------------------- */

	(function() {

		var $fancyboxItems = $('.single-image, .image-gallery, .iframe');

		// Images
		$('.single-image, .image-gallery').fancybox({
			type        : 'image',
			openEffect  : 'fade',
			closeEffect	: 'fade',
			nextEffect  : 'fade',
			prevEffect  : 'fade',
			helpers     : {
				title   : {
					type : 'inside'
				},
				buttons  : {},
				media    : {}
			},
			afterLoad   : function() {
				this.title = this.group.length > 1 ? 'Image ' + ( this.index + 1 ) + ' of ' + this.group.length + ( this.title ? ' - ' + this.title : '' ) : this.title;
			}
		});

		// Iframe
		$('.iframe').fancybox({
			type        : 'iframe',
			openEffect  : 'fade',
			closeEffect	: 'fade',
			nextEffect  : 'fade',
			prevEffect  : 'fade',
			helpers     : {
				title   : {
					type : 'inside'
				},
				buttons  : {},
				media    : {}
			},
			width       : '70%',
			height      : '70%',
			maxWidth    : 800,
			maxHeight   : 600,
			fitToView   : false,
			autoSize    : false,
			closeClick  : false
		});

		// Insert zoom icons, once page is fully loaded
		$(window).load(function() {

			$fancyboxItems.each(function() {

				var $this = $(this);

				if( !$this.hasClass('none') && !$this.children('.entry-image').length && !$this.parents('.image-gallery-slider').length )
					$this.css({
						'height' : $this.children().height() !== 0 ? $this.children().height() : 'auto',
						'width'  : $this.children().width()  !== 0 ? $this.children().width()  : 'auto'
					});

				$this.append('<span class="zoom">&nbsp;</span>');

			});

		});
		
	})();

	/* end Fancybox */

	/* ---------------------------------------------------------------------- */
	/*	Features Slider
	/* ---------------------------------------------------------------------- */

	(function() {

		var $slider = $('#features-slider');

		if( $slider.length ) {

			// Prevent multiple initialization
			if( $slider.data('init') === true )
				return false;

			$slider.data( 'init', true )
				   .smartStartSlider({
				   	   pos                : 0,
					   width              : 940,
					   height             : 380,
					   contentSpeed       : 450,
					   showContentOnhover : true,
					   hideContent        : false,
					   contentPosition    : '',
					   timeout            : 3000,
					   pause              : false,
					   pauseOnHover       : true,
					   hideBottomButtons  : false,
					   type               : {
						   mode           : 'random',
						   speed          : 400,
						   easing         : 'easeInOutExpo',
						   seqfactor      : 100
					   }
				   });

			// Detect swipe gestures support
			if( Modernizr.touch ) {

				function swipeFunc( e, dir ) {
				
					var $slider = $(e.currentTarget);
					
					if( dir === 'left' )
						$slider.find('.pagination-container .next').trigger('click');
					
					if( dir === 'right' )
						$slider.find('.pagination-container .prev').trigger('click');
					
				}
				
				$slider.swipe({
					swipeLeft       : swipeFunc,
					swipeRight      : swipeFunc,
					allowPageScroll : 'auto'
				});
				
			}

		}
		
	})();

	/* end Features Slider */

	/* ---------------------------------------------------------------------- */
	/*	Logos Slider
	/* ---------------------------------------------------------------------- */

	(function() {

		var $slider = $('#logos-slider');

		if( $slider.length ) {

			// Prevent multiple initialization
			if( $slider.data('init') === true )
				return false;

			$slider.data( 'init', true )
				   .smartStartSlider({
				   	   pos                : 0,
					   width              : 940,
					   height             : 380,
					   contentSpeed       : 450,
					   showContentOnhover : true,
					   hideContent        : false,
					   contentPosition    : 'center',
					   timeout            : 3000,
					   pause              : false,
					   pauseOnHover       : true,
					   hideBottomButtons  : false,
					   type               : {
						   mode           : 'random',
						   speed          : 400,
						   easing         : 'easeInOutExpo',
						   seqfactor      : 100
					   }
				   });

			// Detect swipe gestures support
			if( Modernizr.touch ) {
				
				function swipeFunc( e, dir ) {
				
					var $slider = $(e.currentTarget);
					
					if( dir === 'left' )
						$slider.find('.pagination-container .next').trigger('click');
					
					if( dir === 'right' )
						$slider.find('.pagination-container .prev').trigger('click');
					
				}
				
				$slider.swipe({
					swipeLeft       : swipeFunc,
					swipeRight      : swipeFunc,
					allowPageScroll : 'auto'
				});
				
			}

		}
		
	})();

	/* end Logos Slider */

	/* ---------------------------------------------------------------------- */
	/*	Photos Slider
	/* ---------------------------------------------------------------------- */

	(function() {

		var $slider = $('#photos-slider');

		if( $slider.length ) {

			// Prevent multiple initialization
			if( $slider.data('init') === true )
				return false;

			$slider.data( 'init', true )
				   .smartStartSlider({
				   	   pos                : 0,
					   width              : 940,
					   height             : 380,
					   contentSpeed       : 450,
					   showContentOnhover : true,
					   hideContent        : false,
					   contentPosition    : 'bottom',
					   timeout            : 3000,
					   pause              : false,
					   pauseOnHover       : true,
					   hideBottomButtons  : false,
					   type               : {
						   mode           : 'random',
						   speed          : 400,
						   easing         : 'easeInOutExpo',
						   seqfactor      : 100
					   }
				   });

			// Detect swipe gestures support
			if( Modernizr.touch ) {
				
				function swipeFunc( e, dir ) {
				
					var $slider = $(e.currentTarget);
					
					if( dir === 'left' )
						$slider.find('.pagination-container .next').trigger('click');
					
					if( dir === 'right' )
						$slider.find('.pagination-container .prev').trigger('click');
					
				}
				
				$slider.swipe({
					swipeLeft       : swipeFunc,
					swipeRight      : swipeFunc,
					allowPageScroll : 'auto'
				});
				
			}

		}
		
	})();

	/* end Photos Slider */

	/* ---------------------------------------------------------------------- */
	/*	Projects Carousel & Post Carousel
	/* ---------------------------------------------------------------------- */

	(function() {

		var $carousel = $('.projects-carousel, .post-carousel');

		if( $carousel.length ) {

			var scrollCount;

			function getWindowWidth() {

				if( $(window).width() < 480 ) {
					scrollCount = 1;
				} else if( $(window).width() < 768 ) {
					scrollCount = 2;
				} else if( $(window).width() < 960 ) {
					scrollCount = 3;
				} else {
					scrollCount = 4;
				}

			}

			function initCarousel( carousels ) {

				carousels.each(function() {

					var $this  = $(this);

					$this.jcarousel({
						animation           : 600,
						easing              : 'easeOutCubic',
						scroll              : scrollCount,
						itemVisibleInCallback : function() {
							onBeforeAnimation : resetPosition( $this );
							onAfterAnimation  : resetPosition( $this );
						}
					});

				});

			}

			function adjustCarousel() {

				$carousel.each(function() {

					var $this    = $(this),
						$lis     = $this.children('li')
						newWidth = $lis.length * $lis.first().outerWidth( true ) + 100;

					getWindowWidth();

					// Resize only if width has changed
					if( $this.width() !== newWidth ) {

						$this.css('width', newWidth )
							 .data('resize','true');

						initCarousel( $this );

						$this.jcarousel('scroll', 1);

						var timer = window.setTimeout( function() {
							window.clearTimeout( timer );
							$this.data('resize', null);
						}, 600 );

					}

				});

			}

			function resetPosition( elem ) {
				if( elem.data('resize') )
					elem.css('left', '0');
			}

			getWindowWidth();

			initCarousel( $carousel );

			// Detect swipe gestures support
			if( Modernizr.touch ) {
				
				function swipeFunc( e, dir ) {
				
					var $carousel = $(e.currentTarget);
					
					if( dir === 'left' )
						$carousel.parent('.jcarousel-clip').siblings('.jcarousel-next').trigger('click');
					
					if( dir === 'right' )
						$carousel.parent('.jcarousel-clip').siblings('.jcarousel-prev').trigger('click');
					
				}
			
				$carousel.swipe({
					swipeLeft       : swipeFunc,
					swipeRight      : swipeFunc,
					allowPageScroll : 'auto'
				});
				
			}

			// Window resize
			$(window).on('resize', function() {

				var timer = window.setTimeout( function() {
					window.clearTimeout( timer );
					adjustCarousel();
				}, 30 );

			});

		}

	})();


	/* end Projects Carousel & Post Carousel */

	/* ---------------------------------------------------------------------- */
	/*	Image Gallery Slider
	/* ---------------------------------------------------------------------- */

	(function() {

		var $slider = $('.image-gallery-slider > ul');

		if( $slider.length ) {

			// Run slider when all images are fully loaded
			$(window).load(function() {
				
				$slider.each(function(i) {
					var $this = $(this);

					$this.css('height', $this.children('li:first').height() )
						 .after('<div class="image-gallery-slider-nav"> <a class="prev image-gallery-slider-nav-prev-' + i + '">Prev</a> <a class="next image-gallery-slider-nav-next-' + i + '">Next</a> </div>')
						 .cycle({
							 before: function(curr, next, opts) {
								 var $this = $(this);
								 // set the container's height to that of the current slide
								 $this.parent().stop().animate({ height: $this.height() }, opts.speed);
							 },
							 containerResize : false,
							 easing          : 'easeInOutExpo',
							 fx              : 'fixedScrollHorz',
							 fit             : true,
							 next            : '.image-gallery-slider-nav-next-' + i,
							 pause           : true,
							 prev            : '.image-gallery-slider-nav-prev-' + i,
							 slideExpr       : 'li',
							 slideResize     : true,
							 speed           : 600,
							 timeout         : 0,
							 width           : '100%'
						 })
						 .data( 'slideCount', $slider.children('li').length );
					
				});
			
				// Position nav
				var $arrowNav = $('.image-gallery-slider-nav a');
				$arrowNav.css('margin-top', - $arrowNav.height() / 2 );

				// Pause on nav hover
				$('.image-gallery-slider-nav a').on('mouseenter', function() {
					$(this).parent().prev().cycle('pause');
				}).on('mouseleave', function() {
					$(this).parent().prev().cycle('resume');
				})

				// Hide navigation if only a single slide
				if( $slider.data('slideCount') <= 1 )
					$slider.next('.image-gallery-slider-nav').hide();
				
			});

			// Resize
			$(window).on('resize', function() {

				$slider.each(function() {

					var $this = $(this);

					$this.css('height', $this.children('li:visible').height() );

				});

			});

			// Detect swipe gestures support
			if( Modernizr.touch ) {
				
				function swipeFunc( e, dir ) {
				
					var $slider = $( e.currentTarget );

					// Enable swipes if more than one slide
					if( $slider.data('slideCount') > 1 ) {
											
						$slider.data('dir', '');
						
						if( dir === 'left' )
							$slider.cycle('next');
						
						if( dir === 'right' ) {
							$slider.data('dir', 'prev')
							$slider.cycle('prev');
						}

					}
					
				}

				$slider.swipe({
					swipeLeft       : swipeFunc,
					swipeRight      : swipeFunc,
					allowPageScroll : 'auto'
				});

			}

		}

	})();

	/* end Image Gallery Slider */

	/* ---------------------------------------------------------------------- */
	/*	Portfolio Filter
	/* ---------------------------------------------------------------------- */

	(function() {

		var $container = $('#portfolio-items');

		if( $container.length ) {

			var $itemsFilter = $('#portfolio-items-filter'),
				mouseOver;

			// Copy categories to item classes
			$('article', $container).each(function(i) {
				var $this = $(this);
				$this.addClass( $this.attr('data-categories') );
			});

			// Run Isotope when all images are fully loaded
			$(window).on('load', function() {

				$container.isotope({
					itemSelector : 'article',
					layoutMode   : 'fitRows'
				});

			});

			// Filter projects
			$itemsFilter.on('click', 'a', function(e) {
				var $this         = $(this),
					currentOption = $this.attr('data-categories');

				$itemsFilter.find('a').removeClass('active');
				$this.addClass('active');

				if( currentOption ) {
					if( currentOption !== '*' ) currentOption = currentOption.replace(currentOption, '.' + currentOption)
					$container.isotope({ filter : currentOption });
				}

				e.preventDefault();
			});

			$itemsFilter.find('a').first().addClass('active');
			$itemsFilter.find('a').not('.active').hide();

			// On mouseover (hover)
			$itemsFilter.on('mouseenter', function() {
				var $this = $(this);

				clearTimeout( mouseOver );

				// Wait 100ms before animating to prevent unnecessary flickering
				mouseOver = setTimeout( function() {
					if( $(window).width() >= 960 )
						$this.find('li a').stop(true, true).slideHorzShow(300);
				}, 100);
			}).on('mouseleave', function() {
				clearTimeout( mouseOver );

				if( $(window).width() >= 960 )
					$(this).find('li a').not('.active').stop(true, true).slideHorzHide(150);
			});

		}

	})();

	/* end Portfolio Filter */

	/* ---------------------------------------------------------------------- */
	/*	VideoJS
	/* ---------------------------------------------------------------------- */

	(function() {

		var $player = $('.video-js');

		if( $player.length ) {

			function adjustPlayer() {
			
				$player.each(function( i ) {

					var $this        = $(this)
						playerWidth  = $this.parent().width(),
						playerHeight = playerWidth / ( $this.children('.vjs-tech').data('aspect-ratio') || 1.78 );

					if( playerWidth <= 300 ) {
						$this.addClass('vjs-player-width-300');
					} else {
						$this.removeClass('vjs-player-width-300');
					}

					if( playerWidth <= 250 ) {
						$this.addClass('vjs-player-width-250');
					} else {
						$this.removeClass('vjs-player-width-250');
					}

					$this.css({
						'height' : playerHeight,
						'width'  : playerWidth
					})
					.attr('height', playerHeight )
					.attr('width', playerWidth );

				});

			}

			adjustPlayer();

			$(window).on('resize', function() {

				var timer = window.setTimeout( function() {
					window.clearTimeout( timer );
					adjustPlayer();
				}, 30 );

			});

		}

	})();

	/* end VideoJS */

	/* ---------------------------------------------------------------------- */
	/*	FitVids
	/* ---------------------------------------------------------------------- */

	(function() {

		function adjustVideos() {

			var $videos = $('.fluid-width-video-wrapper');

			$videos.each(function() {

				var $this        = $(this)
					playerWidth  = $this.parent().width(),
					playerHeight = playerWidth / $this.data('aspectRatio');

				$this.css({
					'height' : playerHeight,
					'width'  : playerWidth
				});

			});

		}

		$('.container').each(function(){

			var selectors  = [
				"iframe[src^='http://player.vimeo.com']",
				"iframe[src^='http://www.youtube.com']",
				"iframe[src^='http://blip.tv']",
				"iframe[src^='http://www.kickstarter.com']", 
				"object",
				"embed"
			],
				$allVideos = $(this).find(selectors.join(','));

			$allVideos.each(function(){

				var $this = $(this);

				if ( $this.hasClass('vjs-tech') || this.tagName.toLowerCase() == 'embed' && $this.parent('object').length || $this.parent('.fluid-width-video-wrapper').length )
					return;

				var videoHeight = $this.attr('height') || $this.height(),
					videoWidth  = $this.attr('width') || $this.width();

				$this.css({
					'height' : '100%',
					'width'  : '100%'
				})
				.removeAttr('height').removeAttr('width')
				.wrap('<div class="fluid-width-video-wrapper"></div>').parent('.fluid-width-video-wrapper').css({
					'height' : videoHeight,
					'width'  : videoWidth
				})
				.data( 'aspectRatio', videoWidth / videoHeight )
				.addClass( $(this).attr('class') );

				adjustVideos();

			});

		});

		$(window).on('resize', function() {

			var timer = window.setTimeout( function() {
				window.clearTimeout( timer );
				adjustVideos();
			}, 30 );

		});

	})();

	/* end FitVids */

	/* ---------------------------------------------------------------------- */
	/*	AudioPlayerV1
	/* ---------------------------------------------------------------------- */

	(function() {

		var $player = $('.APV1_wrapper');

		if( $player.length ) {

			$player.each(function( i ) {

				var $this = $(this);

				$this.prev('audio').hide().end()
					 .wrap('<div class="entry-audio" />');

			});

			function adjustPlayer( resize ){
			
				$player.each(function( i ) {

					var $this            = $(this),
						$lis             = $this.children('li'),
						$progressBar     = $this.children('li.APV1_container'),
						playerWidth      = $this.parent().width(),
						lisWidth         = 0;

					if( !resize )
						$this.prev('audio').hide()

					if( playerWidth <= 300 ) {
						$this.addClass('APV1_player_width_300');
					} else {
						$this.removeClass('APV1_player_width_300');
					}

					if( playerWidth <= 250 ) {
						$this.addClass('APV1_player_width_250');
					} else {
						$this.removeClass('APV1_player_width_250');
					}

					if( playerWidth <= 200 ) {
						$this.addClass('APV1_player_width_200');
					} else {
						$this.removeClass('APV1_player_width_200');
					}

					$lis.each(function() {

						var $li = $(this);
						lisWidth += $li.width()

					});

					$this.width( $this.parent().width() );
					$progressBar.width( playerWidth - ( lisWidth - $progressBar.width() ) );
					
				});

			}

			adjustPlayer();

			$(window).on('resize', function() {

				var timer = window.setTimeout( function() {
					window.clearTimeout( timer );
					adjustPlayer( resize = true );
				}, 30 );

			});

		}

	})();

	/* end AudioPlayerV1 */

	/* ---------------------------------------------------------------------- */
	/*	Google Maps
	/* ---------------------------------------------------------------------- */

	(function() {

		var $map = $('#map');

		if( $map.length ) {

			$map.gMap({
				address: 'Level 13, 2 Elizabeth St, Melbourne Victoria 3000 Australia',
				zoom: 16,
				markers: [
					{ 'address' : 'Level 13, 2 Elizabeth St, Melbourne Victoria 3000 Australia' }
				]
			});

		}

	})();

	/* end Google Maps */

	/* ---------------------------------------------------------------------- */
	/*	Accordion Content
	/* ---------------------------------------------------------------------- */

	(function() {

		var $container = $('.acc-container'),
			$trigger   = $('.acc-trigger');

		$container.hide();
		$trigger.first().addClass('active').next().show();

		var fullWidth = $container.outerWidth(true);
		$trigger.css('width', fullWidth);
		$container.css('width', fullWidth);
		
		$trigger.on('click', function(e) {
			if( $(this).next().is(':hidden') ) {
				$trigger.removeClass('active').next().slideUp(300);
				$(this).toggleClass('active').next().slideDown(300);
			}
			e.preventDefault();
		});

		// Resize
		$(window).on('resize', function() {
			fullWidth = $container.outerWidth(true)
			$trigger.css('width', $trigger.parent().width() );
			$container.css('width', $container.parent().width() );
		});

	})();

	/* end Accordion Content */
	
	/* ---------------------------------------------------- */
	/*	Content Tabs
	/* ---------------------------------------------------- */

	(function() {

		var $tabsNav    = $('.tabs-nav'),
			$tabsNavLis = $tabsNav.children('li'),
			$tabContent = $('.tab-content');

		$tabsNav.each(function() {
			var $this = $(this);

			$this.next().children('.tab-content').stop(true,true).hide()
												 .first().show();

			$this.children('li').first().addClass('active').stop(true,true).show();
		});

		$tabsNavLis.on('click', function(e) {
			var $this = $(this);

			$this.siblings().removeClass('active').end()
				 .addClass('active');
			
			$this.parent().next().children('.tab-content').stop(true,true).hide()
														  .siblings( $this.find('a').attr('href') ).fadeIn();

			e.preventDefault();
		});

	})();

	/* end Content Tabs */

	/* ---------------------------------------------------------------------- */
	/*	PHP Widgets
	/* ---------------------------------------------------------------------- */

	(function() {

		function fetchFeed( url, element ) {

			element.html('<img src="img/loader.gif" height="11" width="16" alt="Loading..." />');

			$.ajax({
				url: url,
				dataType: 'html',
				timeout: 10000,
				type: 'GET',
				error:
					function( xhr, status, error ) {
						element.html( 'An error occured: ' + error );
					},
				success:
					function( data, status, xhr ) {
						element.html( data );
					}
			});
			
		}

		// Latest Tweets
		var $tweetsContainer = $('.tweets-feed');
		if( $tweetsContainer.length )
			fetchFeed( 'php/tweets.php', $tweetsContainer );

		// Latest Flickr Images
		var $flickrContainer = $('.flickr-feed');
		if( $flickrContainer.length )
			fetchFeed( 'php/flickr.php', $flickrContainer );

	})();
		
	/* end PHP Widgets */

	/* ---------------------------------------------------------------------- */
	/*	Contact Form
	/* ---------------------------------------------------------------------- */

	(function() {

		// Setup any needed variables.
		var $form   = $('.contact-form'),
			$loader = '<img src="img/loader.gif" height="11" width="16" alt="Loading..." />';

		$form.append('<div id="response" class="hidden">');
		var $response = $('#response');
		
		// Do what we need to when form is submitted.
		$form.on('click', 'input[type=submit]', function(e){

			// Hide any previous response text and show loader
			$response.hide().html( $loader ).show();
			
			// Make AJAX request 
			$.post('php/contact-send.php', $form.serialize(), function( data ) {
			
				// Show response message
				$response.html( data );

				// Scroll to bottom of the form to show respond message
				var bottomPosition = $form.offset().top + $form.outerHeight() - $(window).height();
				
				if( $(document).scrollTop() < bottomPosition )
					$('html, body').animate({ scrollTop : bottomPosition });
				
				// If form has been sent succesfully, clear it
				if( data.indexOf('success') !== -1 )
					$form.find('input:not(input[type="submit"]), textarea, select').val('').attr( 'checked', false );
				
			});
			
			// Cancel default action
			e.preventDefault();
		});

	})();

	/* end Contact Form */
	
	/* ---------------------------------------------------------------------- */
	/*	UItoTop (Back to Top)
	/* ---------------------------------------------------------------------- */

	(function() {

		var settings = {
				button      : '#back-to-top',
				text        : 'Back to Top',
				min         : 200,
				fadeIn      : 400,
				fadeOut     : 400,
				scrollSpeed : 800,
				easingType  : 'easeInOutExpo'
			},
			oldiOS     = false,
			oldAndroid = false;

		// Detect if older iOS device, which doesn't support fixed position
		if( /(iPhone|iPod|iPad)\sOS\s[0-4][_\d]+/i.test(navigator.userAgent) )
			oldiOS = true;

		// Detect if older Android device, which doesn't support fixed position
		if( /Android\s+([0-2][\.\d]+)/i.test(navigator.userAgent) )
			oldAndroid = true;
	
		$('body').append('<a href="#" id="' + settings.button.substring(1) + '" title="' + settings.text + '">' + settings.text + '</a>');

		$( settings.button ).click(function( e ){
				$('html, body').animate({ scrollTop : 0 }, settings.scrollSpeed, settings.easingType );

				e.preventDefault();
			});

		$(window).scroll(function() {
			var position = $(window).scrollTop();

			if( oldiOS || oldAndroid ) {
				$( settings.button ).css({
					'position' : 'absolute',
					'top'      : position + $(window).height()
				});
			}

			if ( position > settings.min ) 
				$( settings.button ).fadeIn( settings.fadeIn );
			else 
				$( settings.button ).fadeOut( settings.fadeOut );
		});

	})();

	/* end UItoTop (Back to Top) */

});
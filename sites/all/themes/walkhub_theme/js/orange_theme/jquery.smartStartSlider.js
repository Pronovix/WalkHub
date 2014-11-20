(function($) {
	jQuery.fn.reverse = Array.prototype.reverse;
	
	var globalFunctions = {
			
			buttonWidthLowRes : function( buttons, container ) {
					
				buttons.each(function() {
					
					var $this        = $(this),
						paddingLeft  = parseInt( $this.css('padding-left') ),
						paddingRight = parseInt( $this.css('padding-right') );
					
					$this.css('max-width', ( container.outerWidth() - ( paddingLeft + paddingRight ) * 2 ) / 2);
				
				});
			
			},
			
			buttonWidthHighRes : function( buttons, slideWidth ) {
			
				buttons.each(function() {
				
					var $this        = $(this),
						paddingLeft  = parseInt( $this.css('padding-left') ),
						paddingRight = parseInt( $this.css('padding-right') ),
						width        = slideWidth;
					
					if( !paddingLeft )
						width += paddingLeft;
					else
						width -= paddingLeft;
					
					if( !paddingRight )
						width += paddingRight;
					else
						width -= paddingRight;
					
					$this.css('max-width', width );
				
				});
			
			},
			
		},
		aux = {
			// sets the slides bg image & position
			setSlideBackground : function( bgimage, $slides, slideWidth ) {
				$slides.css('background-image', 'url(' + bgimage + ')').each(function(i) {
					$(this).css('background-position', ( - i * slideWidth )  + 'px 0px');
				});
			},
			preloadImages : function( $slides, nmbSlides, $slideBgImage ) {
				var cnt	= 0;
				$slides.each(function(i) {
					var $slide	= $(this),
						bgimage	= $slideBgImage.attr('src');
					$('<img/>').attr('src', bgimage );
				});
			},
			setup : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $buttons, $content, $slideBgImage, $slideImagesContainer, $slidesContainer, $buttonsContainer, $contentContainer, $paginationContainer, $movingElem, settings ) {
				
				// move descriptions to new place
				$content.each(function(i) {
					var $el = $(this);
					$el.appendTo($contentContainer).addClass('slide-content_' + i);
				});
				
				// add position if needed class & fix position/height
				$contentContainer.addClass( settings.contentPosition ).css('height', $content.eq( settings.pos ).outerHeight() );
				
				// Fix pagination buttons
				$paginationContainer.addClass( settings.contentPosition );
				
				if( settings.contentPosition ) {
					
					$('a', $paginationContainer ).css( 'height', $contentContainer.outerHeight() );
					
				} else {
				
					var paginationButtonHeight = ( $contentContainer.outerHeight() - 1 ) / 2;
					
					$('a', $paginationContainer ).css('height', paginationButtonHeight);
				
					$('.next', $paginationContainer ).css('bottom', parseInt( $('.prev', $paginationContainer ).css('bottom') ) + paginationButtonHeight + 1 + 'px');

				}
				
				// Check for links
				$slides.each(function(i) {
					var $this = $(this),
						href  = $this.find('a').attr('href')
						mode  = $this.find('a').attr('class'),
						title = $this.find('a').attr('title');
						
					$this.add( $this.find( $slideBgImage ) ).data({
						'url'   : href,
						'mode'  : mode,
						'title' : title
					});
				});
				
				// set the slides 
				$slides.css({
					'display' : 'block',
					'height'  : settings.height - $buttons.outerHeight() + 'px'
				}).appendTo( $slidesContainer );
				
				// fix dimensions
				$slidesContainer.css({
					'max-height' : settings.height - $buttons.outerHeight() + 'px',
					'overflow'   : 'hidden',
					'width'      : '100%'
				});
								
				// set the width of the slideBgs
				$slideBg.css('width', slideWidth + 'px');
				
				// set the width of the buttons				
				$buttons.css('width', 100 / nmbSlides + '%');
				
				// move buttons	
				$buttons.appendTo( $buttonsContainer );
				
				// set the correct width of the buttons
				if( $el.width() / 2 === 748 / 2 ) {
				
					globalFunctions.buttonWidthLowRes( $buttons, $el );
				
				} else {
				
					globalFunctions.buttonWidthHighRes( $buttons, slideWidth );
				
				}
				
				// move slide-bg-images
				$slides.find( $slideBgImage ).appendTo( $slideImagesContainer );
				$slides.find('a').remove();
				
				// Give correct height
				$slideImagesContainer.css('max-height', settings.height - $buttons.outerHeight() + 'px');
				
				// set the width, height and background image of the main container
				$el.css({
					'max-height' : settings.height - $buttons.outerHeight() + ( $buttons.outerHeight() * Math.ceil( nmbSlides / 2 ) ) + 'px',
					'max-width'  : slideWidth * nmbSlides + 'px'
				});
				
				// if defaultBg is passed then defaultBg is set as background
				aux.setSlideBackground( settings.posBgImage, $slides, slideWidth );
				
				if( $(window).width() < 960 )
					$slideBgImage.eq( settings.pos ).stop(true, true).fadeIn( settings.type.speed, settings.type.easing ).css('display', 'block');
				
				// Change cursor if needed (has link)
				var slidesHref = $slides.eq( $el.find('.slide-button.active').index() ).data('url');
				$slides.css('cursor', 'auto');
				if( slidesHref ) $slides.css('cursor', 'pointer');
				
				var imgHref = $slideBgImage.eq( $el.find('.slide-button.active').index() ).data('url');
				$slideBgImage.css('cursor', 'auto');
				if( imgHref ) $slideBgImage.eq( $el.find('.slide-button.active').index() ).css('cursor', 'pointer');
				
				// When everything is done
				$(window).load(function() {
					
					$el.addClass('fully-loaded');

					// display slides
					$slides.css( 'width', slideWidth + 'px' );
					
					// position it correctly and set the width of the hover block
					$movingElem.css({
						'bottom'     : $buttons.innerHeight() + parseInt( $buttons.css('border-bottom-width') ) + 'px',
						'left'       : slideWidth * settings.pos,
						'visibility' : 'visible',
						'width'      : slideWidth + 'px'
					});
					
					if( $(window).width() < 960 ) {
				
						// Fix the position
						if( settings.contentPosition === 'center' ) {
						
							var contentContainerOffset = ( $el.width() - $contentContainer.outerWidth() ) / 2 - $('a', $paginationContainer).outerWidth() - 1;
							
							$('.prev', $paginationContainer).css('left', contentContainerOffset );	
							
							$('.next', $paginationContainer).css('right', contentContainerOffset );	
							
						} else if( settings.contentPosition === 'bottom' ) {
						
							$contentContainer.add( $('a', $paginationContainer ) ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() );
						
							$contentContainer.css('width', 
								$slideImagesContainer.outerWidth()
								- ( $('a', $paginationContainer).outerWidth() * 2 + 2 )
								- ( parseInt( $contentContainer.css('padding-left') )
								+ parseInt( $contentContainer.css('padding-right') ) )
							);
						
						} else {
				
							$contentContainer.add( $('.prev', $paginationContainer ) ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() + 30 );
						
							$('.next', $paginationContainer ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() + 30 + $('.next', $paginationContainer ).outerHeight() );
					
						}
						
					}
				
				});
			}
		},
		// animation types
		anim = {
			def : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					var $slide   = $slides.eq( $button.index() ),
						slideIdx = $slide.index(),
						bgimage  = $('img', $slideImagesContainer ).eq( slideIdx ).attr('src'),
						dir;
					
					if( settings.pos === slideIdx ) {
						$el.data( 'anim', false );
						return false;
					}
					
					settings.pos = $slide.index();
					
					anim[settings.type.mode].slideAux( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings );
					
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt = 0;
						
					// set the correct left to the $slideBg
					// and also the bg image
					$slideBg.css({ 
						'left' 				: '0px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						$(this).css('background-position', ( - i * slideWidth )  + 'px 0px');
					});
					$el.data( 'anim', false );
				} 
			},
			fade : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like def mode
					anim['def'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt = 0;
					
					// set the correct left to the $slideBg
					// and also the bg image
					$slideBg.css({ 
						'left' 				: '0px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						$(this).hide()
							   .css('background-position', ( - i * slideWidth )  + 'px 0px')
							   .fadeIn(settings.type.speed, settings.type.easing, function() {
									++cnt;
									if( cnt === nmbSlides ) {
										$el.data( 'anim', false );
										// set default bg
										aux.setSlideBackground( bgimage, $slides, slideWidth );
									}
							   });
					});
					
				} 
			},
			seqFade : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					var $slide   = $slides.eq( $button.index() ),
						slideIdx = $slide.index(),
						bgimage  = $('img', $slideImagesContainer ).eq( slideIdx ).attr('src'),
						dir;
					
					if( settings.pos < slideIdx )
						dir = 1;
					else if( settings.pos > slideIdx )
						dir = -1;	
					else {
						$el.data( 'anim', false );
						return false;
					}
					settings.pos = $slide.index();
					
					anim[settings.type.mode].slideAux( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt    = 0,
						seq_t  = settings.type.seqfactor,
						$elems = $el.find('.slide-img');
					
					if( dir === -1 )
						$elems = $elems.reverse();
						
					// set the correct left to the $slideBg
					// and also the bg image
					$elems.css({ 
						'left' 				: '0px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						var $theSlideBg	= $(this).hide();
						setTimeout(function() {
							var factor	= - i * slideWidth;
							if( dir === -1 )
								factor	= - (nmbSlides - 1 - i) * slideWidth;
							
							$theSlideBg.css('background-position', factor  + 'px 0px')
									   .fadeIn(settings.type.speed, settings.type.easing, function() {
											++cnt;
											if( cnt === nmbSlides ) {
												$el.data( 'anim', false );
												// set default bg
												aux.setSlideBackground( bgimage, $slides, slideWidth );
											}
									   });
						}, i * seq_t);
	
					});
					
				} 
			},
			horizontalSlide : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt = 0;
						
					// set the correct left to the $slideBg depending on dir
					// and also the bg image
					$slideBg.css({
						'left' 				: dir * slideWidth + 'px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						$(this).css('background-position', ( - i * slideWidth )  + 'px 0px')
							   .stop()
							   .animate({
								   left	: '0px'
							   }, settings.type.speed, settings.type.easing, function() {
							       ++cnt;		
								   if( cnt === nmbSlides ) {
								       $el.data( 'anim', false );
									   // set default bg
								       aux.setSlideBackground( bgimage, $slides, slideWidth );
								   }
							   });
					});
				} 
			},
			seqHorizontalSlide : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt    = 0,
						seq_t  = settings.type.seqfactor,
						$elems = $el.find('.slide-img');
					
					if( dir === 1 )
						$elems = $elems.reverse();
						
					// set the correct left to the $slideBg depending on dir
					// and also the bg image
					$elems.css({
						'left' 				: dir * slideWidth + 'px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						var $theSlideBg	= $(this);
						setTimeout(function() {
							var factor	= - i * slideWidth;
							if( dir === 1 )
								factor	= - (nmbSlides - 1 - i) * slideWidth;
								
							$theSlideBg.css('background-position', factor  + 'px 0px')
									   .stop()
									   .animate({
										   left	: '0px'
									   }, settings.type.speed, settings.type.easing, function() {
										   ++cnt;		
										   if( cnt === nmbSlides ) {
											   $el.data( 'anim', false );
											   // set default bg
											   aux.setSlideBackground( bgimage, $slides, slideWidth );
										   }
									   });
						}, i * seq_t);
					});
				} 
			},
			verticalSlide : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt = 0;
						
					// set the correct top to the $slideBg depending on dir
					// and also the bg image
					$slideBg.css({
						'top' 				: dir * settings.height + 'px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						$(this).css('background-position', ( - i * slideWidth )  + 'px 0px')
							   .stop()
							   .animate({
								   top	: '0px'
							   }, settings.type.speed, settings.type.easing, function() {
							       ++cnt;		
								   if( cnt === nmbSlides ) {
								       $el.data( 'anim', false );
									   // set default bg
								       aux.setSlideBackground( bgimage, $slides, slideWidth );
								   }
							   });
					});
				} 
			},
			seqVerticalSlide : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt    = 0,
						seq_t  = settings.type.seqfactor,
						$elems = $el.find('.slide-img');
					
					if( dir === 1 )
						$elems = $elems.reverse();
						
					// set the correct top to the $slideBg depending on dir
					// and also the bg image
					$elems.css({
						'top' 				: dir * settings.height + 'px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						var $theSlideBg	= $(this);
						setTimeout(function() {
							var factor	= - i * slideWidth;
							if( dir === 1 )
								factor	= - (nmbSlides - 1 - i) * slideWidth;
								
							$theSlideBg.css('background-position', factor  + 'px 0px')
									   .stop()
									   .animate({
										   top	: '0px'
									   }, settings.type.speed, settings.type.easing, function() {
										   ++cnt;		
										   if( cnt === nmbSlides ) {
											   $el.data( 'anim', false );
											   // set default bg
											   aux.setSlideBackground( bgimage, $slides, slideWidth );
										   }
									   });
						}, i * seq_t);
					});
				} 
			},
			verticalSlideAlt : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt = 0, j;
						
					// set the correct top to the $slideBg
					// and also the bg image
					$slideBg.css({
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						if( i % 2 === 0 )
							j = 1;
						else
							j = -1;
						$(this).css('top', j * settings.height + 'px')
							   .css('background-position', ( - i * slideWidth )  + 'px 0px')
							   .stop()
							   .animate({
								   top	: '0px'
							   }, settings.type.speed, settings.type.easing, function() {
							       ++cnt;		
								   if( cnt === nmbSlides ) {
								       $el.data( 'anim', false );
									   // set default bg
								       aux.setSlideBackground( bgimage, $slides, slideWidth );
								   }
							   });
					});
				} 
			},
			seqVerticalSlideAlt : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings ) {
					// same like seqFade mode
					anim['seqFade'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, bgimage, dir, settings ) {
					var cnt    = 0,
						seq_t  = settings.type.seqfactor,
						$elems = $el.find('.slide-img'),
						j;
					
					if( dir === 1 )
						$elems = $elems.reverse();
						
					// set the correct top to the $slideBg depending on dir
					// and also the bg image
					$elems.css({
						'top'				: dir * settings.height + 'px',
						'background-image'	: 'url(' + bgimage + ')'
					}).each(function(i) {
						var $theSlideBg	= $(this);
						
						setTimeout(function() {
							var factor	= - i * slideWidth;
							if( dir === 1 )
								factor	= - (nmbSlides - 1 - i) * slideWidth;
							
							if( i % 2 === 0 )
								j = 1;
							else
								j = -1;
							
							$theSlideBg.css('top', j * settings.height + 'px')
									   .css('background-position', factor  + 'px 0px')
									   .stop()
									   .animate({
										   top	: '0px'
									   }, settings.type.speed, settings.type.easing, function() {
										   ++cnt;		
										   if( cnt === nmbSlides ) {
											   $el.data( 'anim', false );
											   // set default bg
											   aux.setSlideBackground( bgimage, $slides, slideWidth );
										   }
									   });
						}, i * seq_t);
					});
				} 
			},
			responsiveDef : {
				slide : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideBgImage, $slideImagesContainer, $slidesContainer, settings ) {
					var $slide   = $slides.eq( $button.index() ),
						slideIdx = $slide.index(),
						bgimage  = $('img', $slideImagesContainer ).eq( slideIdx ).attr('src'),
						dir;
					
					if( settings.pos === slideIdx ) {
						$el.data( 'anim', false );
						return false;
					}
					
					settings.pos = $slide.index();
											
					anim['responsiveDef'].slideAux( $el, $slides, nmbSlides, slideWidth, $slideBg, $slideBgImage, $slideImagesContainer, bgimage, dir, slideIdx, settings );
				},
				slideAux : function( $el, $slides, nmbSlides, slideWidth, $slideBg, $slideBgImage, $slideImagesContainer, bgimage, dir, slideIdx, settings ) {
					var cnt = 0;
					
					// Prevent jumping by setting fixed height
					$slideImagesContainer.css('height', $slideImagesContainer.outerHeight() );
					
					$slideBgImage.stop(true, true).hide().eq( slideIdx ).stop(true, true).fadeIn( settings.type.speed, settings.type.easing, function() {
						
						$(this).css('display', 'block')
						
						// And reset it when animation is done
						$slideImagesContainer.css('height', '');
						
						$el.data( 'anim', false );
					
					});

				} 
			},
		},
		methods = {
			init : function( options ) {
				
				if( this.length ) {
					
					var settings = {
						// zero-based index of the first slide to be displayed
						pos                : 0,
						// slide container width
						width              : 940,
						// slide container height
						height             : 380,
						// speed of the transition
						contentSpeed       : 450,
						// options: default (empty) | center | bottom
						contentPosition    : '',
						// show content only on mouseover
						showContentOnhover : false,
						// hide content
						hideContent        : false,
						// time between slide transitions (0 to disable autoplay)
						timeout            : 3000,
						// stop autoplay on click
						pause              : true,
						// pause autoplay on mouseover
						pauseOnHover       : true,
						// hide bottom navigation buttons
						hideBottomButtons  : false,
						// animation type
						type               : {
							// options: def | fade | seqFade | horizontalSlide | seqHorizontalSlide
							// verticalSlide | seqVerticalSlide | verticalSlideAlt | seqVerticalSlideAlt
							mode      : 'def',
							// speed of the transition
							speed     : 400,
							// easing type for the animation
							easing    : 'jswing',
							// this is the interval between each slide's animation 
							// used for seqFade, seqHorizontalSlide, seqVerticalSlide & seqVerticalSlideAlt  
							seqfactor : 100
						}
					};
					
					return this.each(function() {
						
						// if options exist, lets merge them with our default settings
						if ( options ) {
							$.extend( settings, options );
						}
						
						// Cache some elements
						var $el            = $(this),
						
							$slides        = $el.find('.slide'),
							nmbSlides      = $slides.length,
							
							$slideBgImage  = $el.find('.slide-bg-image'),
							$buttons       = $el.find('.slide-button'),
							$content       = $el.find('.slide-content'),
							
							// For random effect
							animationModes = ['def', 'fade', 'seqFade', 'horizontalSlide', 'seqHorizontalSlide', 'verticalSlide', 'seqVerticalSlide', 'verticalSlideAlt', 'seqVerticalSlideAlt'],
							
							// width for each slide
							slideWidth     = Math.floor( settings.width / nmbSlides ),
							
							animTime, autoplayInt, mouseOver, compareWidth;
							
						// fix height setting (add button height to it)
						settings.height += $buttons.outerHeight();
						compareWidth = $el.width();
						
						// preload images
						aux.preloadImages( $slides, nmbSlides, $slideBgImage );
						
						// Check if need to show content only on hover
						if( settings.showContentOnhover ) $el.addClass('show-content-onhover');
						
						// Check if need to hide content
						if( settings.hideContent ) $el.addClass('hide-content');
						
						// Check if need to hide bottom navigation buttons
						if( settings.hideBottomButtons ) $el.addClass('hide-bottom-buttons');
						
						// The default slide
						var $defaultSlide   = $slides.eq( settings.pos );
						settings.posBgImage	= $defaultSlide.find( $slideBgImage ).attr('src');
						$defaultSlide.find('.slide-button').addClass('active');
						
						// prepend a bg image container for each one of the slides
						// this will have the right image as background
						// have a reference to those containers - $slideBg
						$slides.prepend('<div class="slide-img"></div>');
						var $slideBg = $el.find('.slide-img');
						
						// create slide images container
						$el.append('<div class="slide-images-container"></div>')
						var $slideImagesContainer = $('.slide-images-container');
						
						// create slides container
						$el.append('<div class="slides-container"></div>');
						var $slidesContainer = $('.slides-container');
						
						// create buttons container
						$el.append('<div class="buttons-container"></div>');
						var $buttonsContainer = $('.buttons-container');
						
						// create slide content container
						$el.append('<div class="content-container"></div>');
						var $contentContainer = $('.content-container');
						
						// create pagination
						$el.append('<div class="pagination-container"> <a class="prev">&laquo;</a> <a class="next">&raquo;</a> </div>');
						var $paginationContainer = $('.pagination-container');
						
						// create hover block
						$el.append('<div class="active-slide-bar">&nbsp;</div>');
						var $movingElem = $el.find('.active-slide-bar');
						
						// set this and that...
						aux.setup( $el, $slides, nmbSlides, slideWidth, $slideBg, $buttons, $content, $slideBgImage, $slideImagesContainer, $slidesContainer, $buttonsContainer, $contentContainer, $paginationContainer, $movingElem, settings );
						
						// show default slide content
						var $defContent	= $contentContainer.children('.slide-content_' + settings.pos);
						$defContent.fadeIn( settings.contentSpeed );
						
						// Check if effect should be random
						if( settings.type.mode === 'random' ) $el.data('randomEffect', true);

						// start autoplay after images are loaded
						$(window).load(function() {
							
							if( settings.timeout > 0 && mouseOver !== true )
								autoplayInt = setTimeout( autoPlay, settings.timeout );

						});
						
						// Autoplay
						function autoPlay(){
						
							var $curSlide = $slides.eq( $el.find('.slide-button.active').index() ).next();
							
							// If the last slide, start from beginning
							if( $el.find('.slide-button.active').index() === nmbSlides - 1 ) $curSlide = $slides.first();
								
							var $button      = $buttons.eq( $curSlide.index() ),
							    $curContent = $contentContainer.children('.slide-content_' + $curSlide.index() );
							
							// Make things happening
							swithSlide( $button, $curSlide, $curContent );
							
						}
						
						// The actual switching
						function swithSlide( $button, $curSlide, $curContent ) {
						
							// Clear timer
							clearTimeout( autoplayInt );
							autoplayInt = 0;
						
							clearTimeout( animTime );
							
							animTime = setTimeout(function() {
							
								if( $el.data( 'anim' ) )
									return false;
									
								$el.data( 'anim', true );
								
								if( settings.pos > -1 && !$button.hasClass('active') ) {
									// Move the hover block
									$movingElem.stop().animate({
										left : slideWidth * $curSlide.index()
									}, settings.type.speed * 1);
									
									$buttons.removeClass('active');
									$button.addClass('active');
									
									$content.stop(true, true).hide();
								}
								
								// Get random effect if necessary
								if( $el.data('randomEffect') ) settings.type.mode = animationModes[Math.floor( Math.random() * animationModes.length )];
								
								// If smaller screen,
								if( $(window).width() < 960 ) {
									// Animate slides in simplified way
									anim['responsiveDef'].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideBgImage, $slideImagesContainer, $slidesContainer, settings );
								} else {
									// Animate slides in normal way
									anim[settings.type.mode].slide( $el, $slides, nmbSlides, slideWidth, $slideBg, $button, $slideImagesContainer, $slidesContainer, settings );
								}
								
								// Animate rest stuff
								$curContent.stop(true, true).fadeIn( settings.contentSpeed );
								
								// "Fix" CSS
								$contentContainer.css('height', $curContent.outerHeight() );
								
								if( settings.contentPosition ) {
								
									var paginationButtonHeight = ( $curContent.outerHeight() + parseInt( $contentContainer.css('padding-top') ) + parseInt( $contentContainer.css('padding-bottom') ) );
								
								} else {
								
									var paginationButtonHeight = ( $content.eq( $curSlide.index() ).outerHeight() + parseInt( $contentContainer.css('padding-top') ) + parseInt( $contentContainer.css('padding-bottom') ) - 1 ) / 2;
									
									$('.next', $paginationContainer).css('bottom', parseInt( $('.prev', $paginationContainer).css('bottom') ) + paginationButtonHeight + 1 + 'px');
							
								}
										
								$('a', $paginationContainer).css('height', paginationButtonHeight );
						
								// Change cursor if needed
								var href = $slides.eq( $el.find('.slide-button.active').index() ).data('url');
								$slides.css('cursor', 'auto');
								if( href ) $slides.css('cursor', 'pointer');

								// Start timer again
								if( !$el.data('autoPlayStop') && settings.timeout > 0 && mouseOver !== true )
									autoplayInt = setTimeout( autoPlay, settings.timeout );

							}, 100);
						
						}
						
						// click event on the buttons:
						$buttons.bind( 'click', function(e) {
						
							// stop autoplay
							if( settings.pause )
								$el.data('autoPlayStop', true);

							var $button      = $(this),
								$curSlide   = $slides.eq( $button.index() ),
								$curContent = $contentContainer.children('.slide-content_' + $curSlide.index() );
							
							// Make things happening
							swithSlide( $button, $curSlide, $curContent );
							
							e.preventDefault();
						});
						
						// click event on the pagination:
						$('a', $paginationContainer).bind( 'click', function(e) {

							// stop autoplay
							if( settings.pause )
								$el.data('autoPlayStop', true);
						
							var $this     = $(this),
								$curSlide = $slides.eq( $el.find('.slide-button.active').index() ),
								$button, $curContent;
						
							if( $this.hasClass('next') ) {
								$curSlide = $curSlide.next();
							} else if( $this.hasClass('prev') ) {
								$curSlide = $curSlide.prev();
							}
							
							// If the last slide, start from beginning
							if( $el.find('.slide-button.active').index() === nmbSlides - 1 && $this.hasClass('next') ) $curSlide = $slides.first();
							
							// If the first slide, start from end
							if( $curSlide.index() === -1 && $this.hasClass('prev') ) $curSlide = $slides.last();
							
							$button      = $buttons.eq( $curSlide.index() ),
							$curContent = $contentContainer.children('.slide-content_' + $curSlide.index() );

							// Make sure we aren't at the end yet
							if( ( $this.hasClass('next') && $curSlide.index() < nmbSlides ) || ( $this.hasClass('prev') && $curSlide.index() >= 0 ) ) {
							
								// Make things happening
								swithSlide( $button, $curSlide, $curContent );
								
							}
							
							e.preventDefault();
						});
						
						// Hover
						$el.on('mouseenter', function() {
							mouseOver = true;

							// Clear timer, if necessary
							if( settings.pauseOnHover ) {
								clearTimeout( autoplayInt );
								autoplayInt = 0;
							}
						}).on('mouseleave', function() {
							mouseOver = false;
						
							if( !$el.data('autoPlayStop') && settings.timeout > 0 )
								autoplayInt = setTimeout( autoPlay, settings.timeout );
						});
						
						// Image link
						$slidesContainer.add( $slideImagesContainer ).click(function(e) {

							mouseOver = false;
						
							if( $(window).width() < 960 ) {
						
								var $slide = $slideBgImage.eq( $el.find('.slide-button.active').index() );
								
							} else {
							
								var $slide = $slides.eq( $el.find('.slide-button.active').index() );
								
							}
							
							var href       = $slide.data('url'),
								mode       = $slide.data('mode'),
								title      = $slide.data('title'),
								isFancybox = mode ? mode.match(/(iframe|single-image|image-gallery)/g) : -1,
								showButtons, width, height, maxWidth, maxHeight, fitToView, autoSize, closeClick;
								
							if( typeof href !== 'undefined' && href ) {
								
								// Check if Fancybox mode
								if( isFancybox !== -1 && isFancybox !== null ) {
									
									// Set correct settings
									if( isFancybox[0] === 'iframe' ) {
									
										mode        = 'iframe';
										showButtons = false;
										width       = '70%';
										height      = '70%';
										maxWidth    = 800;
										maxHeight   = 600;
										fitToView   = false;
										autoSize    = false;
										closeClick  = false;
										
									} else {
																	
										mode        = 'image';
										showButtons = {};
										width       = 800;
										height      = 600;
										maxWidth    = 9999;
										maxHeight   = 9999;
										fitToView   = true;
										autoSize    = true;
										closeClick  = false;
									
									}
									
									$.fancybox({
										type        : mode,
										href        : href,
										title       : title,
										openEffect  : 'fade',
										closeEffect	: 'fade',
										nextEffect  : 'fade',
										prevEffect  : 'fade',
										helpers     : {
											title   : {
												type : 'inside'
											},
											buttons  : showButtons
										},
										width       : width,
										height      : height,
										maxWidth    : maxWidth,
										maxHeight   : maxHeight,
										fitToView   : fitToView,
										autoSize    : autoSize,
										closeClick  : closeClick,
										beforeShow  : function() {
											if( $el.data('autoPlayStop') || settings.timeout === 0 || settings.pause )
												$el.data('sliderStopped', true);
												
											$el.data({
												'autoPlayStop' : true,
												'anim'         : false
											});
										},
										afterClose  : function() {
											if( !$el.data('sliderStopped') )
												$el.removeData('autoPlayStop');
											if( !$el.data('autoPlayStop') && settings.timeout > 0 && mouseOver !== true )
												autoplayInt = setTimeout( autoPlay, settings.timeout );
										}
									});
									
								} else {
								
									// If normal url was found, let's redirect then
									window.location = href;
									
								}
								
							}							
							
							e.preventDefault();
							
						});

						// Resize window (responsive)
						$(window).resize(function() {

							if( $el.width() !== compareWidth ) {
			
								// set the correct width of the buttons
								if( $el.width() / 2 === 748 / 2 ) {

									globalFunctions.buttonWidthLowRes( $buttons, $el );
									
									
								} else {

									globalFunctions.buttonWidthHighRes( $buttons, slideWidth );

								}
								
								if( $(window).width() < 960 ) {
									
									// Set content and pagination height
									var $curSlide              = $slideBgImage.eq( $el.find('.slide-button.active').index() ),
										$curContent            = $contentContainer.children('.slide-content_' + $curSlide.index() );
									
									if( settings.contentPosition ) {
									
										var paginationButtonHeight = ( $curContent.outerHeight() + parseInt( $contentContainer.css('padding-top') ) + parseInt( $contentContainer.css('padding-bottom') ) );
									
									} else {
									
										var paginationButtonHeight = ( $content.eq( $curSlide.index() ).outerHeight() + parseInt( $contentContainer.css('padding-top') ) + parseInt( $contentContainer.css('padding-bottom') ) - 1 ) / 2;
										
										$('.next', $paginationContainer).css('bottom', parseInt( $('.prev', $paginationContainer).css('bottom') ) + paginationButtonHeight + 1 + 'px');
										
									}
									
									$contentContainer.css('height', $curContent.outerHeight() );
									
									$('.next', $paginationContainer).css('bottom', parseInt( $('.prev', $paginationContainer).css('bottom') ) + paginationButtonHeight + 1 + 'px');
									$('a', $paginationContainer).css('height', paginationButtonHeight );
									
									if( $curSlide.is(':hidden') )
										$slideBgImage.hide();
										
									$curSlide.fadeIn().css('display', 'block');
									
									// "Fix" the position
									if( settings.contentPosition === 'center' ) {
									
										var contentContainerOffset = ( $el.width() - $contentContainer.outerWidth() ) / 2 - $('a', $paginationContainer).outerWidth() - 1;
										
										$('.prev', $paginationContainer).css('left', contentContainerOffset );	
										
										$('.next', $paginationContainer).css('right', contentContainerOffset );	
										
									} else if( settings.contentPosition === 'bottom' ) {
									
										$contentContainer.add( $('a', $paginationContainer ) ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() );
									
										$contentContainer.css('width',
											$slideImagesContainer.outerWidth()
											- ( $('a', $paginationContainer).outerWidth() * 2 + 2 )
											- ( parseInt( $contentContainer.css('padding-left') )
											+ parseInt( $contentContainer.css('padding-right') ) )
										);
									
									} else {
									
										$contentContainer.add( $('.prev', $paginationContainer ) ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() + 30);
									
										$('.next', $paginationContainer ).css('bottom', $el.outerHeight() - $slideImagesContainer.outerHeight() + 30 + $('.next', $paginationContainer ).outerHeight() );
								
									}
								
								} else {
								
									// Clear timer
									clearTimeout( autoplayInt );
									autoplayInt = 0;
										
									// stop autoplay
									if( settings.pause )
										$el.data('autoPlayStop', true);
											
									// Reset some inline CSS
									if( settings.contentPosition === 'center' ) {
										
										$('.prev', $paginationContainer ).css('left', '');
										
										$('.next', $paginationContainer ).css('right', '');
										
									} else if( settings.contentPosition === 'bottom' ) {
									
										$contentContainer.add( $('a', $paginationContainer ) ).css('bottom', '');
									
										$contentContainer.css('width', '');
									
									} else {
									
										$contentContainer.add( $('a', $paginationContainer ) ).css('bottom', '');
								
									}
								
									var $button     = $el.find('.slide-button.active'),
										$curSlide   = $slides.eq( $button.index() ),
										$curContent = $contentContainer.children('.slide-content_' + $curSlide.index() );
									
									// Make things happening
									swithSlide( $button, $curSlide, $curContent );
									
								}
								
								// Set new current width
								compareWidth = $el.width();
								
							}
							
						});
						
					});
				}
			}
		};
	
	$.fn.smartStartSlider = function(method) {
		if ( methods[method] ) {
			return methods[method].apply( this, Array.prototype.slice.call( arguments, 1 ));
		} else if ( typeof method === 'object' || ! method ) {
			return methods.init.apply( this, arguments );
		} else {
			$.error( 'Method ' +  method + ' does not exist on jQuery.smartStartSlider' );
		}
	};
	
})(jQuery);
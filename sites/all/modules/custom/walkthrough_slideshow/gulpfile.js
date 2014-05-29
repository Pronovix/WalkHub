(function () {
  "use strict";

  var gulp = require('gulp');

  var args = require('yargs').argv;
  var clean = require('gulp-clean');
  var uglify = require('gulp-uglify');
  var concat = require('gulp-concat');
  var gulpif = require('gulp-if');
  var compass = require('gulp-compass');
  var plumber = require('gulp-plumber');
  var csso = require('gulp-csso');
  var cmq = require('gulp-combine-media-queries');
  var svgmin = require('gulp-svgmin');

  var paths = {
    sass: ["./walkthrough_slideshow.sass"],
  };


  gulp.task('buildsass', function () {
    var sassConfig = {
      css: '.tmp',
      sass: '',
    };

    if (args.debug) {
      sassConfig.style = 'expanded';
    }

    return gulp.src(paths.sass)
      .pipe(plumber())
      .pipe(compass(sassConfig))
      .pipe(gulp.dest('.tmp'));
  });

  // Processing css must happen in a separate step:
  // https://github.com/appleboy/gulp-compass/issues/2
  gulp.task('process-css', function() {
    gulp.src(['.tmp/*.css'])
      .pipe(cmq({log: true}))
      .pipe(gulp.dest('.'))
      .pipe(csso())
      .pipe(gulp.dest('.'));
  });

  gulp.task('svgmin', function() {
    return gulp.src('**/*.svg')
      .pipe(svgmin())
      .pipe(gulp.dest('./'));
  });

  gulp.task('clean', function () {
    return gulp.src(['walkthrough_slideshow.css'])
      .pipe(clean());
  });

  gulp.task('default', ['build']);
  gulp.task('build', ['buildsass']);
  gulp.watch('.tmp/*.css', function(){gulp.run('process-css');});
})();

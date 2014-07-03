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
  var minifycss = require('gulp-minify-css');

  var paths = {
    sass: ["sass/custom.sass"],
  };

  gulp.task('buildsass', function () {
    var sassConfig = {
      css: 'css',
      sass: 'sass',
      project: __dirname
    };

    return gulp.src(paths.sass)
      .pipe(compass(sassConfig))
      .pipe(csso())
      .pipe(cmq({log: true}))
      .pipe(gulpif(!args.debug, minifycss()))
      .pipe(gulp.dest("css"));
  });

  gulp.task('svgmin', function() {
    return gulp.src('**/*.svg')
      .pipe(svgmin())
      .pipe(gulp.dest('./'));
  });

  gulp.task('clean', function () {
    return gulp.src(['walkthrough.css'])
      .pipe(clean());
  });

  gulp.task('default', ['build']);
  gulp.task('build', ['buildsass']);
  gulp.watch('.tmp/*.css', function(){gulp.run('process-css');});
})();

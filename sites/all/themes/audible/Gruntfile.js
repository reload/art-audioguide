'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),

    // Watch for changes and trigger compass with livereload on CSS files.
    watch: {
      scss: {
        options: {
          livereload: false
        },
        files: ['sass/*.scss'],
        tasks: ['compass:dev','compass:prod']
      },
      css: {
        files: ['css/*.css','css_dev/*.css'],
        options: {
          livereload: true
        }
      }
    },

    // Compass and SCSS
    compass: {
      options: {
        httpPath: '/sites/all/themes/audible',
        cssDir: 'css_dev',
        sassDir: 'sass',
        imagesDir: 'images',
        javascriptsDir: 'js',
        fontsDir: 'css/fonts',
        assetCacheBuster: 'none'
      },
      dev: {
        options: {
          environment: 'development',
          outputStyle: 'expanded',
          relativeAssets: true,
          raw: 'line_numbers = :true\n'
        }
      },
      prod: {
        options: {
          environment: 'production',
          outputStyle: 'compact',
          force: true,
          cssDir: 'css'
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-compass');

  grunt.registerTask('build', [
    'compass:prod'
  ]);

  grunt.registerTask('default', [
    'compass:dev',
    'watch'
  ]);
};

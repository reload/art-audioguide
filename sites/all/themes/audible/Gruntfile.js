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
        tasks: ['compass:prod']
      },
      css: {
        files: ['css/*.css'],
        options: {
          livereload: true
        }
      }
    },

    // Compass and SCSS
    compass: {
      options: {
        httpPath: '/sites/all/themes/audible',
        cssDir: 'css',
        sassDir: 'sass',
        imagesDir: 'images',
        javascriptsDir: 'js',
        fontsDir: 'css/fonts',
        assetCacheBuster: 'none'
      },
      prod: {
        options: {
          environment: 'production',
          outputStyle: 'compact',
          force: true
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
    'compass:prod',
    'watch'
  ]);
};

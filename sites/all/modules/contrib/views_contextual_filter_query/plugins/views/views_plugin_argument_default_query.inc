<?php

/**
 * @file
 * Contains the url query parameter default plugin.
 */

/**
 * Default argument plugin to use a query parameter from the URL.
 */
class views_plugin_argument_default_query extends views_plugin_argument_default {
  function option_definition() {
    $options = parent::option_definition();
    $options['parameter'] = array('default' => '');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['parameter'] = array(
      '#type' => 'textfield',
      '#title' => t('Parameter name'),
      '#default_value' => $this->options['parameter'],
    );
  }

  function get_argument() {
    $query_parameters = drupal_get_query_parameters();

    if (($parameter = $this->options['parameter']) && isset($query_parameters[$parameter])) {
      return $query_parameters[$parameter];
    }
  }

  function convert_options(&$options) {
    if (!isset($options['parameter']) && isset($this->argument->options['default_argument_query'])) {
      $options['parameter'] = $this->argument->options['default_argument_query'];
    }
  }
}

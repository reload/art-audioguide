<?php

/*
 * CORE
 */

// Caching.
$conf['preprocess_css'] = TRUE;
$conf['preprocess_js'] = TRUE;
$conf['cache'] = TRUE;
$conf['cache_lifetime'] = '300';
$conf['page_cache_maximum_age'] = '300';

// Watchdog/logging.
$conf['dblog_row_limit'] = '10000';
$conf['error_level'] = 0;


// These are settings found on the admin/config/regional/settings page:
$conf['date_default_timezone'] = 'Europe/Copenhagen';
$conf['date_first_day'] = 1;
$conf['date_api_use_iso8601'] = TRUE;
$conf['configurable_timezones'] = FALSE;
$conf['site_default_country'] = 'DK';

// Theme.
$conf['admin_theme'] = 'seven';
$conf['node_admin_theme'] = TRUE;

// Only administrators can create user accounts. There is a constant for this:
// USER_REGISTER_ADMINISTRATORS_ONLY - but it is not available here yet, so
// just use the 0.
$conf['user_register'] = 0;

// Transliteration module.
$conf['transliteration_file_uploads'] = TRUE;
$conf['transliteration_file_lowercase'] = TRUE;

// Display Suite.
$conf['ds_extras_switch_field'] = TRUE;
$conf['ds_extras_hide_page_title'] = TRUE;
$conf['ds_extras_field_template'] = TRUE;
$conf['ft-default'] = 'theme_ds_field_reset';
$conf['site_name'] = 'SMK';
$conf['site_name'] = 'SMK';

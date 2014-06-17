<?php

/**
 * @file
 *
 * This template file would normally be used to generate CSS used
 * for menu-items. But since we don't wish to get any styling to
 * the menu links, we simply create our own version of this tpl and
 * make it "empty" to get rid any possible styling.
 */
?>

a.menu-<?php print $mlid ?>, ul.links li.menu-<?php print $mlid ?> a {
  background: none;
}


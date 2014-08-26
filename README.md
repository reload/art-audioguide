# Art audioguide.

[![Scrutinizer Code Quality](https://scrutinizer-ci.com/g/reload/art-audioguide/badges/quality-score.png?b=develop)](https://scrutinizer-ci.com/g/reload/art-audioguide/?branch=develop)

Installation
---

1. Create a clean drupal installation with the "Audioguide" install profile.

2. After installation you either: *
    * Run the following drush command: `drush features-revert-all`.
    * Go to `Admin > Structure > Features` and revert all.

3. Go to `Admin > Configuration > Translate interface`. In here you select the `UPDATE` tab and choose `Update translations`. This will update translation for all available modules.

_* The title module and features doesn't work 100% together, so we need to go and revert the features including the title module._

Site building
---
After you have installed the site you'll have two pages created: "All routes" and "All artworks". These are lists that will automatically update themselves when you create content.

Theme
---
* To build the audible theme, cd to the theme directory and run `npm install`.

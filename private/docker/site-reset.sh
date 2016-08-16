#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Fix file-permissions.
cd "${SCRIPT_DIR}/../../"
# Chmod to 777 if the file is not owned by www-data
find sites/default/files \! -uid 33  \! -name .gitkeep -print0 | sudo xargs -0 chmod 777

# Make sites/default read-only and executable
sudo chmod 555 sites/default

# Drupal-specific resets
docker-compose run --no-deps --entrypoint "sh -c" --rm drush "drush updb -y \
    && drush vset theme_debug 1 \
    && drush vset preprocess_css 0 \
    && drush cc all \
    && drush --uri=http://local.docker uli"



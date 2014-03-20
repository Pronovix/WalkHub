#!/bin/bash
set +x

INSTALL_DIR=$1
[ -z $INSTALL_DIR ] && echo [ERROR] You need to specify the install folder! e.g. $0 /Users/Shared/walkhub && exit 1

function f_install_drush() {
  if [ ! -d "/usr/local/drush" ]; then
    read -r -p "${1:-Drush not found on /usr/local/drush. Would you like to automatically install it? [Y/n]} " response
    case $response in
       [yY][eE][sS]|[yY])
         echo "[Info] Installing Drush"
         sudo git clone --branch 7.x-5.x http://git.drupal.org/project/drush.git /usr/local/drush
         sudo /usr/local/drush/drush --version
         ;;
       *)
         echo "[Info] You need to build the site using Drush i.e. drush make --prepare-install /tmp/walkhub/build-walkhub.make ${INSTALL_DIR}"
         exit
         ;;
     esac
  fi
}

function f_install_build() {
  echo "[Info] Build site"
  /usr/local/drush/drush make --prepare-install /tmp/walkhub/build-walkhub.make ${INSTALL_DIR}
}

function f_install_site() {
  echo
  echo "[Info] Now you can install your distro site using your browser. If you want to use drush, you can use the commands below"
  echo "drush si -y walkthrough --db-url=\"mysql://root@localhost/walkhub\" --site-name=\"WalkHub\" --account-name=admin --account-pass=password --sites-subdir=default"
  echo Drupal login details:
  echo user: admin
  echo pass: password
  echo
}

f_install_drush
f_install_build
f_install_site

echo Done

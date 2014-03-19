Walkhub
=======

Prerequisites

Git
Drush

Installation

  - Go to the folder where you want to install the Distro i.e.
    $ cd /Users/Shared

  - Copy and paste this into your shell to install everything:
    $ curl -L -s http://goo.gl/5w30CH | bash
  
    What it will do:
    - Clone Drupal from drupal.org
    - Clone WalkHub repo
    - Build a Distro that contains a profile called walkthrough
    - Run build script that will download Drush if necessary, build the site.
    
  - Now you can install your distro site using your browser. If you want to use drush, you can use the commands below. Change the parameters as necessary:
    $ cd walkhub/sites/default/
    $ /usr/local/drush/drush si -y walkhub --db-url="mysql://root@localhost/walkhub" --site-name="WalkHub" --account-name=admin --account-pass=password --sites-subdir=default

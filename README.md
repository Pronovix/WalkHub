Walkhub
=======

Prerequisites

- Git
- Drush

Installation

  - Go to the folder where you want to install the Distro e.g.
  
    cd /Users/Shared

  - Copy and paste the following command into your shell terminal to install everything. This will create a folder with the name walkhub inside your chosen installation directory:
  
    curl -L -s http://goo.gl/dXUbub | bash
  
    What it will do:

    - Clone Drupal from drupal.org
    - Clone WalkHub repo
    - Build a Distro that contains a profile called walkthrough
    - Run build script that will download Drush if necessary, build the site.
    
  - Now you can install your distro site using your browser. Alternatively, if you want to use drush, you can use the commands below, changing the parameters as necessary:
    
    cd walkhub/sites/default/

    drush si -y walkthrough --db-url="mysql://root@localhost/walkhub" --site-name="WalkHub" --account-name=admin --account-pass=password --sites-subdir=default


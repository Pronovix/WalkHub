
-- SUMMARY --

This small module helps theme-developers to deal with cross-browser compatibility.
It makes easier to handle different types of non-widespread browsers just as much as it helps with using different versions of Internet Explorer.

The module extends the $body_classes variable in page.tpl.php based on the enduser's browser, with the following:
  * ie
  * ie[version]
  * opera
  * safari
  * chrome
  * netscape
  * ff
  * konqueror
  * dillo
  * chimera
  * beonex
  * aweb
  * amaya
  * icab
  * lynx
  * galeon
  * operamini

and with the following platforms:
  * win
  * ipad
  * ipod
  * iphone
  * mac
  * android
  * linux
  * nokia
  * blackberry
  * freebsd
  * openbsd
  * netbsd

The module checks if the device is mobile and adds "mobile" or "desktop" class.

The module also makes a $browser_classes variable available in page.tpl.php, which stores the data in an array, this way the developer can make use of it as needed, if he does not wish to use the $body_classes variable.



-- REQUIREMENTS --

None.


-- CONFIGURATION --

The module has a settings page (admin/config/user-interface/browserclass), where the administrator can choose between these options:
  * always add the class with JavaScript
  * only use JavaScript if page cache is enabled
This page is available only users with "administer browser class" permission.



-- DEVELOPERS --

Developers can add their own classes with hook_browserclass_classes(). More information in browserclass_hook.php file.



-- CONTACT --

Kalman Hosszu (hosszu.kalman http://drupal.org/user/267481) http://www.kalman-hosszu.com/


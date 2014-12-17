<?php
if (user_is_logged_in()) {
  return [];
}else{
  ?>
<div class="login-container">
  <div class="row">
    <div><a href="/user">Login</a></div>
  </div>
</div>
<?php
}

?>



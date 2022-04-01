<?php

/**
* Callback for retrieving notifications.
*
* @param int $id
* @return object
*/
function _notifications_retrieve_memberlist($id) {
  $data_set = "hello world";
return $data_set;
}


function _c4m_web_services_notification_resource_access($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], array('account', 'data'));
  }

  global $user;
  switch ($op) {
    case 'view':
    case 'update':
      return user_access('administer users');
    case 'c4m_create_user':
      if (!$user->uid && variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) != USER_REGISTER_ADMINISTRATORS_ONLY) {
        return TRUE;
      }
      else {
        return user_access('administer users');
      }
    case 'password_reset':
      return TRUE;
    case 'delete':
  }
}

<?php

/**
 * @file
 * User resource file.
 */


function _c4m_user_resource_access($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], array('account', 'data'));
  }

  global $user;
  switch ($op) {
    case 'view':
      return user_access('administer users');
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
    case 'cancel':
      return user_access('administer users');
  }
}

  /**
 * Update an existing user.
 *
 * This function uses drupal_form_submit() and as such expects all input to match
 * the submitting form in question.
 *
 * @param $uid
 *   Unique identifier for this user
 * @param $account
 *   Fields to modify for this user.
 *
 * @return
 *   The modified user object.
 */
function _c4m_web_services_user_resource_update($dashboard_id, array $account) {
  // Adds backwards compatability with regression fixed in #1083242
  $account = _services_arg_value($account, 'data');

  $account_loaded = user_load_by_mail($account['email']);
  $updated_account = array();

  $fields_changed = array();

  foreach ($account as $fieldname => $value) {
    switch ($fieldname) {
      case "c4m_user_dashboard_id":
      case "c4m_user_status":
        if ($account_loaded->{$fieldname}[LANGUAGE_NONE][0]["value"] !== $value) {
          $updated_account[$fieldname] = [LANGUAGE_NONE => [['value' => $value]]];
          $fields_changed[] = $fieldname;
        }
        break;
  //    case "type":
  //    break;
      case "ecas_id":
        if ($account_loaded->name !== $value) {
          $updated_account['name'] = $value;
          $fields_changed[] = $fieldname;
        }
        break;
      case "email":
        if ($account_loaded->mail !== $value) {
          $updated_account['mail'] = $value;
          $fields_changed[] = $fieldname;
        }
        break;
      case "c4m_status":
        $c4m_status = $value == "Blocked" ? "0" : "1";
        if ($account_loaded->status !== $c4m_status) {
          // Block / unblock a user:
          $updated_account['status'] = $c4m_status;
          $fields_changed[] = $fieldname;
        }
        break;
      case "first_name":
      case "last_name":
        $organisation = $account["c4m_organisations_informations"]["c4m_organisation"];
        $org_member_info = $organisation["c4m_member_informations"];
        // using the dataset from the organisation section. the main section is currently not updated.
        $value = $org_member_info[LANGUAGE_NONE][0][$fieldname];
        if ($account_loaded->{'c4m_' . $fieldname}[LANGUAGE_NONE][0]['value'] !== $value) {

          $updated_account['c4m_' . $fieldname] = [LANGUAGE_NONE => [['value' => $value]]];
          $fields_changed[] = $fieldname;
        }
        break;
    }
  }

  $nid = c4m_web_services_get_existing_node($organisation['c4m_organisation_dashboard_id'][LANGUAGE_NONE][0]['value']);
  $membership = og_group('node', $nid, ['entity' => $account_loaded]);

  if (count($updated_account) > 0) {
    user_save($account_loaded, $updated_account);
    $message = "updated user :  %usermail (dashboard id : %dashboardID) updated the fields : %fields";
    if (function_exists ('watchdog')) {
      watchdog('my_module', $message, array("%usermail" => $account['email'], "%dashboardID" => $dashboard_id , "%fields" => implode( ',', $fields_changed)), WATCHDOG_INFO);
    }

  }
}

/**
 * Create a new user.
 *
 * This function uses drupal_form_submit() and as such expects all input to match
 * the submitting form in question.
 *
 * @param $account
 *   A object containing account information. The $account object should
 *   contain, at minimum, the following properties:
 *     - name (user name)
 *     - mail (email address)
 *     - pass (plain text unencrypted password)
 *
 *   We need to extract some of the info from the structure of the first organisation.
 *   This might be refactored at a later date.
 *
 *   These properties can be passed but are optional
 *     - status (0 for blocked, otherwise will be active by default)
 *     - notify (1 to notify user of new account, will not notify by default)
 *
 *  Roles can be passed in a roles property which is an associative
 *  array formatted with '<role id>' => '<role id>', not including
 *  the authenticated user role, which is given by default.
 *
 * @return
 *   The user object of the newly created user.
 */
function _c4m_user_resource_user_create($account) {
  if (!isset($account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"]) ||
      !isset($account['email']) ||
      !isset($account['c4m_user_dashboard_id']) ||
      !isset($account['first_name']) ||
      !isset($account['last_name'])) {
    $xml = new SimpleXMLElement('<missing_properties/>');
    $xml->addChild('missing_required_fields', "Missing one of the following minimum required properties");
    $xml->addChild('fields', 'username, email, first-, lastname', 'c4m_user_dashboard_id');
    throw new ServicesException($xml->asXML(), 500);
  }

  if ($account_loaded = user_load_by_mail($account['email'])) {
    $xml = new SimpleXMLElement('<user_already_exists/>');
    $xml->addChild('user_already_exists_with_email', "We have found already a user that is using this email address");
    throw new ServicesException($xml->asXML(), 500);
  }

  $account['first_name'] = $account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"][LANGUAGE_NONE][0]['first_name'];
  $account['last_name'] = $account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"][LANGUAGE_NONE][0]['last_name'];

  if (empty($account['ecas_id'])) {
    $user_name = _c4m_web_services_return_valid_name($account['first_name'] . ' ' . $account['last_name']);
  }
  else {
    $user_name = _c4m_web_services_return_valid_name($account['ecas_id']);
  }

  if ($account_loaded = user_load_by_name($user_name)) {
    $xml = new SimpleXMLElement('<user_already_exists/>');
    $xml->addChild('user_already_exists_with_username', "We have found already a user that is using this username");
    throw new ServicesException($xml->asXML(), 500);
  }

  // Check new user active status on the platform.
  if (isset($account['c4m_status'])) {
    $account['c4m_status'] == "Blocked" ? FALSE : TRUE;
  }
  else {
    $account['c4m_status'] = FALSE;
  }

  $new_user_data = array(
    'name' => $user_name,
    'pass' => user_password(),
    'mail' => $account['email'],
    'c4m_first_name' => [LANGUAGE_NONE => [['value' => $account['first_name']]]],
    'c4m_last_name' => [LANGUAGE_NONE => [['value' => $account['last_name']]]],
    'init' => $account['email'],
    'created' => time(),
    'status' => $account['c4m_status'],
    'c4m_user_dashboard_id' => [LANGUAGE_NONE => [['value' => $account['c4m_user_dashboard_id']]]],
  );

  // Create new user.
  $new_user = user_save(drupal_anonymous_user(), $new_user_data);

  if (empty($new_user)) {
    $xml = new SimpleXMLElement('<error_creating_user/>');
    $xml->addChild('error_creating_user_message', "Something went wrong and user was not created");
    throw new ServicesException($xml->asXML(), 406);
  }

  // Set Authmap record for this newly created user.
  user_set_authmaps($new_user, ['authname_ecas' => $new_user_data['name']]);

  $users[] = array(
    'uid' => $new_user->uid,
    'name' => $new_user->name,
    'email' => $new_user->mail,
  );
  return $users;
}


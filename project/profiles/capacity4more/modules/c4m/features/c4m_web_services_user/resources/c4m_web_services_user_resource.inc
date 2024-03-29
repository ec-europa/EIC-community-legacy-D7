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
  if ($account_loaded == false) {
    //user with email not found, this could indicate an email change
    if (function_exists ('watchdog')) {
      $message = "user not found with with email:  %usermail, dashboard id : %dashboardID , username/ecas_id: %ecas_id ";
      watchdog('ws_user', $message, array("%usermail" => $account['email'], "%dashboardID" => $dashboard_id , "%ecas_id" => $account["ecas_id"]), WATCHDOG_INFO);
    }
    $account_loaded = user_load_by_name($account["ecas_id"]) ;
    if ($account_loaded == false) {
      // also ecas changed, then last change for the update using the dashboard ID.'
      if (function_exists ('watchdog')) {
        $message = "user also not found with with ecas_id:  %usermail, dashboard id : %dashboardID , username/ecas_id: %ecas_id ";
        watchdog('ws_user', $message, array("%usermail" => $account['email'], "%dashboardID" => $dashboard_id , "%ecas_id" => $account["ecas_id"]), WATCHDOG_INFO);
      }
       //$account['c4m_user_dashboard_id'];
      $query = new EntityFieldQuery();
      $results = $query->entityCondition('entity_type', 'user')
        ->propertyCondition('status', 1)
        ->fieldCondition('c4m_user_dashboard_id', 'value', $dashboard_id, '=')
        ->execute();
      // there should be only one result.
      if (count($results['user']) > 1 ){
        $xml = new SimpleXMLElement('<user_issue/>');
        $xml->addChild('message', "Multiple users not found with following c4m_user_dashboard_id:" . $dashboard_id);
        throw new ServicesException($xml->asXML(), 406);
      }
      $account_loaded = user_load( key($results['user']));
    }

  }

  if ($account_loaded == false) {
    //user with email not found, this could indicate an email change
    if (function_exists('watchdog')) {
      $message = "user not found with with one of these values:  %usermail, dashboard id : %dashboardID , username/ecas_id: %ecas_id ";
      watchdog('ws_user', $message, array("%usermail" => $account['email'], "%dashboardID" => $dashboard_id, "%ecas_id" => $account["ecas_id"]), WATCHDOG_INFO);
    }
    $xml = new SimpleXMLElement('<user_not_found/>');
    $xml->addChild('message', "user not found with with one of these key fields: email, ecas_id(username), c4m_user_dashboard_id");
    $xml->addChild('received_data', " email: {$account['email']}, ecas_id / username: {$account['ecas_id']}, dashboard_id: $dashboard_id ");

    throw new ServicesException($xml->asXML(), 404);
  }
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
      watchdog('ws_user', $message, array("%usermail" => $account['email'], "%dashboardID" => $dashboard_id , "%fields" => implode( ',', $fields_changed)), WATCHDOG_INFO);
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
  $required_fields = ['email', 'c4m_user_dashboard_id', 'first_name', 'last_name'];
  $missing_fields = [];
  foreach ($required_fields as $fieldname) {
    if (!array_key_exists($fieldname,$account)) {
      // double check for first- and lastname , check if organization exists
      if (in_array($fieldname, ['first_name', 'last_name']) &&
        !empty(trim($account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"][LANGUAGE_NONE][0][$fieldname]))) {
        // found the fields within the organisation.
        continue;
      }
      $missing_fields[] = $fieldname;
    }
  }
  // can be that isset($account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"]
  if (count($missing_fields) > 0) {
    $str_account = var_export($account,true);
    $str_missing_fields = implode(",", $missing_fields);
    watchdog('ws_user', 'missing one of the required fields (%missing_fields) in : %account', array('%account' => $str_account, '%missing_fields' => $str_missing_fields), WATCHDOG_INFO);
    $xml = new SimpleXMLElement('<missing_properties/>');
    $xml->addChild('missing_required_fields', "Missing one of the following minimum required properties: ");
    $xml->addChild('required_fields', 'email, first-, lastname, c4m_user_dashboard_id');
    $xml->addChild('missing_fields', $str_missing_fields);
    throw new ServicesException($xml->asXML(), 406);
  }
  // We check here for the organisation , if it is missing, it could a new user, other we prefer this dataset
  if (isset($account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"])) {
    $account['first_name'] = $account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"][LANGUAGE_NONE][0]['first_name'];
    $account['last_name'] = $account["c4m_organisations_informations"]["c4m_organisation"]["c4m_member_informations"][LANGUAGE_NONE][0]['last_name'];
  }
  else {
    watchdog('ws_user', 'no organisation info included for user %email with dashboard_id : %user_dashboard_id' ,array('%email' => $account['email'], '%user_dashboard_id' => $account['c4m_user_dashboard_id']) ,WATCHDOG_INFO);
  }

  if ($account_loaded = user_load_by_mail($account['email'])) {
    $xml = new SimpleXMLElement('<user_already_exists/>');
    $xml->addChild('user_already_exists_with_email', "We have found already a user that is using this email address");
    throw new ServicesException($xml->asXML(), 406);
  }

  if (empty(trim($account['ecas_id']))) {
    $user_name = _c4m_web_services_return_valid_name($account['first_name'] . ' ' . $account['last_name']);
    watchdog('ws_user', 'user with email : "%email", has not been registered with EULOGIN yet. Using a temporarily username.',array( '%email' => $account['email'] ),'WATCHDOG_NOTICE');
  }
  else {
    $user_name = _c4m_web_services_return_valid_name($account['ecas_id']);
  }

  if ($account_loaded = user_load_by_name($user_name)) {
    $xml = new SimpleXMLElement('<user_already_exists/>');
    $xml->addChild('user_already_exists_with_username', "We have found already a user that is using this username");
    throw new ServicesException($xml->asXML(), 406);
  }

  // Check new user active status on the platform.
  if (isset($account['c4m_status'])) {
    $account['c4m_status'] = $account['c4m_status'] == "Blocked" ? "0" : "1";
  }
  else {
    watchdog('ws_user', 'No status found for user : %user_name / %email . Blocking access for now!',array('%user_name' => $user_name, '%email' => $account['email'] ),'WATCHDOG_NOTICE');
    $account['c4m_status'] = "0";
  }
  # watchdog('ws_user', 'new account variable check : %account', array('%account'=>$account) ,WATCHDOG_INFO);
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
  watchdog('ws_user', "new user [%uid] :
                                      User_dashboard_id : %user_dashboard_id |
                                      Username :          %new_user_name |
                                      c4m_first_name:     %firstname |
                                      c4m_last_name:      %lastname |
                                      mail:               %mail",
                          array( '%uid' => $new_user->uid, '%user_dashboard_id' => $account['c4m_user_dashboard_id'],
                                 '%new_user_name' => $new_user->name, '%firstname' =>  $account['first_name'],
                                 '%lastname' =>  $account['last_name'], '%mail' => $new_user->mail) ,WATCHDOG_INFO);

  // Set Authmap record for this newly created user.
  user_set_authmaps($new_user, ['authname_ecas' => $new_user_data['name']]);

  $users[] = array(
    'uid' => $new_user->uid,
    'name' => $new_user->name,
    'email' => $new_user->mail,
  );
  return $users;
}


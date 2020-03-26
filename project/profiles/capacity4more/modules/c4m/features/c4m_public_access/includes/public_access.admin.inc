<?php

/**
 * @file
 * Implementation of the administration interface for the module.
 */

/**
 * Creates the Public access settings form. This is located under services tab.
 *
 * @return array $form
 */
function c4m_public_access_admin_settings_general() {
  $form = array();
  // Get event site configuration details.
  $public_access_settings = variable_get('$public_access_settings', array());
  $public_access_settings['stored_nodes'] = empty($public_access_settings['stored_nodes']) ? array() : json_decode($public_access_settings['stored_nodes']);

  $form['public_access_admin'] = array(
    '#id' => 'public_access_admin',
    '#type' => 'fieldset',
    '#title' => t('Manage "book" Pages that can be viewed by anonymous users'),
    '#description' => t('Enter your Event site information.'),
    '#collapsible' => empty($webservice_eventsite) ? FALSE : TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['public_access_admin']['node_id'] = array(
    '#type' => 'textfield',
    '#title' => t('add a new node id'),
    '#description' => '',
     // t('Event site owner when creating through the webservice and owner is not given'),
    '#default_value' =>  '',
    '#required' => FALSE,
  );
  $form['public_access_admin']['add_node'] = array(
    '#type' => 'submit',
    '#value' => t('Add node'),
    '#ajax' => array(
      'callback' => 'ajax_add_node_to_public_access_callback',
      'wrapper' => 'overview_anonymous_nodes',
      'method' => 'replace',
      'effect' => 'fade',
     // '#validate' => 'c4m_public_access_admin_settings_general_validate',
    ),
    );

  // the section where can manage nodes to get made available for anonymous users (booklet pages).

  $header = array(
    'nid' => t('Node ID'),
    'node_type' => t('Type'),
    'title' => t('Title'),
  );

  $result= empty($public_access_settings['stored_nodes']) ? array() : $public_access_settings['stored_nodes'];
  if (!empty($result)) {
    $nodes = node_load_multiple($result);

    foreach ($result as $nid) {
      $options[$nid] = array(
        '#id' => "item_node_" . $nid,
        'nid' => check_plain($nid),
        'node_type' => check_plain($nodes[$nid]->type),
        'title' => check_plain($nodes[$nid]->title),
      );
    }
  }
  if (!empty($options)) {
      $form['public_access_admin']['nodes'] = array(
        '#attributes' => array(
          'id' => 'overview_anonymous_nodes',
        ),
        '#type' => 'tableselect',
        '#header' => $header,
        '#options' => $options,
    );

//    $form['pager'] = array('#value' => theme('pager'));

    $form['public_access_admin']['remove'] = array(
    '#type' => 'submit',
    '#value' => t('Remove selected'),
    '#ajax' => array(
      'callback' => 'ajax_remove_public_access_callback',
      'wrapper' => 'overview_anonymous_nodes',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    );

  }





  $form = system_settings_form($form);
//  $form['#submit'][] = 'c4m_public_access_admin_settings_general_submit';
  $form['#validate'][] = 'c4m_public_access_admin_settings_general_validate';
  return $form;

}
function c4m_public_access_admin_settings_general_validate($form, &$form_state) {
  $error_message="";
  // Check if node actually exists, check node type, just in case.
//  $test_node = node_load(array('nid' => $test_nid));
//  $test_node_exists = ($test_node != false);
//  $test_type = $test_node->type;
//  $user_check = user_load_by_name($form_state['values']['webservice_eventsite']['webservice_eventsite_owner_account']);
  if (isset($_POST["_triggering_element_value"])) {
    if (  $_POST["_triggering_element_value"] == "Add node") {
      if (!empty($form_state["values"]["public_access_admin"]["node_id"])) {
        $new_public_nid = $form_state["values"]["public_access_admin"]["node_id"];
        $node = node_load($new_public_nid);
        if (empty($node)) {
          $error_message = "incorrect node given.";
        }
        elseif ($node->type !== "book") {
          $error_message = "node is not of the <b>'Book Page'</b> type. Only those are allowed to be shown on the public side.";
        }
        if (!empty($error_message)) {
          form_set_error('public_access_admin_node_add', $error_message);
        }
      }
    }
  }

//
//  if (!empty($_POST['ajax_page_state'])) {
//    $delete_some_options = True;
//    #ignore the adding of the node :
//    $form_state["values"]["public_access_admin"]["add_node"] = '';
//  }
//  else {
//
//    }

//  if (!$user_check) {
//   // form_set_error('webservice_eventsite_owner_account', $error_message);
//  }
}


function ajax_remove_public_access_callback($form, &$form_state) {
  // eh delete something here ?
  $public_access_settings = variable_get('$public_access_settings', array());
  $public_access_settings['stored_nodes'] = empty($public_access_settings['stored_nodes']) || $public_access_settings['stored_nodes'] == 'null' ? array() : json_decode($public_access_settings['stored_nodes']);
  $x = $form_state["values"]["public_access_admin"]["nodes"];
  // even after deleteing, the nid is still here :
  // $form_state["values"]["public_access_admin"]["nodes"]
  // AND $form["public_access_admin"]["nodes"]["#options"]
  foreach( $form_state["values"]["public_access_admin"]["nodes"] as $nid => $matching_nid) {
    if ($nid == $matching_nid) {
       $public_access_settings['stored_nodes'] = array_diff(  $public_access_settings['stored_nodes'], array($nid) );
       // need to reindex the list, otherwise json will encode it as an object and not an array.
       $public_access_settings['stored_nodes'] = array_values($public_access_settings['stored_nodes']);
       #remove it from the existing form.
       unset($form["public_access_admin"]["nodes"]["#options"][$nid]);
       unset($form["public_access_admin"]["nodes"][$nid]);
       // Hide also from menu @todo - TOTEST
      _c4m_public_access_show_hide_menu_item_for_anonymous_users("node/" . $nid, False);
    }
  }
  // save new list.
  $public_access_settings['stored_nodes']  = json_encode($public_access_settings['stored_nodes'] );
  variable_set('$public_access_settings', $public_access_settings);
  // create new form
  //$form["public_access_admin"]["nodes"]["#options"]
//  $new_form = c4m_public_access_admin_settings_general();  //$form['public_access_admin']['nodes'];
//
//  drupal_prepare_form($form['#form_id'], $new_form, $form_state);
//  drupal_process_form($form['#form_id'], $new_form, $form_state);

  $form['rebuild'] = TRUE;
  $form_state['rebuild'] = TRUE;
  return $form["public_access_admin"]["nodes"];
}



/**
 * Form submission handler for adding a node to public_access_admin_settings().
 * Ajax based.
 */

function  ajax_add_node_to_public_access_callback($form, &$form_state) {
  if (empty($form_state["values"]["public_access_admin"]["node_id"])) {
    // going to delete some of the entries @todo.
    $form['public_access_admin']['#markup'] = 'No node id given...';
    return $form['public_access_admin'];
  }

  if (form_get_errors()) {
    $element = $form['public_access_admin'];
  	$element['#markup'] = "Could not add this item to the list.";
  	return $element;
  }
  #No errors great, continue.
  $public_access_settings = variable_get('$public_access_settings', array());
  $public_access_settings['stored_nodes'] = empty($public_access_settings['stored_nodes']) || $public_access_settings['stored_nodes'] == 'null' ? array() : json_decode($public_access_settings['stored_nodes']);

  $new_node =$form_state["values"]["public_access_admin"]["node_id"];
  if (!in_array($new_node,$public_access_settings['stored_nodes'])) {
    array_push($public_access_settings['stored_nodes'], $new_node);
    # Saving the new new dataset in json style.
    $public_access_settings['stored_nodes']  = json_encode($public_access_settings['stored_nodes'] );
    variable_set('$public_access_settings', $public_access_settings);
    # Allow to show the menu item for anonymous users.
    _c4m_public_access_show_hide_menu_item_for_anonymous_users("node/" . $new_node, True);
    // Clear the menu cache of the menu;
    cache_clear_all('*', 'cache_menu', TRUE);
  }

  //$new_form = c4m_public_access_admin_settings_general();  //$form['public_access_admin']['nodes'];

  //drupal_prepare_form($form['#form_id'], $new_form, $form_state);
  //drupal_process_form($form['#form_id'], $new_form, $form_state);
  return $form["public_access_admin"]["nodes"];

}

/**
 * UNUSED  : Form submission handler for public_access_admin_settings().
 */
function c4m_public_access_admin_settings_general_submit($form, &$form_statexxx) {
  if (empty($form_state["values"]["public_access_admin"]["add_node"])) {
    // going to delete some of the entries @todo.
    return;
  }
  $public_access_settings = variable_get('$public_access_settings', array());
  $public_access_settings['stored_nodes'] = empty($public_access_settings['stored_nodes']) || $public_access_settings['stored_nodes'] == 'null' ? array() : json_decode($public_access_settings['stored_nodes']);

  $new_node =$form_state["values"]["public_access_admin"]["add_node"];
  if (!in_array($new_node,$public_access_settings['stored_nodes'])) {
    array_push($public_access_settings['stored_nodes'], $new_node);
    # Saving the new new dataset in json style.
    $public_access_settings['stored_nodes']  = json_encode($public_access_settings['stored_nodes'] );
    variable_set('$public_access_settings', $public_access_settings);
    # Allow to show the menu item for anonymous users.
    _c4m_public_access_show_hide_menu_item_for_anonymous_users("node/" . $new_node, True);
    // Clear the menu cache of the menu;
    cache_clear_all('*', 'cache_menu', TRUE);
  }


  //  if ((variable_get('minimum_word_size', 3) != $form_state['values']['minimum_word_size']) ||
  //      (variable_get('overlap_cjk', TRUE) != $form_state['values']['overlap_cjk'])) {
  //    drupal_set_message(t('The index will be rebuilt.'));
  //    search_reindex();
  //  }
}

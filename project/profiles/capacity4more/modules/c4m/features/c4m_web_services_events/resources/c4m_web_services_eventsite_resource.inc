<?php

/**
 * @file
 * Node resource file.
 */


function _c4m_node_events_resource_access_using_dashboard_id($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242.
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], 'node');
  }

  // Make sure we have an object or this all fails, some servers can
  // mess up the types.
  if (is_array($args[0])) {
    $args[0] = (object) $args[0];
  }
  // This is to determine if it is just a string happens on node/%NID.
  elseif (!is_array($args[0]) && !is_object($args[0])) {
    if (empty($node = _c4m_eventsite_load_by_dashboard_id($args[0]))) {
      services_error(t('Unfortunately we were unable to load the Node.'), 406);
    }
    $args[0] = (object) array('nid' => $node->nid);
  }

  if ($op != 'create' && !empty($args)) {
    $node = node_load($args[0]->nid);
  }
  elseif ($op == 'create') {
    if (isset($args[0]->type)) {
      $node = $args[0]->type;
      return node_access($op, $node);
    }
    else {
      return services_error(t('Node type is required'), 406);
    }
  }
  if (isset($node->nid) && $node->nid) {
    return node_access($op, $node);
  }
  else {
    return services_error(t('Node @nid could not be found', array('@nid' => $args[0]->nid)), 404);
  }
}

/**
 * Returns the results of a node_load() for the specified node.
 *
 * This returned node may optionally take content_permissions settings into
 * account, based on a configuration setting.
 *
 * @param $nid
 *   NID of the node we want to return.
 * @return
 *   Node object or FALSE if not found.
 *
 * @see node_load()
 */
function _c4m_node_resource_retrieve_via_dashboard_id($dashboard_id) {
  $node = _c4m_eventsite_load_by_dashboard_id($dashboard_id);

  if ($node) {
    $uri = entity_uri('node', $node);
    $node->path = url($uri['path'], array('absolute' => TRUE));
    // Unset uri as it has complete entity and this
    // cause never ending recursion in rendering.
    unset($node->uri);
  }
  //Lets check field_permissions
  $node = services_field_permissions_clean('view', 'node', $node);
  return $node;
}



/**
 * Updates a new node based on submitted values.
 *
 * Note that this function uses drupal_form_submit() to create new nodes,
 * which may require very specific formatting. The full implications of this
 * are beyond the scope of this comment block. The Googles are your friend.
 *
 * @param string $dashboard_id
 *   Dashboard id of the node we're editing.
 * @param array $node
 *   Array representing the attributes a node edit form would submit.
 *
 * @return int
 *   The node's nid.
 *
 * @see drupal_form_submit()
 */
function _c4m_web_services_events_eventsite_resource_update($dashboard_event_id, array $node) {
  // Adds backwards compatibility with regression fixed in #1083242.
  $node = _services_arg_value($node, 'node');

  $old_node = _c4m_eventsite_load_by_dashboard_id($dashboard_event_id);
  $node['nid'] = $old_node->nid;

  $nid = $old_node->nid;
  if (empty($old_node->nid)) {
    return services_error(t('Node @nid not found', array('@nid' => $old_node->nid)), 404);
  }

  // If no type is provided use the existing node type.
  if (empty($node['type'])) {
    $node['type'] = $old_node->type;
  }
  elseif ($node['type'] != $old_node->type) {
    // Node types cannot be changed once they are created.
    return services_error(t('Node type cannot be changed'), 406);
  }

  // Validate the node. If there is validation error Exception will be thrown
  // so code below won't be executed.
  _node_resource_validate_type($node);

  // The Banner uses the manualcrop module.
  // The metadata is reset because, it thinks it is a new form / entry.
  // We will grab the metadata and so we can put it back later:
  if (isset($old_node->c4m_banner[LANGUAGE_NONE][0])) {
    $fid = $old_node->c4m_banner[LANGUAGE_NONE][0]['fid'];
    $image_file = file_load($fid);
    $manualcrop_metadata = manualcrop_load_crop_selection($image_file->uri, 'banner');
    if (!empty($manualcrop_metadata)) {
      $image_file->manualcrop_data = array('banner' => json_decode(json_encode($manualcrop_metadata), TRUE));
    }
  }

  // Load the required includes for drupal_form_submit.
  module_load_include('inc', 'node', 'node.pages');

  $node_type = $node['type'];
  node_object_prepare($old_node);

  // Setup form_state.
  $form_state = array();
  $form_state['values'] = $node;
  $form_state['values']['op'] = variable_get('services_node_save_button_' . $node_type . '_resource_update', t('Save'));
  $form_state['node'] = $old_node;
  $form_state['programmed_bypass_access_check'] = FALSE;

  // Contributed modules may check the triggering element in the form state.
  // The triggering element is usually set from the browser's POST request, so
  // we'll automatically set it as the submit action from here.
  $stub_form = drupal_get_form($node_type . '_node_form', (object) $old_node);
  $form_state['triggering_element'] = $stub_form['actions']['submit'];

  drupal_form_submit($node_type . '_node_form', $form_state, $old_node);

  if ($errors = form_get_errors()) {
    return services_error(implode(" ", $errors), 406, array('form_errors' => $errors));
  }

  $node = array('nid' => $nid);
  if ($uri = services_resource_uri(array('node', $nid))) {
    $node['uri'] = $uri;
  }

  // RE-Save the manualcrop image data:
  if (isset($image_file->manualcrop_data)) {
    manualcrop_entity_update($image_file, $image_file->entity_type);
  }

  return $node;
}

/**
 * Get node by dashboard id.
 *
 * @param string $dashboard_id
 *   Dashboard id.
 *
 * @return null|object
 *   Node object.
 */
function _c4m_eventsite_load_by_dashboard_id($dashboard_id) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event_site')
    ->fieldCondition('c4m_event_dashboard_id', 'value', $dashboard_id, '=')
    ->range(0, 1);

  $result = $query->execute();
  if (empty($result['node'])) {
    return;
  }
  $nids = array_keys($result['node']);
  if (empty($nids[0])) {
    return;

  }
  return node_load($nids[0]);
}

/**
 * Determine whether the current user can access a node resource.
 *
 * @param string $op
 *   One of view, update, create, delete per node_access().
 * @param array $args
 *   Resource arguments passed through from the original request.
 *
 * @return bool
 *   Access.
 *
 * @see node_access()
 */
function _c4m_node_resource_access($op = 'view', array $args = []) {
  // Adds backwards compatability with regression fixed in #1083242.
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], 'node');
  }

  // Make sure we have an object or this all fails, some servers can
  // mess up the types.
  if (is_array($args[0])) {
    $args[0] = (object) $args[0];
  }
  // This is to determine if it is just a string happens on node/%NID.
  elseif (!is_array($args[0]) && !is_object($args[0])) {
    if (empty($node = _c4m_eventsite_load_by_dashboard_id($args[0]))) {
      services_error(t('Node type is required'), 406);
    }
    $args[0] = (object) array('nid' => $node->nid);
  }

  if ($op != 'create' && !empty($args)) {
    $node = node_load($args[0]->nid);
  }
  elseif ($op == 'create') {
    if (isset($args[0]->type)) {
      $node = $args[0]->type;
      return node_access($op, $node);
    }
    else {
      return services_error(t('Node type is required'), 406);
    }
  }
  if (isset($node->nid) && $node->nid) {
    return node_access($op, $node);
  }
  else {
    return services_error(t('Node @nid could not be found', array('@nid' => $args[0]->nid)), 404);
  }
}

<?php

/**
 * Updates a new node based on submitted values.
 *
 * Note that this function uses drupal_form_submit() to create new nodes,
 * which may require very specific formatting. The full implications of this
 * are beyond the scope of this comment block. The Googles are your friend.
 *
 * @param $dashboard_id
 *   Dashboard id of the node we're editing.
 * @param $node
 *   Array representing the attributes a node edit form would submit.
 * @return
 *   The node's nid.
 *
 * @see drupal_form_submit()
 */
function _c4m_web_services_node_resource_update($dashboard_id, $node) {
  // Adds backwards compatability with regression fixed in #1083242
  $node = _services_arg_value($node, 'node');

  $old_node = _c4m_organisation_load_by_dashboard_id($dashboard_id);
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

  // Load the required includes for drupal_form_submit
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
  return $node;
}


/**
 * @param $dashboard_id
 * @return bool|mixed|void
 */
function _c4m_organisation_load_by_dashboard_id($dashboard_id) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'organisation')
    ->fieldCondition('c4m_organisation_dashboard_id', 'value', $dashboard_id, '=')
    ->range(0,1);

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
 * @param $op
 *   One of view, update, create, delete per node_access().
 * @param $args
 *   Resource arguments passed through from the original request.
 * @return bool
 *
 * @see node_access()
 */
function _c4m_node_resource_access($op = 'view', $args = array()) {
  $a = 0;
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], 'node');
  }

  // Make sure we have an object or this all fails, some servers can
  // mess up the types.
  if (is_array($args[0])) {
    $args[0] = (object) $args[0];
  }
  elseif (!is_array($args[0]) && !is_object($args[0])) {  //This is to determine if it is just a string happens on node/%NID
    if (empty($node = _c4m_organisation_load_by_dashboard_id($args[0]))) {
      services_error(t('Node type is required'), 406);
    }
    $args[0] = (object)array('nid' => $node->nid);
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
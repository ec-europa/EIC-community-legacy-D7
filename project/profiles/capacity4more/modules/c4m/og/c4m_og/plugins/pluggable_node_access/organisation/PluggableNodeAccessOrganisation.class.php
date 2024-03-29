<?php

/**
 * @file
 * Contains \PluggableNodeAccessOrganisation.
 */

/**
 * Class PluggableNodeAccessOrganisation.
 */
class PluggableNodeAccessOrganisation extends PluggableNodeAccessBase {

  /**
   * {@inheritdoc}
   */
  public static function getNodeGrants($account = NULL, $op = 'view') {
    if (empty($account)) {
      global $user;
      $user_id = $user->uid;
    }
    else {
      $user_id = $account->uid;
    }
    // We need the full user object.
    $account = user_load($user_id);

    if (!$account->uid) {
      // Anonymous user.
      return array();
    }

    if ($op != 'view') {
      // Not a view operation.
      return array();
    }
    $realms = array();

    if (empty($account->og_user_node[LANGUAGE_NONE])) {
     return array();
    }
    $user_organisation_memberships = $account->og_user_node[LANGUAGE_NONE];


    $query = db_select('node', 'n');

    $query
      ->condition('n.status', 1, '=')
      ->condition('n.type', 'organisation', '=')
      ->condition('n.nid', $user_organisation_memberships, 'IN');

    $query->fields('n', array('title', 'nid'));

    $organisations = $query->execute()->fetchAll();

    foreach ($organisations as $organisation) {
      // The "realm" name is the plugin name.
      // The "gid" is always 1, as it just indicates the user has the email
      // domain.
      $realm = 'organisation::' . $organisation->nid;
      $realms[$realm] = array(1);
    }
    return $realms;
  }

  /**
   * {@inheritdoc}
   */
  public function getNodeAccessRecords() {
    $node = $this->getNode();

    if (empty($node->status)) {
      // Node is unpublished, so we don't allow every group member to see
      // it.
      return array();
    }

    $grants = array();
    $entities = $this->getAccessEntities('node', $node, 'organisation');
    $entities = array_unique($entities);
    foreach ($entities as $entity) {
      foreach ($entity->data as $organisation) {
        $realm = 'organisation::' . $organisation;
        $grants[] = array(
          'realm' => $realm,
          'gid' => 1,
          'grant_view' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 0,
        );
      }
    }

    return $grants;
  }

  /**
   * {@inheritdoc}
   */
  public function checkForNodeAccessChange() {
    foreach ($this->getAccessEntities() as $access_entity) {
      // Restricted access was changed to other kind of the restricted access.
      if ($access_entity->timestamp == REQUEST_TIME) {
        return TRUE;
      }
    }
    // Get editing node.
    $node = $this->getNode();
    $fields = $this->getReferenceFields($node);
    foreach ($fields as $field) {
      // Removed or added number of restricted access entities.
      if ($node->original->{$field} != $node->{$field}) {
        return TRUE;
      }
    }
    return FALSE;
  }

}

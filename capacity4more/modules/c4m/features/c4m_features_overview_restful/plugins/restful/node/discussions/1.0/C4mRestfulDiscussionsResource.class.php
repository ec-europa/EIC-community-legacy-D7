<?php

/**
 * @file
 * Contains C4mRestfulDiscussionsResource.
 */

class C4mRestfulDiscussionsResource extends RestfulEntityBaseNode {

  /**
   * Overrides \RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'c4m_body',
      'sub_property' => 'value',
    );

    $public_fields['group'] = array(
      'property' => OG_AUDIENCE_FIELD,
      'resource' => array(
        'group' => array(
          'name' => 'groups',
          'full_view' => FALSE,
        ),
      ),
    );

    $public_fields['discussion_type'] = array(
      'property' => 'c4m_discussion_type',
    );

    return $public_fields;
  }
}

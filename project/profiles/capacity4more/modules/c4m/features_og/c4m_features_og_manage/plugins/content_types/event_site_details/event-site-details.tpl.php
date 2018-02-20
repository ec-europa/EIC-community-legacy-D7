<?php

/**
 * @file
 * Template for the project management dashboard.
 */
?>

<div class="row project-management-dashboard">
  <div class="col-md-12 project-management-wrapper">
    <div class="project-administration">
      <div class="title">
        <h2><?php print t('Event site administration') ?></h2>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Owner') ?> (<a
            href="<?php print $details['owner_edit']; ?>"><?php print t(
              'Edit'
            ) ?></a>)
        </div>
        <div class="col-md-9"><?php print $details['owner']; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Administrators') ?> (<a
            href="<?php print $details['admins_edit']; ?>"><?php print t(
              'Edit'
            ) ?></a>)
        </div>
        <div class="col-md-9"><?php print $details['admins']; ?></div>
      </div>
    </div>
    <div class="project-details">
      <div class="title">
        <h2><?php print t('Event site details') ?></h2>
        <a href="<?php print $details['edit_link'] ?>#edit-details"><?php print t('Edit'); ?></a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site name') ?></div>
        <div class="col-md-9"><?php print (isset($details['title'])) ? $details['title'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site path') ?></div>
        <div class="col-md-9"><?php print (isset($details['purl'])) ? $details['purl'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site tag line') ?></div>
        <div class="col-md-9"><?php print isset($details['tagline']) ? $details['tagline'] : ''; ?></div>
      </div>
      <div class="row">
         <div class="col-md-3"><?php print t('Event site type') ?></div>
         <div class="col-md-9"><?php print isset($details['event_type']) ? $details['event_type'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site description') ?></div>
        <div class="col-md-9"><?php print isset($details['description']['value']) ? $details['description']['value'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organised by') ?></div>
        <div class="col-md-9"><?php print isset($details['organised_by']) ? $details['organised_by'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Registration URL') ?></div>
        <div class="col-md-9"><?php print (isset($details['url'])) ? $details['url'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Facebook Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['f_url'])) ? $details['f_url'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Twitter Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['t_url'])) ? $details['t_url'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Duration') ?></div>
        <div class="col-md-9"><?php print (isset($details['duration'])) ? $details['duration'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Location') ?></div>
        <div class="col-md-9"><?php print (isset($details['location'])) ? $details['location'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Agenda & information') ?></div>
        <div class="col-md-9"><?php print (isset($details['document_agenda'])) ? $details['document_agenda'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Presentations') ?></div>
        <div class="col-md-9"><?php print (isset($details['document_presentation'])) ? $details['document_presentation'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Additional') ?></div>
        <div class="col-md-9"><?php print (isset($details['related_document'])) ? $details['related_document'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site topics') ?></div>
        <div class="col-md-9"><div class="c4m-taxonomy-tree"><?php print (isset($details['topics'])) ? $details['topics'] : ''; ?></div></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Event site regions & countries') ?></div>
        <div class="col-md-9"><div class="c4m-taxonomy-tree"><?php print (isset($details['locations'])) ? $details['locations'] : ''; ?></div></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Related content') ?></h2>
        <a
          href="<?php print $details['edit_link'] ?>#edit-related-content"><?php print t(
            'Edit'
          ) ?> </a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Related Groups') ?></div>
        <div class="col-md-9"><?php print (isset($details['related_groups'])) ? $details['related_groups'] : ''; ?></div>
      </div>
    </div>
    <div class="project-related-content">
      <div class="title">
        <h2><?php print t('Categories') ?></h2>
        <?php print $details['taxonomy_manage_link'] ?>
      </div>
      <div class="row">
        <div class="col-md-12"><?php print t(
            'This project has <strong>@cat_count Categories</strong> and <strong>@term_count Terms</strong>',
            array(
              '@cat_count' => $details['categories_count'],
              '@term_count' => $details['terms_count'],
            )
          ) ?></div>
      </div>
    </div>
    <div class="project-features">
      <div class="title">
        <h2><?php print t('Features') ?></h2>
        <?php print $details['features_manage_link'] ?>
      </div>
      <?php foreach ($details['features_available'] as $feature) : ?>
        <div class="row">
          <div class="col-md-3"><?php print $feature['name']; ?></div>
          <div
            class="col-md-9"><?php print empty($details['features_enabled'][$feature['machine_name']]) ? t(
              'Disabled'
            ) : '<strong>' . t('Enabled') . '</strong>'; ?></div>
        </div>
      <?php endforeach; ?>
    </div>
    <div class="project-navigation">
      <div class="title">
        <h2><?php print t('Event site Navigation') ?></h2>
        <a href="<?php print $details['menu_link']; ?>"><?php print t(
            'Edit'
          ) ?></a>
      </div>
    </div>
  </div>
</div>

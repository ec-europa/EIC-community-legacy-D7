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
        <h2><?php print t('Organisation administration') ?></h2>
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
        <h2><?php print t('Organisation details') ?></h2>
        <a href="<?php print $details['edit_link'] ?>#edit-details"><?php print t('Edit'); ?></a>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organisation name') ?></div>
        <div class="col-md-9"><?php print (isset($details['title'])) ? $details['title'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organisation path') ?></div>
        <div class="col-md-9"><?php print (isset($details['purl'])) ? $details['purl'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organisation tag line') ?></div>
        <div class="col-md-9"><?php print isset($details['tagline']) ? $details['tagline'] : ''; ?></div>
      </div>
      <div class="row">
         <div class="col-md-3"><?php print t('Organisation type') ?></div>
         <div class="col-md-9"><?php print isset($details['c4m_organisations_type']) ? $details['c4m_organisations_type'] : ''; ?></div>
      </div>
      <div class="row">
         <div class="col-md-3"><?php print t('Organisation size') ?></div>
         <div class="col-md-9"><?php print isset($details['c4m_organisation_size']) ? $details['c4m_organisation_size'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organisation description') ?></div>
        <div class="col-md-9"><?php print isset($details['description']) ? $details['description'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Organisation website') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_link'])) ? $details['c4m_link'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Facebook Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_facebook'])) ? $details['c4m_facebook'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Twitter Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_twitter'])) ? $details['c4m_twitter'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('YouTube Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_youtube'])) ? $details['c4m_youtube'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('LinkedIn Page') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_linkedin'])) ? $details['c4m_linkedin'] : ''; ?></div>
      </div>

      <div class="row">
        <div class="col-md-3"><?php print t('Location') ?></div>
            <div class="col-md-9"><?php print (isset($details['c4m_location_address'])) ? $details['c4m_location_address'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Countries based in') ?></div>
            <div class="col-md-9"><?php print (isset($details['c4m_vocab_geo'])) ? $details['c4m_vocab_geo'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Countries selling to') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_vocab_geo_selling'])) ? $details['c4m_vocab_geo_selling'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Email') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_email'])) ? $details['c4m_email'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Phone') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_phone'])) ? $details['c4m_phone'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Contact persons') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_contact_persons'])) ? $details['c4m_contact_persons'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Date of establishment') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_date_est'])) ? $details['c4m_date_est'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Product/service type') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_product_service_type'])) ? $details['c4m_product_service_type'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Target markets') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_target_markets'])) ? $details['c4m_target_markets'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Offering') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_offering'])) ? $details['c4m_offering'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Looking for') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_looking_for'])) ? $details['c4m_looking_for'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Topics') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_vocab_topic'])) ? $details['c4m_vocab_topic'] : ''; ?></div>
      </div>
      <div class="row">
        <div class="col-md-3"><?php print t('Qualitative attributes') ?></div>
        <div class="col-md-9"><?php print (isset($details['c4m_qualitative_attributes'])) ? $details['c4m_qualitative_attributes'] : ''; ?></div>
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
        <h2><?php print t('Organisation Navigation') ?></h2>
        <a href="<?php print $details['menu_link']; ?>"><?php print t(
            'Edit'
          ) ?></a>
      </div>
    </div>
  </div>
</div>

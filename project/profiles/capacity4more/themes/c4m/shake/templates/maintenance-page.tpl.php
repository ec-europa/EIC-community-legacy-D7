<?php

/**
 * @file
 * Copy of system/maintenane-page.tpl.php.
 *
 * Add markup from the html.tpl.php and page.tpl.php inside this theme and base
 * theme.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<!-- TODO -->
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">

<section class="page-container">

  <header id="page-header" role="banner">
    <div id="header-ec-wrapper">
      <div class="container">
        <div class="header-logo">
          <?php if ($logo): ?>
            <a class="logo pull-left" href="<?php print $front_page; ?>"
              title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('EU Flag'); ?>" title="<?php print t('EU Flag'); ?>"/>
            </a>
          <?php endif; ?>
          <div class="site-name-slogan">
            <h1><?php print (!empty($site_name)) ? $site_name : ''; ?></h1>
            <h2><?php print (!empty($site_slogan)) ? $site_slogan : ''; ?></h2>
          </div>
        </div>
      </div>
    </div><!-- /banner-ec -->

    <div id="ecl-page-header">
      <div class="container">
        <div class="header-breadcrumb">
        </div>
      </div>
    </div>
  </header>

  <div id="main-wrapper">
    <div class="container">
      <div class="page-content">
        <?php if (!empty($title)): ?>
          <h1 class="title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print $content; ?>
      </div>
    </div>
  </div>

</section>


</body>
</html>

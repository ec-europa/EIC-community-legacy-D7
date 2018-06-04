<?php

/**
 * @file
 * Template for presenting footer.
 */
?>

<div class="ecl-footer__corporate-top">
    <div class="ecl-container">
        <div class="ecl-row">
            <div class="ecl-footer__column ecl-col-md">
                <h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-about-ec"><?php print t('European Commission');?></h2>
                <?php print $left_column;?>
            </div>
            <div class="ecl-footer__column ecl-col-md">
                <h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-social-media"><?php print t('Follow the European Commission');?></h2>
                <?php print $social_media;?>
            </div>
            <div class="ecl-footer__column ecl-col-md">
                <h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-about-eu"><?php print t('European Union');?></h2>
                <?php print $right_column;?>
            </div>
        </div>
    </div>
</div>
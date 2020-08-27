/**
 * @file
 * Dealroom matching tool functionality.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
  "use strict";

  $(document).ready(function() {
    $(".open-dealroom-trigger").click(function() {
      event.preventDefault();
      $(this).after('<p><a class="dealroom-sdk__link" data-widget="matchingTool" href="https://app.dealroom.co/target-investors"></a></p>');
      $.getScript("https://platform.dealroom.co/sdk.js");
      $(this).hide();
    });
  });

})
(jQuery);

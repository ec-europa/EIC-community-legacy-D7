/**
 * @file
 * Dealroom matching tool functionality.
 */

var Drupal = Drupal || {};
var jQuery = jQuery || {};

(function ($) {
  "use strict";

  $(document).ready(function() {
    $(".external-content-approval .open-dealroom-trigger").click(function() {
      event.preventDefault();
      var parent = $(this).closest('.external-content-approval');
      parent.after('<p><a class="dealroom-sdk__link" data-widget="matchingTool" href="https://app.dealroom.co/target-investors"></a></p>');
      $.getScript("https://platform.dealroom.co/sdk.js");
      parent.hide();
    });
  });

})
(jQuery);

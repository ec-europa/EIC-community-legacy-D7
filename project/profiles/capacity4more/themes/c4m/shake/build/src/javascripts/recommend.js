(function ($) {
    MutationObserver = window.MutationObserver || window.WebKitMutationObserver;
    var observer = new MutationObserver(function(mutations, observer) {
        // Check if there is at least one flag on the page.
        if ($('.flag-wrapper').length > 0) {
            Drupal.flagLink();
            Drupal.behaviors.increaseDecrease.attach();
        }
    });

    observer.observe(document, {
        subtree: true,
        attributes: true
    });

    function decrease(flag) {
        var count = flag.closest('.count-recommends').find('.like-count');
        var counter = parseInt(count.text());
        counter--;
        count.text(counter);
        flag.addClass('counter-processed');
    }

    function increase(flag) {
        var count = flag.closest('.count-recommends').find('.like-count');
        var counter = parseInt(count.text());
        counter++;
        count.text(counter);
        flag.addClass('counter-processed');
    }

    Drupal.behaviors.increaseDecrease = {};
    Drupal.behaviors.increaseDecrease.attach = function(context) {

        $('.flag-wrapper a.unflag-action').one('click', function(event) {
            if (!$(this).hasClass('counter-processed')){
                decrease($(this));
            }
        });
        $('.flag-wrapper a.flag-action').one('click', function(event) {
            if (!$(this).hasClass('counter-processed')){
                increase($(this));
            }
        });
    };

})(jQuery, Drupal);

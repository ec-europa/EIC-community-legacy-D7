/**
 * @file
 * Kapablo theme global behaviours.
 */

var Drupal = Drupal || {};

(function ($) {
    "use strict";

    /**
     * Add proper bootstrap classes to the discussion type selector on the node form of discussions.
     *
     * @type {{attach: Drupal.behaviors.eventFormClasses.attach}}
     */
    Drupal.behaviors.discussionFormClasses = {
        attach: function () {
            var discussionTypes = $("#edit-c4m-discussion-type-und");

            discussionTypes.addClass("row");

            $("input:radio", discussionTypes).each((function () {
                var value = $(this).attr("value");
                // Target the label.
                var parent = $(this).parent();
                parent.addClass("discussion-type-button")
                    .addClass("discussion-type-" + value);
                // Target the wrapper div.
                parent.parent()
                    .addClass("col-xs-6")
                    .addClass("col-sm-3");
            }));
        }
    };

    /**
     * Add proper bootstrap classes to the event type selector on the node form of events.
     *
     * @type {{attach: Drupal.behaviors.eventFormClasses.attach}}
     */
    Drupal.behaviors.eventFormClasses = {
        attach: function () {
            var eventTypes = $("#edit-c4m-event-type-und");

            eventTypes.addClass("row");

            $("input:radio", eventTypes).each((function () {
                var value = $(this).attr("value");
                // Target the label.
                var parent = $(this).parent();
                parent.addClass("event-type-button")
                    .addClass("event-type-" + value);
                // Target the wrapper div.
                parent.parent().addClass("col-xs-4");

            }));
        }
    };

    /**
     * Attach the YouTube iFrame API on the front page (for anonymous users) for the promo video.
     *
     * @type {{attach: Drupal.behaviors.youTubeVideo.attach}}
     */
    Drupal.behaviors.youTubeVideo = {
        attach: function () {
            var tag, firstScriptTag;

            // Only attach IFrame API on frontpage for anonymous users.
            if ($("body").is(".front, .not-logged-in")) {
                // Inject YouTube IFrame API script.
                tag = document.createElement("script");
                tag.src = "https://www.youtube.com/iframe_api";
                firstScriptTag = document.getElementsByTagName("script")[0];
                firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
            }
        }
    };

    /**
     * Allow wiki pages to be displayed in "fullscreen" mode, and save this state when clicking other pages.
     *
     * @type {{attach: Drupal.behaviors.sidebarCollapseExpand.attach}}
     */
    Drupal.behaviors.sidebarCollapseExpand = {
        attach: function () {
            var url = location.href;
            var fullscreen = _getParameter(url, "fullscreen");
            var sidebar = $("#collapse-sidebar");
            var navLinks = $(".og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a, .book-navigation a");

            if (fullscreen === "1") {
                collapseSidebar(sidebar);
            }

            sidebar.on("click", (function () {
                var buttonClasses = $(this).attr("class");
                // If the button has the "collapsed" class: expand the sidebar, otherwise collapse it.
                if (buttonClasses.indexOf("collapsed") >= 0) {
                    expandSidebar($(this), navLinks);
                }
                else {
                    collapseSidebar($(this), navLinks);
                }
            }));

            /**
             * Collapse the sidebar in the Wiki pages.
             *
             * Changes classes of the right and left column,
             * hides the content in the sidebar.
             *
             * @param button
             *  The clicked button element.
             */
            function collapseSidebar(button, navLinks) {
                var groupLeft = $(".group-left");
                var groupRight = $(".group-right");
                var href;

                button.addClass("collapsed");
                button.html("<i class=\"fa fa-chevron-circle-right\"></i>");
                groupLeft.removeClass("col-sm-4").addClass("col-sm-1 sidebar-collapsed");
                groupRight.removeClass("col-sm-8").addClass("col-sm-11");

                $(navLinks).each((function () {
                    href = _addParameter($(this).attr("href"), "fullscreen", "1");
                    $(this).attr("href", href);
                }));
            }

            /**
             * Expand the sidebar in the Wiki pages.
             *
             * Changes classes of the right and left column,
             * shows the content in the sidebar.
             *
             * @param button
             *  The clicked button element.
             */
            function expandSidebar(button, navLinks) {
                var groupLeft = $(".group-left");
                var groupRight = $(".group-right");
                var href;
                var sidebarContent = $(".collapsible");

                button.removeClass("collapsed");
                button.html("<i class=\"fa fa-chevron-circle-left\"></i> " + Drupal.t("Hide sidebar"));
                groupLeft.removeClass("col-sm-1 sidebar-collapsed").addClass("col-sm-4");
                groupRight.removeClass("col-sm-11").addClass("col-sm-8");
                sidebarContent.show();

                $(navLinks).each((function () {
                    href = _removeURLParameter($(this).attr("href"), "fullscreen");
                    $(this).attr("href", href);
                }));
            }
        }
    };

    Drupal.behaviors.wikiPagesSubNavigation = {
        attach: function (context, settings) {
            var $wrapper = $('#group-pages-navigation-left');

            if ($wrapper == null) {
                return;
            }

            collapsibleNavigation($wrapper.find('ul[role="menu"]'));

            // .wrapInner() does not retain bound events.
            var wrapper = $wrapper.get(0);

            if (wrapper == null) {
                return;
            }

            var url = location.href;
            var collapsed = _getParameter(url, 'collapsed');

            var nav_links = $('.og-menu-link.wiki .c4m-book-og-menu-link, #group-pages-navigation-left .field-name-c4m-content-wiki-page-navigation a, .book-navigation a');
            var href;

            $('.field-group-format-title', wrapper).on("click", function () {
                if ($(wrapper).hasClass("collapsed")) {
                    $(nav_links).each(function () {
                        href = _addParameter($(this).attr('href'), 'collapsed', '1');
                        $(this).attr('href', href);
                    });
                }
                else {
                    $(nav_links).each(function () {
                        href = _removeURLParameter($(this).attr('href'), 'collapsed');
                        $(this).attr('href', href);
                    });
                }
            });

            if (collapsed !== '1') {
                toggleSubpages(wrapper);
            }

            else {
                $(nav_links).each(function () {
                    href = _addParameter($(this).attr('href'), 'collapsed', '1');
                    $(this).attr('href', href);
                });
            }

            function toggleSubpages(wrapper) {
                if (!wrapper.animating || wrapper.animating == null) {
                    wrapper.animating = true;
                    var speed = $wrapper.hasClass('speed-fast') ? 300 : 1000;
                    if ($wrapper.hasClass('effect-none') && $wrapper.hasClass('speed-none')) {
                        $('> .field-group-format-wrapper', wrapper).toggle();
                    }
                    else if ($wrapper.hasClass('effect-blind')) {
                        $('> .field-group-format-wrapper', wrapper).toggle('blind', {}, speed);
                    }
                    else {
                        $('> .field-group-format-wrapper', wrapper).toggle(speed);
                    }
                    wrapper.animating = false;
                    $wrapper.toggleClass('collapsed');

                    return false;
                }
            }
        }
    };

    Drupal.behaviors.initTooltips = {
        attach: function (context, settings) {
            var tooltips = $('[data-toggle="tooltip"]');
            tooltips.tooltip();
        }
    };

    Drupal.behaviors.initDropdowns = {
        attach: function (context, settings) {
            $('.dropdown-toggle').dropdown();
        }
    };

    Drupal.behaviors.jumpToTitle = {
        attach: function (context, settings) {
            // Do this only once.
            if (context !== document) {
                return;
            }

            if (settings.c4m && !settings.c4m.jumpToTitle) {
                return;
            }

            // We have to use setTimeout because:
            // - for some reason when attaching the behaviour h1 has the scroll top
            //   value of 0. Only on $(document).ready() it has the right value.
            // - we have to let admin menu to do its thing.
            var timeout = 0;
            var $body = $('body');
            if ($body.hasClass('admin-menu')) {
                timeout = 500;
            }

            setTimeout(function () {
                // Don't do anything if the user already scrolled to a different
                // position.
                if ($body.scrollTop() !== 0) {
                    return;
                }
                $('html, body').animate({
                    scrollTop: parseInt($('h1').offset().top) + 'px'
                }, 100);
            }, timeout);
        }
    };

    Drupal.behaviors.fixLeafletMaps = {
        attach: function (context, settings) {
            setTimeout(function () {
                if (typeof settings.leaflet != 'undefined' && settings.leaflet instanceof Array) {
                    settings.leaflet[0].lMap.invalidateSize(false);
                }
            }, 100);
        }
    };

    Drupal.behaviors.registration = {
        attach: function (context, settings) {
            $('.use-another-email', context).click(function () {
                $('input[name="mail"]').val('').focus();
                return false;
            });

            $('#user-register-form').submit(function () {
                $(':disabled', this).prop('disabled', false);
            });
        }
    };

    $(window).bind("load", function () {
        // After ajax processing, the form often gets the id "user-register--2" or similar.
        $('[id^=user-register] input[name="mail"]').focus();
    });

    // Disable form buttons on AJAX calls.
    $(document)
        .ajaxStart(function () {
            $('.form-submit').addClass('drupal-ajax-disabled').attr('disabled', 'disabled');
        })
        .ajaxComplete(function () {
            $('.drupal-ajax-disabled').removeAttr('disabled');
        });

    function collapsibleNavigation(element) {
        var element = $(element);

        element.find('li.expanded').each(function (index, el) {
            var el = $(el);
            var subnav = el.find('> .collapse');
            if (subnav.hasClass('in')) {
                el.find('> a > i').removeClass('fa-caret-right').addClass('fa-caret-down');
            }
        });

        element.find('[data-toggle="collapse"]').on('click', function (e) {
            e.preventDefault();

            var $this = $(this);

            var target = $this.data('target');
            var sub_navigation = $(target);

            sub_navigation.toggleClass('in');

            if ($this.hasClass('fa-caret-right')) {
                $this.removeClass('fa-caret-right');
                $this.addClass('fa-caret-down');
            }
            else if ($this.hasClass('fa-caret-down')) {
                $this.removeClass('fa-caret-down');
                $this.addClass('fa-caret-right');
            }

            return false;
        });
    }

    /**
     * Remove a parameter from an URL string.
     *
     * @param url
     *   Url or path to remove parameter from.
     * @param parameter
     *   Name of the parameter to remove.
     *
     * @returns {*}
     *
     * @private
     */
    function _removeURLParameter(url, parameter) {
        // Prefer to use l.search if you have a location/link object.
        var urlparts = url.split('?');
        if (urlparts.length >= 2) {

            var prefix = encodeURIComponent(parameter) + '=';
            var pars = urlparts[1].split(/[&;]/g);

            // Reverse iteration as may be destructive.
            for (var i = pars.length; i-- > 0;) {
                // Idiom for string.startsWith.
                if (pars[i].lastIndexOf(prefix, 0) !== -1) {
                    pars.splice(i, 1);
                }
            }

            if (pars.length > 0) {
                url = urlparts[0] + '?' + pars.join('&');
            }
            else {
                url = urlparts[0];
            }

            return url;
        }
        else {
            return url;
        }
    }

    /**
     * Add a parameter to an URL string.
     *
     * @param url
     *   Url or path to add parameter to.
     * @param parameterName
     *   Name of the parameter to add.
     * @param parameterValue
     *   Value to give the parameter.
     *
     * @returns {string}
     *
     * @private
     */
    function _addParameter(url, parameterName, parameterValue) {
        var replaceDuplicates = true;
        var urlhash;
        var cl;

        if (url.indexOf('#') > 0) {
            cl = url.indexOf('#');
            urlhash = url.substring(url.indexOf('#'), url.length);
        }
        else {
            urlhash = '';
            cl = url.length;
        }
        var sourceUrl = url.substring(0, cl);

        var urlParts = sourceUrl.split("?");
        var newQueryString = "";

        if (urlParts.length > 1) {
            var parameters = urlParts[1].split("&");
            for (var i = 0; (i < parameters.length); i++) {
                var parameterParts = parameters[i].split("=");
                if (!(replaceDuplicates && parameterParts[0] === parameterName)) {
                    if (newQueryString === "") {
                        newQueryString = "?";
                    }
                    else {
                        newQueryString += "&";
                    }
                    newQueryString += parameterParts[0] + "=" + (parameterParts[1] ? parameterParts[1] : '');
                }
            }
        }
        if (newQueryString === "") {
            newQueryString = "?";
        }

        if (newQueryString !== "" && newQueryString !== '?') {
            newQueryString += "&";
        }
        newQueryString += parameterName + "=" + (parameterValue ? parameterValue : '');
        return urlParts[0] + newQueryString + urlhash;
    };

    function _getParameter(url, parameter) {
        var urlParts = url.split("?");

        if (urlParts.length > 1) {
            var parameters = urlParts[1].split("&");
            for (var i = 0; (i < parameters.length); i++) {
                var parameterParts = parameters[i].split("=");
                if (parameterParts[0] === parameter) {
                    return parameterParts[1];
                }
            }
        }
    };

})
(jQuery);

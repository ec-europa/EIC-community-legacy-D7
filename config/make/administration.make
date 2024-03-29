core = 7.x
api = 2

; Modules to make the life of a Drupal admin more pleasant.

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc6"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.7"

projects[adminimal_admin_menu][subdir] = "contrib"
projects[adminimal_admin_menu][version] = "1.7"
; https://www.drupal.org/node/2598278
projects[adminimal_admin_menu][patch][] = https://www.drupal.org/files/issues/adminimal_admin_menu-js-error-2407007-3-no-whitespace-changes.patch
projects[adminimal_admin_menu][patch][] = https://www.drupal.org/files/issues/adminimal_admin_menu-js-error-2407007-3.patch

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.2"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.0-beta2"

projects[blockreference][subdir] = "contrib"
projects[blockreference][version] = "2.7"

projects[chr][subdir] = "contrib"
projects[chr][version] = "1.x-dev"

projects[context][subdir] = "contrib"
projects[context][version] = "3.10"

projects[context_block_disable][subdir] = "contrib"
projects[context_block_disable][version] = "2.1"

projects[context_local_tasks][subdir] = "contrib"
projects[context_local_tasks][version] = "1.0-alpha1"

projects[context_no_title][subdir] = "contrib"
projects[context_no_title][version] = "1.0"

projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"

projects[eu_cookie_compliance][subdir] = "contrib"
projects[eu_cookie_compliance][version] = "1.18"

projects[elysia_cron][subdir] = "contrib"
projects[elysia_cron][version] = "2.8"

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.7"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.30"

projects[file_download_count][subdir] = "contrib"
projects[file_download_count][version] = "1.0-rc1"
projects[file_download_count][patch][] = "../patches/file-download-count-skip-download-count.patch"

projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][version] = "1.8"

projects[mefibs][subdir] = "contrib"
projects[mefibs][version] = "1.x-dev"

projects[masquerade][subdir] = "contrib"
projects[masquerade][version] = "1.0-rc7"

projects[plupload][subdir] = "contrib"
projects[plupload][version] = "2.x-dev"

projects[save_draft][subdir] = "contrib"
projects[save_draft][version] = "1.4"

projects[smart_trim][subdir] = "contrib"
projects[smart_trim][version] = "1.6"

projects[jquery_expander][subdir] = "contrib"
projects[jquery_expander][version] = "1.0"

projects[summary_settings][subdir] = "contrib"
projects[summary_settings][version] = "1.x-dev"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[ds][subdir] = "contrib"
projects[ds][version] = "2.16"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.x-dev"
projects[flag][patch][] = "../patches/flag-array-check-1925922.patch"
projects[flag][patch][] = https://www.drupal.org/files/issues/2019-07-16/3067469_php_7.2_issues.patch

projects[node_gallery][subdir] = "contrib"
projects[node_gallery][version] = "1.x-dev"
projects[node_gallery][patch][] = "../patches/node-gallery-unpublished-frontend.patch"

projects[queue_ui][subdir] = "contrib"
projects[queue_ui][version] = "2.x-dev"

projects[restful][subdir] = "contrib"
projects[restful][version] = "1.10"
projects[restful][patch][] = "../patches/restful-fix-rr.patch"

projects[shield][subdir] = "contrib"
projects[shield][version] = "1.3"

projects[smtp][subdir] = "contrib"
projects[smtp][version] = "1.x-dev"
projects[smtp][patch][] = "../patches/smtp-smtp_reroute_address-default-value.patch"

projects[term_reference_tree][subdir] = "contrib"
projects[term_reference_tree][version] = "1.11"

projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.2"
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/views_data_export-permanent-files-1875456-63-beta9-do-not-test.patch
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/2020-03-05/views_data_export-gtid_replicate-2209853-27.patch

; Themes to upgrade the admin backend.

projects[adminimal_theme][subdir] = "contrib"
projects[adminimal_theme][version] = "1.25"
projects[adminimal_theme][type] = "theme"

; Libraries

libraries[select2][type] = "libraries"
libraries[select2][download][type] = "file"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/4.0.2.zip"

libraries[plupload][download][type]= "get"
libraries[plupload][download][url] = "https://github.com/moxiecode/plupload/archive/v2.2.1.zip"
libraries[plupload][directory_name] = "plupload"
libraries[plupload][destination] = "libraries"

libraries[leaflet_draw][download][type]= "get"
libraries[leaflet_draw][download][url] = "https://github.com/Leaflet/Leaflet.draw/archive/v1.0.4.zip"
libraries[leaflet_draw][directory_name] = "Leaflet.draw"
libraries[leaflet_draw][destination] = "libraries"

core = 7.x
api = 2

; Modules related to exporting/importing configuration.

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.4"

projects[features][subdir] = "contrib"
projects[features][version] = "2.11"
projects[features][patch][] = https://www.drupal.org/files/issues/features-user_permission_reset_cache-2334409-6.patch
projects[features][patch][] = https://www.drupal.org/files/issues/features-add_pre_post_install_hooks-2479689-4.patch

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"



projects[menu_per_role][subdir] = "contrib"
projects[menu_per_role][version] = "1.0"

projects[elements][subdir] = "contrib"
projects[elements][version] = "1.5"

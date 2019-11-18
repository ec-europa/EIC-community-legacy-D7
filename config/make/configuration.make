core = 7.x
api = 2

; Modules related to exporting/importing configuration.

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.4"

projects[features][subdir] = "contrib"
projects[features][version] = "2.11"
projects[features][patch][] = https://www.drupal.org/files/issues/features-user_permission_reset_cache-2334409-6.patch

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

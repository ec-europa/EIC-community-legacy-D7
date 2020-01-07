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

projects[node_view_permissions][subdir] = "contrib"
projects[node_view_permissions][version]  = 1.x-dev
; projects[node_view_permissions][download][type] = "git"
; projects[node_view_permissions][download][url] = "https://git.drupal.org/project/node_view_permissions.git"
; projects[node_view_permissions][download][revision] = "6012e87a7c05c6fc47f0cccf4dc8f99b72585e15"
;projects[node_view_permissions][patch][] = "../patches/node_view_permissions-deny_anonymous_access.patch"

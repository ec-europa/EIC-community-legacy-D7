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

projects[node_view_permissions][subdir] = "contrib"
projects[node_view_permissions]["version"] = "1.6"
projects[node_view_permissions][download][type] = "git"
projects[node_view_permissions][download][url] = "https://git.drupal.org/project/node_view_permissions.git"
projects[node_view_permissions][download][revision] = "a0e5dfd9ac6f8dac6cad1202c23a69dd3d12ddc6"



projects[menu_per_role][subdir] = "contrib"
projects[menu_per_role][version] = "1.0"

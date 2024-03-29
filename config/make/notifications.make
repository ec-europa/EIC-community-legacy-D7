core = 7.x
api = 2

; Notifications stack.

projects[mailsystem][version] = "2.35"
projects[mailsystem][subdir] = "contrib"

projects[message][subdir] = "contrib"
projects[message][version] = "1.12"

projects[message_subscribe][subdir] = "contrib"
projects[message_subscribe][version] = "1.x-dev"
projects[message_subscribe][download][url] = "http://git.drupal.org/project/message_subscribe.git"
projects[message_subscribe][download][revision] = "ab6bb5c68ef0fd85ba4446d8e6ec510fbe3cc239"
projects[message_subscribe][patch][] = "https://www.drupal.org/files/issues/prevent_loop_of_message-2303795-12.patch"
projects[message_subscribe][patch][] = "../patches/message_subscribe_assign_uids_on_start.patch"

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[mimemail][version] = "1.2"
projects[mimemail][subdir] = "contrib"

projects[reroute_email][version] = "1.2"
projects[reroute_email][subdir] = "contrib"

projects[ajax_comments][version] = "1.3"
projects[ajax_comments][subdir] = "contrib"

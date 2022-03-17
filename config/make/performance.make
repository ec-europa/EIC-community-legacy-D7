core = 7.x
api = 2

; Performance optimizations

projects[memcache][subdir] = "contrib"
projects[memcache][version] = "1.8"
projects[memcache][patch][] = https://www.drupal.org/files/issues/2020-07-27/3161631-memcache-cli-string.patch

projects[chained_fast][subdir] = "contrib"
projects[chained_fast][version] = "1.0-beta1"

projects[apcu][subdir] = "contrib"
projects[apcu][version] = "1.0-beta1"

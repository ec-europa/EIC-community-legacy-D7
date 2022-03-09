core = 7.x
api = 2

; Contrib field definitions

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.3"

projects[currency][subdir] = "contrib"
projects[currency][version] = "2.6"

projects[date][subdir] = "contrib"
projects[date][version] = "2.12"

projects[dragndrop_upload][subdir] = "contrib"
projects[dragndrop_upload][version] = "1.x-dev"

projects[email][subdir] = "contrib"
projects[email][version] = "1.3"

projects[telephone][subdir] = "contrib"
projects[telephone][version] = "1.0-alpha1"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.6"

projects[geocoder][subdir] = "contrib"
projects[geocoder][version] = "1.4"

projects[geophp][subdir] = "contrib"
projects[geophp][version] = "1.7"

projects[geofield][subdir] = "contrib"
projects[geofield][version] = "2.4"

projects[hierarchical_taxonomy][subdir] = "contrib"
projects[hierarchical_taxonomy][version] = "1.x-dev"

projects[leaflet][subdir] = "contrib"
projects[leaflet][version] = "1.4"

projects[link][subdir] = "contrib"
projects[link][version] = "1.6"

projects[maxlength][subdir] = "contrib"
projects[maxlength][version] = "3.3"

projects[money][subdir] = "contrib"
projects[money][version] = "1.x-dev"

projects[paragraphs][subdir] = "contrib"
projects[paragraphs][version] = "1.0-rc5"
projects[paragraphs][patch][] = "https://www.drupal.org/files/issues/paragraphs-fix_parents_access-2562463-20-7.x.patch"
projects[paragraphs][patch][] = "../patches/rename_to_submit_new_paragraph_form.patch"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.x-dev"

projects[weight][subdir] = "contrib"
projects[weight][version] = "3.1"

projects[content_taxonomy][subdir] = "contrib"
projects[content_taxonomy][version] = "1.0-rc1"

libraries[leaflet][download][type]= "get"
libraries[leaflet][download][url] = "http://cdn.leafletjs.com/leaflet/v0.7.7/leaflet.zip"
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][destination] = "libraries"

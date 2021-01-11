core = 7.x
api = 2

; CKEditor

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = "1.19"

projects[media_ckeditor][subdir] = "contrib"
projects[media_ckeditor][version] = "2.14"
projects[media_ckeditor][patch][] = "../patches/media_ckeditor-image_resize_fix.patch"

projects[wysiwyg_filter][subdir] = "contrib"
projects[wysiwyg_filter][version] = "1.6-rc9"

libraries[ckeditor][download][type]= "get"
libraries[ckeditor][download][url] = "https://download.cksource.com/CKEditor/CKEditor/CKEditor%204.14.0/ckeditor_4.14.0_full.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

projects[iframeremove][subdir] = "contrib"
projects[iframeremove][version] = "1.4"
projects[iframeremove][patch][] = "../patches/suppress-invalid-dom-messages.patch"

projects[pathologic][subdir] = "contrib"
projects[pathologic][version] = "3.1"

SUBDIRS = language \
po \
rhythmbox \
voxforge \
gnome \
libreoffice \
firefox \
terminal

ACLOCAL_AMFLAGS = -I m4

readmedir=$(datadir)/@SHARE_FOLDER@/language
dist_readme_DATA = \
../README.md

##### files to be included in 'make dist'
EXTRA_DIST = \
build-aux/config.rpath \
$(dist_readme_DATA)


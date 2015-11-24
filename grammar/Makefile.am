SUBDIRS = po rhythmbox

ACLOCAL_AMFLAGS = -I m4

datafilesdir=$(datadir)/@SHARE_FOLDER@/language
dist_datafiles_DATA = \
language/en_tiedlist \
language/en_hmmdefs \
language/en_voxforgedict.txt \
language/en_voxshell.jconf \
language/en_grammar_list

##### files to be included in 'make dist'
EXTRA_DIST = \
build-aux/config.rpath \
$(dist_datafiles_DATA)


if  VF_WINDOWS
MAYBE_GRAM = windows
else

if  VF_LINUX
MAYBE_GRAM = grammars
endif

endif
SUBDIRS = $(MAYBE_GRAM)

LANGROOT=$(datadir)/@SHARE_FOLDER@/en

##### files to be included in 'make install'
langrootdir=$(LANGROOT)
# target           = source
dist_langroot_DATA = voxshell.jconf ../../README.md

acousticmodeldir=$(datadir)/@SHARE_FOLDER@/en/acoustic_model
dist_acousticmodel_DATA = \
acoustic_model/tiedlist \
acoustic_model/hmmdefs 

lexicondir=$(datadir)/@SHARE_FOLDER@/en/lexicon
dist_lexicon_DATA = \
lexicon/VoxForgeDict.txt

##### files to be included in 'make dist'
EXTRA_DIST = \
$(dist_langroot_DATA) \
$(dist_acousticmodel_DATA) \
$(dist_lexicon_DATA)


APP=rhythmbox
APPSCRIPTS= \
scripts/dbus_fastforward.sh \
scripts/dbus_rewind.sh \
scripts/search.sh \
scripts/show.sh
# compile source code
#bin_PROGRAMS = rhythmbox_voxcreate
noinst_PROGRAMS = rhythmbox_voxcreate
rhythmbox_voxcreate_SOURCES = rhythmbox_voxcreate.c 
LDADD = $(LIBINTL) ../lib/libget_parameters.la

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"

# compile grammars
SOURCES= $(APP).vox $(APP).grammar
TARGETS= $(APP).dict $(APP).term $(APP).dfa
CLEANFILES=$(TARGETS)

VF_ROOT=$(abs_top_builddir)/@VOXSHELL_SOURCE_ROOT@
GRAMMAR_FOLDER=@GRAM_SOURCE_DIR@/$(APP)

all: $(TARGETS) 

# so it doesn't try to run this script 3 times, one for each target
.NOTPARALLEL: $(TARGETS)
 
$(TARGETS): rhythmbox_voxcreate $(SOURCES) 
	./rhythmbox_voxcreate --grammar @GRAMMAR_ROOT@ > rhythmbox.vox
	cd $(VF_ROOT) && julia @COMPILE_GRAMMAR@ $(GRAMMAR_FOLDER) $(APP) @MKFA@ @DFA_MINIMIZE@ @VOXFORGE_DICT@

##### files to be included in 'make install'
appdir=$(datadir)/@GRAM_INST_DIR@/$(APP)
dist_app_DATA = $(TARGETS)

appscriptdir=$(datadir)/@GRAM_INST_DIR@/$(APP)/scripts
dist_appscript_SCRIPTS = $(APPSCRIPTS)

##### files to be included in 'make dist'
EXTRA_DIST = \
$(SOURCES) \
$(TARGETS) \
$(APPSCRIPTS) 




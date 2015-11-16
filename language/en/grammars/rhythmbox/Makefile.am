APP=rhythmbox
APPSCRIPTS= \
scripts/dbus_fastforward.sh \
scripts/dbus_rewind.sh \
scripts/search.sh \
scripts/show.sh

SOURCES= $(APP).vox $(APP).grammar
TARGETS= $(APP).dict $(APP).term $(APP).dfa
CLEANFILES=$(TARGETS)

VF_ROOT=$(abs_top_builddir)/@VOXSHELL_SOURCE_ROOT@
GRAMMAR_FOLDER=@GRAM_SOURCE_DIR@/$(APP)

all: $(TARGETS) 

# so it doesn't try to run this script 3 times, one for each target
.NOTPARALLEL: $(TARGETS)

$(TARGETS): $(SOURCES)
	cd $(VF_ROOT) && julia @COMPILE_GRAMMAR@ $(GRAMMAR_FOLDER) $(APP) @MKFA_DIR@ @DFA_MINIMIZE_DIR@ @VOXFORGE_DICT@

##### files to be included in 'make install'
appdir=$(datadir)/@GRAM_INST_DIR@/$(APP)
dist_app_SCRIPTS = $(TARGETS)

appscriptdir=$(datadir)/@GRAM_INST_DIR@/$(APP)/scripts
dist_appscript_DATA = $(APPSCRIPTS)

##### files to be included in 'make dist'
EXTRA_DIST = \
$(SOURCES) \
$(TARGETS) \
$(APPSCRIPTS) 

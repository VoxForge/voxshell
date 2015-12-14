APP=firefox
APPSCRIPTS= \
scripts/page_down.sh \
scripts/page_up.sh \
scripts/start.sh

# compile source code
noinst_PROGRAMS = firefox_voxcreate
firefox_voxcreate_SOURCES = firefox_voxcreate.c 
LDADD = $(LIBINTL) ../lib/libget_parameters.la

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"

# compile grammars
SOURCES= $(APP).vox $(APP).grammar
TARGETS= $(APP).dict $(APP).term $(APP).dfa
CLEANFILES=$(TARGETS) $(APP).vox

VF_ROOT=$(abs_top_builddir)/@VOXSHELL_SOURCE_ROOT@
GRAMMAR_FOLDER=@GRAM_SOURCE_DIR@/$(APP)

all: $(TARGETS) 

# so it doesn't try to run this script 3 times, once for each target
.NOTPARALLEL: $(TARGETS)
 
$(TARGETS): $(APP)_voxcreate $(SOURCES)
	cd $(VF_ROOT) && julia @COMPILE_GRAMMAR@ $(GRAMMAR_FOLDER) $(APP) @MKFA@ @DFA_MINIMIZE@ @VOXFORGE_DICT@

$(APP).vox: $(APP)_voxcreate
	LANG=$(LANG) ./$(APP)_voxcreate --grammar @GRAMMAR_ROOT@ > $(APP).vox

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

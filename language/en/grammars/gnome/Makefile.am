APP=gnome
APPSCRIPTS= \
scripts/next_workspace.sh \
scripts/open.sh \
scripts/previous_workspace.sh

SOURCES= $(APP).vox $(APP).grammar
TARGETS= $(APP).dict $(APP).term $(APP).dfa
CLEANFILES=$(TARGETS)

all: $(TARGETS) 

$(TARGETS): $(SOURCES)
	julia $(abs_top_builddir)/@COMPILE_GRAMMAR@ $(APP) $(abs_top_builddir)/@MKFA_DIR@ $(abs_top_builddir)/@DFA_MINIMIZE_DIR@ $(abs_top_builddir)/@VOXFORGE_DICT@

##### files to be included in 'make install'
appdir=$(datadir)/@GRAM_INST_DIR@/$(APP)
dist_app_DATA = $(TARGETS)

appscriptdir=$(datadir)/@GRAM_INST_DIR@/$(APP)/scripts
dist_appscript_DATA = $(APPSCRIPTS)

install-data-hook:
	chmod +x $(appscriptdir)/*

##### files to be included in 'make dist'
EXTRA_DIST = \
$(SOURCES) \
$(TARGETS) \
$(APPSCRIPTS) 

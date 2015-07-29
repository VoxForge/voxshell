# make file to create/update grammars

all: shell.dict

shell.dict: shell.vox shell.grammar
	julia $(COMPILE_GRAMMAR) shell $(MKFA_DIR) $(VOXFORGE_DICT)

clean:
	rm -f *.dict *.dfa *.term *.tmp


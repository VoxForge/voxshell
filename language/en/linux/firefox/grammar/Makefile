# make file to create/update grammars

all: firefox.dict

firefox.dict: firefox.vox firefox.grammar
	julia $(COMPILE_GRAMMAR) firefox $(MKFA_DIR) $(VOXFORGE_DICT)

clean:
	rm -f *.dict *.dfa *.term *.tmp


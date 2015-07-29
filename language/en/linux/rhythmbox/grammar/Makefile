# make file to create/update grammars

all: rhythmbox.dict

rhythmbox.dict: rhythmbox.vox rhythmbox.grammar
	julia $(COMPILE_GRAMMAR) rhythmbox $(MKFA_DIR) $(VOXFORGE_DICT)

clean:
	rm -f *.dict *.dfa *.term *.tmp


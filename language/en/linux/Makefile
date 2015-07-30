# make file to create/update grammars

# update this path to your voxshell directory
VOXSHELL=~/VoxForge-git/voxshell

export COMPILE_GRAMMAR=$(VOXSHELL)/bin/compile_grammar.jl
export MKFA_DIR=$(VOXSHELL)/bin/linux
export VOXFORGE_DICT=$(VOXSHELL)/language/en/lexicon/VoxForgeDict.txt

FIREFOX_DIR=firefox/grammar
RHYTHMBOX_DIR=rhythmbox/grammar
SHELL_DIR=shell/grammar

all: firefox_grammar rhythmbox_grammar shell_grammar

rhythmbox_grammar:
	 $(MAKE) -s -C $(RHYTHMBOX_DIR)

firefox_grammar:
	 $(MAKE) -s -C $(FIREFOX_DIR)

shell_grammar:
	 $(MAKE) -s -C $(SHELL_DIR)

clean:
	$(MAKE) -s clean -C $(FIREFOX_DIR)
	$(MAKE) -s clean -C $(RHYTHMBOX_DIR)
	$(MAKE) -s clean -C $(SHELL_DIR)

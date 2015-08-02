# update to your environment:
VOXSHELL=~/VoxForge-git/voxshell
JULIUS_DIR=/usr/bin

export COMPILE_GRAMMAR=$(VOXSHELL)/bin/compile_grammar.jl
export VOXFORGE_DICT=$(VOXSHELL)/language/en/lexicon/VoxForgeDict.txt
export MKFA_DIR=$(JULIUS_DIR)

RM=/usr/bin/rm -f
INSTALL=/usr/bin/install -c

# update this path to your voxshell directory
LINUX_GRAMMARS=language/en/linux
JULIUS_SIMPLE=src

prefix=~/VoxForge-git/voxshell
exec_prefix=$(prefix)

.all: linux

linux: grammars julius-simple

julius-simple:
	$(MAKE) -s -C $(JULIUS_SIMPLE)
	$(MAKE) -s install -C $(JULIUS_SIMPLE)

grammars: 
	${INSTALL} src/compile_grammar.jl $(exec_prefix)/bin
	$(MAKE) -s -C $(LINUX_GRAMMARS)

clean:
	$(MAKE) -s clean -C $(LINUX_GRAMMARS)
	$(MAKE) -s clean -C $(JULIUS_SIMPLE)
	$(RM) bin/voxshell
	$(RM) bin/compile_grammar.jl


# update to your environment:
export VOXSHELL=~/VoxForge-git/voxshell
JULIUS_DIR=/usr/bin
export RM=rm -f
export INSTALL=install -c
# 32-bit
export CFLAGS_MOD=-m32
export LDFLAGS_MOD=-L../lib
# 64-bit
#export CFLAGS_MOD=
#export LDFLAGS_MOD=-L../lib64

###############################################################################
export COMPILE_GRAMMAR=$(VOXSHELL)/bin/compile_grammar.jl
export VOXFORGE_DICT=$(VOXSHELL)/language/en/lexicon/VoxForgeDict.txt
export MKFA_DIR=$(JULIUS_DIR)

# update this path to your voxshell directory
LINUX_GRAMMARS=language/en/linux
JULIUS_SIMPLE=src

.all: linux

linux: grammars julius-simple

julius-simple:
	$(MAKE) -s -C $(JULIUS_SIMPLE)
	$(MAKE) -s install -C $(JULIUS_SIMPLE)

grammars: 
	${INSTALL} src/compile_grammar.jl $(VOXSHELL)/bin
	$(MAKE) -s -C $(LINUX_GRAMMARS)

clean:
	$(MAKE) -s clean -C $(LINUX_GRAMMARS)
	$(MAKE) -s clean -C $(JULIUS_SIMPLE)
	$(RM) bin/voxshell
	$(RM) bin/compile_grammar.jl


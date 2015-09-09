# Copyright (c) 1991-2013 Kawahara Lab., Kyoto University
# Copyright (c) 2000-2005 Shikano Lab., Nara Institute of Science and Technology
# Copyright (c) 2005-2013 Julius project team, Nagoya Institute of Technology
# All rights reserved
#
# Makefile.in --- Makefile Template for configure
#
# $Id: Makefile.in,v 1.6 2013/06/20 17:14:16 sumomo Exp $
#
SHELL=/bin/sh

SUBDIRS=lib/libsent lib/libjulius src lib/gramtools
CONFIG_SUBDIRS=lib/libsent lib/libjulius lib/gramtools
INSTALL_SUBDIRS=src lib/gramtools

RM=/usr/bin/rm -f
RMDIR=/usr/bin/rm -fr
prefix=/home/kmaclean/VoxForge-git/voxshell
exec_prefix=${prefix}
datadir=${prefix}/share
INSTALL=/usr/bin/install -c

###############################################################################
export COMPILE_GRAMMAR=$(prefix)/bin/compile_grammar.jl
export VOXFORGE_DICT=$(prefix)/language/en/lexicon/VoxForgeDict.txt
export MKFA_DIR=$(prefix)/bin
LINUX_GRAMMARS=$(prefix)/language/en/linux

all:
	for d in $(SUBDIRS); do \
	  (cd $$d; $(MAKE)); \
	done

install:
	for d in $(INSTALL_SUBDIRS); do \
	  (cd $$d; $(MAKE) install); \
	done

clean:
	for d in $(SUBDIRS); do \
	  (cd $$d; $(MAKE) clean); \
	done
	$(RM) config.log config.cache
	$(RMDIR) autom4te.cache

distclean:
	for d in $(SUBDIRS); do \
	  if test -f $$d/Makefile; then \
	   (cd $$d; $(MAKE) distclean); \
	  fi; \
	done
	$(RM) config.log config.cache
	$(RM) config.status
	$(RM) Makefile
	$(RMDIR) autom4te.cache

config:
	for d in $(CONFIG_SUBDIRS); do \
	  (cd $$d; autoconf); \
	done

grammar: 
	$(MAKE) -s -C $(LINUX_GRAMMARS)

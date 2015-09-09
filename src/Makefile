# Copyright (c) 2015 VoxForge
# All rights reserved
#
# Makefile.in --- Makefile Template for configure
#
# $Id: Makefile.in,v 0.1 2015/09/08 Exp $
#
SHELL=/bin/sh
RM=/usr/bin/rm -f
prefix=/home/kmaclean/VoxForge-git/voxshell
exec_prefix=${prefix}
INSTALL=/usr/bin/install -c

LIBSENT=../lib/libsent
LIBJULIUS=../lib/libjulius

CC=gcc
CFLAGS=-g -O2 

####
#### When using system-installed libraries
####
# CPPFLAGS=`libjulius-config --cflags` `libsent-config --cflags`
# LDFLAGS=`libjulius-config --libs` `libsent-config --libs`

####
#### When using within-package libraries
####
CPPFLAGS=-I$(LIBJULIUS)/include -I$(LIBSENT)/include  `$(LIBSENT)/libsent-config --cflags` `$(LIBJULIUS)/libjulius-config --cflags`
LDFLAGS= -L$(LIBJULIUS) `$(LIBJULIUS)/libjulius-config --libs` -L$(LIBSENT) `$(LIBSENT)/libsent-config --libs`

TARGET=compile_grammar.jl voxshell

############################################################

all: voxshell

voxshell: voxshell.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o voxshell voxshell.c $(LDFLAGS)

install: install.bin

install.bin:
	${INSTALL} -d ${exec_prefix}/bin
	${INSTALL} $(TARGET) ${exec_prefix}/bin

clean:
	$(RM) *.o *.bak *~ core TAGS

distclean:
	$(RM) *.o *.bak *~ core TAGS
	$(RM) voxshell
	$(RM) Makefile

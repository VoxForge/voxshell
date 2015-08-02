CC=gcc
CFLAGS=-g -O2 -Wall

CPPFLAGS=-I../include `./libsent-config --cflags` `./libjulius-config --cflags`
LDFLAGS=-L../lib `./libjulius-config --libs` `./libsent-config --libs`
RM=/usr/bin/rm -f
INSTALL=/usr/bin/install -c

prefix=~/VoxForge-git/voxshell/bin
exec_prefix=$(prefix)

############################################################
TARGET=julius-simple

all: $(TARGET)

julius-simple: julius-simple.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -m32 -o $(TARGET) julius-simple.c $(LDFLAGS) 

install: $(TARGET)
	${INSTALL} $(TARGET) ${exec_prefix}

clean:
	$(RM) *.o *.bak *~ 
	$(RM) julius-simple


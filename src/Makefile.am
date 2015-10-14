bin_PROGRAMS = voxshell
voxshell_SOURCES = voxshell.c 
voxshell_CFLAGS = -Wall -g -O2
voxshell_CPPFLAGS = -Iinclude -I../lib/libjulius/include -I../lib/libsent/include

# note: must use 'make install' for voxshell executable to work properly.
# libtool 'make' creates a shell script called 'voxshell' in src directory that
# will seem to run, but will not recognize speech commands when compiled with *.la libs
# it works if specify static libraries, e.g.:
#voxshell_LDADD= ../lib/libjulius/.libs/libjulius.a ../lib/libsent/.libs/libsent.a

# must use 'configure --disable-shared' for voxshell to work properly with .la libraries (it
# compiles but does not recognize any speech.
voxshell_LDADD= ../lib/libjulius/libjulius.la ../lib/libsent/libsent.la

voxshell_LDFLAGS= -ldl -lpthread -lpulse-simple -lpulse -lasound -lz -lnsl -lm

# julius-simple
# CPPFLAGS=`libjulius-config --cflags` `libsent-config --cflags`
# LDFLAGS=`libjulius-config --libs` `libsent-config --libs`

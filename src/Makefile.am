bin_PROGRAMS = voxshell
voxshell_SOURCES = voxshell.c 
voxshell_CFLAGS = -Wall -g -O2
voxshell_CPPFLAGS = -Iinclude -I../lib/libjulius/include -I../lib/libsent/include `libjulius-config --cflags` `libsent-config --cflags`
voxshell_LDADD= ../lib/libjulius/libjulius.la ../lib/libsent/libsent.la

LIBSENT=../lib/libsent
LIBJULIUS=../lib/libjulius
#voxshell_LDFLAGS= -ldl -lpthread -lpulse-simple -lpulse -lasound -lz -lnsl -lm
voxshell_LDFLAGS = `$(LIBSENT)/libsent-config --libs` `$(LIBJULIUS)/libjulius-config --libs`

# julius-simple
# CPPFLAGS=`libjulius-config --cflags` `libsent-config --cflags`
# LDFLAGS=`libjulius-config --libs` `libsent-config --libs`

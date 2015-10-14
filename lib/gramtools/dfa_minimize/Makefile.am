LIBSENT=../../libsent

libjulius_la_CFLAGS = -Wall -g -O2
AM_CPPFLAGS = -Iinclude -I$(LIBSENT)/include `$(LIBSENT)/libsent-config --cflags`
bin_PROGRAMS = dfa_minimize
dfa_minimize_SOURCES = dfa_minimize.c
dfa_minimize_LDADD= $(LIBSENT)/libsent.la
dfa_minimize_LDFLAGS = -L$(libdir) -lpulse-simple -lpulse -lasound -lz -lm

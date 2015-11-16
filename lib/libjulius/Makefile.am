#SUBDIRS = ../libsent # create at top level

SRC = \
src/recogmain.c \
src/instance.c \
src/default.c \
src/jfunc.c \
src/callback.c \
src/useropt.c \
src/m_usage.c \
src/m_options.c \
src/m_jconf.c \
src/m_chkparam.c \
src/m_info.c \
src/m_fusion.c \
src/hmm_check.c \
src/multi-gram.c \
src/gramlist.c \
src/wchmm.c \
src/wchmm_check.c \
src/m_adin.c \
src/adin-cut.c \
src/wav2mfcc.c \
src/beam.c \
src/pass1.c \
src/spsegment.c \
src/realtime-1stpass.c \
src/factoring_sub.c \
src/outprob_style.c \
src/backtrellis.c \
src/search_bestfirst_main.c \
src/search_bestfirst_v1.c \
src/search_bestfirst_v2.c \
src/ngram_decode.c \
src/dfa_decode.c \
src/graphout.c \
src/confnet.c \
src/mbr.c \
src/gmm.c \
src/word_align.c \
src/plugin.c \
src/version.c 

LIBSENT=../libsent

# if have problems with zlib compiling improperly with shared version of libjulius (-fPIC), look
# at library paths.  My system has two versions: 
#$ whereis libz
# libz: /usr/lib/libz.so /usr/lib64/libz.so /usr/local/lib/libz.a
# after removing /usr/local/lib/libz.as, libjulius compiled OK 
# might try setting -prefix to non-default directory...


lib_LTLIBRARIES = libjulius.la
libjulius_la_CFLAGS = -Wall -g -O2
libjulius_la_CPPFLAGS = -Iinclude -I$(LIBSENT)/include  `$(LIBSENT)/libsent-config --cflags`
libjulius_la_SOURCES = $(SRC) 
libjulius_la_LIBADD= ../libsent/libsent.la
#libjulius_la_LDFLAGS = -L$(LIBSENT) `$(LIBSENT)/libsent-config --libs`
libjulius_la_LDFLAGS = `$(LIBSENT)/libsent-config --libs`

ACLOCAL_AMFLAGS=-I m4

juliusincludedir = $(includedir)/julius
dist_juliusinclude_HEADERS = \
include/julius/acconfig.h \
include/julius/config.h \
include/julius/define.h \
include/julius/graph.h \
include/julius/julius.h \
include/julius/misc.h \
include/julius/recog.h \
include/julius/trellis.h \
include/julius/beam.h \
include/julius/extern.h \
include/julius/jconf.h \
include/julius/multi-gram.h \
include/julius/search.h \
include/julius/useropt.h \
include/julius/callback.h \
include/julius/global.h \
include/julius/jfunc.h \
include/julius/juliuslib.h \
include/julius/plugin.h \
include/julius/stamp-h1 \
include/julius/wchmm.h 


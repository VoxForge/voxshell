SRC = \
src/adin/adin_file.c \
src/adin/adin_sndfile.c \
src/adin/adin_tcpip.c \
src/adin/zc-e.c \
src/adin/zmean.c \
src/adin/ds48to16.c \
src/anlz/param_malloc.c \
src/anlz/rdparam.c \
src/anlz/paramselect.c \
src/anlz/paramtypes.c \
src/anlz/strip.c \
src/anlz/strip_mfcc.c \
src/anlz/wrsamp.c \
src/anlz/wrwav.c \
src/anlz/vecin_net.c \
src/dfa/init_dfa.c \
src/dfa/rddfa.c \
src/dfa/dfa_lookup.c \
src/dfa/cpair.c \
src/dfa/mkcpair.c \
src/dfa/mkterminfo.c \
src/dfa/dfa_util.c \
src/dfa/dfa_malloc.c \
src/hmminfo/rdhmmdef.c \
src/hmminfo/rdhmmdef_data.c \
src/hmminfo/rdhmmdef_mpdf.c \
src/hmminfo/rdhmmdef_dens.c \
src/hmminfo/rdhmmdef_options.c \
src/hmminfo/rdhmmdef_state.c \
src/hmminfo/rdhmmdef_trans.c \
src/hmminfo/rdhmmdef_var.c \
src/hmminfo/rdhmmdef_streamweight.c \
src/hmminfo/rdhmmdef_tiedmix.c \
src/hmminfo/rdhmmdef_regtree.c \
src/hmminfo/hmm_lookup.c \
src/hmminfo/check_hmm_restriction.c \
src/hmminfo/check_hmmtype.c \
src/hmminfo/put_htkdata_info.c \
src/hmminfo/rdhmmlist.c \
src/hmminfo/cdhmm.c \
src/hmminfo/guess_cdHMM.c \
src/hmminfo/cdset.c \
src/hmminfo/init_phmm.c \
src/hmminfo/chkhmmlist.c \
src/hmminfo/write_binhmm.c \
src/hmminfo/read_binhmm.c \
src/hmminfo/write_binhmmlist.c \
src/hmminfo/read_binhmmlist.c \
src/net/rdwt.c \
src/net/server-client.c \
src/ngram/init_ngram.c \
src/ngram/ngram_read_arpa.c \
src/ngram/ngram_read_bin.c \
src/ngram/ngram_write_bin.c \
src/ngram/ngram_compact_context.c \
src/ngram/ngram_access.c \
src/ngram/ngram_lookup.c \
src/ngram/ngram_util.c \
src/ngram/ngram_malloc.c \
src/phmm/outprob_init.c \
src/phmm/outprob.c \
src/phmm/gms.c \
src/phmm/gms_gprune.c \
src/phmm/calc_mix.c \
src/phmm/calc_tied_mix.c \
src/phmm/gprune_common.c \
src/phmm/gprune_none.c \
src/phmm/gprune_safe.c \
src/phmm/gprune_heu.c \
src/phmm/gprune_beam.c \
src/phmm/addlog.c \
src/phmm/mkwhmm.c \
src/phmm/vsegment.c \
src/util/endian.c \
src/util/jlog.c \
src/util/mymalloc.c \
src/util/mybmalloc.c \
src/util/ptree.c \
src/util/aptree.c \
src/util/readfile.c \
src/util/gzfile.c \
src/util/mystrtok.c \
src/util/strcasecmp.c \
src/util/confout.c \
src/util/qsort.c \
src/voca/init_voca.c \
src/voca/voca_load_htkdict.c \
src/voca/voca_load_wordlist.c \
src/voca/voca_lookup.c \
src/voca/voca_malloc.c \
src/voca/voca_util.c \
src/wav2mfcc/ss.c \
src/wav2mfcc/wav2mfcc-buffer.c \
src/wav2mfcc/wav2mfcc-pipe.c \
src/wav2mfcc/mfcc-core.c \
src/wav2mfcc/para.c \
\
include/sent/adin.h \
src/adin/lpfcoef_2to1.h \
src/adin/lpfcoef_3to4.h 

# re: "src/net/server-client.c"
# (see http://stackoverflow.com/questions/4638604/where-does-one-get-the-sys-socket-h-header-source-file)
# The header <sys/socket.h> is defined in IEEE Std. 1003.1 (POSIX), but 
# sadly Windows is non-compliant with the POSIX standard. The MinGW compiler 
# is a port of GCC for compiling Windows applications, and therefore does 
# not include these POSIX system headers.
# libsent uses winsock2.h instead...

HDR = \
include/sent/adin.h \
include/sent/hmm.h \
include/sent/htk_param.h \
include/sent/ngram2.h \
include/sent/stamp-h1 \
include/sent/tcpip.h \
include/sent/config.h \
include/sent/dfa.h \
include/sent/htk_defs.h \
include/sent/machines.h \
include/sent/ptree.h \
include/sent/stddefs.h \
include/sent/util.h \
include/sent/hmm_calc.h \
include/sent/htk_hmm.h \
include/sent/mfcc.h \
include/sent/speech.h \
include/sent/vocabulary.h 

############################################################

lib_LTLIBRARIES = libsent.la
libsent_la_CFLAGS = -Wall -g -O2
libsent_la_CPPFLAGS = -I$(includedir) -I$(srcdir)/include $Isrc/adin/pa/common/
libsent_la_SOURCES = $(SRC)
libsent_la_LDFLAGS = -lm -lz

if MICTYPE_AUTO_ALSA
  libsent_la_SOURCES += src/adin/adin_mic_linux.c src/adin/adin_mic_linux_alsa.c
  libsent_la_LDFLAGS += -lasound
endif
if ALTYPE_PORTAUDIO
  libsent_la_SOURCES += src/adin/adin_portaudio.c
  libsent_la_LDFLAGS += -lportaudio
endif
#if ALTYPE_PA
#  libsent_la_SOURCES += src/adin/pa/common/pa_allocation.c src/adin/pa/common/pa_converters.c src/adin/pa/common/pa_cpuload.c src/adin/pa/common/pa_debugprint.c src/adin/pa/common/pa_dither.c src/adin/pa/common/pa_front.c src/adin/pa/common/pa_process.c src/adin/pa/common/pa_ringbuffer.c src/adin/pa/common/pa_skeleton.c src/adin/pa/common/pa_stream.c src/adin/pa/common/pa_trace.c
#  libsent_la_CPPFLAGS += -Isrc/adin/pa/include -Isrc/adin/pa/common
#endif
if ALTYPE_PA_WINMM
  libsent_la_SOURCES += src/adin/pa/common/pa_allocation.c src/adin/pa/common/pa_converters.c src/adin/pa/common/pa_cpuload.c src/adin/pa/common/pa_debugprint.c src/adin/pa/common/pa_dither.c src/adin/pa/common/pa_front.c src/adin/pa/common/pa_process.c src/adin/pa/common/pa_ringbuffer.c src/adin/pa/common/pa_skeleton.c src/adin/pa/common/pa_stream.c src/adin/pa/common/pa_trace.c
  libsent_la_CPPFLAGS += -Isrc/adin/pa/include -Isrc/adin/pa/common

  libsent_la_CPPFLAGS += -DPA_NO_DS -DPA_NO_ASIO
  libsent_la_SOURCES += src/adin/pa/os/win/pa_win_hostapis.c src/adin/pa/os/win/pa_win_util.c src/adin/pa/os/win/pa_win_waveformat.c
  libsent_la_SOURCES += src/adin/pa/hostapi/wmme/pa_win_wmme.c
  libsent_la_LDFLAGS += -lwinmm
  libsent_la_SOURCES += src/adin/adin_portaudio.c
endif
if HAS_WINSOCK2
  libsent_la_LDFLAGS += -lws2_32
endif

ACLOCAL_AMFLAGS=-I m4

sentincludedir = $(includedir)/sent
dist_sentinclude_HEADERS = $(HDR)



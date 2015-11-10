dnl Copyright (c) 1991-2013 Kawahara Lab., Kyoto University
dnl Copyright (c) 2000-2005 Shikano Lab., Nara Institute of Science and Technology
dnl Copyright (c) 2005-2013 Julius project team, Nagoya Institute of Technology
dnl All rights reserved
dnl
dnl  $Id: configure.in,v 1.37 2014/01/16 05:41:05 sumomo Exp $
dnl

dnl Process this file with autoconf to produce a configure script.
AC_INIT([libsent], [4.3.1], [contact@voxforge.org])
AC_CONFIG_HEADER(include/sent/config.h)
AC_CONFIG_AUX_DIR(../support)

# if get error: 
#   libtoolize: AC_CONFIG_MACRO_DIR([m4]) conflicts with ACLOCAL_AMFLAGS=-I m4
# solution:
#   dos2unix configure.ac && dos2unix Makefile.am
# Error is caused by using CRLFs in Makefile.am. "m4<CR>" != "m4" and thus the 
# libtoolize script will produce an error.
# (http://pete.akeo.ie/2010/12/that-darn-libtoolize-acconfigmacrodirm4.html)
AC_CONFIG_MACRO_DIR([m4]) 


AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects]) 
#AM_PROG_AR # don't use in mingw/ works on cygwin/ required for Linux
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
#case "$host_os" in  # this does ont work on Linux
#  linux*)
#    AM_PROG_AR
#	;;
#esac

LT_INIT

LIBSENT_VERSION=4.3.1

dnl Checks for options
# mic type
with_mictype=auto

# NetAudio support
AC_ARG_WITH(netaudio-dir,
[  --with-netaudio-dir=DIR DatLink/NetAudio include/lib are in DIR],,with_netaudio_dir=auto)

dnl use addlog array function
AC_ARG_ENABLE(addarray,
[  --disable-addarray      [debug] do not use addlog_array() function],
want_addarray=$enableval
,want_addarray=yes)

dnl extend to int
AC_ARG_ENABLE(words-int,
[  --enable-words-int      use integer instead of unsigned short for word ID
                           to extend vocabulary limit to 2^31=2G words],
want_words_int=$enableval
,want_words_int=no)

dnl class N-gram support
AC_ARG_ENABLE(class-ngram,
[  --disable-class-ngram   disable class N-gram support],
use_class_ngram=$enableval
,use_class_ngram=yes)

dnl enable fork for adinnet
AC_ARG_ENABLE(fork,
[  --enable-fork           enable process forking on adinnet],
use_fork=$enableval
,use_fork=no)

dnl sin/cos table for MFCC calc
AC_ARG_ENABLE(mfcc-table,
[  --disable-mfcc-table    disable sin/cos table for MFCC calculation],
use_mfcc_table=$enableval
,use_mfcc_table=yes)

dnl MSD model support
AC_ARG_ENABLE(msd,
[  --enable-msd            enable MSD model support],
want_msd=$enableval
,want_msd=no)

dnl MBR support
AC_ARG_ENABLE(mbr,
[  --disable-mbr           disable MBR support],
want_mbr=$enableval
,want_mbr=yes)

dnl enable/disable use of zlib library
AC_ARG_ENABLE(zlib,
[  --disable-zlib          disable zlib library],
use_zlib=$enableval
,use_zlib=yes)

dnl libsndfile
AC_ARG_WITH(sndfile,
[  --without-sndfile       does not link libsndfile library])


if test "$want_addarray" = yes; then
	AC_DEFINE(USE_ADDLOG_ARRAY,1,[USE_ADDLOG_ARRAY])
fi
if test "$want_words_int" = yes; then
	AC_DEFINE(WORDS_INT,1,[WORDS_INT])
fi
if test "$use_class_ngram" = yes; then
	AC_DEFINE(CLASS_NGRAM,1,[CLASS_NGRAM])
fi
if test "$use_fork" = yes; then
	AC_DEFINE(FORK_ADINNET,1,[FORK_ADINNET])
fi
if test "$use_mfcc_table" = yes; then
	AC_DEFINE(MFCC_SINCOS_TABLE,1,[MFCC_SINCOS_TABLE])
fi
if test "$want_msd" = yes; then
	AC_DEFINE(ENABLE_MSD,1,[ENABLE_MSD])
fi
if test "$want_mbr" = yes; then
	AC_DEFINE(USE_MBR,1,[USE_MBR])
fi

dnl Checks for system.
AC_CANONICAL_HOST

dnl Checks for optimization flag
AC_MSG_CHECKING([host specific optimization flag])
if test -z "$CFLAGS" ; then
    OPTFLAG=../support/cflags.${host_cpu}-${host_vendor}-${host_os}
    if test -f "$OPTFLAG" ; then
	. $OPTFLAG
	AC_MSG_RESULT([$OPTFLAG])
    else
	AC_MSG_RESULT([no])
    fi
else
    AC_MSG_RESULT([skipped])
fi

dnl Checks for compiler.
AC_PROG_CC
AC_PROG_CPP
AM_PROG_CC_C_O
AC_PROG_CXX

dnl Checks for programs.
AC_PROG_INSTALL
AC_PATH_PROG(RM, rm)
AC_PATH_PROG(AR, ar)
AC_EXEEXT

dnl Check for static link for cygwin / mingw libraries
case "$host_os" in
  cygwin*|mingw*)
    EXTRALIB="-static $EXTRALIB"
    ;;
esac

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_C_CONST
dnl AC_TYPE_SIZE_T
AC_MSG_CHECKING([for socklen_t])
AC_TRY_COMPILE([#include <sys/types.h>
#include <sys/socket.h>
],[socklen_t dummy;],
AC_DEFINE(HAVE_SOCKLEN_T,1,[HAVE_SOCKLEN_T])
AC_MSG_RESULT([yes]),
AC_MSG_RESULT([no]))

dnl Checks for library functions.
AM_CONDITIONAL([WINSOCK2], [test "$altype" = libportaudio])
AC_CHECK_FUNC(gethostbyname,,AC_CHECK_LIB(nsl,gethostbyname))
AC_CHECK_FUNC(connect,,AC_CHECK_LIB(socket, connect,,
AC_MSG_CHECKING([for connect in -lws2_32])
xxxxLIBS=$LIBS
LIBS="$LIBS -lws2_32"
AC_TRY_LINK([#include <winsock2.h>
int sd;
struct sockaddr_in s;
], [connect(sd, (struct sockaddr *)&s, sizeof(s));],
EXTRALIB="$EXTRALIB -lws2_32"
AC_MSG_RESULT([yes])
has_winsock2=true,
LIBS=$xxxxLIBS
AC_MSG_RESULT([no])
has_winsock2=false
)
))
AM_CONDITIONAL([HAS_WINSOCK2], [test "$altype" = has_winsock2])

AC_CHECK_FUNCS(strcasecmp)
AC_CHECK_FUNCS(sleep)

# ===== Check for available common adin files
case "$host_os" in
  cygwin*|mingw*)
# avoid ALSA/OSS detection for Windows environment
    has_alsa=no
    has_oss=no
    ;;
  *)
# ALSA
    has_alsa=yes
    AC_CHECK_HEADERS(alsa/asoundlib.h,,
      AC_CHECK_HEADERS(sys/asoundlib.h,,
       has_alsa=no
    ))
    ;;
esac

# ESounD
has_esd=yes
AC_CHECK_HEADERS(esd.h,,has_esd=no)

# PulseAudio
has_pulseaudio=no
AC_CHECK_LIB(pulse-simple,pa_simple_new,AC_CHECK_HEADERS(pulse/simple.h, has_pulseaudio=yes))

# =====Checks for default audio input API (order is important)
if test "$with_mictype" = auto; then
  AC_MSG_CHECKING(for default input device type)
  altype=no
  case "$host_os" in
  linux*)
	  # Linux - availability already checked, set default
	  if test "$has_alsa" = yes; then
	     altype=alsa
	  else
	     AC_MSG_ERROR([alsa header/lib not found!])
	  fi
	;;
  darwin*)
        # MacOSX (CoreAudio)
	AC_TRY_CPP([#include <CoreAudio/CoreAudio.h>],altype=coreaudio)
	;;
  cygwin*|mingw*)
	  # minGW - portaudio (auto select winmm / dsound)
	  altype=portaudio
	;;
  esac
  AC_MSG_RESULT($altype)
else
  altype=$with_mictype
fi

# If PortAudio library found at the system, use it.
# if not, V19 codes included in this distribution will be compiled in.
case $altype in
  portaudio)
    pa_system=no
    AC_CHECK_LIB(portaudio,Pa_Initialize,AC_CHECK_HEADERS(portaudio.h, pa_system=yes))
    if test "$pa_system" = no; then
      case "$host_os" in
      cygwin*|mingw*)
        AC_CHECK_LIB(dsound,main,
            AC_CHECK_HEADERS(DSound.h,
                altype="pa-dsound",
	      altype="pa-winmm"),
          altype="pa-winmm")
      ;;
      esac
    else
      altype="libportaudio"
    fi
;;
esac

# set appropriate parameters for the determined API
SOUNDLIB=""
ADINOBJ=""

# when auto, several available interfaces will be enabled
adinlist=""

# set makefile.am conditional variables
AM_CONDITIONAL([MICTYPE_AUTO_ALSA], [test "$with_mictype" = auto -a "$has_alsa" = yes])

if test "$with_mictype" = auto; then
  # if alsa exist, include it
  if test "$has_alsa" = yes; then
      SOUNDLIB="$SOUNDLIB -lasound"
      ADINOBJ="$ADINOBJ src/adin/adin_mic_linux_alsa.c"
      AC_DEFINE(HAS_ALSA,1,[HAS_ALSA])
      adinlist="$adinlist alsa"
  fi
fi

# altype-specific setup

# set makefile.am conditional variables
AM_CONDITIONAL([ALTYPE_PORTAUDIO], [test "$altype" = libportaudio])
AM_CONDITIONAL([ALTYPE_PA], [[test "$altype" = pa-*]])
AM_CONDITIONAL([ALTYPE_PA_WINMM], [test "$altype" = pa-winmm])

case $altype in
  libportaudio)
    aldesc="PortAudio library (external)"
    ADINOBJ="$ADINOBJ src/adin/adin_portaudio.c"
    SOUNDLIB="$SOUNDLIB -lportaudio"
    AC_DEFINE(USE_MIC,1,[USE_MIC])
  ;;
  pa-*)
    aldesc="PortAudio library (internal)"
    ADINOBJ="$ADINOBJ src/adin/pa/common/pa_allocation.o src/adin/pa/common/pa_converters.o src/adin/pa/common/pa_cpuload.o src/adin/pa/common/pa_debugprint.o src/adin/pa/common/pa_dither.o src/adin/pa/common/pa_front.o src/adin/pa/common/pa_process.o src/adin/pa/common/pa_ringbuffer.o src/adin/pa/common/pa_skeleton.o src/adin/pa/common/pa_stream.o src/adin/pa/common/pa_trace.o"
    SOUNDINC="-Isrc/adin/pa/include -Isrc/adin/pa/common"
    AC_DEFINE(USE_MIC)
    case "$altype" in
      pa-winmm)
	      aldesc="$aldesc (WinMM)"
	      SOUNDINC="$SOUNDINC -DPA_NO_DS -DPA_NO_ASIO"
        ADINOBJ="$ADINOBJ src/adin/pa/os/win/pa_win_hostapis.o src/adin/pa/os/win/pa_win_util.o src/adin/pa/os/win/pa_win_waveformat.o"
	      ADINOBJ="$ADINOBJ src/adin/pa/hostapi/wmme/pa_win_wmme.o"
        SOUNDLIB="$SOUNDLIB -lwinmm"
      ;;
      esac
      ADINOBJ="$ADINOBJ src/adin/adin_portaudio.o"
      ;;
  alsa)
    if test "$has_alsa" = no; then
      AC_MSG_ERROR([no ALSA header!])
    fi
    aldesc="Advanced Linux Sound Architecture"
    AC_DEFINE(USE_MIC,1,[USE_MIC])
    ADINOBJ="$ADINOBJ src/adin/adin_mic_linux.c"
    if test "$with_mictype" != auto; then
      SOUNDLIB="$SOUNDLIB -lasound"
      ADINOBJ="$ADINOBJ src/adin/adin_mic_linux_alsa.c"
      AC_DEFINE(HAS_ALSA,1,[HAS_ALSA])
      adinlist="$adinlist alsa"
    fi
  ;;
  coreaudio)
    aldesc="MacOSX CoreAudio"
    ADINOBJ="$ADINOBJ src/adin/adin_mic_darwin_coreaudio.c"
    AC_DEFINE(USE_MIC,1,[USE_MIC])
    SOUNDLIB="$SOUNDLIB -Wl,-framework -Wl,CoreServices -Wl,-framework -Wl,CoreAudio -Wl,-framework -Wl,AudioUnit -Wl,-framework -Wl,AudioToolbox"
  ;;
  *)
    aldesc="no support"
    AC_MSG_ERROR([mictype not supported, or specified type not exist])
  ;;
esac

dnl check for NetAudio support
if test "$with_netaudio_dir" = auto ; then
	AC_MSG_CHECKING([for DatLink/NetAudio support])
else
	AC_MSG_CHECKING([for DatLink/NetAudio support on ${with_netaudio_dir}])
fi
TMPCPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS -I${with_netaudio_dir}/include"
use_netaudio=no
AC_TRY_CPP([#include <netaudio.h>],
	use_netaudio=yes
	AC_DEFINE(USE_NETAUDIO,1,[USE_NETAUDIO])
	SOUNDINC="-I${with_netaudio_dir}/include"
	ADINOBJ="$ADINOBJ src/adin/adin_netaudio.c src/adin/adin_na.c"
	SOUNDLIB="$SOUNDLIB -L${with_netaudio_dir}/lib -lnetaudio -lsupport"
	adinlist="$adinlist netaudio")
AC_MSG_RESULT($use_netaudio)
CPPFLAGS="$TMPCPPFLAGS"
EXTRAOBJ="$EXTRAOBJ $ADINOBJ"

# using Autotools creates static and dynamic versions all code...
# problem is that zlib is only compiled statically (on Fedora at least...)
# (https://bugzilla.redhat.com/show_bug.cgi?id=832545)
#
# on Mingw, zlib called libz; development package needs to be installed
dnl check for file decompression using zlib
have_zlib=no;
if test "$use_zlib" = yes; then
  AC_CHECK_LIB(z, deflate,
    AC_CHECK_HEADERS(zlib.h,
      have_zlib=yes;
      gzdesc="zlib library";
      EXTRALIB="$EXTRALIB -lz"
      AC_DEFINE(HAVE_ZLIB,1,[HAVE_ZLIB])))
  if test "$have_zlib" = no; then
      AC_MSG_WARN([not found])
      use_zlib=no;
  fi
fi
dnl next, check for built-in file decompression using gzip
if test "$use_zlib" = no; then
  AC_CHECK_PROG(GZIP, gzip, found, no)
  if test "$GZIP" = no; then
    gzdesc="none";
    AC_MSG_WARN([not found, compressed file input disabled])
  else
    gzdesc="gzip command";
    AC_DEFINE(ZCAT, ["gzip -d -c"], [ZCAT])
  fi
fi

dnl check for libsndfile
wavefile_support="RAW and WAV only"
if test -z "$with_sndfile"; then
   with_sndfile=yes
fi
if test "$with_sndfile" = yes; then
 have_libsndfile=no
 AC_CHECK_LIB(sndfile, sf_open,
  AC_CHECK_HEADERS(sndfile.h,
    wavefile_support='various formats by libsndfile ver.1'
    AC_DEFINE(HAVE_LIBSNDFILE,1,[HAVE_LIBSNDFILE])
    AC_DEFINE(HAVE_LIBSNDFILE_VER1,1,[HAVE_LIBSNDFILE_VER1])
    EXTRALIB="$EXTRALIB -lsndfile"
    have_libsndfile=yes))
 if test "$have_libsndfile" = no; then
  AC_CHECK_LIB(sndfile, sf_open_read,
    AC_CHECK_HEADERS(sndfile.h,
      wavefile_support='various formats by libsndfile ver.0'
      AC_DEFINE(HAVE_LIBSNDFILE,1,[HAVE_LIBSNDFILE])
      EXTRALIB="$EXTRALIB -lsndfile"
      have_libsndfile=yes))
 fi
 if test "$have_libsndfile" = no; then
  AC_MSG_WARN([libsndfile enables AIFF AU SND NIST format for Julius.
It's available at http://www.mega-nerd.com/libsndfile/])
 fi
fi

dnl max os 10 needs extra iconv library
case "$host_os" in
  darwin*)
    EXTRALIB="$EXTRALIB -liconv"
    ;;
esac

dnl substitute some definitions in libsent-config
AC_SUBST(LIBSENT_VERSION)
AC_SUBST(altype)
AC_SUBST(aldesc)
AC_SUBST(adinlist)
AC_SUBST(use_netaudio)
AC_SUBST(use_pthread)
AC_SUBST(wavefile_support)
AC_SUBST(use_class_ngram)
AC_SUBST(use_fork)
AC_SUBST(gzdesc)

dnl define configuration descriptions
AC_DEFINE_UNQUOTED(LIBSENT_VERSION, "$LIBSENT_VERSION", [LIBSENT_VERSION])
AC_DEFINE_UNQUOTED(AUDIO_API_NAME, "$altype", [AUDIO_API_NAME])
AC_DEFINE_UNQUOTED(AUDIO_API_DESC, "$aldesc", [AUDIO_API_DESC])
AC_DEFINE_UNQUOTED(AUDIO_FORMAT_DESC, "$wavefile_support", [AUDIO_FORMAT_DESC])
AC_DEFINE_UNQUOTED(GZIP_READING_DESC, "$gzdesc", [GZIP_READING_DESC])

dnl substitute in Makefile
AC_SUBST(EXTRAOBJ)
AC_SUBST(EXTRALIB)
AC_SUBST(SOUNDINC)
AC_SUBST(SOUNDLIB)

AC_OUTPUT_COMMANDS(
[chmod +x libsent-config libsent-config-dist
./libsent-config --info
],
altype=$altype
aldesc="$aldesc"
adinlist="$adinlist"
use_netaudio=$use_netaudio
use_pthread=$use_pthread
wavefile_support="$wavefile_support"
gzdesc="$gzdesc"
)
AC_OUTPUT(Makefile libsent-config libsent-config-dist)

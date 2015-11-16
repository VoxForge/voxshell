AC_INIT([voxshell], [0.3.1], [contact@voxforge.org]) 
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror]) 
#AM_PROG_AR # don't use in mingw/ works on cygwin
LT_INIT
AC_PROG_CC
AM_PROG_CC_C_O
AC_CONFIG_HEADERS([src/config.h])

AC_MSG_CHECKING(for host type)
case "$host_os" in
  cygwin*|mingw*)
    AC_DEFINE(VF_WINDOWS,1,[VF_WINDOWS])
  ;;
  linux*)
    AC_DEFINE(VF_LINUX,1,[VF_LINUX])
	;;
esac
AC_MSG_RESULT($host_os)

AC_CONFIG_FILES([Makefile src/Makefile language/Makefile])
AC_CONFIG_SUBDIRS([lib/libsent lib/libjulius lib/gramtools language/en])
AC_OUTPUT

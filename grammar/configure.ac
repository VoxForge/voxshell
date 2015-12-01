AC_INIT([voxshell_apps], [0.1], [contact@voxforge.org])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AM_GNU_GETTEXT_VERSION([0.18.3])
AM_GNU_GETTEXT([external])

AM_PROG_AR
LT_INIT

AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([ \
lib/Makefile \
po/Makefile.in \
language/Makefile \
Makefile \
rhythmbox/Makefile \
])

# source directories
SHARE_FOLDER=voxshell
AC_SUBST(SHARE_FOLDER)
AC_SUBST(GRAM_INST_DIR, [$SHARE_FOLDER/grammar])


# relative to $(abs_top_builddir)
AC_SUBST(VOXSHELL_SOURCE_ROOT, [..])
AC_MSG_CHECKING(for host type)
case "$host_os" in
  cygwin*|mingw*)
    AC_SUBST(MKFA, [lib/gramtools/mkfa/mkfa.exe])
    AC_SUBST(DFA_MINIMIZE, [lib/gramtools/dfa_minimize/dfa_minimize.exe])
  ;;
  linux*)
    AC_SUBST(MKFA, [lib/gramtools/mkfa/mkfa])
    AC_SUBST(DFA_MINIMIZE, [lib/gramtools/dfa_minimize/dfa_minimize])
	;;
esac
AC_MSG_RESULT($host_os)
AC_SUBST(COMPILE_GRAMMAR, [scripts/compile_grammar.jl])

AC_SUBST(VOXFORGE_DICT, [grammar/language/en/voxforgedict.txt])
AC_SUBST(GRAM_SOURCE_DIR, [grammar])
AC_SUBST(WIN_GRAM_SOURCE_DIR, [language/en/windows])

# location of grammar files after 'make install'
AC_SUBST(GRAMMAR_ROOT, [share/voxshell/grammar])

# configure script replaces @VAR@ variables in *.in files (e.g. firefox.vox.in)
#AC_OUTPUT( \
#language/en_grammar_list \
#)
AC_OUTPUT()

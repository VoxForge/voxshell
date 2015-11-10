AC_INIT([en], [0.1], [contact@voxforge.org])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign])
#AM_PROG_AR # mingw does not like htis
LT_INIT

# source directories
# relative to $(abs_top_builddir)
AC_SUBST(VOXSHELL_SOURCE_ROOT, [../..])
AC_SUBST(COMPILE_GRAMMAR, [scripts/compile_grammar.jl])
AC_SUBST(MKFA_DIR, [lib/gramtools/mkfa])
AC_SUBST(DFA_MINIMIZE_DIR, [lib/gramtools/dfa_minimize])
AC_SUBST(VOXFORGE_DICT, [language/en/lexicon/VoxForgeDict.txt])
AC_SUBST(GRAM_SOURCE_DIR, [language/en/grammars])
AC_SUBST(WIN_GRAM_SOURCE_DIR, [language/en/windows])

dnl Check for Windows
# AM_CONDITIONAL([VF_WINDOWS], [test $host_os = "cygwin*|mingw*"]) # wildcard does not work
# use case statement b/c can use wildcards...
WINDOWS_FOUND=false
LINUX_FOUND=false
case "$host_os" in
  cygwin*|mingw*)
    WINDOWS_FOUND=true
  ;;
  linux*)
    LINUX_FOUND=true
  ;;
esac
AM_CONDITIONAL([VF_WINDOWS], [test WINDOWS_FOUND=true]) 
AM_CONDITIONAL([VF_LINUX], [test LINUX_FOUND=true]) 

# before install directories
# relative to $(datadir)
SHARE_FOLDER=voxshell
AC_SUBST(SHARE_FOLDER)
AC_SUBST(GRAM_INST_DIR, [$SHARE_FOLDER/en/grammars])

AC_CONFIG_FILES( \
[Makefile \
grammars/Makefile \
grammars/firefox/Makefile \
grammars/shell/Makefile \
grammars/gnome/Makefile \
grammars/libreoffice/Makefile \
grammars/rhythmbox/Makefile \
windows/Makefile \
windows/firefox/Makefile \
])

# location of grammar files after 'make install'
AC_SUBST(GRAMMAR_ROOT, [share/voxshell/en/grammars])

# configure script replaces @VAR@ variables in *.in files (e.g. firefox.vox.in)
AC_OUTPUT( \
grammars/firefox/firefox.vox \
grammars/shell/shell.vox \
grammars/gnome/gnome.vox \
grammars/libreoffice/libreoffice.vox \
grammars/rhythmbox/rhythmbox.vox \
)

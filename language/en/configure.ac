AC_INIT([en], [0.1], [contact@voxforge.org])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign])
AM_PROG_AR
LT_INIT

SHARE_FOLDER=voxshell
AC_SUBST(SHARE_FOLDER)
# relative to $(abs_top_builddir)
AC_SUBST(COMPILE_GRAMMAR, [../../scripts/compile_grammar.jl])
AC_SUBST(MKFA_DIR, [../../lib/gramtools/mkfa])
AC_SUBST(DFA_MINIMIZE_DIR, [../../lib/gramtools/dfa_minimize])
AC_SUBST(VOXFORGE_DICT, [lexicon/VoxForgeDict.txt])
# relative to $(datadir)
AC_SUBST(GRAM_INST_DIR, [$SHARE_FOLDER/en/grammars])

AC_CONFIG_FILES( \
[Makefile \
grammars/Makefile \
grammars/firefox/Makefile \
grammars/shell/Makefile \
grammars/gnome/Makefile \
grammars/libreoffice/Makefile \
grammars/rhythmbox/Makefile \
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

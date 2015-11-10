#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#AC_PREREQ([2.69]) # mingw does not like htis
AC_INIT([gramtools], [1.0], [kmaclean@voxforge.org])
AM_INIT_AUTOMAKE([foreign -Wall -Werror]) 

# if get error: 
#   libtoolize: AC_CONFIG_MACRO_DIR([m4]) conflicts with ACLOCAL_AMFLAGS=-I m4
# solution:
#   dos2unix configure.ac && dos2unix Makefile.am
# Error is caused by using CRLFs in Makefile.am. "m4<CR>" != "m4" and thus the 
# libtoolize script will produce an error.
# (http://pete.akeo.ie/2010/12/that-darn-libtoolize-acconfigmacrodirm4.html)
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
LT_INIT
# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_LEX
AC_PROG_YACC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile mkfa/Makefile dfa_minimize/Makefile])
#AC_CONFIG_SUBDIRS([dfa_minimize])
AC_OUTPUT

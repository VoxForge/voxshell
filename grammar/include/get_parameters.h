//getOptions
#ifndef GETOPT_H
#define GETOPT_H
#include <getopt.h>
#endif /* GETOPT_H */

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif /* STDIO_H */

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif /* STDLIB_H */

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif /* STRING_H */

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif /* STDBOOL_H */

#ifndef LOCALE_H
#define LOCALE_H
#include <locale.h>
#endif /* GETTEXT_H */

#ifndef GETTEXT_H
#define GETTEXT_H
#include "../include/gettext.h"
#define _(string) gettext (string)
#endif /* GETTEXT_H */

typedef struct parameters_template 
{
  char* grammar_root; 
} parameters_t;




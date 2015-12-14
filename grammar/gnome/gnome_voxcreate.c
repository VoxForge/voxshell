// Internationalization & Localization
#ifndef CONFIG_H
#define CONFIG_H
#include <config.h>
#endif /* CONFIG_H */

#ifndef LOCALE_H
#define LOCALE_H
#include <locale.h>
#endif /* GETTEXT_H */

#ifndef GETTEXT_H
#define GETTEXT_H
#include "../include/gettext.h"
#define _(string) gettext (string)
#endif /* GETTEXT_H */

#ifndef GET_PARAMETERS_H
#define GET_PARAMETERS_H
#include "../include/get_parameters.h"
#endif /* GET_PARAMETERS_H */

#define NUMARTISTS 4
#define NUMALBUMS 6
#define NUMGENRE 1

#include <stdio.h>

/**
 * Main function
 * 
 */
// to update po file use:
// cd po
// make update-po
// msginit -l fr
int
main(int argc, char *argv[])
{
  parameters_t parms; // parameters to be collected from user upon startup
  int i; // counter

  // get user parameters from command line
  get_parameters(argc, argv, &parms);

  // Localization
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE,
                  LOCALEDIR);
  textdomain (PACKAGE);

  puts("% NS_B");
  puts("[] <s>");
  puts("");

  puts("% NS_E");
  puts("[] <s>");
  puts("");

  puts("% FILLER");
  printf("[] "); puts(_("UH WELL HUM"));
  puts("");

  puts("% GNOME ");
  printf("[] "); puts( _("GNOME SUPER") );
  puts("");

  puts("% GNOME_ACTION");
  printf("[%s/gnome/scripts/open.sh] ", parms.grammar_root); puts( _("DESKTOP NAVIGATION") );
  puts("");

  puts("% WORKSPACE");
  printf("[] "); puts( _("WORK-SPACE") );
  puts("");

  puts("% WORKSPACE_NAVIGATION");
  printf("[%s/gnome/scripts/next_workspace.sh] ", parms.grammar_root); puts( _("NEXT") );
  printf("[%s/gnome/scripts/next_workspace.sh] ", parms.grammar_root); puts( _("PREVIOUS") );
  puts("");

  // exit program
  return(0);
}


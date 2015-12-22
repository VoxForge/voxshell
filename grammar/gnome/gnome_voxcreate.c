// Internationalization & Localization
#include <config.h>
#include <locale.h>
#include "../include/gettext.h"
#define _(string) gettext (string)
#include "../include/get_parameters.h"

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


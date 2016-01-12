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

  // generate .vox file
  puts("% NS_B");
  puts("[] <s>");
  puts("");

  puts("% NS_E");
  puts("[] <s>");
  puts("");

  puts("% FILLER");
  printf("[] "); puts(_("UH WELL HUM"));
  puts("");

  puts("% BROWSER");
  printf("[] "); puts( _("BROWSER FIREFOX") );
  puts("");

  puts("% START");
  printf("[%s/firefox/scripts/start.sh] ", parms.grammar_root); puts( _("START") );
  puts("");

  puts("% PAGE");
  printf("[] "); puts( _("PAGE SCREEN") );
  puts("");

  puts("% PAGE_DIRECTION");
  char *ff="[xdotool search Mozilla windowactivate --sync key";
  printf("%s Next] ", ff); puts( _("DOWN") );
  printf("%s Prior] ", ff); puts( _("UP") );
  puts("");

  // exit program
  return(0);
}


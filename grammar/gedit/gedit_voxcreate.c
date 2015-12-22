// Internationalization & Localization
#include <config.h>

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

  puts("% GEDIT");
  printf("[] "); puts( _("EDIT EDITOR G-EDIT") );
  puts("");

  char *xdotool="[xdotool search --onlyvisible --limit 1 --class gedit windowactivate key --window 0 ";

  puts("% ACTION");
  printf(xdotool); printf(" ctrl ctrl+f] "); puts( _("FIND") ); // first 'ctrl' keycode is ignored (but needs to be a valid xdotool keycode)
  printf(xdotool); printf(" ctrl ctrl+h] "); puts( _("REPLACE") );
  printf(xdotool); printf(" ctrl ctrl+s] "); puts( _("SAVE") );
  printf(xdotool); printf(" ctrl ctrl+w] "); puts( _("CLOSE") );
  printf(xdotool); printf(" ctrl ctrl+o] "); puts( _("OPEN") );
  printf(xdotool); printf(" ctrl ctrl+q] "); puts( _("QUIT") );
  printf(xdotool); printf(" ctrl+alt+Prior] "); puts( _("TAB-LEFT") ); // no need for leading dummy keycode when three keycodes in a row
  printf(xdotool); printf(" ctrl+alt+Next] "); puts( _("TAB-RIGHT") );
  printf(xdotool); printf(" ctrl ctrl+z] "); puts( _("UNDO") );
  printf(xdotool); printf(" shift+ctrl+z] "); puts( _("REDO") );
  printf(xdotool); printf(" ctrl ctrl+Home] "); puts( _("HOME BEGINNING FRONT") );
  printf(xdotool); printf(" ctrl ctrl+End] "); puts( _("END BOTTOM") );
  printf("[%s/gedit/scripts/start.sh] ",    parms.grammar_root); puts( _("START NEW-TAB") );
  puts("");

  puts("% PAGE");
  printf("[] "); puts( _("PAGE SCREEN") );
  puts("");

  puts("% PAGE_DIRECTION");
  printf(xdotool); printf(" Prior Prior] "); puts( _("UP BACK") );
  printf(xdotool); printf(" Next Next] "); puts( _("DOWN FORWARD") );
  puts("");

  // exit program
  return(0);
}


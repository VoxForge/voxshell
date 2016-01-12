// Internationalization & Localization
#include <config.h>
#include <locale.h>
#include "../include/gettext.h"
#include "../include/get_parameters.h"

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

  // hacky way to get xdotool to work with gedit
  // see: 
  char *xdotool="[xdotool search --onlyvisible --limit 1 --class gedit windowactivate key --window 0 ";

  puts("% ACTION");
  printf("%s ctrl ctrl+f] ", xdotool); puts( _("FIND") ); // first 'ctrl' keycode is ignored (but needs to be a valid xdotool keycode)
  printf("%s ctrl ctrl+h] ", xdotool); puts( _("REPLACE") );
  printf("%s ctrl ctrl+s] ", xdotool); puts( _("SAVE") );
  printf("%s ctrl ctrl+w] ", xdotool); puts( _("CLOSE") );
  printf("%s ctrl ctrl+o] ", xdotool); puts( _("OPEN") );
  printf("%s ctrl ctrl+q] ", xdotool); puts( _("QUIT") );
  printf("%s ctrl+alt+Prior] ", xdotool); puts( _("TAB-LEFT") ); // no need for leading dummy keycode when three keycodes in a row
  printf("%s ctrl+alt+Next] ", xdotool); puts( _("TAB-RIGHT") );
  printf("%s ctrl ctrl+z] ", xdotool); puts( _("UNDO") );
  printf("%s shift+ctrl+z] ", xdotool); puts( _("REDO") );
  printf("%s ctrl ctrl+Home] ", xdotool); puts( _("HOME BEGINNING FRONT") );
  printf("%s ctrl ctrl+End] ", xdotool); puts( _("END BOTTOM") );
  printf("[%s/gedit/scripts/start.sh] ",    parms.grammar_root); puts( _("START NEW-TAB") );
  puts("");

  puts("% PAGE");
  printf("[] "); puts( _("PAGE SCREEN") );
  puts("");

  puts("% PAGE_DIRECTION");
  printf("%s Prior Prior] ", xdotool); puts( _("UP BACK") );
  printf("%s Next Next] ", xdotool); puts( _("DOWN FORWARD") );
  puts("");

  // exit program
  return(0);
}


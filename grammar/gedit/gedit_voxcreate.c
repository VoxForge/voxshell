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

  puts("% ACTION");
  printf("[%s/gedit/scripts/find.sh] ",     parms.grammar_root); puts( _("FIND") );
  printf("[%s/gedit/scripts/replace.sh] ",  parms.grammar_root); puts( _("REPLACE") );
  printf("[%s/gedit/scripts/save.sh] ",     parms.grammar_root); puts( _("SAVE") );
  printf("[%s/gedit/scripts/start.sh] ",    parms.grammar_root); puts( _("START NEW-TAB") );
  printf("[%s/gedit/scripts/close.sh] ",    parms.grammar_root); puts( _("CLOSE") );
  printf("[%s/gedit/scripts/open.sh] ",     parms.grammar_root); puts( _("OPEN") );
  printf("[%s/gedit/scripts/quit.sh] ",     parms.grammar_root); puts( _("QUIT") );
  printf("[%s/gedit/scripts/tableft.sh] ",  parms.grammar_root); puts( _("TAB-LEFT") );
  printf("[%s/gedit/scripts/tabright.sh] ", parms.grammar_root); puts( _("TAB-RIGHT") );
  printf("[%s/gedit/scripts/undo.sh] ",     parms.grammar_root); puts( _("UNDO") );
  printf("[%s/gedit/scripts/redo.sh] ",     parms.grammar_root); puts( _("REDO") );

  puts("% PAGE");
  printf("[] "); puts( _("PAGE SCREEN") );
  puts("");

  puts("% PAGE_DIRECTION");
  printf("[%s/gedit/scripts/pagedown.sh] ", parms.grammar_root); puts( _("DOWN FORWARD") );
  printf("[%s/gedit/scripts/pageup.sh] ", parms.grammar_root); puts( _("UP BACK") );
  puts("");

  // exit program
  return(0);
}


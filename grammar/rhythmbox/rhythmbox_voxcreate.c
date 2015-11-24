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
#include "get_parameters.h"
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

  puts("% MUSIC_PLAYER ");
  printf("[] "); puts( _("RHYTHMBOX PLAYER MUSIC") );
  puts("");

  puts("% CONTROL");
  printf("[rhythmbox-client --play] "); puts( _("PLAY START") );
  printf("[rhythmbox-client --next] "); puts( _("NEXT SKIP") );
  printf("[rhythmbox-client --previous] "); puts( _("PREVIOUS BACK") );
  printf("[%s/rhythmbox/scripts/show.sh] ", parms.grammar_root); puts( _("SHOW WHO ABOUT INFORMATION") );
  printf("[rhythmbox-client --volume-up] "); puts( _("UP LOUDER") );
  printf("[rhythmbox-client --volume-down] "); puts( _("DOWN LOWER SOFTER QUIETER") );
  printf("[rhythmbox-client --pause] "); puts( _("SILENCE STOP QUIET MUTE") );
  char *dbus="[dbus-send --print-reply --dest=org.mpris.MediaPlayer2.rhythmbox /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Seek";
  printf(dbus); printf(" int64:30000000 > /dev/null] "); puts( _("FAST-FORWARD ADVANCE") );
  printf(dbus); printf(" int64:-30000000 > /dev/null] "); puts( _("REWIND GO-BACK") );
  puts("");

  puts("% PLAY_CONTROL");
  printf("[] "); puts( _("PLAY") );
  puts("");

  puts("% ARTIST");
  char artist[NUMARTISTS][2][1024]={
              {{"arcade fire"}, {"ARCADE-FIRE"}},
              {{"police"}, {"POLICE"}},
              {{"radiohead"}, {"RADIO-HEAD"}},
              {{"u2"}, {"U-TWO"}},
  };
  for (i=0; i<NUMARTISTS; i++) 
  {
    printf("[%s/rhythmbox/scripts/search.sh %s] %s\n",  parms.grammar_root, artist[i][0], artist[i][1]); 
  }
  puts("");

  puts("% ALBUM");
  char album[NUMALBUMS][2][1024]={
              {{"The Police"}, {"THE-POLICE"}},
              {{"Police Every Breath"}, {"POLICE-EVERY-BREATH"}},
              {{"U2 best of"}, {"BEST-OF-U-TWO"}},
              {{"U2 Zooropa"}, {"U-TWO-ZOOP-ROPE-A"}},
              {{"radiohead best of"}, {"BEST-OF-RADIO-HEAD"}},
              {{"radiohead OK Computer"}, {"OK-COMPUTER"}},
  };
  for (i=0; i<NUMALBUMS; i++) 
  {
    printf("[%s/rhythmbox/scripts/search.sh %s] %s\n",  parms.grammar_root, album[i][0], album[i][1]); 
  }
  puts("");

  puts("% GENRE");
  char genre[NUMGENRE][2][1024]={
              {{"rock"}, {"ROCK-AND-ROLL"}},
  };
  for (i=0; i<NUMGENRE; i++) 
  {
    printf("[%s/rhythmbox/scripts/search.sh %s] %s\n",  parms.grammar_root, genre[i][0], genre[i][1]); 
  }

  // exit program
  return(0);
}


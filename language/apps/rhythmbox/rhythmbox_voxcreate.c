// Internationalization & Localization
#include <config.h>
#include <locale.h>
#include "../include/gettext.h"
#define _(string) gettext (string)

#include <stdio.h>

#define RHYTHMBOX rhythmbox-client
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
  puts(_("UH WELL HUM"));
  puts("");

  puts("% MUSIC_PLAYER ");
  puts( _("RHYTHMBOX PLAYER MUSIC") );
  puts("");

  puts("% DO");
  printf("[rhythmbox-client --play] "); puts( _("PLAY START") );
  printf("[rhythmbox-client --next] "); puts( _("NEXT SKIP") );
  printf("[rhythmbox-client --previous] "); puts( _("PREVIOUS BACK") );
  printf("[@GRAMMAR_ROOT@/rhythmbox/scripts/show.sh] "); puts( _("SHOW WHO ABOUT INFORMATION") );
  printf("[rhythmbox-client --volume-up] "); puts( _("UP LOUDER") );
  printf("[rhythmbox-client --volume-down] "); puts( _("DOWN LOWER SOFTER QUIETER") );
  printf("[rhythmbox-client --pause] "); puts( _("SILENCE STOP QUIET MUTE") );

  char *dbus="[dbus-send --print-reply --dest=org.mpris.MediaPlayer2.rhythmbox /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Seek";
  printf(dbus); printf(" int64:30000000 > /dev/null] "); puts( _("FAST-FORWARD ADVANCE") );
  printf(dbus); printf(" int64:-30000000 > /dev/null] "); puts( _("REWIND GO-BACK") );

  puts("");

  // exit program
  return(0);
}


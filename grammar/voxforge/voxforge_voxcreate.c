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

  puts("% VOXFORGE ");
  printf("[COM] "); puts( _("VOXFORGE") );
  puts("");

  puts("% VOXFORGE_CAT");
  printf("[firefox -remote openurl(http://www.voxforge.org)] "); puts( _("HOME PAGE") );
  char *ff="[firefox -remote openurl(http://www.voxforge.org/home";
  printf(ff); printf("/read)] "); puts( _("READ SUBMIT") );
  printf(ff); printf("/listen)] "); puts( _("LISTEN") );
  printf(ff); printf("/forums)] "); puts( _("FORUMS") );
  printf(ff); printf("/dev)] "); puts( _("DEVELOP DEVELOPER") );
  printf(ff); printf("/about)] "); puts( _("ABOUT") );
  printf(ff); printf("/dev/acousticmodels/linux/create/htkjulius/how-to/download)] "); puts( _("HOWTO") );
  printf(ff); printf("/dev/acousticmodels/linux/create/htkjulius/tutorial/download)] "); puts( _("TUTORIAL") );
  puts("");

  // exit program
  return(0);
}


#ifndef GET_PARAMETERS_H
#define GET_PARAMETERS_H
#include "get_parameters.h"
#endif /* GET_PARAMETERS_H */

// get user parameters from command line
void 
get_parameters(int argc, char* argv[], parameters_t *p)
{
  // defaults 
  p->grammar_root= NULL;

  int c; // return code for getopt_long

  // handle command line parameters
  while (1)
  {
    static struct option long_options[] = 
    {
      {"grammar",  required_argument,  0,  'g' },
      {0, 0, 0, 0}
    };

    int option_index = 0;
    c = getopt_long(argc, argv, "g:", long_options, &option_index);

    // If we've reached the end of the options, stop iterating
    if (c == -1)
      break;

    switch (c)
    {
      case 'g':
        p->grammar_root =  optarg;
        break;
      case '?':
        // Error message already printed by getopt_long -- we'll just exit
        exit(EXIT_FAILURE);
        break;
    }
  }

  // handle non-option arguments
  // check for too many arguments
  if (argc-optind > 1) 
  {
    fprintf(stderr, _("Error: Too many non-option arguments (only [GRAMMAR_ROOT] is permitted)\n") );
    exit(EXIT_FAILURE);
  }
  else if (argc-optind == 1) 
  {
    fprintf(stderr, _("Usage: either -g [grammar root folder] or --grammar [grammar root folder])\n") );
    exit(EXIT_FAILURE);
  }
}


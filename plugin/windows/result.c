/**
 * @file   result.c
 * 
 * <EN>
 * @brief  Plugin to process recognition result
 * </EN>
 * 
 * 
 * @author Akinobu Lee
 * @date   Fri Aug 22 15:17:59 2008
 * 
 * $Revision: 1.1 $
 * 
 */

/**
 * Required for a file
 *   - get_plugin_info()
 *
 * Optional for a file
 *   - initialize()
 * 
 */
/**
 * Result processing function
 * 
 *   - result_str()
 *   
 */

/***************************************************************************/

#include <stdio.h>
#include <string.h>
// !!!!!!
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <process.h>
void child(char *result_str);
// !!!!!!

#define PLUGIN_TITLE "plugin for Julius"

/** 
 * <EN>
 * @brief  Initialization at loading time (optional)
 * 
 * If defined, this will be called just before this plugin is loaded to Julius.
 * if this returns -1, the whole functions in this file will not be loaded.
 *
 * This function is OPTIONAL.
 * </EN>
 * <JA>
 * @brief  ÆÉ€ß¹þ€ß»þ€ÎœéŽü²œ¡ÊÇ€°Õ¡Ë
 *
 * µ¯Æ°»þ¡€Julius €¬€³€Î¥×¥é¥°¥€¥ó€òÆÉ€ß¹þ€àºÝ€ËºÇœé€ËžÆ€Ð€ì€ë¡¥
 * -1 €òÊÖ€¹€È¡€€³€Î¥×¥é¥°¥€¥óÁŽÂÎ€¬ÆÉ€ß¹þ€Þ€ì€Ê€¯€Ê€ë¡¥
 * ŒÂ¹Ô²ÄÇœÀ­€Î¥Á¥§¥Ã¥¯€Ë»È€š€ë¡¥
 *
 * </JA>
 * 
 * 
 * @return 0 on success, -1 on failure.
 * 
 */
int
initialize()
{
  return 0;
}

/** 
 * <EN>
 * @brief  Get information of this plugin (required)
 *
 * This function should return informations of this plugin file.
 * The required info will be specified by opcode:
 *  - 0: return description string of this file into buf
 *
 * This will be called just after Julius find this file and after
 * initialize().
 *
 * @param opcode [in] requested operation code
 * @param buf [out] buffer to store the return string
 * @param buflen [in] maximum length of buf
 *
 * @return 0 on success, -1 on failure.  On failure, Julius will ignore this
 * plugin.
 * 
 * </EN>
 * 
 */
int
get_plugin_info(int opcode, char *buf, int buflen)
{
  switch(opcode) {
  case 0:
    /* plugin description string */
    strncpy(buf, PLUGIN_TITLE, buflen);
    break;
  }

  return 0;
}


// to compile for Windows (from Cygwin terminal): i686-w64-mingw32-gcc -shared -o result.jpi result.c

// to run: clear && ./julius -input mic -C voxshell.jconf -plugindir plugin -quiet
void result_best_str(char *result_str)
{
printf("result %s\n", result_str); 
  pid_t pid; // process id
  if (result_str == NULL) {
    printf("[null result]\n");
  } else {
      child(result_str);
  }
}

void child(char *result)
{
//printf("child [%s]\n", result); 
  int status;
  int i;
  int parse_idx;
  char command[2048]; 

  bool reading_command=true;
  int command_idx=0;
  i=9; // skip [<s> COM "]
  //command[command_idx++] = '\\'; // put first escaped double quote in command string
  command[command_idx++] = '"';
  while ( result[i] != '<' && result[i] != '\0' ) // stops before "</s>"
  {
//printf("%i %c\n", i, result[i]);
    if (reading_command) 
    {
      if (result[i] == '"') // trailing double quotes
      {
        //command[command_idx++] = '\\'; // put first escaped double quote in command string
        command[command_idx++] = '"';
        reading_command=false;
      }
      else
      {
        command[command_idx++] = result[i];
      }
    }
    else // reading parameters
    {
      command[command_idx++] = result[i];  
    }

    i++;
  }
  command[command_idx]='\0';



  // debug
  //printf("command: [%s]\n", command); 

  //char parsed = "firefox.exe www.voxforge.org";

  //status = execvp(tokens[0], tokens); // does not work in mingw32; works in Cygwin
  //system("\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\" www.voxforge.org"); // blocks
  //status = system(command); // blocks until user closes firfox window
                              // spawns a shell to execute the command
  //int len=3;
  //const char *my_args[4]; // spawnv wants a constant char???
  //my_args[0]="C:\\Program Files\\Mozilla Firefox\\firefox.exe";
  //my_args[1]="-new-tab";
  //my_args[2]="www.voxforge.org/home/about";
  //my_args[3]='\0';
  //  printf("Debug: \n");
  //  for (i=0; i<len; i++)
  //  {
  //    printf("%d [%s]\n", i, my_args[i]);
  //  }
  // _flushall();
  //status = _spawnv(P_NOWAIT, "bob", my_args); // opens two firefox windows???? not sure why

  popen(command,"r"); 
  

  //if (status < 0)
  //{
  //  printf("Warning: can't find command: \n");
  //  for (i=0; i<len; i++)
  //  {
  //    printf("%d [%s]\n", i, my_args[i]);
  //  }
  //  exit(EXIT_FAILURE);
 // }
}



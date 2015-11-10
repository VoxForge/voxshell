/**
 * @file   voxshell.h
 * 
 * <EN>
 * @brief  header for voxshell.c
 * </EN>
 * 
 * @author voxforge
 * @date   Tue Nov 11 2015
 * 
 * $Revision: 0.3.1 $
 * 
 */

#ifndef CONFIG_H
#define CONFIG_H
#include "config.h"
#endif /* CONFIG_H */

#ifndef JULIUSLIB_H
#define JULIUSLIB_H
#include <julius/juliuslib.h>
#endif /* JULIUSLIB_H */

#ifndef SYS_TYPES_H
#define SYS_TYPES_H
#include <sys/types.h> 
#endif /* SYS_TYPES_H */

#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h> 
#endif /* UNISTD_H */

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h> 
#endif /* STDLIB_H */

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif /* STDBOOL_H */

#ifdef VF_WINDOWS
# include <process.h>
#else
# include <sys/wait.h>
#endif /* VF_WINDOWS */

// Callback to be called when start waiting speech input.
static void status_recready(Recog *recog, void *dummy);

// Callback to be called when speech input is triggered.
static void status_recstart(Recog *recog, void *dummy);

// output message according to the status code
static void process_status(RecogProcess *r);

// ############################################################################

// Callback to output final recognition result
static void output_result(Recog *recog, void *dummy);

#ifdef VF_WINDOWS
// exec parsed command
void win_process_command(char command[]);
// while parsing it replaces spaces with string endings ('\0')
void child(char *rec_result);
#endif /* VF_WINDOWS */

#ifdef VF_LINUX
// exec parsed command
void lin_process_command(char command[]);

// tokenize recognition result to determine command to call on exec or spawn
void parse_command(char result[], char *tokens[]);
#endif /* VF_LINUX */



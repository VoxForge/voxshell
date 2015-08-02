/**
 * @file   julius-simple.c
 * 
 * <EN>
 * @brief  Sample code for JuliusLib
 *
 * This is a simple code to link JuliusLib and do recognition.
 * 
 * This program will output recognition result to stdout according
 * to the given jconf setting.
 * </EN>
 * 
 * <JA>
 * @brief  JuliusLib用サンプルコード
 *
 * このコードは JuliusLib をリンクして簡単な認識器を構築します．
 *
 * このプログラムは音声入力に対して与えられた jconf 設定のもとで
 * 認識を行い，結果を標準出力に出力します．
 * 
 * </JA>
 * 
 * @author Akinobu Lee
 * @date   Tue Dec 11 14:40:04 2007
 * 
 * $Revision: 1.5 $
 * 
 */

/* include top Julius library header */
#include <julius/juliuslib.h>
// !!!!!!
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <sys/wait.h>
// !!!!!!


/** 
 * Callback to be called when start waiting speech input. 
 * 
 */
static void
status_recready(Recog *recog, void *dummy)
{
  if (recog->jconf->input.speech_input == SP_MIC || recog->jconf->input.speech_input == SP_NETAUDIO) {
    fprintf(stderr, "<<< please speak >>>");
  }
}

/** 
 * Callback to be called when speech input is triggered.
 * 
 */
static void
status_recstart(Recog *recog, void *dummy)
{
  if (recog->jconf->input.speech_input == SP_MIC || recog->jconf->input.speech_input == SP_NETAUDIO) {
    fprintf(stderr, "\r                    \r");
  }
}

static void
process_status(RecogProcess *r)
{
  /* outout message according to the status code */
  switch(r->result.status) 
  {
    case J_RESULT_STATUS_REJECT_POWER:
      printf("<input rejected by power>\n");
      break;
    case J_RESULT_STATUS_TERMINATE:
      printf("<input teminated by request>\n");
      break;
    case J_RESULT_STATUS_ONLY_SILENCE:
      printf("<input rejected by decoder (silence input result)>\n");
      break;
    case J_RESULT_STATUS_REJECT_GMM:
      printf("<input rejected by GMM>\n");
      break;
    case J_RESULT_STATUS_REJECT_SHORT:
      printf("<input rejected by short input>\n");
      break;
    case J_RESULT_STATUS_REJECT_LONG:
      printf("<input rejected by long input>\n");
      break;
    case J_RESULT_STATUS_FAIL:
      printf("<search failed>\n");
      printf("\a"); // ring terminal bell
      break;
  }
}

void 
parse_command(char result[], char *tokens[]) // modifies result string!
{
  int i; // result index counter
  int idx; // token index counter

  i=0;
  idx=0;
  tokens[idx++]=&(result[i]); 
  while ( result[i] != '\0' )
  {
    // skip non-valid ASCII printable characters && special characters (&,|,<,>)
    if ( (result[i] >= 32 && result[i] <= 126) &&
         (result[i] != '\t' && result[i] != '&' && result[i] != '|'  && 
           result[i] != '<' && result[i] != '>')
       ) 
    {
      // split command tokens based on space or tab
      if (result[i] == ' '|| result[i] == '\t') 
      {
        // terminate token string inside result string
        result[i]='\0'; 
        i++;
        // skip any additional spaces, tabs, 
        while ( result[i] == ' ' || result[i] == '\t' ) 
        {      
          i++; 
        }
        tokens[idx++]=&(result[i]); 
      }
    
    }
    else
    {
      printf("Warning: unsupported grammar character: [%c]\n", result[i]);
    }

    i++;
  }
  tokens[idx]='\0';
}

void 
process_command(char command[]) 
{
  char *tokens[100]; // array of pointers to strings (char arrays)
  pid_t pid; // process id
  int status;
  int len=2048;  // max parse_command length
  char command_modifiable[len];

  // see https://stackoverflow.com/questions/1961209/making-some-text-in-printf-appear-in-green-and-red
  printf("\033[1m\033[30mcommand [%s]\033[0m\n", command); /* Bold Black */

  strncpy(command_modifiable, command, len);
  parse_command(command_modifiable, tokens);

  pid = fork();
  if (pid < 0) 
  {
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  if(pid > 0) // parent
  {
    wait(NULL);
  } 
  else // child
  {
    status = execvp(tokens[0], tokens); 
    if (status < 0)
    {
      printf("Warning: can't find command: [%s]\n", tokens[0]);
      exit(EXIT_FAILURE);
    }
  }
}

/** 
 * Callback to output final recognition result.
 * This function will be called just after recognition of an input ends
 * 
 */
static void
output_result(Recog *recog, void *dummy)
{
  int i;
  WORD_INFO *winfo;
  WORD_ID *seq;
  int seqnum;
  int n;
  Sentence *s;
  RecogProcess *r;
  // !!!!!!
  bool skip;
  int min_confidence=.7;

  //PROCESS_LM *lm;
  //for(lm=recog->lmlist;lm;lm=lm->next) {
  //  printf("lmlist %d\n", multigram_get_all_num(lm) );
  // }
  // !!!!!!
  /* all recognition results are stored at each recognition process
     instance */
  for(r=recog->process_list;r;r=r->next) 
  {

    /* skip the process if the process is not alive */
    if (! r->live) continue;

    /* result are in r->result.  See recog.h for details */

    /* check result status */
    if (r->result.status < 0)  /* no results obtained */
    {     
      process_status(r);
      /* continue to next process instance */
      continue;
    }

    /* output results for all the obtained sentences */
    winfo = r->lm->winfo;

    /* for all sentences */
    for(n = 0; n < r->result.sentnum; n++) 
    { 
      s = &(r->result.sent[n]);
      seq = s->word;
      seqnum = s->word_num;

      // !!!!!!
      skip=false;
      for (i=0;i<seqnum; i++) 
      {
        if (s->confidence[i] < min_confidence)
        {
          printf("word %d confidence too low: %5.3f\n", i+1, s->confidence[i]);
          skip=true;
        }
      }
      if (skip)
      {
        printf("\a"); // ring terminal bell
      }
      else
      {
        // the before last word in woutput contains the command to execute
        char *command = winfo->woutput[seq[seqnum-2]];
        if (command == NULL) 
        {
          printf("[null result]\n");
        } 
        else
        {
          process_command(command);
        }
      }
      // !!!!!!
    }
  }

  /* flush output buffer */
  fflush(stdout);
}


/**
 * Main function
 * 
 */
int
main(int argc, char *argv[])
{
  /**
   * configuration parameter holder
   * 
   */
  Jconf *jconf;

  /**
   * Recognition instance
   * 
   */
  Recog *recog;

  int ret;

  /* by default, all messages will be output to standard out */
  /* to disable output, uncomment below */
  //jlog_set_output(NULL); // disable start up log output; replaces -logfile

  /* output log to a file */
  //FILE *fp; fp = fopen("log.txt", "w"); jlog_set_output(fp);

  /* if no argument, output usage and exit */
  if (argc == 1) 
  {
    fprintf(stderr, "Julius rev.%s - based on ", JULIUS_VERSION);
    j_put_version(stderr);
    fprintf(stderr, "Try '-setting' for built-in engine configuration.\n");
    fprintf(stderr, "Try '-help' for run time options.\n");
    return -1;
  }

  /************/
  /* Start up */
  /************/
  /* 1. load configurations from command arguments */
  jconf = j_config_load_args_new(argc, argv);
  /* else, you can load configurations from a jconf file */
  //jconf = j_config_load_file_new(jconf_filename);
  if (jconf == NULL) 
  {		/* error */
    fprintf(stderr, "Try `-help' for more information.\n");
    return -1;
  }
  
  /* 2. create recognition instance according to the jconf */
  /* it loads models, setup final parameters, build lexicon
     and set up work area for recognition */
  recog = j_create_instance_from_jconf(jconf);
  if (recog == NULL) 
  {
    fprintf(stderr, "Error in startup\n");
    return -1;
  }

  /*********************/
  /* Register callback */
  /*********************/
  /* register result callback functions */
  callback_add(recog, CALLBACK_EVENT_SPEECH_READY, status_recready, NULL);
  callback_add(recog, CALLBACK_EVENT_SPEECH_START, status_recstart, NULL);
  callback_add(recog, CALLBACK_RESULT, output_result, NULL);

  /**************************/
  /* Initialize audio input */
  /**************************/
  /* initialize audio input device */
  /* ad-in thread starts at this time for microphone */
  if (j_adin_init(recog) == FALSE)  /* error */
  {   
    return -1;
  }

  /* output system information to log */
  j_recog_info(recog);

  /***********************************/
  /* Open input stream and recognize */
  /***********************************/

  /* raw speech input (microphone etc.) */

  switch(j_open_stream(recog, NULL)) 
  {
    case 0:			/* succeeded */
      break;
    case -1:      		/* error */
      fprintf(stderr, "error in input stream\n");
      return(0);
    case -2:			/* end of recognition process */
      fprintf(stderr, "failed to begin input stream\n");
      return(0);
  }
  
  /**********************/
  /* Recognization Loop */
  /**********************/
  /* enter main loop to recognize the input stream */
  /* finish after whole input has been processed and input reaches end */
  ret = j_recognize_stream(recog);
  if (ret == -1) 	/* error */
  {
    return -1;
  }
  /*******/
  /* End */
  /*******/


  /* calling j_close_stream(recog) at any time will terminate
     recognition and exit j_recognize_stream() */
  j_close_stream(recog);

  j_recog_free(recog);

  /* exit program */
  return(0);
}

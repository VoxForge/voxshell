#!/bin/bash
# see: https://stackoverflow.com/questions/9666102/bash-double-bracket-issue
# On Ubuntu systems, /bin/sh is dash, not bash, and dash does not support the 
# double bracket keyword. You can solve your problem by explicitly invoking 
# bash instead

if [[ $(ps -Al | grep rhythmbox) =~ 'rhythmbox' ]]
then
  rhythmbox-client --pause
fi
inxi -w -c 0
if [[ $(inxi -w -c 0) =~ 'Weather:' ]]
then
  inxi -w -c 0 | awk '{print $5, "Selsius", $8 $9}' | festival --tts # using phonetic spelling for Celcius
fi

if [[ $(ps -Al | grep rhythmbox) =~ 'rhythmbox' ]]
then
  rhythmbox-client --play
fi

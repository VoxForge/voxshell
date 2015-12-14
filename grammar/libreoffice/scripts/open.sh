#!/bin/bash 

# find window
WID=`xdotool search --class firefox | tail -1` 
if [[ -z "$WID" ]]; then
  echo -ne '\007' # beep
  echo "Firefox Window not found, starting Firefox"
  firefox &
  WID=`xdotool search --class firefox | tail -1` 
fi
sleep .5s
xdotool windowfocus $WID 



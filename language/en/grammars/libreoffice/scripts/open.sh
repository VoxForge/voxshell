#!/bin/bash 

# find window
WID=`xdotool search --class libreoffice | tail -1` 
if [[ -z "$WID" ]]; then
  echo -ne '\007' # beep
  echo "LibreOffice Window not found, starting LibreOffice"
  libreoffice &
fi
sleep .5s
xdotool windowfocus $WID 
# go to find window
xdotool key alt+f 
xdotool key u 
xdotool key 1


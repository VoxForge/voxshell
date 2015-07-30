#!/bin/bash 

# find rhythmbox window
WID=`xdotool search --class rhythmbox | tail -1` 
xdotool windowfocus $WID 
# go to find window
xdotool key ctrl+f 
# write parameter in find window
xdotool type $1

xdotool key "Return"


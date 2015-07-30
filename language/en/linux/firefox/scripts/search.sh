#!/bin/bash 

# not working... cannot select the first result??? 
WID=`xdotool search --name "Mozilla Firefox" | head -1` 
xdotool windowfocus $WID 
xdotool key ctrl+l 
xdotool key Tab 
xdotool type $1
xdotool key "Return"
xdotool key Down 
xdotool key "Return"

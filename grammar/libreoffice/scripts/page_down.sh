#!/bin/bash 
WID=`xdotool search --class libreoffice | tail -1` 
xdotool windowfocus $WID
# see: /usr/share/X11/xkb/symbols/pc
xdotool key Next


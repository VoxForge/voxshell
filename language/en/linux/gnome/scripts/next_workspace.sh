#!/bin/bash 
#see: http://www.artificialworlds.net/blog/2011/03/04/switching-workspace-in-gnome-via-the-command-line/
CURRENT_WS=`wmctrl -d | grep \* | cut -d " " -f 1`
NEW_WS=`echo $CURRENT_WS "+" 1 | bc`
wmctrl -s $NEW_WS



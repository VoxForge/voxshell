#!/bin/bash 

### add music group to Rhythmbox queue
# find rhythmbox window
WID=`xdotool search --class rhythmbox | tail -1` 
xdotool windowfocus $WID 
# go to find window
xdotool key ctrl+f 
# write parameter in find window (empty parameters get ignored by search)
xdotool type $1 " " $2 " " $3 " " $4 " " $5
xdotool key "Return"
sleep 0.6s
### start playing selected music group
rhythmbox-client --next
rhythmbox-client --play

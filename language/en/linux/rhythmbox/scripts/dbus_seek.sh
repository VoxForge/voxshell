#!/bin/bash
# see: http://specifications.freedesktop.org/mpris-spec/latest/Player_Interface.html
dbus-send --print-reply --dest=org.mpris.MediaPlayer2.rhythmbox /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Seek int64:$1

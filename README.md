# VoxShell

VoxShell is a simple command and control dialog manager that uses the [Julius](http://julius.osdn.jp/en_index.php)
speech recognition engine and [VoxForge](http://www.voxforge.org) acoustic models.

In the most generic sense, the term 'shell' means any program that a user
employs to type commands.  Unlike a regular shell, VoxShell allows 
you to speak key words or phrases into a microphone to execute those commands. 
You can set up grammars to execute any shell command or program using your 
own voice. 

[Julius](http://julius.osdn.jp/en_index.php) is a high-performance, two-pass large vocabulary continuous speech 
recognition (LVCSR) decoder.  [VoxForge](http://www.voxforge.org) is a 'Free' speech repository (speech 
corpus) that uses the collected speech to create acoustic models.

# Try it out

Extract the github zip file to a directory, and execute one of the following 
command:

##  Linux:

### Software prerequisites

  [Julia](http://julialang.org/) - scripting language (required to compile  grammars); [Julius](http://julius.osdn.jp/en_index.php) large vocabulary speech recognition engine (dfa_minimize & mkfa)

      # yum install julius
      # yum install julia

### Grammar prerequisites

  Gnome grammar requires: wmctrl - command line interface to X Window Manager; xdotool - command-line X11 automation tool.

      # yum install wmctrl xdotool

  Rhythmbox grammar requires: rhythmbox-client - controls a running instance of rhythmbox; dbus-send - Send a message to a message bus.

      # yum install rhythmbox-client dbus-send

  Shell grammar requires: inxi - Command line system information script for console (for weather lookup); festival - text-to-speech system

      # yum install inxi festival

### commands

      $ make
      $ bin/julius-simple -input mic -C voxshell.jconf -gramlist language/en/grammars_linux

Look to the .vox and .grammar grammar files to see what the system will recognize (e.g. language/en/linux/rhythmbox/rhythmbox.vox & rhythmbox.grammar.  If you modify one of the grammar files, just run 'make' at the top level directory.

##  Windows:

      C:> bin\windows\julius.exe -input mic -C voxshell.jconf -gramlist language/en/grammars_windows.txt -plugindir bin/windows/plugin -logfile julius.log  

Note that we need many more speech submissions to create high quality free Acoustic 
Models.  Please take the time to submit some speech to [www.voxforge.org](http://www.voxforge.org) using the 
[VoxForge speech applet](http://www.voxforge.org/home/read).

thank you,

VoxForge.

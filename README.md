# VoxShell

VoxShell is a simple command and control dialog manager that uses the Julius
speech recognition engine and [VoxForge](http://www/voxforrge.org) acoustic models.

In the most generic sense, the term 'shell' means any program that a user
employs to type commands.  However, unlike a regular shell, VoxShell allows 
you to speak key words or phrases into a microphone to execute those commands. 
You can set up grammars to execute any shell command or program using your 
own voice. 

Julius is a high-performance, two-pass large vocabulary continuous speech 
recognition (LVCSR) decoder.  [VoxForge](http://www/voxforrge.org) is a 'Free' speech repository (speech 
corpus) that uses the collected speech to create acoustic models.

# Try it out

Extract the github zip file to a directory, and execute one of the following 
command:

  Linux:
 
      $ bin/julius -input mic -C voxshell.jconf -gramlist grammars_linux -plugindir plugin/linux

  Windows:

      C:> bin\julius.exe -input mic -C voxshell.jconf -gramlist grammars_windows.txt -plugindir plugin/windows

Note that we need many more speech submissions to create high quality free Acoustic 
Models.  Please take the time to submit some speech to www.voxforge.org using the 
VoxForge speech applet.

thank you,

VoxForge.

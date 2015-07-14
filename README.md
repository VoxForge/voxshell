# voxshell

VoxShell is a simple command and control dialog manager that uses the Julius
speech recognition engine and VoxForge acoustic models.

Julius is a high-performance, two-pass large vocabulary continuous speech 
recognition (LVCSR) decoder.  VoxForge is a Free speech repository (speech 
corpus) that uses the collected speech to create Free and Open acoustic models.

In the most generic sense, the term 'shell' means any program that a user
employs to type commands.  VoxShell is a shell program that uses the
underlying operating system as its command dispatcher.  Users can create 
commands in any language to be executed when predefined keywords or phrases
are spoken into a microphone.

Extract the github zip file to a directory, and execute one of the following 
command:

  Linux:
 
      $ bin/julius -input mic -C voxshell.jconf -gramlist grammars_linux -plugindir plugin/linux

  Windows:

      C:> bin\julius.exe -input mic -C voxshell.jconf -gramlist grammars_windows.txt -plugindir plugin/windows

For information on the Julius grammar syntax, see the enclosed GRAMMAR_NOTES.

Note that we need many more speech submissions to create high quality free Acoustic 
Models.  Please take the time to submit some transcribed speech to www.voxforge.org.

thank you,

VoxForge.

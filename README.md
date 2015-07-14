# voxshell

# notes
Linux version works; still working Windows side

# draft description
Speech Recognition Shell using Julius, a high-performance, two-pass large 
vocabulary continuous speech recognition (LVCSR) decoder.

VoxForge & Julius Quick Start.

This Tar file contains everything you need to get Julius working:
 * Julius Run-time engine executable;
 * VoxForge Acoustic Model files;
 * VoxForge sample Grammar files.

Extract the gzipped tar file to a directory, and execute the following command:
Linux:
 
  $ bin/julius -input mic -C voxshell.jconf -gramlist grammars_linux -plugindir plugin/linux

Windows:

  C:> bin\julius.exe -input mic -C voxshell.jconf -gramlist grammars_windows.txt -plugindir plugin/windows

For information on the Julius grammar syntax, see the enclosed GRAMMAR_NOTES.

Note that we need many more speech submissions to create decent quality Acoustic 
Models.  Please take the time to submit some transcribed speech to www.voxforge.org.

thank you,

VoxForge.

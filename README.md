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

follow instructions in INSTALL.md.

##  Linux:

### run VoxShell version of julius
      
      $ bin/voxshell -input mic -C voxshell.jconf -gramlist language/en/grammars_linux

### how do grammar files work?

Look to the .vox and .grammar grammar files to see what the system will recognize (e.g. language/en/linux/rhythmbox/rhythmbox.vox & rhythmbox.grammar).  

If you modify one of the grammar files, just run make in the top voxshell directory to recompile your grammar files (i.e. .dict, .dfa, .term).

##  Windows:

      C:> bin\windows\julius.exe -input mic -C voxshell.jconf -gramlist language/en/grammars_windows.txt -plugindir bin/windows/plugin -logfile julius.log  

# Submit speech samples to make better acoustic models

We need many more speech submissions to create high quality free Acoustic 
Models.  Please take the time to submit some speech to [www.voxforge.org](http://www.voxforge.org) using the [VoxForge speech applet](http://www.voxforge.org/home/read).

thank you!

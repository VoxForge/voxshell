# VoxShell install

Extract the github zip file to a directory.

## Linux software prerequisites

  [Julius](http://julius.osdn.jp/en_index.php) is a large vocabulary speech recognition engine.  VoxShell uses the Julius backend libraries for speech recognition and grammar creation/update.

###  Fedora:

#### install voxshell compile dependencies

     $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel pulseaudio-libs pulseaudio-libs-devel alsa-plugins-pulseaudio

#### install Julia

      $ sudo yum install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars

### Ubuntu:

#### install voxshell compile dependencies

      $ sudo apt-get install build-essential libasound2-dev libasound2-plugins libc6 libc6-dev zlib1g-dev

#### install Julia

     $ sudo apt-get install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars.


### build executable and compile grammars

#### to install VoxShell binaries to default (/usr/local/bin)

  * $ configure 
  * $ make
  * $ sudo make install

#### to install VoxShell binaries to another location

  * $ configure --prefix=pathToVoxShell      # e.g. --prefix=~/voxshell to create a bin directory in the voxshell folder
  * $ make
  * $ sudo make install


## Grammar Dependencies

  The Julius grammars can be build without these dependencies.  However, if you try to execute certain speech commands, nothing will happen because the associated program has not been installed.

### Rhythmbox grammar 

  requires: **rhythmbox-client** (controls a running instance of rhythmbox); **dbus-send** (send a message to a message bus).

  Fedora:

      # yum install rhythmbox-client dbus-send

  Ubuntu:

    these are installed by default.

### Gnome grammar 

  requires: **wmctrl** (command line interface to X Window Manager); **xdotool** (command-line X11 automation tool).

  Fedora:

      $ sudo yum install wmctrl xdotool

  Ubuntu:

      $ sudo apt-get install wmctrl xdotool   

### Shell grammar

  requires: **inxi** (command line system information script for console - used for weather lookup example); **festival** (text-to-speech system).

  Fedora:

      $ sudo yum install inxi festival

  Ubuntu:

      $ sudo apt-get install inxi festival

##  Windows:

  Currently uses prebuilt binaries - no make required.


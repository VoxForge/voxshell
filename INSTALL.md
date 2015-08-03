# VoxShell install

Extract the github zip file to a directory.

## Linux software prerequisites

  [Julius](http://julius.osdn.jp/en_index.php) is a large vocabulary speech recognition engine.  VoxShell uses the Julius backend libraries.  We need Julius rev.4.3.1 to be able to compile VoxShell on your computer.  Unfortunately, Fedora 22 & Ubuntu 14.01 both use Julius rev.4.2.2.  

  To get around this, the VoxShell includes static libraries in the 'lib' and 'lib64' directories.  The /src/Makefile uses lib64 by default, see below to change it for 32-bit architectures.  We still need Julius because the package provides the dfa_minimize & mkfa executables used for grammar compilation.

###  Fedora:

#### Julius

     $ sudo yum install julius

#### compile dependencies

     $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel pulseaudio-libs pulseaudio-libs-devel alsa-plugins-pulseaudio

#### Julia

      $ sudo yum install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars

### Ubuntu:

#### Julius

     $ sudo apt-get install julius

#### compile dependencies

      $ sudo apt-get install build-essential libasound2-dev libasound2-plugins libc6 libc6-dev zlib1g-dev

#### install Julia

     $ sudo apt-get install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars.


### build executable and compile grammars

#### update voxshell Makefile

  Manually update the src/Makefile to point to your VoxShell directory, and set your computer architecture (i.e. 32-bit or 64-bit-default)

#### run make command

  'make' is a tool to generate executables and other non-source files from a program's source files.

      $ make

## grammar dependencies

  The Julius grammars can be build without these dependencies.  However, if you try to execute certain speech commands, nothing will happen because the underlying package has not been installed.

  Rhythmbox grammar requires: **rhythmbox-client** (controls a running instance of rhythmbox); **dbus-send** (send a message to a message bus).

      # yum install rhythmbox-client dbus-send

  Gnome grammar requires: **wmctrl** (command line interface to X Window Manager); **xdotool** (command-line X11 automation tool).

      # yum install wmctrl xdotool

  Shell grammar requires: **inxi** (command line system information script for console - used for weather lookup example); **festival** (text-to-speech system).

      # yum install inxi festival


##  Windows:

  Currently uses prebuilt binaries - no make required.


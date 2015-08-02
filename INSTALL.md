# VoxShell install

Extract the github zip file to a directory.

## Linux software prerequisites

###  Fedora:

####older than Julius r4.3.1

  You need Julius r4.3.1 to be able to compile voxshell on your computer.  
Unfortunately, Fedora 23 uses Julius r4.2.2.  To get around this, the VoxShell
includes 32-bit static libraries in the 'lib' directory.  The /src/Makefile 
uses these by default.

  Install [Julius](http://julius.osdn.jp/en_index.php) (large vocabulary speech recognition engine - provides the dfa_minimize & mkfa executables used for grammar compilation): 

      $ sudo yum install julius

####Julius r4.3.1 or later

  If your O/S package manager installs Julius r4.3.1 or later, then install these dependencies:

      $ sudo yum install julius julius-devel pulseaudio-libs-devel zlib-devel flex-devel alsa-lib-devel

  And, update the src/Makefile to use your O/S dynamic shared libraries.

####Julia

  Install [Julia](http://julialang.org/) (scripting language required  to compile  grammars).

      $ sudo yum install julia

###  Ubuntu:

  You need Julius r4.3.1 to be able to compile voxshell on your computer.  
Unfortunately, Ubuntu 14.01 uses Julius r4.2.2.  To get around this, the VoxShell
includes 32-bit static libraries in the 'lib' directory.  The /src/Makefile 
uses these by default.

  Install [Julius](http://julius.osdn.jp/en_index.php) (large vocabulary speech recognition engine - provides the dfa_minimize & mkfa executables) - you need the executable and development packages: 

      $ sudo apt-get install julius julius-devel build-essential zlib1g-dev flex libasound2-dev libesd0-dev libsndfile1-dev

  Install [Julia](http://julialang.org/) (scripting language required  to compile  grammars).

      $ sudo apt-get install julia

####Julius r4.3.1 or later

  If your O/S package manager installs Julius r4.3.1 or later, then install these dependencies:

      $ sudo yum install julius julius-devel pulseaudio-libs-devel zlib-devel flex-devel alsa-lib-devel

  And, update the src/Makefile to use your O/S dynamic shared libraries.

####Julia

  Install [Julia](http://julialang.org/) (scripting language required  to compile  grammars).

     $ sudo apt-get install julia

## grammar prerequisites

  Rhythmbox grammar requires: **rhythmbox-client** (controls a running instance of rhythmbox); **dbus-send** (send a message to a message bus).

      # yum install rhythmbox-client dbus-send

  Gnome grammar requires: **wmctrl** (command line interface to X Window Manager); **xdotool** (command-line X11 automation tool).

      # yum install wmctrl xdotool

  Shell grammar requires: **inxi** (command line system information script for console - used for weather lookup example); **festival** (text-to-speech system).

      # yum install inxi festival

### build executable and compile grammars

  Make is a tool to generate executables and other non-source files from the program's source files.  It can be run serially (one build command at a time), or in parallel, with the -j parameter, with a number indicating the number of build jobs to run concurrently.

      $ make        # to run make serially (one grammar build at a time)
      -or-
      $ make -j 4   # to run make in parallel, with max of 4 jobs at same time

##  Windows:

  Currently uses prebuilt binaries - no make required.


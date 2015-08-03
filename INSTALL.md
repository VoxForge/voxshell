# VoxShell install

Extract the github zip file to a directory.

## Linux software prerequisites

  You need Julius r4.3.1 to be able to compile voxshell on your computer.  Unfortunately, Fedora 23 & Ubuntu 14.01 both use Julius r4.2.2.  To get around this, the VoxShell includes static libraries in the 'lib' and
'lib64' directories.  The /src/Makefile uses these by default.

###  Fedora:

#### install Julius

     $ sudo yum install julius

  [Julius](http://julius.osdn.jp/en_index.php) is a large vocabulary speech recognition engine.  Voxshell replaces the 'julius' front-end to the julius libraries.  We still need it because the package provides the dfa_minimize & mkfa executables used for grammar compilation.

#### get version Julius number

     $ julius

####older than Julius rev.4.3.1

  If your package manager installs a version of Julius older than r4.3.1, then install these dependencies:

     $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel pulseaudio-libs pulseaudio-libs-devel alsa-plugins alsa-plugins-pulseaudio

####Julius r4.3.1 or later

  If your package manager installs Julius r4.3.1 or newer, then install these dependencies:

      $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel pulseaudio-libs pulseaudio-libs-devel alsa-plugins alsa-plugins-pulseaudio

  And, update the src/Makefile to use your O/S dynamic shared libraries.

####Julia

  Install [Julia](http://julialang.org/) (scripting language used to compile VoxShell grammars).

      $ sudo yum install julia









### Ubuntu:

#### install Julius

     $ sudo apt-get install julius

  [Julius](http://julius.osdn.jp/en_index.php) is a large vocabulary speech recognition engine.  Voxshell replaces the 'julius' front-end to the julius libraries.  We still need it because the package provides the dfa_minimize & mkfa executables used for grammar compilation.

####older than Julius r4.3.1

  Install [Julius](http://julius.osdn.jp/en_index.php) (large vocabulary speech recognition engine - provides the dfa_minimize & mkfa executables used for grammar compilation): 

      $ sudo apt-get install julius libjulius-dev build-essential zlib1g-dev flex libsndfile1-dev libc6-dev-i386 libasound2-dev:i386 libasound2-plugins:i386

####Julius r4.3.1 or later

  If your O/S package manager installs Julius r4.3.1 or later, then install these dependencies:

      $ sudo yum install julius julius-devel pulseaudio-libs-devel zlib-devel flex-devel alsa-lib-devel

  And, update the src/Makefile to use your O/S dynamic shared libraries.

####Julia

  Install [Julia](http://julialang.org/) (scripting language used to compile VoxShell grammars).

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
      $ make -j n   # to run grammar makes in parallel, with max of n jobs at same time

##  Windows:

  Currently uses prebuilt binaries - no make required.


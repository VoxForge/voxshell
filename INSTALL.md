# VoxShell install

Extract the github zip file to a directory.

## Linux software prerequisites

  remove all [Julius](http://julius.osdn.jp/en_index.php) executables and development packages.

  remove Julius header files in: /usr/include/julius; and
  and remove static libraries:
    /usr/lib/libsent.a
    /usr/lib/libjulius.a

###  Fedora:

#### install voxshell compile dependencies

     $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel pulseaudio-libs pulseaudio-libs-devel alsa-plugins-pulseaudio

#### install Julia

      $ sudo yum install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars

### Ubuntu:

#### install voxshell compile dependencies

      $ sudo apt-get install build-essential libasound2-dev libasound2-plugins libc6 libc6-dev zlib1g-dev libpulse-dev

#### install Julia

     $ sudo apt-get install julia

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars.


### build executable and compile grammars

#### to compile and install VoxShell binaries
##### to default (/usr/local/bin)

  * $ configure --disable-shared --with-mictype=alsa
  * $ make
  * $ sudo make install

##### to another location

  * $ configure --disable-shared --prefix=pathToVoxShell      # e.g. --prefix=~/voxshell to create a bin directory in the voxshell folder
  * $ make
  * $ sudo make install

#### to compile grammars

    $ make grammar

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


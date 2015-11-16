# VoxShell install

Extract the github zip file to a directory.

- or- 

Follow the instructions on github to clone voxshell to your computer

  * git clone https://github.com/VoxForge/voxshell.git

## Linux software prerequisites

  remove all [Julius](http://julius.osdn.jp/en_index.php) executables and development packages.

  remove Julius header files in: 
    * /usr/include/julius; 

  remove static libraries:
    *  /usr/lib/libsent.a; 
    *  /usr/lib/libjulius.a

###  Fedora:

#### install voxshell compile dependencies

     $ sudo yum install gcc glibc-devel libgcc alsa-lib alsa-lib-devel

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

#### to compile and install VoxShell binaries
##### to default (/usr/local/bin)

  * $ autoreconf -ivf
  * $ configure
  * $ make -j
  * $ sudo make install

##### to another location

  * $ autoreconf -ivf
  * $ configure --prefix=pathToVoxShell      # e.g. pathToVoxShell=*full path* to folder where voxshell is to be installed
  * $ make -j
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

#### Mingw
  
  MingW is preferred over Cynwin because an executable created using MingW 
  can be executed in a regular Windows Command Prompt window without any
  additional files. 

  Download and install [Mingw installer](http://www.mingw.org/category/wiki/download) 

#### install voxshell compile dependencies

  use the mingw-get GUI installer to install the following dependencies:

  Basic Setup
    Package
      mingw-developer-toolkit
      mingw32-base
      msys-base
  All Packages
    MinGW
      mingw32-autoconf
      mingw32-autotools
      mingw32-base
      mingw32-binutils
      mingw32-gcc
      mingw32-libgcc
      mingw32-libtool
      mingw32-libz
      mingw32-make
      mingw32-mingwrt
    MSYS
      msys-autoconf
      msys-automake
      msys-base
      msys-bash
      msys-bison
      msys-core
      msys-coreutils
      msys-dos2unix
      msys-flex
      msys-libz2
      msys-m4
      msys-make

  msys is you unix-style command shell and is located at

    C:\MinGW\msys\1.0\msys.bat

  It is easiest to create a shortcut on your desktop of the msys start script.

#### install Julia

  Download and install [Julia](http://julialang.org/downloads/)

  [Julia](http://julialang.org/) is the scripting language used to compile VoxShell grammars


### build executable and compile grammars

#### to compile and install VoxShell binaries
##### to default (/usr/local/bin)

  From an msys console, execute the following commands:

  * $ git config core.autocrlf = input
  * $ git clone git@github.com:VoxForge/voxshell.git
  * $ autoreconf -ivf
  * $ configure --prefix=pathToVoxShell      # e.g. pathToVoxShell=full path to folder to install voxshell
  * $ make -j
  * $ sudo make install

  


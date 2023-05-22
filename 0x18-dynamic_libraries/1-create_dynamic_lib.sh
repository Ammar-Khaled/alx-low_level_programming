#!/bin/bash

# First, How to create a shared library
gcc -c -fPIC *.c
# -c: tells gcc to only compile the code into an object file, 
# without linking it into an executable.
# -fPIC: tells gcc to generate the object files in the format of
# Position-Independent Code, which can be loaded and excuted at 
# any memory address, in order to be used in a shared library

gcc -shared -o liball.so *.o
# -shared: tells gcc to create a shared library, 
# which is a library that can be dynamically loaded at runtime by programs that depend on it.

# nm -D liball.so
# nm: show the symbols in object files and libraries
# -D: tells nm to only show dynamic symbols, 
# i.e. symbols that can be resolved at runtime by the dynamic linker.

#################################

# Second How to utilize a shared library
# 1- include its header into your source files

# 2- compile your files like this:
# gcc -L . 0-main.c -l dynamic 
# -L . : is an option that tells the linker to search for shared libraries in the current directory (represented by .)
# This is necessary when linking with a shared library that is not installed in a system directory.
# -l dynamic : is an option that tells the linker to link with the shared library named "lib + name_you_provide +.so",
# which provides the implementation for some of the functions called in 0-main.c.
# Notice that this option should be after 0-main.c

# tip: ldd a.out =>  print shared object dependencies
# prints  the shared objects (shared libraries) required by each program or shared object specified on the command line.

# 3- to load your shared lib during runtime
# * you have to add the location of your library files
#  into the environmental variable LD_LIBRARY_PATH to know where to find the functions.
# > export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
# or
# * copy your dynamic library into the /usr/lib directory
# > sudo cp libdynamic.so /usr/lib

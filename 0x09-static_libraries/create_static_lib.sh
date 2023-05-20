#!/bin/bash
gcc -c *.c  # compile all .c files without linking them => generates object files
ar -cr liball.a *.o  # -c create the archive, -r insert files into archive with replacement
ranlib liball.a  # create a random library, which contains symbol table used by linker, from the archive library

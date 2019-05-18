#
# Makefile for the disk emulator
# Author: Reham Islam
# Date: Spring 2017
#
# A List of all the source files that should be compiled together
#
SOURCES = UI.h FileSystem.h directory.h FileControlBlock.h diskprocess.cpp driver.cpp

#
# A list of the objects that result from the compilation process
#
OBJECTS = diskprocess.o FileSystem.o FileControlBlock.o driver.o UI.o directory.o
#
# A list of include files on which theh compilation depends
#
//DEFS = 
#
# What flags to send to the compiler when you compile source files
#
CPPFLAGS = -g
#
# Any libraries that should be included in the linkage step of compilation
LIBFLAGS = -lm

#

demo: $(SOURCES) $(DEFS)
	g++ $(CPPFAGS) $(SOURCES) -o demo $(LIBFLAGS)

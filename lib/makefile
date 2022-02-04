##
#
# makefile : build instructions for the project.
#
# See `LICENSE' for full license.
# See `README.md' for project details.
#
##

##
#
# Copyright (C) 2021 Kevin Matthes & 2022 Niklas Leukroth
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
##

################################################################################

##
#
# Variables.
#
##

# Software.
ARCHIVE	:= ar
# ARCHIVE	:= x86_64-w64-mingw32-ar
CC		:= g++
# CC		:= x86_64-w64-mingw32-g++
COPY	:= cp
DOXYGEN	:= doxygen
NEWDIR	:= mkdir
REMOVE	:= rm

# Software flags.
AFLAGS		:= rs
CFLAGS		:= -std=c++11 -Wall -Werror -Wextra -Wpedantic -D__ELLIPSE_INTERNAL__
LFLAGS		:= -lm
DLLFLAGS	:= -s -shared -Wl,--subsystem,windows,--out-implib,libellipse.a
WINFLAGS	:= -D_WINDOWS -D_MAKEDLL

# Make directories.
MDOX	:= -C ../.docs/latex/

# Directories.
LIBDIR	:= ../../lib/
DIRS	:= $(LIBDIR)

# Library compilation requirements.
HEADERS	:= $(wildcard ./*.hpp)
LIBRARY	:= ./libellipse.a
DLL 	:= ./ellipse.dll
SOURCE	:= $(wildcard ./*.cpp)
OBJECTS	:= $(subst .cpp,.o, $(SOURCE))

# Concrete files.
DOXYFILE	:= ./doxygen.cfg
SELF		:= ./makefile



##
#
# Build instructions.
#
##

.PHONY: default doxygen library submodule tidy

default: library

$(DIRS):
	$(NEWDIR) $@

doxygen: $(wildcard ./*.dox) $(HEADERS) $(SOURCE)
	$(DOXYGEN) $(DOXYFILE)
	make $(MDOX) all

library: $(LIBRARY)

DLL : ellipse.o
	$(CC) $(CFLAGS) -o ellipse.dll ellipse.o $(DLLFLAGS)

$(LIBRARY): $(OBJECTS)
#In case of windows, create a dll
	@make DLL
	$(ARCHIVE) $(AFLAGS) $@ $^

$(OBJECTS): $(SOURCE)
#In case of windows, compile with the windows specific flags
	$(CC) $(CFLAGS) -c $(LFLAGS) $(WINFLAGS) $^


submodule: $(HEADERS) $(LIBRARY) $(LIBDIR)
	$(COPY) $(HEADERS) $(LIBRARY) $(LIBDIR)
	make tidy

tidy: $(LIBRARY) $(OBJECTS)
	$(REMOVE) $^
################################################################################

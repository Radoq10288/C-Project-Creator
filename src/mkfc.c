/* C Project Creator - A command line tool that setup basic C project.
 * Copyright (C) 2021 Radoq10288
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


/* File:			mkfc.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation file of mkfc.h
 *
 * Date created:	04-20-2021-11:14:24-AM
 */


#include "cpcerr.h"
#include "fc.h"
#include <stdio.h>


int create_exec_makefile(char *c_filename) {

	char *makefile_template[] = {
		"# Directories\n",
		"BINDIR = bin\n",
		"SRCDIR = src\n",
		"OBJDIR = obj\n\n\n",
		"# Program name\n",
		"PROGRAM = $(BINDIR)/", c_filename, ".exe\n\n",
		"# C compiler\n",
		"CC = mingw32-gcc\n\n",
		"# C compiler flags\n",
		"CFLAGS = -g -pedantic -std=c11 -Wall\n\n\n",
		"# C files\n",
		"CFILES = $(SRCDIR)/", c_filename, ".c\n\n",
		"# Object files\n",
		"OBJFILES = $(OBJDIR)/", c_filename, ".o\n\n\n",
		"# Build and compile program\n",
		"$(PROGRAM) : $(OBJFILES)\n",
		"\t$(CC) -o $(PROGRAM) $(OBJFILES)\n\n",
		"$(OBJDIR)/", c_filename, ".o : $(CFILES)\n",
		"\t$(CC) -c $(CFILES) $(CFLAGS)\n\n",
		"# Move any '*.o' file(s) to 'obj' directory.\n",
		"\t@mv *.o obj\n\n\n",
		"# Clean working directory\n",
		".PHONY: clean\n",
		"clean :\n",
		"\trm -f $(PROGRAM) $(OBJFILES)",
		"\n\n\n"
	};

	int mkft_size = sizeof(makefile_template) / sizeof(char*),
		cem_status;

	cem_status = create_txt_file("makefile", "", makefile_template, mkft_size);
	if (cem_status) {
		goto handle_error;
	}

	return CPC_OK;

	handle_error:
	return cem_status;
}



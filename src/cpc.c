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


/* File:			cpc.c
 *
 * Author:			Radoq10288
 *
 * Description:		A command line tool that setup basic C project.
 *
 * Date created:	04-17-2021-10:45:28-AM
 */


#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	char *project_name = argv[1],
		 *c_filename = argv[2];

	if (argc == 1) {
		puts("Too few arguments.");
		goto handle_error;
	}
	else if (strcmp(argv[1], "create") == 0) {
		if (argc >= 2 && argc < 4) {
			puts("Few arguments.");
			goto handle_error;
		}
		else if (argc > 4) {
			puts("Too many arguments.");
			goto handle_error;
		}
		else {
			// Notice
			puts("Notice:\n"
				 "Development on progress...");
			puts("C file or C header file will be created here, soon...");
		}
	}
	else if (strcmp(argv[1], "help") == 0) {
		if (argc > 2) {
			puts("Too many arguments.");
			goto handle_error;
		}
		else {
			// Notice
			puts("Notice:\n"
				 "Development on progress...");
			puts("List of C project creator command(s) and arguments "
				 "should show here, soon...");
		}
	}
	else {
		if (argc >= 2 && argc < 3) {
			puts("Few arguments.");
			goto handle_error;
		}
		else if (argc > 3) {
			puts("Too many arguments.");
			goto handle_error;
		}
		else {
			// Notice
			puts("Notice:\n"
				 "Development on progress...");
			puts("C project setup should be done here, soon...");
		}
	}

	return 0;

	handle_error:
	puts("Type 'cpc help' for list of arguments.\n");
	return -1;
}



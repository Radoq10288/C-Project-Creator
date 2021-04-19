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


#include "pc.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	char *project_name = argv[1],
		 *c_filename = argv[2];

	char *cpc_commands[] = {
		"help", "new"
	};

	/* TODO
	 * Need definition of the purpose of 'arg_number'.
	 */
	int arg_number[] = {
		2, 4
	};

	int cc_size = sizeof(cpc_commands) / sizeof(char*),
		com_index;

	if (argc == 1) {
		puts("Too few arguments.");
		goto handle_error;
	}
	else if (argc > 4) {
		puts("Too many argument.");
		goto handle_error;
	}
	else {
		com_index = 0;
		while (com_index != cc_size) {
			if (strcmp(argv[1], cpc_commands[com_index]) == 0) {
				if (argc < arg_number[com_index]) {
					puts("Few arguments.");
					goto handle_error;
				}
				else if (argc > arg_number[com_index]) {
					puts("Too many arguments.");
					goto handle_error;
				}
				else {
					// Notice
					puts("Notice:\n"
				 		 "Development on progress...");
					printf("Execute cpc command '%s'.\n", argv[1]);
					break;
				}
			}

			com_index++;

			if (com_index == cc_size) {
				if (argc == 2) {
					puts("Few arguments.");
					goto handle_error;
				}
				else if (argc > 3) {
					puts("Too many arguments.");
					goto handle_error;
				}
				else {
					puts("Notice:\n"
				 		 "Development on progress...");
					if (!create_project(project_name, c_filename)) {
						printf("C project '%s' created successfully.\n", project_name);
					}
					else {
						puts("Failed to create C project.");
						goto handle_error;
					}
					break;
				}
			}
		}
	}

	return 0;

	handle_error:
	puts("Type 'cpc help' for list of arguments.\n");
	return -1;
}



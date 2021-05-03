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


#include "cpcerr.h"
#include "details.h"
#include "help.h"
#include "pc.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	char *project_name = argv[1],
		 *c_filename = argv[2],
		 *project_type = argv[3];

	char *cpc_commands[] = {
		"about", "c", "help",
		"new", "w"
	};

	/* arg_number specifies the number of arguments each cpc command,
	 * including the name of the program, consist. For example, 'new'
	 * command consist of 4 arguments including 'cpc':
	 *
	 * >cpc new -c cfile
	 *
	 * This will be matched against 'argc' to identify if a command
	 * has few arguments or too many.
	 */
	int arg_number[] = {
		2, 2, 3,
		4, 2
	};

	int (*exec_cpc_command[])() = {
		&cpc_about, &cpc_conditions, &cpc_help,
		&create_new_file, &cpc_warranty
	};

	int cc_size = sizeof(cpc_commands) / sizeof(char*),
		com_index, cpc_status;

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
				/* Executes functions in function pointer exec_cpc_command
				 * with no arguments or have single arguments.
				 */
				if (argc == 2 || argc == 3) {
					if (argc > arg_number[com_index]) {
						puts("Too many arguments.");
						goto handle_error;
					}

					cpc_status = exec_cpc_command[com_index](argv[2]);
					if (cpc_status) {
						print_cpc_err_msg(cpc_status);
						goto handle_error;
					}
					break;
				}

				/* Executes functions in function pointer exec_cpc_command
				 * with 2 arguments.
				 */
				if (argc == 4) {
					if (argc < arg_number[com_index]) {
						puts("Few arguments.");
						goto handle_error;
					}
					else if (argc > arg_number[com_index]) {
						puts("Too many arguments.");
						goto handle_error;
					}
					else {
						cpc_status = exec_cpc_command[com_index](argv[3], argv[2]);
						if (cpc_status) {
							print_cpc_err_msg(cpc_status);
							goto handle_error;
						}
						printf("New file '%s' created.\n", argv[3]);
						break;
					}
				}
			}

			com_index++;

			if (com_index == cc_size) {
				if (argc == 2) {
					puts("Few arguments.");
					goto handle_error;
				}
				else if (argc > 4) {
					puts("Too many arguments.");
					goto handle_error;
				}
				else {
					cpc_status = create_project(project_name, c_filename, project_type);
					if (cpc_status) {
						print_cpc_err_msg(cpc_status);
						goto handle_error;
					}
					printf("C project '%s' created successfully.\n", project_name);
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



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


/* File:			help.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation file of help.h
 *
 * Date created:	04-23-2021-01:48:45-PM
 */


#include "cpcerr.h"
#include <stdio.h>
#include <string.h>


int cpc_help(char *help_args) {
	if (help_args == NULL) {
		printf("List of arguments.\n\n"
			"Arguments for creating C project.\n"
			"<Project-Name>      - Name of project to create delimited by hypen (-)\n"
            "\t\t      or underscore. Don't use space to delimit project\n"
            "\t\t      name as 'cpc' will assume that the second word for\n"
            "\t\t      the project name (if any), will be the next\n"
			"\t\t      argument.\n"
			"<Filename>          - Filename for the C file to create.\n\n"
			"Arguments for creating individual file.\n"
			"new                 - To create C file or C header file.\n"
			"-c                  - Indicate that C file will be created. Use together\n"
            "\t\t      with 'create'.\n"
			"-h                  - Indicate that C header file will be created. Use\n"
            "\t\t      together with 'create'.\n"
			"<Filename>          - Filename for the C file or C header file to create.\n\n\n"
			"To show command format to create new file, type 'cpc help new'.\n"
			"To show command format to create C project, type 'cpc help project'.\n\n"
			);
	}
	else if (strcmp(help_args, "new") == 0) {
		printf("Creating new file.\n\n"
			"Format:\n"
			"cpc new [-c/-h] [filename]\n\n"
			"To see list of arguments for creating new file, type"
			"'cpc help'.\n\n"
			);
	}
	else if (strcmp(help_args, "project") == 0) {
		printf("Creating project.\n\n"
			"Format:\n"
			"cpc [Project-name] [C-file]\n\n"
			"To see list of arguments for creating project, type 'cpc help'.\n\n"
			);
	}
	else {
		return INVALID_ARGUMENT;
	}

	return CPC_OK;
}



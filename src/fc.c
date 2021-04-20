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


/* File:			fc.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation file of fc.h
 *
 * Date created:	04-20-2021-9:01:22-PM
 */


#include <stdio.h>
#include "sysdt.h"


int create_c_file(char *c_filename) {
	char *current_date_time = get_sys_date_time();
	
	char *c_file_template[] = {
		"/* File:\t\t\t", c_filename, ".c\n",
		" *\n",
		" * Author:\t\t\t\n",
		" *\n",
		" * Description:\t\t\n",
		" *\n",
		" * Date created:\t", current_date_time, "\n",
		" */\n\n\n",
		"#include <stdio.h>\n",
		"\n\n",
		"int main() {\n",
		"\t\n",
		"\tprintf(\"Hello world!\\n\");\n",
		"\t\n",
		"\treturn 0;\n",
		"}",
		"\n\n\n"
	};

	int cft_size = sizeof(c_file_template) / sizeof(char*);

	/* TODO
	 * Implement a function that will create a file and write to it
	 * the value of c_file_template string array.
	 */

	return 0;
}


int create_ec_file(char *c_filename) {
	char *current_date_time = get_sys_date_time();

	char *c_file_template[] = {
		"/* File:\t\t\t", c_filename, ".c\n",
		" *\n",
		" * Author:\t\t\t\n",
		" *\n",
		" * Description:\t\t\n",
		" *\n",
		" * Date created:\t", current_date_time, "\n",
		" */\n\n\n",
		"\n\n\n"
	};

	int cft_size = sizeof(c_file_template) / sizeof(char*);

	/* TODO
	 * Implement a function that will create a file and write to it
	 * the value of c_file_template string array.
	 */

	return 0;
}



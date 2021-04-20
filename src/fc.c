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


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sysdt.h"


static char *ucase_string;


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

/* Frees memory allocated by malloc() in toupper_string().
 */
void free_mem_fc(void) {
	ucase_string = NULL;

	free(ucase_string);
}


/* Description:	Convert string of lower case letters to string
 *				of capital letters.
 *
 * Parameter:
 *   *lcase_string - strings containing lower case letters.
 *
 * Return:		If function succeed, returns string in upper case.
 *				Else, return null.
 */
static char *toupper_string(char *lcase_string) {
    if (lcase_string == NULL) {
        goto handle_error;
    }

	int lcase_string_len = strlen(lcase_string);
	ucase_string = malloc(sizeof(char) * lcase_string_len);
    if (ucase_string == NULL) {
		goto handle_error;
	}

	ucase_string[lcase_string_len] = '\0';

	int lcs_char_index = 0;
	while (lcs_char_index != lcase_string_len) {
		ucase_string[lcs_char_index] = toupper(lcase_string[lcs_char_index]);
		lcs_char_index++;
	}

	atexit(free_mem_fc);
	return ucase_string;

	handle_error:
	return NULL;
}


int create_h_file(char *h_filename) {
	char *current_date_time = get_sys_date_time(),
		 *macro_name = toupper_string(h_filename);

	/* Transform each non-alphabet characters to underscore
	* (_) character.
	*/
	int char_index = 0;

	while (macro_name[char_index] != '\0') {
		if (!isalnum(macro_name[char_index])) {
			macro_name[char_index] = '_';
		}

		char_index++;
	}

	char *header_file_template[] = {
		"/* File:\t\t\t", h_filename, ".h\n",
		" *\n",
		" * Author:\t\t\t\n",
		" *\n",
		" * Description:\t\t\n",
		" *\n",
		" * Date created:\t", current_date_time, "\n",
		" */\n\n\n",
		"#ifndef _", macro_name, "_H_",
		"\n",
		"#define _", macro_name, "_H_",
		"\n\n",
		"\t// Functions definitions goes here...",
		"\n\n",
		"#endif // _", macro_name, "_H_INCLUDED_",
		"\n\n\n"
	};

	/* TODO
	 * Implement a function that will create a file and write to it
	 * the value of header_file_template string array.
	 */

	return 0;
}


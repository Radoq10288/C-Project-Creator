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


/* File:			pc.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of pc.h
 *
 * Date created:	04-17-2021-10:12:23-PM
 */


#include <io.h>
#include <stdio.h>
#include <string.h>


static int create_cmd_script(char *c_filename) {

	char *cmd_script_template[] = {
		"@echo off\n\n",
		"if not exist \"Makefile\" (\n",
		"\techo No 'Makefile' is found!\n",
		"\techo.\n\n",
		") else (\n",
		"\trem Clear the screen\n",
		"\tcls\n\n",
		"\trem Create 'obj' directory if it doesn't exist.\n",
		"\tif not exist \"obj\" (\n",
		"\t\tmkdir obj\n",
		"\t)\n\n",
		"\techo.\n",
		"\techo ---------------Clean directory------------------\n",
		"\trem Clean the current directory\n",
		"\tmingw32-make clean\n\n",
		"\techo.\n",
		"\techo.\n",
		"\techo -----------------Build Files--------------------\n",
		"\trem Build project\n",
		"\tmingw32-make\n\n",
		"\techo.\n",
		"\techo.\n",
		"\techo -----------------Run Program--------------------\n",
		"\techo.\n\n",
		"\trem Change to directory to bin\n",
		"\tcd bin\n\n",
		"\trem Run the program\n",
		"\t", c_filename, ".exe\n\n",
		"\techo.\n",
		"\techo.\n\n",
		"\trem Return to previous directory.\n",
		"\tcd ..\n\n",
		")\n\n\n",
	};

	int cst_arr_size = sizeof(cmd_script_template) / sizeof(char*),
		cst_index;

	/* TODO
	 * Function that create the actual cmd script will be
	 * implemented here.
	 */

	return 0;
}


static int create_makefile(char *c_filename) {
	/* TODO
	 * Create makefile that builds executable C program.
	 * Function that create the actual makefile will be implemented
	 * in separate module.
	 */

	return 0;
}


int create_project(char *project_name, char *c_filename) {
	if (_mkdir(project_name)) {
		goto handle_error;
	}

	_chdir(project_name);
	_mkdir("bin");
	_mkdir("src");
	_chdir("src");
	
	/* TODO
	 * Create C file here.
	 */
	
	_chdir("...");
	
	/* TODO
	 * Create makefile here.	[half-done]
	 * Create cmd script here.	[half-done]
	 */
	if (create_cmd_script(c_filename)) {
		goto handle_error;
	}

	if (create_makefile(c_filename)) {
		goto handle_error;
	}
	
	return 0;

	handle_error:
	return -1;
}


int create_new_file(char *filename, char *file_type) {
	char *file_type_list[] = {
		"-c", "-h"
	};

	int ftl_size = sizeof(file_type_list) / sizeof(char*),
		ftl_index = 0;

	while (ftl_index != ftl_size) {
		if (strcmp(file_type, file_type_list[ftl_index]) == 0) {
			/* TODO
			 * Create C file or C header file here.
			 */
			break;
		}

		ftl_index++;

		if (ftl_index == ftl_size) {
			/* If file_type have no match found on file_type_list,
			 * branch-out to handle_error.
			 */
			goto handle_error;
		}
	}

	return 0;

	handle_error:
	return -1;
}



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


#include "cpcerr.h"
#include "fc.h"
#include <io.h>
#include "mkfc.h"
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

	int cst_size = sizeof(cmd_script_template) / sizeof(char*),
		ccs_status;

	ccs_status = create_txt_file("debug_build", ".bat", cmd_script_template, cst_size);
	if (ccs_status) {
		goto handle_error;
	}

	return CPC_OK;

	handle_error:
	return ccs_status;
}


static int create_makefile(char *c_filename, char *makefile_type) {
	int cm_status;

	if (makefile_type == NULL) {
		cm_status = create_exec_makefile(c_filename);
		if (cm_status) {
			goto handle_error;
		}
	}
	else {
		char *mkf_type[] = {
			"gcc-static-lib", "gcc-dyn-lib",
			"win32-static-lib", "win32-dyn-lib"
		};

		int (*exec_cm[])() = {
			&create_gsl_makefile, &create_gdl_makefile,
			&create_wsl_makefile, &create_wdl_makefile
		};

		int mt_size = sizeof(mkf_type) / sizeof(char*),
			mt_index = 0;

		while (1) {
			if (strcmp(makefile_type, mkf_type[mt_index]) == 0) {
				cm_status = exec_cm[mt_index](c_filename, c_filename);
				if (cm_status) {
					goto handle_error;
				}
				break;
			}

			mt_index++;

			if (mt_index == mt_size) {
				cm_status = INVALID_ARGUMENT;
				goto handle_error;
			}
		}
 	}

 	return CPC_OK;

	handle_error:
	return cm_status;
}


int create_project(char *project_name, char *c_filename, char* project_type) {
	int cp_status;

	if (_mkdir(project_name)) {
		cp_status = PROJECT_EXIST;
		goto handle_error;
	}

	_chdir(project_name);
	_mkdir("bin");
	_mkdir("src");
	_chdir("src");

	if (project_type == NULL) {
		cp_status = create_c_file(c_filename);
		if (cp_status) {
			goto handle_error;
		}
	}
	else if (strcmp(project_type, "win32-dyn-lib") == 0) {
		cp_status = create_ec_file(c_filename);
		if (cp_status) {
			goto handle_error;
		}

		cp_status = create_wh_file(c_filename);
		if (cp_status) {
			goto handle_error;
		}
	}
	else {
		cp_status = create_ec_file(c_filename);
		if (cp_status) {
			goto handle_error;
		}

		cp_status = create_h_file(c_filename);
		if (cp_status) {
			goto handle_error;
		}
 	}

	_chdir("..");

	cp_status = create_cmd_script(c_filename);
	if (cp_status) {
		goto handle_error;
	}

	cp_status = create_makefile(c_filename, project_type);
	if (cp_status) {
		goto handle_error;
	}

	return CPC_OK;

	handle_error:
	return cp_status;
}


int create_new_file(char *filename, char *file_type) {
	char *file_type_list[] = {
		"-c", "-h"
	};
	
	int (*exec_create_file[])() = {
		&create_ec_file, &create_h_file
	};

	int ftl_size = sizeof(file_type_list) / sizeof(char*),
		ftl_index = 0, cnf_status;

	while (ftl_index != ftl_size) {
		if (strcmp(file_type, file_type_list[ftl_index]) == 0) {
			cnf_status = (*exec_create_file[ftl_index])(filename);
			if (cnf_status) {
				goto handle_error;
			}
			break;
		}

		ftl_index++;

		if (ftl_index == ftl_size) {
			/* If file_type have no match found on file_type_list,
			 * branch-out to handle_error.
			 */
			cnf_status = INVALID_ARGUMENT;
			goto handle_error;
		}
	}

	return CPC_OK;

	handle_error:
	return cnf_status;
}



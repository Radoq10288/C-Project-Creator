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
	 * Create makefile here.
	 * Create cmd script here.
	 */
	
	return 0;

	handle_error:
	return -1;
}



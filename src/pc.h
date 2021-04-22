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


/* File:			pc.h
 *
 * Author:			Radoq10288
 *
 * Description:		
 *
 * Date created:	04-17-2021-10:47:07-AM
 */


#ifndef _PC_H_
#define _PC_H_

	/* Description:	Creates C project.
	 *
	 * Parameter:
	 *	project_name	- name of the C project to create.
	 *	c_filename		- name of the C file to create.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative value.
	 */
	int create_project(char *project_name, char *c_filename);

	/* Description:	Creates C or C header file.
	 *
	 * Parameter:
	 *	filename	- filename of the file to create.
	 *	file_type	- type of file to create. Argument of '-c',
	 *				  for C file, and '-h' for C header file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative value.
	 */
	int create_new_file(char *filename, char *file_type);

#endif // _PC_H_INCLUDED_



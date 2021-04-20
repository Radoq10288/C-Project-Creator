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


/* File:			fc.h
 *
 * Author:			Radoq10288
 *
 * Description:		Collection of functions to create C file, C header
 *					file.
 *
 * Date created:	04-17-2021-11:04:52-AM
 */


#ifndef _FC_H_
#define _FC_H_

	/* Description:	Create C file with preset basic C program.
	 *
	 * Parameter:
	 *	c_filename	- filename of the C file to create.
	 *
	 * Return:		If function succeed, return 0. Else, return -1.
	 */
	int create_c_file(char *c_filename);

	/* Description:	Create empty C file.
	 *
	 * Parameter:
	 *	c_filename	- filename of the C file to create.
	 *
	 * Return:		If function succeed, return 0. Else, return -1.
	 */
	int create_ec_file(char *c_filename);

	/* Description:	Create C header file with preset header guard.
	 *
	 * Parameter:
	 *	h_filename	- filename of the C header file to create.
	 *
	 * Return:		If function succeed, it return 0. Else, return -1.
	 */
	int create_h_file(char *h_filename);

	/* Description: Create a text file and write value of file_content[]
	 *				to it.
	 *
	 * Parameter:
	 *	filename			- name of the file to create.
	 *	file_extension		- extension name of the file to create.
	 *	file_content		- a string array where content of the file will be
	 *					  	  initialized.
	 *	fc_size				- size of the string array file_content.
	 *
	 * Return:		If function succeed, it return 0. Else, return -1.
	 */
	int create_txt_file(char *filename, char *file_extension, char *file_content[], int fc_size);

#endif // _FC_H_INCLUDED_



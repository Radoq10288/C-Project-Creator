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


/* File:			mkfc.h
 *
 * Author:			Radoq10288
 *
 * Description:		Collection of functions that create makefile for
 *					specific C project setup.
 *
 * Date created:	04-17-2021-10:58:25-AM
 */


#ifndef _MKFC_H_
#define _MKFC_H_

	/* These functions creates makefile that builds C program for 32bit
	 * architecture and  uses MinGW's 'mingw32-gcc' as compiler and
	 * 'mingw32-make' as build system.
	 */

	/* Description:	Creates makefile to build executable file.
	 *
	 * Parameter:
	 *	c_filename	- filename of C file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative value.
	 */
	int create_exec_makefile(char *c_filename);


	/* Functions that create makefile to build GCC library.
	 */

	/* Description:	Creates makefile to build GCC static library.
	 *
	 * Parameter:
	 *   c_file	-	filename of the created C file.
	 *   h_file -	filename of the created C header file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative number.
	 */
	int create_gsl_makefile(char *c_file, char *h_file);

	/* Description:	Creates makefile to build GCC dynamic library.
	 *
	 * Parameter:
	 *   c_file	-	filename of the created C file.
	 *   h_file -	filename of the created C header file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative number.
	 */
	int create_gdl_makefile(char *c_file, char *h_file);

	/* Description:	Creates makefile to build Win32 static library.
	 *
	 * Parameter:
	 *   c_file	-	filename of the created C file.
	 *   h_file -	filename of the created C header file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative number.
	 */
	int create_wsl_makefile(char *c_file, char *h_file);

	/* Description:	Creates makefile to build win32 dynamic library.
	 *
	 * Parameter:
	 *   c_file	-	filename of the created C file.
	 *   h_file -	filename of the created C header file.
	 *
	 * Return:		If function succeed, return 0. Else, return non-
	 *				negative number.
	 */
	int create_wdl_makefile(char *c_file, char *h_file);

#endif // _MKFC_H_INCLUDED_



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


/* File:			cpcerr.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of cpcerr.h
 *
 * Date created:	04-17-2021-11:55:37-AM
 */


#include <stdio.h>


void print_cpc_err_msg(int cpc_err_code) {
	switch(cpc_err_code) {
		case 0:
			puts("No error."); break;
		case 0x1388:
			puts("Failed to create file."); break;
		case 0x1389:
			puts("Failed to retrieve system date & time."); break;
		case 0x138a:
			puts("File already exist."); break;
		case 0x138b:
			puts("Invalid argument."); break;
		case 0x138c:
			puts("Null argument"); break;
		case 0x138d:
			puts("Project already exist."); break;
		case 0x138e:
			puts("Failed to allocate memory."); break;
		default:
			puts("No such error code.");
	}
}



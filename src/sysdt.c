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


/* File:			sysdt.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation file of sysdt.h
 *
 * Date created:	04-20-2021-12:55:59-PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static char *date_time_string,
			*sys_date_string,
			*sys_time_string;


static void free_mem_gsdt(void) {
	sys_date_string = NULL;
	sys_time_string = NULL;
	date_time_string = NULL;

	free(sys_date_string);
	free(sys_time_string);
	free(date_time_string);
}


static char *get_sys_date(void) {
	sys_date_string = malloc(sizeof(char) * 11);
	if (sys_date_string == NULL) {
		goto handle_error;
	}

	time_t sys_date = time(NULL);
	struct tm *loc_date = localtime(&sys_date);

	strftime(sys_date_string, 11, "%m-%d-%Y", loc_date);

	atexit(free_mem_gsdt);
	return sys_date_string;

	handle_error:
	free(sys_date_string);
	return NULL;
}


static char *get_sys_time(void) {
	sys_time_string = malloc(sizeof(char) * 12);
	if (sys_time_string == NULL) {
		goto handle_error;
	}

	time_t sys_time = time(NULL);
	struct tm *loc_time = localtime(&sys_time);

	strftime(sys_time_string, 12, "%I:%M:%S-%p", loc_time);

	atexit(free_mem_gsdt);
	return sys_time_string;

	handle_error:
	free(sys_time_string);
	return NULL;
}


char *get_sys_date_time(void) {
	date_time_string = malloc(sizeof(char) * 23);
	if (date_time_string == NULL) {
		goto handle_error;
	}

	strcpy(date_time_string, get_sys_date());
	strcat(date_time_string, "-");
	strcat(date_time_string, get_sys_time());

	atexit(free_mem_gsdt);
	return date_time_string;

	handle_error:
	free(date_time_string);
	return NULL;
}



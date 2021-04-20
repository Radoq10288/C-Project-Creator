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


/* File:			sysdt.h
 *
 * Author:			Radoq10288
 *
 * Description:		Retrieve system date and time.
 *
 * Date created:	04-17-2021-11:14:40-AM
 */


#ifndef _SYSDT_H_
#define _SYSDT_H_

	/* Description:	Retrieve current system date and time.
	 *
	 * Parameter:
	 *
	 * Return:		If function succeed, return current system date and
	 *				time in the following format: "mm-dd-yyyy-hh:mm:ss-(AM/PM)".
	 *				Else, retun null.
	 */
	char *get_sys_date_time(void);

#endif // _SYSDT_H_INCLUDED_



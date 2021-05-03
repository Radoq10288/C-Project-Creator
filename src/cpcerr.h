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


/* File:			cpcerr.h
 *
 * Author:			Radoq10288
 *
 * Description:		C project creator error handler
 *
 * Date created:	04-17-2021-11:45:54-AM
 */


#ifndef _CPCERR_H_
#define _CPCERR_H_

	typedef enum {
		CPC_OK						= 0x0,		// No error
		FAILED_CREATE_FILE			= 0x1388,	// Failed to create file
		FAILED_DATE_TIME_RETRIEVE	= 0x1389,	// Failed to retrieve system date & time
		FILE_EXIST					= 0x138a,	// File already exist
		INVALID_ARGUMENT			= 0x138b,	// Invalid argument
		NULL_ARGUMENT				= 0x138c,	// Null argument
		PROJECT_EXIST				= 0X138d,	// Project already exist
		MEMORY_ALLOC_FAILURE		= 0X138e	// Memory allocation failure
	}cpc_error;

	/* Description:	Show detailed error based on error code.
	 *
	 * Parameter:
	 *	cpc_err_num		- error code that correspond to specific error
	 *					  message.
	 *
	 * Return:
	 */
	void print_cpc_err_msg(int cpc_err_code);

#endif // _CPCERR_H_INCLUDED_



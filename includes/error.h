/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 05:12:09 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 15:51:04 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** This enum is for the possible error codes. Leave ERROR_MESSAGE_COUNT as the
** last item, as it represents the size of the error strings array and is used
** for bounds checking when relating the codes to their actual string message.
** Make sure if you add a new code to add the proper string in error.c, in the
** get_error_string function.
*/

enum	ERROR_CODE
{
	E_NOARGS = 1,
	E_TOOMANYARGS,
	E_NOPERMISSION,
	E_NOTADIR,
	E_NOFILEORDIR,
	E_HOMENOTSET,
	E_BADENV,
	E_BADENVNAME,
	E_NOSUCHENV,
	E_EXPECTEDINT,
	E_STATFAIL,
	E_LSTATFAIL,
	E_GNLFAIL,
	E_MALLOCFAIL,
	E_FORKFAIL,
	E_EXECFAIL,
	E_NOTACOMMAND,
	ERROR_MESSAGE_COUNT,
};

int		print_error(const char *command, enum ERROR_CODE error_code);
int		print_builtin_error(const char *builtin, const char *command,
			enum ERROR_CODE error_code);

#endif

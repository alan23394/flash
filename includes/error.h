/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 05:12:09 by alan              #+#    #+#             */
/*   Updated: 2019/06/21 19:47:50 by alan             ###   ########.fr       */
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

enum	e_err_code
{
	E_NOARGS = 1,
	E_TOOMANYARGS,
	E_NOPERMISSION,
	E_NOTADIR,
	E_NOFILEORDIR,
	E_HOMENOTSET,
	E_NOOLDPWD,
	E_CHDIRFAIL,
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

int		print_error(const char *command, enum e_err_code error_code);
int		print_builtin_error(const char *builtin, const char *command,
			enum e_err_code error_code);

#endif

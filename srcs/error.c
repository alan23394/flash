/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:06 by alan              #+#    #+#             */
/*   Updated: 2019/06/08 20:58:31 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "ft_printf.h"

/*
** This function checks the error code and returns the string it corresponds to
**
** The error messages start at 1, so that's why the first parameter in this
** list is 0 (i.e. no string).
** The e_err_code type is an enum, and ERROR_MESSAGE_COUNT is the last item, so
** it is one larger than the last error message (i.e. a valid error message
** must be less than that number).
*/

const char	*get_error_string(enum e_err_code error_code)
{
	static const char	*error_strings[ERROR_MESSAGE_COUNT] = {
		0,
		"Needs arguments",
		"Too many arguments",
		"Permission denied",
		"Not a directory",
		"No such file or directory",
		"HOME not set",
		"Bad environment variable",
		"Bad environment variable name",
		"No such environment variable",
		"Expected integer",
		"Can't access with stat",
		"Can't access with lstat",
		"Can't get input (get_next_line fail)",
		"Can't create memory (malloc fail)",
		"Can't fork current process",
		"Can't exec new process",
		"No such command"
	};

	if (error_code > 0 && error_code < ERROR_MESSAGE_COUNT)
		return (error_strings[error_code]);
	return (0);
}

int			print_error(const char *command, enum e_err_code error_code)
{
	const char	*error;

	error = get_error_string(error_code);
	ft_printfd(2, "%s: %s: %s\n", g_shell_name, command, error);
	return (1);
}

int			print_builtin_error(const char *builtin, const char *command,
				enum e_err_code error_code)
{
	const char	*error;

	error = get_error_string(error_code);
	ft_printfd(2, "%s: %s: %s: %s\n", g_shell_name, builtin, command, error);
	return (1);
}

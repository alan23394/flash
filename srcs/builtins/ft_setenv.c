/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:52 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 15:51:36 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
#include "ft_printf.h"
#include "ft_list.h"

/*
** This builtin shell function sets an environment variable.
**
** If we couldn't make more memory, do nothing
** If we successfully added the pointer, set args->content to 0 so that way the
** string in that spot doesn't get deleted when the argument list is deleted.
*/

int	ft_setenv(t_list *args)
{
	int			ret;
	const char	*builtin_name;

	if (!args)
		return (print_error("ft_setenv", E_NOARGS));
	builtin_name = args->content;
	args = args->next;
	if (!args || !args->content)
		return (print_error(builtin_name, E_NOARGS));
	while (args && args->content)
	{
		if (validate_env(args->content) == 0)
			print_builtin_error(builtin_name, args->content, E_BADENV);
		else
		{
			ret = add_env(args->content);
			if (!ret)
				print_error(builtin_name, E_MALLOCFAIL);
			else
				args->content = 0;
		}
		args = args->next;
	}
	return (0);
}

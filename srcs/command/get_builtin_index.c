/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:23:13 by alan              #+#    #+#             */
/*   Updated: 2019/05/31 09:08:08 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "ft_list.h"

/*
** Make sure these strings stay up to date with the jump table that calls the
** functions, found in run_builtin().
*/

static char	*g_builtins[] = {
	"echo",
	"cd",
	"setenv",
	"unsetenv",
	"env",
	0
};

/*
** This function just checks if a command is a builtin, and it returns the
** index of that builtin if it is. It returns -1 if it is not.
*/

int		get_builtin_index(const char *command)
{
	int	command_len;
	int	i;

	command_len = ft_strlen(command);
	i = 0;
	while (g_builtins[i])
	{
		if (ft_strnequ(g_builtins[i], command, command_len))
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

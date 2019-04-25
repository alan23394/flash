/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:23:13 by alan              #+#    #+#             */
/*   Updated: 2019/04/25 07:05:46 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_word.h"
#include "ft_list.h"

/*
** This file is the controller for the builtins
*/

static char	*g_builtins[] = {
	"echo",
	"setenv",
	"unsetenv",
	"env",
	0
};

/*
** Before using run_builtin, make sure you check the index is valid with
** check_builtins! This function assumes you've done that already.
*/

int		run_builtin(int index, t_list *args)
{
	static int	(*builtins[])() = {
		[0] = ft_echo,
		[1] = ft_setenv,
		[2] = ft_unsetenv,
		[3] = ft_env,
	};

	return (builtins[index](args));
}

/*
** This function just checks if a command's first word is a builtin, and it
** returns the index of that builtin if it is. It returns -1 if it is not.
*/

int		check_builtins(const char *command)
{
	int	i;

	i = 0;
	while (g_builtins[i])
	{
		if (ft_wordequ(g_builtins[i], command))
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

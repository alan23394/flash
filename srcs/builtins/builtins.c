/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:23:13 by alan              #+#    #+#             */
/*   Updated: 2019/04/07 18:10:56 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_word.h"

/*
** This file is the controller for the builtins
*/

static char	*g_builtins[] = {
	"setenv",
	"env",
	0
};

/*
** Before using run_builtin, make sure you check the index is valid with
** check_builtins! This function assumes you've done that already.
*/

int		run_builtin(int index, const char *command)
{
	static int	(*builtins[])() = {
		[0] = ft_setenv,
		[1] = ft_env,
	};

	return (builtins[index](command));
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

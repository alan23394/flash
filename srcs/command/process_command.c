/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:02:54 by alan              #+#    #+#             */
/*   Updated: 2019/06/02 23:58:17 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "ft_list.h"

/*
** Before using run_builtin, make sure you have a valid builtin index with
** get_builtin_index! This function assumes you've done that already.
**
** Note: this jump table must be in the same order as the list of the command
** names in get_builtin_index()!
*/

static int	run_builtin(int index, t_list *args)
{
	static int	(*builtins[])() = {
		ft_echo,
		ft_cd,
		ft_setenv,
		ft_unsetenv,
		ft_env
	};

	return (builtins[index](args));
}

int			process_command(t_list *args)
{
	int	ret;
	int	builtin_index;

	if (!args)
		return (0);
	ret = 0;
	builtin_index = get_builtin_index(args->content);
	if (builtin_index == -1)
		ret = run_command(args);
	else
		ret = run_builtin(builtin_index, args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:02:54 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:10:24 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "ft_list.h"

int		process_command(t_list *args)
{
	int	builtin_nr;
	int	ret;

	builtin_nr = check_builtins(args->content);
	ret = 0;
	if (builtin_nr == -1)
		ret = run_command(args);
	else
	{
		// TODO: decide whether or not to include the name
		// I imagine it'll make error messages nicer
		args = args->next;
		ret = run_builtin(builtin_nr, args);
	}
	return (ret);
}

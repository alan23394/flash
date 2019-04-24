/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:20:03 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "ft_list.h"
#include "ft_conv.h"
#include "error.h"
#include "ft_string.h"
#include "ft_mem.h"

int		run_command(t_list *args)
{
	const char	**d_args;
	char		*command_path;
	int			ret;

	d_args = ft_lst_to_darr(args);
	command_path = get_command_path(d_args[0]);
	if (!command_path)
	{
		print_error(d_args[0], "command not found");
		return (1);
	}
	ret = call_command(command_path, d_args);
	ft_memdel((void **)d_args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/22 05:21:35 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_list.h"
#include "ft_darr.h"
#include "ft_conv.h"
#include <unistd.h>

/*
** This file will be the controller for running a command
** The command is verified to not be a builtin when using these
*/

int	run_command(t_list *args)
{
	const char	**d_args;

	d_args = ft_lst_to_darr(args);
	ft_print_darr(d_args);
	return (0);
}

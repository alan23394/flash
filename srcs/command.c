/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/15 00:41:00 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
** This file will be the controller for running a command
** The command is verified to not be a builtin when using these
*/

int	run_command(const char *command)
{
	ft_printf("command: %s\n", command);
	return (0);
}

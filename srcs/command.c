/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/07 23:07:56 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
** This file will be the controller for running a command
** The command is verified to not be a builtin when using these
*/

/*
int		ft_darr_i(void **

char	*ft_getenv(const char *name)
{

}
*/

int	run_command(const char *command)
{
	ft_printf("command: %s\n", command);
	return (0);
}

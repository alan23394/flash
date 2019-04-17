/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:39:01 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 16:04:21 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function validates command as an env key-value pair. It must have an =,
** and everything before the = must be considered a valid env name. Anything
** after is fair game.
**
** To validate the name, I get the length of it by finding the first '=' and
** getting the difference from the initial pointer, then I send the command and
** the name length to validate_envn_name, which takes care of the rest.
*/

int	validate_env(const char *command)
{
	char	*sign;

	sign = ft_strchr(command, '=');
	if (!sign)
		return (0);
	return (validate_envn_name(command, sign - command));
}

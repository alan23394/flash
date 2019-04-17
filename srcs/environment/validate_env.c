/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:39:01 by alan              #+#    #+#             */
/*   Updated: 2019/04/15 04:41:30 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"

int	validate_envn_name(const char *env, int env_namelen)
{
	int	i;

	i = 0;
	if (env_namelen != 0 && !ft_isdigit(env[i]))
	{
		while (i < env_namelen)
		{
			if (!(ft_isalnum(env[i]) || env[i] == '_'))
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

int	validate_env(const char *command)
{
	char	*sign;

	sign = ft_strchr(command, '=');
	if (sign)
		return (validate_envn_name(command, sign - command));
	return (0);
}

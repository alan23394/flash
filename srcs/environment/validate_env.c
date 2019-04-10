/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:39:01 by alan              #+#    #+#             */
/*   Updated: 2019/04/08 03:43:53 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"

int	validate_env(const char *command)
{
	char	*sign;

	sign = ft_strchr(command, '=');
	if (sign && command != sign && !ft_isdigit(*command))
	{
		while (command < sign)
		{
			if (!ft_isalnum(*command) && *command != '_')
				return (1);
			++command;
		}
		return (0);
	}
	return (1);
}

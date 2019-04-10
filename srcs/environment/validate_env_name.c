/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:05:58 by alan              #+#    #+#             */
/*   Updated: 2019/04/08 06:15:38 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"

int	validate_env_name(const char *command)
{
	if (!ft_isdigit(*command))
	{
		while (*command)
		{
			if (!ft_isalnum(*command) && *command != '_')
				return (1);
			++command;
		}
		return (0);
	}
	return (1);
}

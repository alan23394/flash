/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:55:17 by alan              #+#    #+#             */
/*   Updated: 2019/04/12 18:21:22 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

const char	*get_env(const char *env_name)
{
	int		i;
	char	*var;

	i = get_env_index(env_name);
	if (i != -1)
	{
		var = ft_strchr(g_environ[i], '=');
		if (var)
			++var;
		else
			return (0);
		return (var);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:33:59 by alan              #+#    #+#             */
/*   Updated: 2019/04/12 19:51:30 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

const char	*get_envn(const char *env_name, int env_namelen)
{
	int		i;
	char	*var;

	i = get_envn_index(env_name, env_namelen);
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

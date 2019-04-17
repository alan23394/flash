/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envn_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:46 by alan              #+#    #+#             */
/*   Updated: 2019/04/15 00:20:16 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function uses ft_strnequ with the env_namelen variable passed in,
** which allows me to search with strings that aren't null terminated.
** It returns -1 if the variable could not be found.
*/

static int	envnequ(const char *e1, const char *e2, int env_namelen)
{
	if (!e1 || !e2)
		return (0);
	while (env_namelen && *e1 && *e2 && *e1 == *e2)
	{
		++e1;
		++e2;
		--env_namelen;
	}
	if (env_namelen == 0 && *e2 == '=')
		return (1);
	return (0);
}

int	get_envn_index(const char *env_name, int env_namelen)
{
	int	i;

	if (env_namelen == 0)
		return (-1);
	i = 0;
	while (g_environ[i])
	{
		if (envnequ(env_name, g_environ[i], env_namelen))
			return (i);
		++i;
	}
	return (-1);
}

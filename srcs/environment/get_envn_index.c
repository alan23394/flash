/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envn_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:46 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 15:59:01 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function compares e1 with e2, only up to length env_namelen.
** e1 is the env name, e2 should be an env key-value (with an = sign).
** The comparison stops when env_namelen runs out or the characters don't
** match. It is considered a full match if, after env_namelen is empty, the
** next character in e2 is a '='. If it isn't, then it wasn't a full match!
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

/*
** This function uses envnequ with the env_namelen variable passed in,
** which allows me to search with strings that aren't null terminated.
** It returns -1 if the variable could not be found.
*/

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

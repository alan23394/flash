/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:46 by alan              #+#    #+#             */
/*   Updated: 2019/05/16 16:50:04 by alan             ###   ########.fr       */
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
	if (!e1 || !e2 || !env_namelen)
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
** It returns -1 if the variable could not be found, or if either of the
** parameters passed were 0.
*/

int			get_envn_index(const char *env, int env_namelen)
{
	int	i;

	if (!env || !env_namelen)
		return (-1);
	i = 0;
	while (g_environ[i])
	{
		if (envnequ(env, g_environ[i], env_namelen))
			return (i);
		++i;
	}
	return (-1);
}

/*
** This function uses ft_strlen to get the length of the passed variable, and
** sends the variable and it's length to get_envn_index.
** It returns -1 on failure, and the index on success (0 is valid).
*/

int			get_env_index(const char *env_name)
{
	if (!env_name)
		return (-1);
	return (get_envn_index(env_name, ft_strlen(env_name)));
}

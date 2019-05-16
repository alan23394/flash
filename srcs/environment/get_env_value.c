/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:55:17 by alan              #+#    #+#             */
/*   Updated: 2019/05/16 14:11:42 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function takes a validated environment variable index, and it returns a
** pointer to the value of that variable.
** This variable is not validated in any way in this function, it assumes it's
** being sent after it has been found already.
** It then returns a pointer to after the = (i.e. at the start of the env
** value).
** It returns 0 on failure, or the environment variable value on success.
*/

const char	*get_envi_value(int env_index)
{
	const char	*value;

	value = ft_strchr(g_environ[env_index], '=');
	if (!value)
		return (0);
	return (value + 1);
}

/*
** This function takes an env string and the length of the name at the start.
** It gets the index of the env in the environment variable list, using the
** env_namelen value.
** It then calls get_envi_value, which takes an environment variable index, and
** returns it's value.
** It returns 0 on failure, or the environment variable value on success.
*/

const char	*get_envn_value(const char *env, int env_namelen)
{
	int		i;

	if (!env || !env_namelen)
		return (0);
	i = get_envn_index(env, env_namelen);
	if (i == -1)
		return (0);
	return (get_envi_value(i));
}

/*
** This function takes a string with ONLY the environment variable name you
** want the value of. It then gets that string's length and passes it on to
** get_envn_value.
** It returns 0 on failure, or the environment variable value on success.
*/

const char	*get_env_value(const char *env_name)
{
	if (!env_name)
		return (0);
	return (get_envn_value(env_name, ft_strlen(env_name)));
}

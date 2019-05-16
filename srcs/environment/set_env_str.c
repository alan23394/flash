/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:32:59 by alan              #+#    #+#             */
/*   Updated: 2019/05/15 16:35:29 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_darr.h"

/*
** Takes a validated environment variable index, and the string value to set it
** to.
** This function uses the environment variable index passed to get the name of
** the new string, and uses the passed string as the new value for it.
** It then adds the new environment variable into the array by freeing the old
** one at that index, and setting the index to the new string.
** Returns 0 on failure, and 1 on success.
*/

int		set_envi_str(int env_index, const char *env_value)
{
	int			env_namelen;
	const char	*new_env;

	env_namelen = ft_strchr(g_environ[env_index], '=') - g_environ[env_index];
	new_env = make_envn_str(g_environ[env_index], env_namelen, env_value);
	if (!new_env)
		return (0);
	ft_strdel((char **)&g_environ[env_index]);
	g_environ[env_index] = new_env;
	return (1);
}

/*
** Takes an environment variable, the length of it's name, and the string value
** to set it to.
** Calls set_envi_str with the validated index.
** If there's no index, it uses ft_darradd to add the newly created environment
** variable into the environment variables.
** Returns 0 on failure, 1 on success
*/

int		set_envn_str(const char *env, int env_namelen, const char *env_value)
{
	int			env_index;
	const char	*new_env;

	if (!env || !env_namelen)
		return (0);
	env_index = get_envn_index(env, env_namelen);
	if (env_index != -1)
		return (set_envi_str(env_index, env_value));
	new_env = make_envn_str(env, env_namelen, env_value);
	if (ft_darradd(&g_environ, new_env))
		return (1);
	return (0);
}

/*
** This function takes an env name, and the value to set it to.
** Using the length of the name, it calls set_envn_str.
** It returns 0 on failure, 1 on success.
*/

int		set_env_str(const char *env_name, const char *env_value)
{
	if (!env_name)
		return (0);
	return (set_envn_str(env_name, ft_strlen(env_name), env_value));
}

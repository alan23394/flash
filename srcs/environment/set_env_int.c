/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 00:22:26 by alan              #+#    #+#             */
/*   Updated: 2019/05/15 16:35:17 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_darr.h"

/*
** Takes a validated environment variable index, and the integer value to set
** it to.
** This function uses the environment variable index passed to get the name of
** the new string, and uses the passed integer as the new value for it.
** It then adds the new environment variable into the array by freeing the old
** one at that index, and setting the index to the new string.
** Returns 0 on failure, and 1 on success.
*/

int		set_envi_int(int env_index, int env_value)
{
	int			env_namelen;
	const char	*new_env;

	env_namelen = ft_strchr(g_environ[env_index], '=') - g_environ[env_index];
	new_env = make_envn_int(g_environ[env_index], env_namelen, env_value);
	if (!new_env)
		return (0);
	ft_strdel((char **)&g_environ[env_index]);
	g_environ[env_index] = new_env;
	return (1);
}

/*
** Takes an environment variable, the length of it's name, and the integer
** value to set it to.
** Calls set_envi_int with the validated index.
** If there's no index, it uses ft_darradd to add the newly created environment
** variable into the environment variables.
** Returns 0 on failure, 1 on success
*/

int		set_envn_int(const char *env, int env_namelen, int env_value)
{
	int			env_index;
	const char	*new_env;

	if (!env || !env_namelen)
		return (0);
	env_index = get_envn_index(env, env_namelen);
	if (env_index != -1)
		return (set_envi_int(env_index, env_value));
	new_env = make_envn_int(env, env_namelen, env_value);
	if (ft_darradd(&g_environ, new_env))
		return (1);
	return (0);
}

/*
** Takes a name string, and the integer value to set it to.
** Calls set_envn_int with the strlen of the env_name.
** Returns 0 on failure, 1 on success
*/

int		set_env_int(const char *env_name, int env_value)
{
	if (!env_name)
		return (0);
	return (set_envn_int(env_name, ft_strlen(env_name), env_value));
}

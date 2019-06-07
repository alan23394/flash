/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 03:08:32 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 13:45:26 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_utils.h"
#include "ft_string.h"
#include "error.h"

/*
** This function increments the integer value inside an environment variable.
** It takes the index of the environment variable.
** Calls set_envi_int with the validated index.
** If there's no index, it uses ft_darradd to add the newly created environment
** variable into the environment variables.
** Returns 0 on failure, 1 on success
*/

static const char	*get_inc_env_str(int env_index, int env_namelen)
{
	const char	*new_env;
	const char	*env_value;
	int			env_num;

	if (env_index == -1)
	{
		new_env = make_envn_int(g_environ[env_index], env_namelen, 1);
	}
	else
	{
		env_value = get_envi_value(env_index);
		if (!ft_str_is_num(env_value))
		{
			return (0);
		}
		env_num = ft_atoi(env_value);
		new_env = make_envn_int(g_environ[env_index], env_namelen, env_num + 1);
	}
	return (new_env);
}

/*
** This function attempts to increment the integer value inside an env
** It takes the env to increment, and the length of it's name
** If the variable doesn't exist in the environment, it is set to 1.
*/

int				inc_envn(char *env, int env_namelen)
{
	int			env_index;
	const char	*new_env;

	if (!env || !env_namelen)
		return (1);
	env_index = get_envn_index(env, env_namelen);
	new_env = get_inc_env_str(env_index, env_namelen);
	if (new_env == 0)
		return (print_error("inc_env", E_EXPECTEDINT));
	return (add_envi(new_env, env_index));
}

/*
** This function increments the integer value inside an environment variable.
** Takes a name string.
** Calls inc_env with the strlen of the env_name.
** Returns 0 on success, 1 on failure
*/

int				inc_env(char *env_name)
{
	if (!env_name)
		return (1);
	return (inc_envn(env_name, ft_strlen(env_name)));
}

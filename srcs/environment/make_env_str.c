/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:29:15 by alan              #+#    #+#             */
/*   Updated: 2019/05/16 14:56:38 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** This function takes an env variable string and the length of the name at the
** beginning of that string, and the string to set it to. It doesn't change the
** environment variables, it only makes a new string and returns it.
*/

const char	*make_envn_str(const char *env, int env_namelen,
				const char *env_value)
{
	int		value_len;
	char	*new_env;

	if (!env || !env_value)
		return (0);
	value_len = ft_strlen(env_value);
	new_env = ft_strnew(env_namelen + 1 + value_len);
	if (!new_env)
		return (0);
	ft_strncpy(new_env, env, env_namelen);
	new_env[env_namelen] = '=';
	ft_strncpy(new_env + env_namelen + 1, env_value, value_len);
	return (new_env);
}

/*
** This function takes a new env name, and the string value to set it to.
** It makes a new string with the created environment variable, and returns it,
** using make_envn_str, which takes the string length of the name.
*/

const char	*make_env_str(const char *env_name, const char *env_value)
{
	if (!env_name)
		return (0);
	return (make_envn_str(env_name, ft_strlen(env_name), env_value));
}

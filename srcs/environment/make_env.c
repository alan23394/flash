/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:29:15 by alan              #+#    #+#             */
/*   Updated: 2019/04/26 17:42:18 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*make_env(const char *env_name, const char *env_value)
{
	int		name_len;
	int		value_len;
	char	*new_env;

	name_len = ft_strlen(env_name);
	value_len = ft_strlen(env_value);
	new_env = ft_strnew(name_len + 1 + value_len);
	if (!new_env)
		return (0);
	ft_strncpy(new_env, env_name, name_len);
	new_env[name_len] = '=';
	ft_strncpy(new_env + name_len + 1, env_value, value_len);
	return (new_env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:05:58 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 13:48:11 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function gets the length of a valid env up to env_namelen with
** get_valid_envn_len. If the length it returns is the same as env_namelen,
** then the input env is valid.
*/

int	validate_envn_name(const char *env, int env_namelen)
{
	int	len;

	if (!env || !env_namelen)
		return (0);
	len = get_valid_envn_len(env, env_namelen);
	if (len == env_namelen)
		return (1);
	return (0);
}

/*
** This function validates an entire string as an env name, by getting it's
** length and then using validate_envn_name.
** It returns 1 if the name is valid, and 0 if it isn't.
*/

int	validate_env_name(const char *env_name)
{
	if (!env_name)
		return (0);
	return (validate_envn_name(env_name, ft_strlen(env_name)));
}

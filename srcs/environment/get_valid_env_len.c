/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_env_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:21:31 by alan              #+#    #+#             */
/*   Updated: 2019/05/16 15:14:38 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/*
** This function is for checking for a valid env with up to env_namelen bytes
** from the env string. It returns the length of the valid env name.
**
** It is very similar to get_valid_env_len, which does the same thing but does
** not stop at a given length. It could just use this function with a strlen,
** but I didn't want to do that as it would waste time.
*/

int	get_valid_envn_len(const char *env, int env_namelen)
{
	int	len;

	if (!env || ft_isdigit(*env))
		return (0);
	len = 0;
	while (len < env_namelen && env[len])
	{
		if (!(ft_isalnum(env[len]) || env[len] == '_'))
			return (len);
		++len;
	}
	return (len);
}

/*
** This function returns the length of a valid env name starting at the env
** string. It should be used when there's no clear stopping point, and you
** don't want to count the length of the string beforehand.
**
** It is very similar to get_valid_envn_len, because while I could have just
** sent that function a strlen of the env, I didn't want to needlessly count
** the length of the string.
*/

int	get_valid_env_len(const char *env_name)
{
	int	len;

	if (!env_name || ft_isdigit(*env_name))
		return (0);
	len = 0;
	while (env_name[len])
	{
		if (!(ft_isalnum(env_name[len]) || env_name[len] == '_'))
			return (len);
		++len;
	}
	return (len);
}

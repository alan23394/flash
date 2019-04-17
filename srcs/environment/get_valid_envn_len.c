/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_envn_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:22:09 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 16:02:41 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/*
** This function is for checking for a valid env with up to env_len bytes from
** the env string. It returns the length of the valid env name.
**
** It is very similar to get_valid_env_len, which does the same thing but does
** not stop at a given length. It could just use this function with a strlen,
** but I didn't want to do that as it would waste time.
*/

int	get_valid_envn_len(const char *env, int env_len)
{
	int	len;

	if (!env || ft_isdigit(*env))
		return (0);
	len = 0;
	while (len < env_len && env[len])
	{
		if (!(ft_isalnum(env[len]) || env[len] == '_'))
			return (len);
		++len;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_env_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:21:31 by alan              #+#    #+#             */
/*   Updated: 2019/04/23 00:35:48 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/*
** This function returns the length of a valid env name starting at the env
** string. It should be used when there's no clear stopping point, and you
** don't want to count the length of the string beforehand. It won't step over
** null terminators.
**
** It is very similar to get_valid_envn_len, because while I could have just
** sent that function a strlen of the env, I didn't want to needlessly count
** the length of the string.
*/

int	get_valid_env_len(const char *env)
{
	int	len;

	if (!env || ft_isdigit(*env))
		return (0);
	len = 0;
	while (env[len])
	{
		if (!(ft_isalnum(env[len]) || env[len] == '_'))
			return (len);
		++len;
	}
	return (len);
}

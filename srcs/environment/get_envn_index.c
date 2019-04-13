/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envn_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:31:46 by alan              #+#    #+#             */
/*   Updated: 2019/04/13 01:32:59 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function uses ft_strnequ with the env_namelen variable passed in,
** which allows me to search with strings that aren't null terminated.
** It returns -1 if the variable could not be found.
*/

int	get_envn_index(const char *env_name, int env_namelen)
{
	int	i;

	i = 0;
	while (g_environ[i])
	{
		if (ft_strnequ(env_name, g_environ[i], env_namelen))
			return (i);
		++i;
	}
	return (-1);
}

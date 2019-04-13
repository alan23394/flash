/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 04:24:30 by alan              #+#    #+#             */
/*   Updated: 2019/04/12 19:51:59 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_darr.h"

/*
** This function uses darradd to add a string into a double array.
** It first checks if the item is in the array with get_envn_i, which takes a
** string and the length of the env_name (which I get with a ft_strchr, as it
** is guaranteed that the string has an = in it if it's made it to here), and
** returns the index if it's in the environment variables, and if it isn't, it
** returns -1. If the item exists already, we free the old one, and set the
** pointer to the passed string. If it doesn't, we use ft_darradd, which makes
** a new array of size 1 larger than the passed one, copies all the pointers
** over, frees the passed one and sets it's pointer to the new one, and also
** returns the new one. It returns 0 if the allocation fails, so I use it in an
** if check to see if it failed to allocate. This function returns 0 if that
** happens, and it returns 1 if it completes successfully. NOTE: It does not
** get rid of the old envs if the new one could not allocate, but of course it
** does not add the new one in.
*/

int		add_env(const char *env)
{
	int	i;

	i = get_envn_index(env, ft_strchr(env, '=') - env);
	if (i != -1)
	{
		ft_strdel((char **)&g_environ[i]);
		g_environ[i] = env;
	}
	else if (ft_darradd(&g_environ, env) == 0)
	{
		return (0);
	}
	return (1);
}

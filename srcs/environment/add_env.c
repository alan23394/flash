/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 04:24:30 by alan              #+#    #+#             */
/*   Updated: 2019/04/08 05:07:22 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_darr.h"

/*
** This function uses darradd to add a string into a double array. It makes a
** new array of size 1 larger than the passed one, copies all the pointers
** over, frees the passed one and sets it's pointer to the new one, and also
** returns the new one. It returns 0 if the allocation fails, so I use it in an
** if check to see if it failed to allocate. This function returns 0 if that
** happens, and it returns 1 if it completes successfully.
** NOTE: It does not get rid of the old envs if the new one could not allocate,
** but of course it does not add the new one in.
*/

int		add_env(const char *env)
{
	if (!ft_darradd(&g_environ, env))
		return (0);
	return (1);
}

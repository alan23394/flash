/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:29:53 by alan              #+#    #+#             */
/*   Updated: 2019/05/15 16:36:33 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_utils.h"
#include "ft_string.h"

/*
** Returns the integer value in an env, from the index of that env
** Useful for if you already have the validated env index
** Note, this does not care if the env var is not actually a number.
*/

int		get_envi_int(int env_index)
{
	int	num;

	num = ft_atoi(ft_strchr(g_environ[env_index], '=') + 1);
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 05:47:43 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 03:37:07 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function uses ft_strnequ with the length of the env_name variable,
** which saves ft_strequ from calculating the length each time. So if env_name
** has trailing characters, it will not find a match.
** It returns -1 if the variable could not be found.
*/

int	get_env_index(const char *env_name)
{
	return (get_envn_index(env_name, ft_strlen(env_name)));
}

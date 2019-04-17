/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 05:47:43 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 16:00:03 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

/*
** This function uses ft_strlen to get the length of the passed variable, and
** sends the variable and it's length to get_envn_index.
*/

int	get_env_index(const char *env_name)
{
	return (get_envn_index(env_name, ft_strlen(env_name)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:55:17 by alan              #+#    #+#             */
/*   Updated: 2019/04/13 04:01:41 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"

const char	*get_env(const char *env_name)
{
	return (get_envn(env_name, ft_strlen(env_name)));
}

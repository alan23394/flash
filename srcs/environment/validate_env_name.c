/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:05:58 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 16:19:27 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_utils.h"
#include "ft_string.h"

/*
** This function validates an entire string as an env name, by getting it's
** length and then using validate_envn_name.
*/

int	validate_env_name(const char *command)
{
	return (validate_envn_name(command, ft_strlen(command)));
}

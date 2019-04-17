/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_envn_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:22:36 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 16:08:52 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
** This function gets the length of a valid env up to env_namelen with
** get_valid_envn_len. If the length it returns is the same as env_namelen,
** then the input env is valid.
*/

int	validate_envn_name(const char *env, int env_namelen)
{
	int	len;

	len = get_valid_envn_len(env, env_namelen);
	if (len == env_namelen)
		return (1);
	return (0);
}

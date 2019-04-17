/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_envn_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:22:36 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 11:23:12 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	validate_envn_name(const char *env, int env_namelen)
{
	int	len;

	len = get_valid_envn_len(env, env_namelen);
	if (len == env_namelen)
		return (1);
	return (0);
}

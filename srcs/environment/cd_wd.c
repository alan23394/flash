/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_wd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:27:17 by alan              #+#    #+#             */
/*   Updated: 2019/06/23 00:32:08 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** These functions are for setting and retrieving the current working
** directory. It is managed like this so I can properly navigate in and out of
** symlinks.
*/

static const char	*g_wd = 0;

const char	*get_cd_wd(void)
{
	return (g_wd);
}

void		set_cd_wd(const char *path)
{
	if (g_wd)
		ft_strdel((char **)&g_wd);
	g_wd = path;
}

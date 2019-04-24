/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:01:34 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:27:33 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_printf.h"
#include "ft_list.h"
#include "ft_darr.h"

int	ft_unsetenv(t_list *args)
{
	int			ret;

	if (!args || !args->content)
	{
		ft_printfd(2, "needs arguments dude\n");
		return (1);
	}
	while (args && args->content)
	{
		ret = validate_env_name(args->content);
		if (ret == 1)
			ft_printfd(2, "error \"%s\" bad\n", args->content);
		else
		{
			ret = get_env_index(args->content);
			if (ret == -1)
				ft_printfd(2, "error no such environ \"%s\"\n", args->content);
			else
				ft_darrrm_i(&g_environ, ret);
		}
		args = args->next;
	}
	return (0);
}

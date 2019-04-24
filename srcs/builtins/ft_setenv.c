/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:52 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:13:03 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_printf.h"
#include "ft_list.h"

int	ft_setenv(t_list *args)
{
	int			ret;

	if (!args || !args->content)
	{
		ft_printfd(2, "needs arguments dude\n");
		return (1);
	}
	while (args && args->content)
	{
		if (validate_env(args->content) == 0)
			ft_printfd(2, "error \"%s\" bad\n", args->content);
		else
		{
			ret = add_env(args->content);
			// If we couldn't make more memory, don't hide the pointer
			// If we successfully added the pointer, set words[i] to 0 so that
			// way it doesn't get deleted
			if (!ret)
				ft_printfd(2, "error couldn't make new memory\n");
			else
				args->content = 0;
		}
		args = args->next;
	}
	return (0);
}

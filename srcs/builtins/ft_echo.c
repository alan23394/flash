/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:35:42 by alan              #+#    #+#             */
/*   Updated: 2019/04/25 09:51:16 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_darr.h"
#include "ft_list.h"
#include "ft_put.h"

/*
** Returns the length of the content inside the list, and sets the len pointer
** to the amount of nodes.
*/

static int	lst_content_len(t_list *list, int *len)
{
	int	total_len;

	total_len = 0;
	*len = 0;
	while (list)
	{
		total_len += list->content_size;
		list = list->next;
		++(*len);
	}
	return (total_len);
}

static char	*echo_comb(t_list *args)
{
	int		links;
	int		total_len;
	char	*new_string;
	char	*cur;

	if (!args)
		return (0);
	total_len = lst_content_len(args, &links);
	new_string = ft_strnew(total_len + links);
	cur = new_string;
	while (links--)
	{
		ft_strncpy(cur, args->content, args->content_size);
		if (links)
		{
			cur[args->content_size] = ' ';
			cur += args->content_size + 1;
		}
		else
			cur[args->content_size] = '\n';
		args = args->next;
	}
	return (new_string);
}

int	ft_echo(t_list *args)
{
	char	*comb_str;

	comb_str = echo_comb(args);
	if (comb_str)
		ft_putstr(comb_str);
	return (0);
}

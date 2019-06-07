/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:35:42 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 14:14:36 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
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

/*
** This function combines the strings in the argument list to have a space in
** between them, and a newline at the end. It gets the total length of those
** arguments, and the amount of them, so that way it may make the string all in
** one go. If there's no arguments (total length zero, and also zero links),
** set total_length to 1, so that way we may allocate the new line.
*/

static const char	*echo_comb(t_list *args)
{
	int		links;
	int		total_len;
	char	*new_string;
	char	*cur;

	total_len = lst_content_len(args, &links);
	if (!total_len && !links)
		total_len = 1;
	new_string = ft_strnew(total_len + links);
	cur = new_string;
	while (links-- && args)
	{
		ft_strncpy(cur, args->content, args->content_size);
		cur += args->content_size;
		if (links)
			*cur++ = ' ';
		args = args->next;
	}
	*cur = '\n';
	return (new_string);
}

int	ft_echo(t_list *args)
{
	const char	*comb_str;

	if (!args)
		return (print_error("ft_echo", E_NOARGS));
	args = args->next;
	comb_str = echo_comb(args);
	ft_putstr(comb_str);
	return (0);
}

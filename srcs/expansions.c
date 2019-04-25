/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:02:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/25 07:03:10 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_list.h"

static char	*expand_arg(char **command)
{
	t_list	*arg_list;
	size_t	arg_len;
	char	*arg;
	char	*chunk_start;

	arg_list = 0;
	arg_len = 0;
	arg = *command;
	chunk_start = *command;
	while (**command && **command != ';' && !ft_isspace(**command))
	{
		if (**command == '~')
			arg_len += expand_tilde(&arg_list, arg, &chunk_start, *command);
		else if (**command == '$')
			arg_len += expand_dollar(&arg_list, &chunk_start, *command);
		++(*command);
	}
	if (chunk_start != *command)
		arg_len += get_chunk(&arg_list, chunk_start, *command - 1);
	arg = ft_lstcomb_str(arg_list, arg_len);
	ft_lstdel(&arg_list, 0);
	return (arg);
}

t_list		*expand_command(char **command)
{
	t_list	*list;
	char	*new_command;

	list = 0;
	if (!*command)
		return (0);
	while (**command && **command != ';')
	{
		*command = (char *)ft_skipspace(*command);
		if (**command && **command != ';')
		{
			new_command = expand_arg(command);
			if (new_command)
				ft_lstadd_tail(&list,
						ft_lstinit(new_command, ft_strlen(new_command)));
		}
	}
	if (**command && **command == ';')
		++(*command);
	return (list);
}

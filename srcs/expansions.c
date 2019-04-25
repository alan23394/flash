/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:02:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/25 10:13:15 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_list.h"

/*
** This function takes a command at the start of an argument, and splits that
** argument into the expanded chunks (replacing ~ for the home path, $VARs
** etc), and then combines that list into one new string, which it returns. It
** sets the len pointer passed in to the length of the string it returns.
*/

static char	*expand_arg(char **command, int *len)
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
	*len = arg_len;
	ft_lstdel(&arg_list, 0);
	return (arg);
}

t_list		*expand_command(char **command)
{
	t_list	*list;
	char	*new_command;
	int		arg_len;

	list = 0;
	arg_len = 0;
	if (!*command)
		return (0);
	while (**command && **command != ';')
	{
		*command = (char *)ft_skipspace(*command);
		if (**command && **command != ';')
		{
			new_command = expand_arg(command, &arg_len);
			if (new_command)
				ft_lstadd_tail(&list, ft_lstinit(new_command, arg_len));
		}
	}
	if (**command && **command == ';')
		++(*command);
	return (list);
}

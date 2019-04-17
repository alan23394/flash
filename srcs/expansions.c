/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:02:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 03:21:12 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "environment.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_word.h"
#include "ft_list.h"

/*
** This function adds a chunk into the list
** delimited by chunk_start and chunk_end, inclusive.
*/

int		get_chunk(t_list **list, char *chunk_start, char *chunk_end)
{
	int		len;

	len = (chunk_end - chunk_start) + 1;
	if (len > 0)
		ft_lstadd_tail(list, ft_lstinit(chunk_start, len));
	return (len);
}

int		expand_tilde(t_list **list, char *arg_start, char **chunk_start,
			char *tilde_index)
{
	const char	*home_env;
	int			home_len;

	home_len = 0;
	if (tilde_index == arg_start)
	{
		home_env = get_env("HOME");
		home_len = ft_strlen(home_env);
		ft_lstadd_tail(list, ft_lstinit(home_env, home_len));
		*chunk_start = tilde_index + 1;
	}
	return (home_len);
}

/*
** This function needs to be careful, because these expansions can be on the
** first character. Make sure not to move backwards if you're at the beginning!
*/

char	*expand_arg(char **command)
{
	t_list	*arg_list;
	size_t	arg_len;
	char	*arg;
	char	*chunk_start;

	arg_list = 0;
	arg_len = 0;
	arg = *command;
	chunk_start = *command;
	while (**command && !ft_isspace(**command))
	{
		if (**command == '~')
			arg_len += expand_tilde(&arg_list, arg, &chunk_start, *command);
		else if (**command == '$')
			arg_len += 0;
		++(*command);
	}
	if (chunk_start != *command)
		arg_len += get_chunk(&arg_list, chunk_start, *command - 1);
	arg = ft_lstcomb_str(arg_list, arg_len);
	return (arg);
}

char	*expand_command(char *command)
{
	t_list	*list;
	char	*command_start;

	list = 0;
	command_start = command;
	while (*command)
	{
		command = (char *)ft_skipspace(command);
		ft_lstadd_tail(&list, ft_lstinit(expand_arg(&command), 0));
	}
	ft_lstiter(list, ft_lstputstr);
	ft_printf("\n");
	ft_strdel(&command_start);
	return (0);
}

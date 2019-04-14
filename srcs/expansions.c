/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:02:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/13 19:03:00 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "environment.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "ft_printf.h"
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

int		expand_tilde(t_list **list, char *command_start, char **chunk_start,
			char *tilde_index)
{
	const char	*home_env;
	int			total_len;
	int			home_len;

	total_len = 0;
	if (tilde_index == command_start || ft_isspace(*(tilde_index - 1)))
	{
		if (tilde_index != command_start)
			total_len += get_chunk(list, *chunk_start, tilde_index - 1);
		home_env = get_env("HOME");
		home_len = ft_strlen(home_env);
		ft_lstadd_tail(list, ft_lstinit(home_env, home_len));
		total_len += home_len;
		*chunk_start = tilde_index + 1;
	}
	return (home_len);
}

/*
** This function needs to be careful, because these expansions can be on the
** first character. Make sure not to move backwards if you're at the beginning!
*/

char	*expand_command(char *command)
{
	t_list	*list;
	char	*command_start;
	char	*chunk_start;
	int		total_len;

	list = 0;
	command_start = command;
	chunk_start = command;
	total_len = 0;
	while (*command)
	{
		if (*command == '~')
		{
			total_len += expand_tilde(&list, command_start, &chunk_start, command);
		}
		else if (*command == '$')
		{
			total_len += 0;
		}
		++command;
	}
	if (chunk_start != command)
		total_len += get_chunk(&list, chunk_start, command - 1);
	ft_lstiter(list, ft_lstputstr_len);
	command = ft_lstcomb_str(list, total_len);
	ft_strdel(&command_start);
	return (command);
}

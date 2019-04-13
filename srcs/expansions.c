/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:02:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/13 03:13:45 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "environment.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "ft_list.h"

void	expand_tilde(t_list **list)
{
	const char	*home_env;

	home_env = get_env("HOME");
	ft_lstadd_tail(list, ft_lstinit(home_env, ft_strlen(home_env)));
}

/*
** This function adds a chunk into the list
** delimited by chunk_start and chunk_end, inclusive.
*/

void	get_chunk(t_list **list, char *chunk_start, char *chunk_end)
{
	int		len;

	len = (chunk_end - chunk_start) + 1;
	if (len <= 0)
		return ;
	ft_lstadd_tail(list, ft_lstinit(chunk_start, len));
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

	list = 0;
	command_start = command;
	chunk_start = command;
	while (*command)
	{
		if (*command == '~')
		{
			if (command == command_start || ft_isspace(*(command - 1)))
			{
				if (command != command_start)
					get_chunk(&list, chunk_start, command - 1);
				expand_tilde(&list);
				chunk_start = command + 1;
			}
		}
		/*
		else if (*command == '$')
		{
			
		}
		*/
		++command;
	}
	if (chunk_start != command)
		get_chunk(&list, chunk_start, command - 1);
	ft_lstiter(list, ft_lstputstr_len);
	return (command_start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 08:58:16 by alan              #+#    #+#             */
/*   Updated: 2019/04/23 00:37:56 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "ft_string.h"
#include "ft_list.h"

/*
** This function returns a pointer to the env name found after the dollar sign.
** It takes a pointer to the dollarsign in a string. It moves that pointer
** to the end of the variable name (and optional brackets). It sets the length
** pointer to the length of the variable name.
** It returns 0 (and doesn't move the dollar_index) if no expansion was found.
*/

static char	*get_dollar_envname(char **dollar_index, int *len)
{
	char	*env_name;

	if (*(*dollar_index + 1) == '{')
	{
		*len = ft_strchr((*dollar_index + 2), '}') - (*dollar_index + 2);
		env_name = (*dollar_index + 2);
		*dollar_index = (*dollar_index + 2) + *len + 1;
	}
	else
	{
		env_name = (*dollar_index + 1);
		*len = get_valid_env_len(env_name);
		if (*len)
			*dollar_index = (*dollar_index + 1) + *len;
	}
	return (env_name);
}

/*
** This function doesn't need to worry about sending 1 character before the
** start of the string to get_chunk, because if it's before chunk_start (which
** it would be, if it were one character behind the start) then when get_chunk
** tries to get the length by subtracting the indexes and adding 1, it'll get a
** length of 0, and won't do anything.
**
** The env variable is used to store the name of the variable initially, and
** then it gets set to the value of the variable with get_envn, which takes the
** name, and the length of the name (stored in env_len, set by
** get_dollar_envname). env_len is then set to the length of the env value, so
** that it can be properly added into the linked list and the total size can be
** updated.
**
** TODO: as it sits, this function makes a chunk every time it enters (and
** there is a chunk to be made), even if it doesn't have to add an expansion.
** This is too much, I should limit it to only add a chunk when there is also
** an expansion to prevent making extra links for no reason.
*/

int			expand_dollar(t_list **list, char **chunk_start,
				char *dollar_index)
{
	const char	*env;
	int			total_len;
	int			env_len;

	total_len = get_chunk(list, *chunk_start, dollar_index - 1);
	*chunk_start = dollar_index;
	env = get_dollar_envname(chunk_start, &env_len);
	if (env_len == 0)
		return (0);
	env = get_envn(env, env_len);
	env_len = ft_strlen(env);
	ft_lstadd_tail(list, ft_lstinit(env, env_len));
	total_len += env_len;
	return (total_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:35:01 by alan              #+#    #+#             */
/*   Updated: 2019/06/09 04:05:08 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "ft_string.h"
#include "ft_list.h"

/*
** This function expands a tilde into the home variable, and it adds that
** variable into the linked list for expanding an argument.
**
** This function doesn't have to add a previous chunk into the list, because
** there should never be anything before a tilde in an argument.
*/

int		expand_tilde(t_list **list, const char *arg_start,
			const char **chunk_start, const char *tilde_index)
{
	const char	*home_env;
	int			home_len;

	home_len = 0;
	if (tilde_index == arg_start)
	{
		home_env = get_env_value("HOME");
		home_len = ft_strlen(home_env);
		ft_lstadd_tail(list, ft_lstinit(home_env, home_len));
		*chunk_start = tilde_index + 1;
	}
	return (home_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:43:57 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 11:44:13 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

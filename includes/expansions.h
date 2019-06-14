/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:10:48 by alan              #+#    #+#             */
/*   Updated: 2019/06/09 04:12:10 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

typedef struct s_list	t_list;

int		get_chunk(t_list **list, const char *chunk_start,
			const char *chunk_end);
t_list	*expand_command(const char **command);
int		expand_tilde(t_list **list, const char *arg_start,
			const char **chunk_start, const char *tilde_index);
int		expand_dollar(t_list **list, const char **chunk_start,
			const char *dollar_index);

#endif

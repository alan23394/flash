/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:10:48 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 11:37:16 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

typedef struct s_list	t_list;

int		get_chunk(t_list **list, char *chunk_start, char *chunk_end);
char	*expand_command(char *command);

int		expand_tilde(t_list **list, char *arg_start, char **chunk_start,
			char *tilde_index);
int		expand_dollar(t_list **list, char **chunk_start,
			char *dollar_index);

#endif

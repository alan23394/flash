/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:50 by alan              #+#    #+#             */
/*   Updated: 2019/05/31 08:15:17 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_list	t_list;

int			call_command(const char *command, const char **args);
const char	*get_command_path(const char *command, int command_len);
int			run_command(t_list *args);
int			get_builtin_index(const char *command);
int			process_command(t_list *args);

#endif

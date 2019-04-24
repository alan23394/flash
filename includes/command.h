/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:50 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:03:32 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_list	t_list;

int		call_command(char *command, const char **args);
char	*get_command_path(const char *command);
int		run_command(t_list *args);
int		process_command(t_list *args);

#endif

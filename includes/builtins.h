/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:10 by alan              #+#    #+#             */
/*   Updated: 2019/04/22 05:03:23 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** Builtins:
** echo
** cd
** setenv
** unsetenv
** env
** exit
**
** Expansions:
** $
** ~
*/

typedef struct s_list	t_list;

int	check_builtins(const char *command);
int	run_builtin(int index, t_list *args);

int	ft_setenv(t_list *args);
int	ft_unsetenv(t_list *args);
int	ft_env(t_list *args);

#endif

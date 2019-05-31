/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:10 by alan              #+#    #+#             */
/*   Updated: 2019/05/30 03:33:14 by alan             ###   ########.fr       */
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
** exit -- not technically used like a builtin
*/

typedef struct s_list	t_list;

int	ft_echo(t_list *args);
int	ft_cd(t_list *args);
int	ft_setenv(t_list *args);
int	ft_unsetenv(t_list *args);
int	ft_env(t_list *args);

#endif

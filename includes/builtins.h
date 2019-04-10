/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:10 by alan              #+#    #+#             */
/*   Updated: 2019/04/08 06:02:00 by alan             ###   ########.fr       */
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

int	check_builtins(const char *command);
int	run_builtin(int index, const char *command);

int	ft_setenv(const char *command);
int	ft_unsetenv(const char *command);
int	ft_env(const char *command);

#endif

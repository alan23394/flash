/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:06 by alan              #+#    #+#             */
/*   Updated: 2019/06/02 23:55:26 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"

int	print_error(const char *command, const char *error)
{
	ft_printfd(2, "%s: %s: %s\n", g_shell_name, command, error);
	return (1);
}

int	print_builtin_error(const char *builtin, const char *command,
		const char *error)
{
	ft_printfd(2, "%s: %s: %s: %s\n", g_shell_name, builtin, command, error);
	return (1);
}

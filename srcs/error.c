/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:06 by alan              #+#    #+#             */
/*   Updated: 2019/06/01 12:03:54 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"

int	print_error(const char *command, const char *error)
{
	ft_printfd(2, "%s: %s: %s\n", g_shell_name, command, error);
	return (1);
}

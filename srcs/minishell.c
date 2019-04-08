/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/07 16:22:12 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "minishell.h"
#include "builtins.h"
#include "prompt.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_darr.h"

int		main(int argc, char **argv)
{
	char		*line;
	int			len;
	extern char	**environ;

	(void)argc;
	(void)argv;
	g_environ = ft_dup_darr(environ);
	print_prompt(1);
	while (42)
	{
		print_prompt(1);
		len = get_next_line(0, &line);
		ft_printf("%d\n", len);
		ft_printf("line: %s\n", line);
	}
	return (0);
}

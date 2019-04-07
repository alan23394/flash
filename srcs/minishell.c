/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/06 18:26:10 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "prompt.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_darr.h"

int		main(int argc, char **argv)
{
	char		*line;
	int			len;
	extern char	**environ;
	char		**new_environ;

	(void)argc;
	(void)argv;
	new_environ = ft_dup_darr(environ);
	(void)new_environ;
	while (42)
	{
		print_prompt(1);
		len = get_next_line(0, &line);
		ft_printf("%d\n", len);
		ft_printf("line: %s\n", line);
	}
	return (0);
}

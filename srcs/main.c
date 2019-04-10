/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/07 18:11:52 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "minishell.h"
#include "builtins.h"
#include "command.h"
#include "prompt.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_darr.h"

int		process_command(char *command)
{
	int	builtin_nr;
	int	ret;

	builtin_nr = check_builtins(command);
	ret = 0;
	if (builtin_nr == -1)
		ret = run_command(command);
	else
	{
		//ft_next_word
		ret = run_builtin(builtin_nr, command);
	}
	return (ret);
}

int		print_error()
{
	ft_printfd(2, "%s\n", "get_next_line failed, I dunno but quit time now");
	return (1);
}

int		main()
{
	char		*line;
	int			ret;
	extern char	**environ;

	g_environ = ft_dup_darr(environ);
	print_prompt(1);
	while ((ret = get_next_line(0, &line)) != 0)
	{
		if (ret == -1)
		{
			return (print_error());
		}
		process_command(line);
		print_prompt(1);
	}
	return (0);
}
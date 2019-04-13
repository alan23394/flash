/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/12 18:12:44 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "minishell.h"
#include "builtins.h"
#include "command.h"
#include "prompt.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_darr.h"
#include "ft_word.h"

int		process_command(const char *command)
{
	int	builtin_nr;
	int	ret;

	builtin_nr = check_builtins(command);
	ret = 0;
	if (builtin_nr == -1)
		ret = run_command(command);
	else
	{
		command = ft_wordnext(command);
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
	char		*expanded;
	int			ret;
	extern char	**environ;

	g_environ = ft_dup_darr((const char **)environ);
	// Increase SHLVL variable
	print_prompt(1);
	while ((ret = get_next_line(0, &line)) != 0)
	{
		if (ret == -1)
		{
			return (print_error());
		}
		expanded = expand_command(line);
		process_command(expanded);
		print_prompt(1);
	}
	return (0);
}

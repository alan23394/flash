/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/22 05:13:07 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "builtins.h"
#include "command.h"
#include "prompt.h"
#include "get_next_line.h"
#include "ft_darr.h"
#include "ft_word.h"
#include "ft_list.h"
#include "error.h"

int		process_command(t_list *args)
{
	int	builtin_nr;
	int	ret;

	builtin_nr = check_builtins(args->content);
	ret = 0;
	if (builtin_nr == -1)
		ret = run_command(args);
	else
		ret = run_builtin(builtin_nr, args);
	return (ret);
}

int		main()
{
	char		*line;
	t_list		*args;
	int			ret;
	extern char	**environ;

	g_environ = ft_dup_darr((const char **)environ);
	// Increase SHLVL variable
	print_prompt(1);
	while ((ret = get_next_line(0, &line)) != 0)
	{
		if (ret == -1)
		{
			return (print_error("get_next_line: couldn't make memory"));
		}
		args = expand_command(line);
		process_command(args);
		print_prompt(1);
	}
	return (0);
}

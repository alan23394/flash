/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/28 04:51:24 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "command.h"
#include "prompt.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_darr.h"
#include "ft_list.h"
#include "error.h"

static int	shell_loop()
{
	char		*line;
	char		*line_start;
	int			ret;
	t_list		*args;

	line = 0;
	ret = 0;
	args = 0;
	while ((line && *line) || (((ret = get_next_line(0, &line_start)) != 0) && (line = line_start)))
	{
		if (ret == -1)
			return (print_error("get_next_line", "couldn't make memory"));
		args = expand_command(&line);
		if (args && ft_strequ(args->content, "exit"))
			break ;
		ret = process_command(args);
		ft_lstdel(&args, ft_lstmemdel);
		if (*line == '\0')
		{
			ft_strdel(&line_start);
			line = 0;
			print_prompt(1);
		}
		ret = 0;
	}
	ft_lstdel(&args, ft_lstmemdel);
	ft_strdel(&line_start);
	return (0);
}

int			main()
{
	extern char	**environ;

	g_environ = ft_dup_darr((const char **)environ);
	// Increase SHLVL variable
	print_prompt(1);
	return (shell_loop());
}

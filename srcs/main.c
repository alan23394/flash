/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/04/25 12:03:56 by alan             ###   ########.fr       */
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

void	shell_loop()
{
	char		*line;
	t_list		*args;
	int			ret;

	line = 0;
	while ((line && *line) || (ret = get_next_line(0, &line)) != 0)
	{
		if (ret == -1)
		{
			(void)print_error("get_next_line", "couldn't make memory");
			break ;
		}
		args = expand_command(&line);
		if (args && ft_strequ(args->content, "exit"))
		{
			ft_lstdel(&args, ft_lstmemdel);
			break ;
		}
		ret = process_command(args);
		ft_lstdel(&args, ft_lstmemdel);
		ret = 0;
		if (*line == '\0')
			print_prompt(1);
	}
}

int		main()
{
	extern char	**environ;

	g_environ = ft_dup_darr((const char **)environ);
	// Increase SHLVL variable
	print_prompt(1);
	shell_loop();
	return (0);
}

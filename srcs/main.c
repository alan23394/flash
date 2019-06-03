/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/06/02 23:32:24 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environment.h"
#include "expansions.h"
#include "command.h"
#include "prompt.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_darr.h"
#include "ft_list.h"
#include "error.h"

static int	shell_loop(void)
{
	char		*cur;
	char		*line;
	int			ret;
	t_list		*args;

	cur = 0;
	ret = 0;
	args = 0;
	while ((cur && *cur) ||
			(((ret = get_next_line(0, &line)) != 0) && (cur = line)))
	{
		if (ret == -1)
			return (print_error("get_next_line", "couldn't make memory"));
		args = expand_command(&cur);
		if (args && ft_strequ(args->content, "exit"))
			break ;
		ret = process_command(args);
		ft_lstdel(&args, ft_lstmemdel);
		if (*cur == '\0')
		{
			ft_strdel(&line);
			cur = 0;
			print_prompt(1);
		}
		ret = 0;
	}
	ft_lstdel(&args, ft_lstmemdel);
	ft_strdel(&line);
	return (0);
}

/*
** This function returns a pointer to the last component of the path
** First set name to the last /
** If there wasn't a /, ft_strrchr will return 0
** If it didn't return 0, move name after the /
** If it did return zero, set it to the path
** Return name
*/

static const char	*get_name_from_path(const char *path)
{
	const char	*name;

	name = ft_strrchr(path, '/');
	if (name)
	{
		name += 1;
	}
	else
	{
		name = path;
	}
	return (name);
}

void		shell_setup(const char *shell_name)
{
	inc_env("SHLVL");
	g_shell_name = get_name_from_path(shell_name);
	print_prompt(1);
}

int		main(int argc, char **argv)
{
	extern char	**environ;

	(void)argc;
	g_environ = ft_dup_darr((const char **)environ);
	shell_setup((const char *)argv[0]);
	shell_loop();
	return (0);
}

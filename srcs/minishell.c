/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 23:33:46 by alan              #+#    #+#             */
/*   Updated: 2019/06/09 04:46:09 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environment.h"
#include "expansions.h"
#include "command.h"
#include "prompt.h"
#include "ft_utils.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_darr.h"
#include "ft_list.h"
#include "error.h"

void	shell_setup(const char *shell_launch_path)
{
	extern char	**environ;

	g_shell_name = get_path_filename(shell_launch_path);
	g_environ = ft_dup_darr((const char **)environ);
	inc_env("SHLVL");
	print_prompt(1);
}

int		shell_loop(void)
{
	const char	*cur;
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
			return (print_error("get_next_line", E_GNLFAIL));
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

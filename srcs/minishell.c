/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 23:33:46 by alan              #+#    #+#             */
/*   Updated: 2019/06/14 20:34:13 by abarnett         ###   ########.fr       */
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

int		process_line(const char **line_cursor)
{
	t_list	*args;
	int		ret;

	ret = 0;
	args = expand_command(line_cursor);
	if (!args)
		return (0);
	if (ft_strequ(args->content, "exit"))
		return (-1);
	ret = process_command(args);
	ft_lstdel(&args, ft_lstmemdel);
	return (ret);
}

int		shell_loop(void)
{
	const char	*cur;
	char		*line;
	int			ret;
	int			last_ret;

	cur = 0;
	ret = 0;
	while ((cur && *cur) || (((ret = get_next_line(0, &line)) != 0) &&
				(cur = line)))
	{
		if (ret == -1)
			return (print_error("get_next_line", E_GNLFAIL));
		if ((ret = process_line(&cur)) == -1)
			break ;
		if (*cur == '\0')
		{
			ft_strdel(&line);
			cur = 0;
			print_prompt(1);
		}
		last_ret = ret;
		ret = 0;
	}
	ft_strdel(&line);
	return (last_ret);
}

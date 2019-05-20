/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:46:05 by alan              #+#    #+#             */
/*   Updated: 2019/05/31 07:28:42 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "expansions.h"
#include "command.h"
#include "environment.h"
#include "prompt.h"
#include "ft_utils.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_printf.h"
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

/*
** This function attempts to increment the integer value inside an env
** It takes the env to increment, and the length of it's name
** If the variable doesn't exist in the environment, it is set to 1.
**
** What we need to do
** find if the variable exists
** if it isn't in there,
**	make a string with 1
**	add it
** if it is,
**	make sure it's a number
**	if it isn't,
**		error message, and quit
**	get it's int value
**	make a new string with increased int value
**	delete the old string, and replace it with the new one
**		(this skips the additional validation required by other functions)
*/

void	envn_inc(char *env, int env_namelen)
{
	int			env_index;
	int			env_num;
	const char	*new_env;
	const char	*env_val;

	if (!env || !env_namelen)
		return ;
	env_index = get_envn_index(env, env_namelen);
	if (env_index == -1)
	{
		new_env = make_envn_int(env, env_namelen, 1);
		ft_darradd(&g_environ, new_env);
	}
	else
	{
		env_val = get_envi_value(env_index);
		if (!ft_str_is_num(env_val))
		{
			print_error("error: expected integer", env_val);
			return ;
		}
		env_num = get_envi_int(env_index);
		new_env = make_envn_int(env, env_namelen, env_num + 1);
		ft_strdel((char **)&g_environ[env_index]);
		g_environ[env_index] = new_env;
	}
}

void	env_inc(char *env_name)
{
	if (!env_name)
		return ;
	envn_inc(env_name, ft_strlen(env_name));
}

void	shell_setup(void)
{
	env_inc("SHLVL");
	print_prompt(1);
}

int		main(void)
{
	extern char	**environ;

	g_environ = ft_dup_darr((const char **)environ);
	shell_setup();
	shell_loop();
	return (0);
}

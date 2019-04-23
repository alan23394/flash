/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/23 03:54:32 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_list.h"
#include "ft_darr.h"
#include "ft_conv.h"
#include "ft_string.h"
#include "environment.h"
#include <unistd.h>

/*
** This file will be the controller for running a command
** The command is verified to not be a builtin when using these
*/

/*
** This function makes a new string, bounded by start and end inclusive, with
** append_string added after a /. It is used to combine a path string from the
** PATH variable and a command into one string with the path of a variable.
*/

static char	*get_path_chunk_app(const char *chunk_start, char *chunk_end,
				const char *append_string)
{
	int		chunk_len;
	int		app_len;
	char	*new_string;

	chunk_len = (chunk_end - chunk_start) + 1;
	if (chunk_len <= 0)
		return (0);
	// TODO fix strlen segfault when unsafe
	app_len = ft_strlen(append_string);
	new_string = ft_strnew(chunk_len + 1 + app_len);
	ft_strncpy(new_string, chunk_start, chunk_len);
	new_string[chunk_len] = '/';
	ft_strncpy(new_string + chunk_len + 1, append_string, app_len);
	return (new_string);
}

/*
** TODO: be able to turn on and off path caching (caching in general)
*/

int		get_paths(const char *command)
{
	const char	*path;
	char		*new_command;

	path = get_envn("PATH", 4);
	if (!path)
		return (0);
	new_command = get_path_chunk_app(path, ft_strchr(path, ':') - 1, command);
	ft_printf("%s\n", new_command);
	return (0);
	/*
	while (*path)
	{
		
	}
	*/
}

int	run_command(t_list *args)
{
	const char	**d_args;
	int			something;

	d_args = ft_lst_to_darr(args);
	ft_print_darr(d_args);
	something = get_paths((const char *)args->content);
	return (something);
}

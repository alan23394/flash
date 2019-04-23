/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/04/23 05:00:48 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_list.h"
#include "ft_darr.h"
#include "ft_conv.h"
#include "ft_string.h"
#include "environment.h"
#include <unistd.h>
#include <sys/stat.h>

/*
** This file will be the controller for running a command
** The command is verified to not be a builtin when using these
*/

/*
** This function makes a new string, bounded by start and end inclusive, with
** append_string added after a /. It is used to combine a path string from the
** PATH variable and a command into one string with the path of a variable.
*/

static char	*get_path_chunk_app(const char *chunk_start, const char *chunk_end,
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

char	*get_paths(const char *command)
{
	const char	*path;
	char		*new_command;
	struct stat	stats;
	int			len;

	path = get_envn("PATH", 4);
	if (!path)
		return (0);
	while (*path)
	{
		len = ft_strchr_end(path, ':') - path;
		new_command = get_path_chunk_app(path, path + len - 1, command);
		if (!new_command)
			return (0);
		if (stat(new_command, &stats) == 0)
		{
			if (!(stats.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
			{
				ft_printf("error: no permissions on %s\n", new_command);
				return (0);
			}
			else
			{
				return (new_command);
			}
		}
		path += len + !!path[len];
		ft_strdel(&new_command);
	}
	return (0);
}

int	run_command(t_list *args)
{
	const char	**d_args;
	char		*something;

	d_args = ft_lst_to_darr(args);
	ft_print_darr(d_args);
	something = get_paths((const char *)args->content);
	ft_printf("%s\n", something);
	return (0);
}

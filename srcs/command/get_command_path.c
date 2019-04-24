/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:15:49 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:10:55 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_printf.h"
#include <unistd.h>
#include <sys/stat.h>

/*
** This function makes a new string, bounded by start and end inclusive, with
** append_string added after a /. It is used to combine a path string from the
** PATH variable and a command into one string with the path of a variable.
**
** TODO fix strlen segfault when using unsafe libft
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
	app_len = ft_strlen(append_string);
	new_string = ft_strnew(chunk_len + 1 + app_len);
	ft_strncpy(new_string, chunk_start, chunk_len);
	new_string[chunk_len] = '/';
	ft_strncpy(new_string + chunk_len + 1, append_string, app_len);
	return (new_string);
}

/*
** This function tests if the command (which represents the full path to an
** executable) exists. If it does not exist, the function returns 0. If it
** does, and it's executable, it returns 1. If it exists and is not executable,
** it prints an error message and returns -1.
*/

static int	test_command(char *command)
{
	struct stat	stats;

	if (!command)
		return (0);
	if (stat(command, &stats) == 0)
	{
		if (!(stats.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		{
			ft_printf("error: no permissions on %s\n", command);
			return (-1);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

/*
** This function returns the full path of a command, after searching the PATH
** environment variable. It returns 1 if found, 0 otherwise.
**
** The path += len + !!path[len] trick does this:
** 	move path len bytes forward. If path[len] is not the null terminator, move
** 	over one more character.
** !!x turns it into a bool, so if x is 4112898 it's 1 and if it's 0 it's 0.
** TODO: be able to turn on and off path caching (caching in general)
*/

char	*get_command_path(const char *command)
{
	const char	*path;
	int			len;
	char		*new_command;
	int			ret;

	path = get_envn("PATH", 4);
	if (!path)
		return (0);
	while (*path)
	{
		len = ft_strchr_end(path, ':') - path;
		new_command = get_path_chunk_app(path, path + len - 1, command);
		ret = test_command(new_command);
		if (ret)
			return ((ret == -1) ? 0 : new_command);
		ft_strdel(&new_command);
		path += len + !!path[len];
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:15:49 by alan              #+#    #+#             */
/*   Updated: 2019/06/21 21:05:49 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "error.h"
#include <unistd.h>
#include <sys/stat.h>

/*
** This function makes a new string, bounded by start and end inclusive, with
** append_string added after a /. It is used to combine a path string from the
** PATH variable and a command into one string with the path of a variable.
**
** TODO fix strlen segfault when using unsafe libft
*/

static const char	*get_path_chunk_app(const char *chunk_start, int chunk_len,
						const char *append_string, int app_len)
{
	char	*new_string;

	if (chunk_len <= 0)
		return (0);
	new_string = ft_strnew(chunk_len + 1 + app_len);
	ft_strncpy(new_string, chunk_start, chunk_len);
	new_string[chunk_len] = '/';
	ft_strncpy(new_string + chunk_len + 1, append_string, app_len);
	return ((const char *)new_string);
}

/*
** This function returns the full path of a command, after searching the PATH
** environment variable. It returns 1 if found, 0 otherwise.
** If the command contains a /, we don't append it to the normal path, just
** check if it exists.
** If there is no path string, we check in the current directory.
**
** The path += len + !!path[len] trick does this:
** 	move path len bytes forward. If path[len] is not the null terminator, move
** 	over one more character.
** !!x turns it into a bool, so if x is any non-zero int it gets turned into 1,
** and if it's zero then it stays at zero.
** TODO: be able to turn on and off path caching (caching in general)
*/

const char			*get_command_path(const char *command, int command_len)
{
	const char	*path;
	int			len;
	const char	*new_command;

	if (ft_strchr(command, '/'))
	{
		if (access(command, F_OK) == 0)
			return ((const char *)ft_strdup(command));
		return (0);
	}
	path = get_env_value("PATH");
	if (!path)
		path = ".";
	while (*path)
	{
		len = ft_strchr_i_end(path, ':');
		new_command = get_path_chunk_app(path, len, command, command_len);
		if (access(new_command, F_OK) == 0)
			return (new_command);
		ft_strdel((char **)&new_command);
		path += len + !!path[len];
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:33:00 by alan              #+#    #+#             */
/*   Updated: 2019/06/08 05:17:34 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "ft_list.h"
#include "ft_conv.h"
#include "error.h"
#include "ft_mem.h"
#include "ft_string.h"
#include <unistd.h>

/*
** This function runs the command specified in the argument list.
**
** It first calls get_command_path, which checks for the name of the command in
** all the folders specified by the $PATH variable. If that function returns 0,
** then the command was not found. Otherwise, it should return the path to the
** command.
**
** That path is then tested to be executable and readable with access, which
** returns 0 on success. If it fails, then we do not have permission to execute
** the file.
**
** Once the path is proven to be executable, we convert the list into the
** double array of arguments to send to call_command, which deals with the
** forking and executing of the command, and returns 0 on success (TODO: make
** it return the command's return value). The double array gets deleted at the
** end without deleting the arguments, this is because the arguments are
** deleted with the list (it was easier this way).
*/

int		run_command(t_list *args)
{
	const char	*command_path;
	const char	**d_args;
	int			ret;

	command_path = get_command_path(args->content, args->content_size);
	if (!command_path)
	{
		return (print_error(args->content, E_NOTACOMMAND));
	}
	else if (access(command_path, R_OK | X_OK) != 0)
	{
		return (print_error(command_path, E_NOPERMISSION));
	}
	else
	{
		d_args = ft_lst_to_darr(args);
		ret = call_command(command_path, d_args);
		ft_memdel((void **)&d_args);
		ft_strdel((char **)&command_path);
		return (ret);
	}
}

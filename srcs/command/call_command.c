/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 23:52:42 by alan              #+#    #+#             */
/*   Updated: 2019/04/24 00:00:13 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include <unistd.h>
#include <sys/wait.h>

/*
** This function forks the process, and calls execve with the command and the
** arguments passed in.
*/

int		call_command(char *command, const char **args)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid < 0)
	{
		return (1);
	}
	else if (pid == 0)
	{
		execve(command, (char * const *)args, (char * const *)g_environ);
		return (1);
	}
	else
	{
		waitpid(pid, &stat, 0);
		return (0);
	}
}

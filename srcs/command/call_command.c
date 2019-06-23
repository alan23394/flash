/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 23:52:42 by alan              #+#    #+#             */
/*   Updated: 2019/06/22 23:29:03 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
** This function forks the process, and calls execve with the command and the
** arguments passed in.
** It returns 0 on success, 1 on failure.
** We return 1 after the call to execve, because it should never be reached
** unless the exec command fails (upon successful completion, exec switches
** processes).
*/

int		call_command(const char *command, const char **args)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid < 0)
	{
		return (print_error("call_command", E_FORKFAIL));
	}
	else if (pid == 0)
	{
		execve(command, (char *const *)args, (char *const *)g_environ);
		exit(print_builtin_error("call_command", command, E_EXECFAIL));
	}
	else
	{
		waitpid(pid, &stat, 0);
		if (WIFEXITED(stat))
			return (WEXITSTATUS(stat));
		return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:34:54 by alan              #+#    #+#             */
/*   Updated: 2019/05/15 16:31:12 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "ft_list.h"
#include "error.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

static int	check_bad_dir(const char *filename)
{
	int			ret;
	struct stat	stats;

	ret = access(filename, F_OK);
	if (ret == -1)
		return (print_error("cd", "No such file or directory"));
	else
	{
		ret = lstat(filename, &stats);
		if (ret == 0)
		{
			if ((stats.st_mode & S_IFDIR) == 0)
				return (print_error("cd", "Not a directory"));
			if (access(filename, X_OK) == -1)
				return (print_error("cd", "Permission denied"));
			return (0);
		}
		return (1);
	}
}

static int	ft_chdir(const char *newdir)
{
	const char	*wd;
	const char	*oldpwd;
	const char	*newpwd;

	if (check_bad_dir(newdir))
		return (1);
	wd = getcwd(0, 0);
	oldpwd = make_env_str("OLDPWD", wd);
	chdir(newdir);
	ft_strdel((char **)&wd);
	wd = getcwd(0, 0);
	newpwd = make_env_str("PWD", wd);
	ft_strdel((char **)&wd);
	add_env(oldpwd);
	add_env(newpwd);
	return (0);
}

/*
** If no args: cd $HOME
** If one arg: cd there
** If more than one: error
*/

int	ft_cd(t_list *args)
{
	const char	*home_env;

	if (!args)
	{
		if ((home_env = get_envn("HOME", 4)) == 0)
			return (print_error("cd", "HOME not set"));
		return (ft_chdir(home_env));
	}
	else
	{
		if (args->next)
			return (print_error("cd", "too many arguments"));
		return (ft_chdir(args->content));
	}
}

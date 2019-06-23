/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:34:54 by alan              #+#    #+#             */
/*   Updated: 2019/06/23 00:33:01 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "ft_list.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

static enum e_err_code	check_bad_dir(const char *filename)
{
	int			ret;
	struct stat	stats;

	ret = access(filename, F_OK);
	if (ret == -1)
		return (E_NOFILEORDIR);
	else
	{
		ret = stat(filename, &stats);
		if (ret == 0)
		{
			if ((stats.st_mode & S_IFDIR) == 0)
				return (E_NOTADIR);
			if (access(filename, X_OK) == -1)
				return (E_NOPERMISSION);
			return (0);
		}
		return (E_STATFAIL);
	}
}

static enum e_err_code	ft_chdir(const char *newdir)
{
	const char		*oldpwd;
	const char		*newpwd;
	enum e_err_code	error_code;

	if ((error_code = check_bad_dir(newdir)) != 0)
	{
		return (error_code);
	}
	error_code = chdir(newdir);
	if (error_code != 0)
	{
		return (E_CHDIRFAIL);
	}
	newdir = getcwd(0, 0);
	oldpwd = make_env_str("OLDPWD", get_cd_wd());
	set_cd_wd(newdir);
	newpwd = make_env_str("PWD", get_cd_wd());
	add_env(oldpwd);
	add_env(newpwd);
	return (0);
}

static int				cd_arg(const char *builtin_name, const char *arg)
{
	enum e_err_code	error_code;

	if (ft_strequ(arg, "-"))
	{
		arg = get_env_value("OLDPWD");
		if (!arg)
		{
			return (E_NOOLDPWD);
		}
	}
	error_code = ft_chdir(arg);
	if (error_code != 0)
	{
		return (print_builtin_error(builtin_name, arg, error_code));
	}
	return (0);
}

/*
** If no args: cd $HOME
** If one arg: cd there
** If more than one: error
*/

int						ft_cd(t_list *args)
{
	const char		*dir;
	const char		*builtin_name;

	if (!args)
		return (print_error("ft_cd", E_NOARGS));
	builtin_name = args->content;
	args = args->next;
	if (!args)
	{
		dir = get_env_value("HOME");
		if (!dir)
			return (print_error(builtin_name, E_HOMENOTSET));
	}
	else
	{
		if (args->next)
			return (print_error(builtin_name, E_TOOMANYARGS));
		dir = args->content;
	}
	return (cd_arg(builtin_name, dir));
}

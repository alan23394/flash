/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:01:34 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 14:19:20 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
#include "ft_list.h"
#include "ft_darr.h"

int	ft_unsetenv(t_list *args)
{
	int			ret;
	const char	*builtin_name;

	if (!args)
		return (print_error("ft_unsetenv", E_NOARGS));
	builtin_name = args->content;
	args = args->next;
	if (!args || !args->content)
		return (print_error(builtin_name, E_NOARGS));
	while (args && args->content)
	{
		ret = validate_envn_name(args->content, args->content_size);
		if (ret == 0)
			print_builtin_error(builtin_name, args->content, E_BADENVNAME);
		else
		{
			ret = get_envn_index(args->content, args->content_size);
			if (ret == -1)
				print_builtin_error(builtin_name, args->content, E_NOSUCHENV);
			else
				ft_darrrm_i(&g_environ, ret);
		}
		args = args->next;
	}
	return (0);
}

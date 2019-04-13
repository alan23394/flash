/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:01:34 by alan              #+#    #+#             */
/*   Updated: 2019/04/13 01:32:11 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_word.h"
#include "ft_darr.h"
#include "ft_printf.h"

int	ft_unsetenv(const char *command)
{
	int			ret;
	char		**words;
	int			i;

	words = ft_wordsplit(command);
	if (!words)
	{
		ft_printfd(2, "needs arguments dude\n");
		return (1);
	}
	i = 0;
	while (words[i])
	{
		ret = validate_env_name(words[i]);
		if (ret == 1)
			ft_printfd(2, "error \"%s\" bad\n", words[i]);
		else
		{
			ret = get_env_index(words[i]);
			// If we couldn't make more memory, don't hide the pointer
			// If we successfully added the pointer, set words[i] to 0 so that
			// way it doesn't get deleted
			if (ret == -1)
				ft_printfd(2, "error no such environ \"%s\"\n", words[i]);
			else
				ft_darrrm_i(&g_environ, ret);
		}
		++i;
	}
	ft_delete_darr((void **)words);
	return (0);
}

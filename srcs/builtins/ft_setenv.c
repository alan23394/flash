/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:52 by alan              #+#    #+#             */
/*   Updated: 2019/04/15 04:49:18 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_word.h"
#include "ft_printf.h"
#include "ft_darr.h"

int	ft_setenv(const char *command)
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
		if (validate_env(words[i]) == 0)
			ft_printfd(2, "error \"%s\" bad\n", words[i]);
		else
		{
			ret = add_env(words[i]);
			// If we couldn't make more memory, don't hide the pointer
			// If we successfully added the pointer, set words[i] to 0 so that
			// way it doesn't get deleted
			if (!ret)
				ft_printfd(2, "error couldn't make new memory\n");
			else
				words[i] = 0;
		}
		++i;
	}
	ft_delete_darr((void **)words);
	return (0);
}

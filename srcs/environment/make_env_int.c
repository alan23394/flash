/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:07:59 by alan              #+#    #+#             */
/*   Updated: 2019/05/16 14:56:38 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"
#include "ft_math.h"

/*
** This function takes a string that has malloced space that is guaranteed to
** fit the size of the number, and it converts the number to a string while
** placing it inside the string. It's like itoa, except for it doesn't make
** memory.
**
** The string starts at the end of the number, with the pointer pointing to the
** last digit.
**
** It will recursively break down the number, moving the string backwards with
** each step. Once the number is small enough, it will add the ascii at the
** character position. It does not care about the sign of the number.
*/

static void			ft_nbrcpy(long long nb, char *str)
{
	if (nb >= 10 || nb <= -10)
		ft_nbrcpy(nb / 10, str - 1);
	if (nb < 0)
		*str = (ft_abs(nb % 10) + '0');
	else
		*str = (nb % 10 + '0');
}

/*
** This function takes an env variable string and the length of the name at the
** beginning of that string, and the int to set it to. It doesn't change the
** environment variables, it only makes a new string and returns it.
*/

const char	*make_envn_int(const char *env, int env_namelen, int env_value)
{
	int		value_len;
	char	*new_env;

	if (!env)
		return (0);
	value_len = ft_numlen(env_value);
	new_env = ft_strnew(env_namelen + 1 + value_len);
	if (!new_env)
		return (0);
	ft_strncpy(new_env, env, env_namelen);
	new_env[env_namelen] = '=';
	ft_nbrcpy(env_value, new_env + env_namelen + 1);
	return (new_env);
}

/*
** This function takes a new env name, and the int value to set it to.
** It makes a new string with the created environment variable, and returns it,
** using make_envn_str, which takes the string length of the name.
*/

const char	*make_env_int(const char *env_name, int env_value)
{
	if (!env_name)
		return (0);
	return (make_envn_int(env_name, ft_strlen(env_name), env_value));
}

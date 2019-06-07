/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:04:21 by alan              #+#    #+#             */
/*   Updated: 2019/06/06 13:09:53 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "error.h"
#include "ft_darr.h"
#include "ft_list.h"

int	ft_env(t_list *args)
{
	if (!args)
		return (print_error("ft_env", E_NOARGS));
	ft_print_darr(g_environ);
	return (0);
}

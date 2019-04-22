/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:04:21 by alan              #+#    #+#             */
/*   Updated: 2019/04/22 05:10:45 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "ft_darr.h"
#include "ft_list.h"

int	ft_env(t_list *args)
{
	(void)args;
	ft_print_darr(g_environ);
	return (0);
}

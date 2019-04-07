/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:31:11 by alan              #+#    #+#             */
/*   Updated: 2019/04/05 16:54:37 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

/*
** This file is the configuration for my prompt strings
** For now it just has color codes in it, and the main function prototype
*/

#define DARK_MAGENTA "\e[0;35m"
#define MAGENTA "\e[1;35m"
#define NORMAL "\e[m"

void	print_prompt(int prompt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:31:11 by alan              #+#    #+#             */
/*   Updated: 2019/06/23 00:28:50 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

/*
** This file is the configuration for my prompt strings
** For now it just has color codes in it, and the main function prototype
*/

# define DARK_MAGENTA "\e[0;35m"
# define MAGENTA "\e[1;35m"
# define DARK_GREEN "\e[0;32m"
# define GREEN "\e[1;32m"
# define DARK_BLUE "\e[0;34m"
# define BLUE "\e[1;34m"
# define NORMAL "\e[m"

void	print_prompt(int prompt);

#endif

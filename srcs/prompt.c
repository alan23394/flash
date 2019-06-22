/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:25:45 by alan              #+#    #+#             */
/*   Updated: 2019/06/21 19:00:46 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "prompt.h"
#include "ft_printf.h"
#include <time.h>

/*
** Minishell prompt file
** Prompts are created in a function that gets added to a jump table
** They are one call to printf, that makes use of other functions/color codes
** Printing a prompt must be done through a call to print_prompt, which indexes
** a jump table with the sent value
** Which prompt to print gets decided when certain things happen, for example:
**	No closing single quote gets prompt 2,
**	No closing double quote gets prompt 3
** Those extra prompts/rules are not implemented yet, so for now it's just
** prompt 1, which happens for the start of every command.
** They are also subject to change, that's just the plan for now
*/

static void	prompt_1(void)
{
	char	*time;

	time = "Thu Jun 20 22:20:13 2019\n";
	ft_printf("%s%s%.19s%s%s%s%s\n%s",
			MAGENTA">",
			BLUE, time,
			MAGENTA">",
			GREEN, get_cd_wd(),
			MAGENTA">",
			MAGENTA">>> "NORMAL);
}

static void	prompt_2(void)
{
	ft_printf("%s\'> %s",
			DARK_MAGENTA,
			NORMAL);
}

static void	prompt_3(void)
{
	ft_printf("%s\"> %s",
			DARK_MAGENTA,
			NORMAL);
}

/*
** Uses a jump table to run a prompt.
** This also checks to make sure prompt_index will actually fit in the array.
** Index - 1 is used because arrays start at 0, but these things start at 1.
*/

void		print_prompt(int prompt_index)
{
	static void	(*run_prompt[3])() = {
		prompt_1,
		prompt_2,
		prompt_3,
	};

	if (prompt_index >= 1 && prompt_index <= 3)
		run_prompt[prompt_index - 1]();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:25:45 by alan              #+#    #+#             */
/*   Updated: 2019/04/05 16:54:57 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "ft_printf.h"

/*
** Minishell prompt file
** Prompts are created in a function that gets added to a jump table
** They are one call to printf, that makes use of other functions/color codes
** Printing a prompt must be done through a call to print_prompt, which indexes
** a jump table with the sent value
** Which prompt to print gets decided when certain things happen, for example:
**	No closing quote/parenthesis gets prompt 2,
**	No newline (for ex when ending line with \) gets prompt 3,
**	Not a finished script (if [ -f file ]; then [newline]) gets prompt 4
** Those extra prompts/rules are not implemented yet, so for now it's just
** prompt 1, which happens for the start of every command.
*/

static void	prompt_1()
{
	ft_printf("%s>>> %s",
			MAGENTA,
			NORMAL);
}

static void	prompt_2()
{
	ft_printf("%s> %s"
			DARK_MAGENTA,
			NORMAL);
}

void		print_prompt(int prompt)
{
	if (prompt == 1)
		prompt_1();
	else if (prompt == 2)
		prompt_2();
}

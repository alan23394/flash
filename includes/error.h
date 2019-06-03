/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 05:12:09 by alan              #+#    #+#             */
/*   Updated: 2019/06/01 12:22:01 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int	print_error(const char *command, const char *error);
int	print_builtin_error(const char *builtin, const char *command,
		const char *error);

#endif

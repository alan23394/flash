/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:10:35 by alan              #+#    #+#             */
/*   Updated: 2019/04/09 02:38:47 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

const char	**g_environ;

int			add_env(const char *env);
int			get_env_i(const char *env_name);
const char	*get_env(const char *env_name);

int			validate_env(const char *command);
int			validate_env_name(const char *command);

#endif

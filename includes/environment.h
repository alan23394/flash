/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:10:35 by alan              #+#    #+#             */
/*   Updated: 2019/04/17 11:49:41 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

const char	**g_environ;

int			add_env(const char *env);

int			get_env_index(const char *env_name);
int			get_envn_index(const char *env_name, int env_namelen);

const char	*get_env(const char *env_name);
const char	*get_envn(const char *env_name, int env_namelen);

int			get_valid_env_len(const char *env);
int			get_valid_envn_len(const char *env, int env_len);

int			validate_env_name(const char *command);
int			validate_envn_name(const char *env, int env_namelen);
int			validate_env(const char *command);

#endif

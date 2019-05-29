/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:10:35 by alan              #+#    #+#             */
/*   Updated: 2019/05/28 21:43:05 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

const char	**g_environ;

/*
** Setters
*/

int			add_envi(const char *env, int env_index);
int			add_envn(const char *env, int env_namelen);
int			add_env(const char *env);

int			set_env_int(const char *env_name, int env_value);
int			set_envn_int(const char *env, int env_namelen, int env_value);
int			set_envi_int(int env_index, int env_value);

int			set_env_str(const char *env_name, const char *env_value);
int			set_envn_str(const char *env, int env_namelen,
				const char *env_value);
int			set_envi_str(int env_index, const char *env_value);

int			inc_envn(char *env, int env_namelen);
int			inc_env(char *env_name);

/*
** Getters
*/

int			get_envi_int(int env_index);

const char	*get_env_value(const char *env_name);
const char	*get_envn_value(const char *env, int env_namelen);
const char	*get_envi_value(int env_index);

int			get_env_index(const char *env_name);
int			get_envn_index(const char *env, int env_namelen);

/*
** Utilities
*/

const char	*make_env_int(const char *env_name, int	env_value);
const char	*make_envn_int(const char *env, int env_namelen, int env_value);

const char	*make_env_str(const char *env_name, const char *env_value);
const char	*make_envn_str(const char *env, int env_namelen,
				const char *env_value);

int			get_valid_env_len(const char *env_name);
int			get_valid_envn_len(const char *env, int env_namelen);

int			validate_env_name(const char *env_name);
int			validate_envn_name(const char *env, int env_namelen);

int			validate_env(const char *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:51:08 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:32:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../core/core.h"

int		ms_builtin_export(int c, char **args, char **env, int fd);
int		ms_builtin_unset(int c, char **args, char **env, int fd);
int		ms_builtin_echo(int c, char **args, char **env, int fd);
int		ms_builtin_exit(int c, char **args, char **env, int fd);
int		ms_builtin_env(int c, char **args, char **env, int fd);
int		ms_builtin_pwd(int c, char **args, char **env, int fd);
int		ms_builtin_cd(int c, char **args, char **env, int fd);

#endif
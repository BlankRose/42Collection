/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:45:44 by cciobanu          #+#    #+#             */
/*   Updated: 2022/05/13 18:24:51 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../core/core.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_wordcount(const char *str, char c);
char	*ft_getbin(char *command, char **envp);
void	ft_freemem(char **arr);
int		pipex(int argc, char ***argv, char **envp);

#endif
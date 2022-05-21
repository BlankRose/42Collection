/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:09:37 by cciobanu          #+#    #+#             */
/*   Updated: 2022/05/20 20:17:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wordcount(const char *str, char c)
{
	int	res;
	int	issep;

	res = 0;
	issep = 1;
	while (*str)
	{
		if (*str != c && issep == 1)
		{
			issep = 0;
			res++;
		}
		else if (*str == c)
			issep = 1;
		str++;
	}
	return (res);
}

static char	*ft_commandjoin(char *path, char *command)
{
	char	*tmp;

	tmp = path;
	path = ft_strjoin(path, "/");
	if (!path)
		return (NULL);
	free(tmp);
	tmp = path;
	path = ft_strjoin(path, command);
	if (!path)
		return (NULL);
	free(tmp);
	return (path);
}

char	*ft_testbin(char *command)
{
	char	*path;

	path = 0;
	if (!access(command, F_OK))
		path = ft_strdup(command);
	return (path);
}

char	*ft_getbin(char *command, char **envp)
{
	char	*path;
	char	**paths;
	int		i;

	i = -1;
	if (!command || !envp)
		return (NULL);
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = envp[i];
	}
	paths = ft_split(&path[5], ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = ft_commandjoin(paths[i], command);
		if (!access(paths[i], F_OK))
		{
			path = ft_strdup(paths[i]);
			return (path);
		}
	}
	ft_freemem(paths);
	return (NULL);
}

void	ft_freemem(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

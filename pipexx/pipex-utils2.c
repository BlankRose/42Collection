/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:09:37 by cciobanu          #+#    #+#             */
/*   Updated: 2022/04/26 09:46:10 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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

char	*ft_strdup(const char *src)
{
	int		i;
	int		length;
	char	*tmp;

	length = 0;
	while (src[length])
		length++;
	tmp = malloc(sizeof(*tmp) * length + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_freemem(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

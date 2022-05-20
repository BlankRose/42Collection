/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:50:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 18:33:29 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ms_isvalid(char *str, int fd)
{
	char	*tmp;

	tmp = str;
	if (!ft_isalpha(*tmp) && *tmp != '_')
		return (ft_printf(fd, "%sexport: not an identifier: %s%s\n", \
		RED, str, RESETFONT));
	tmp++;
	while (*tmp)
	{
		if (!ft_isalnum(*tmp) && *tmp != '_' && *tmp != '=')
			return (ft_printf(fd, "%sexport: not an identifier: %s%s\n", \
			RED, str, RESETFONT));
		if (*tmp == '=' && tmp[1])
			return (0);
		else if (*tmp == '=' && !tmp[1])
			return (ft_printf(fd, "%sexport: missing value for identifier: %s%s \
			\n", RED, str, RESETFONT));
		tmp++;
	}
	return (1);
}

static void	ms_changeenv(char *str)
{
	char	*key;
	t_plist	*current;

	key = ft_substr(str, 0, ft_strlenlimit(str, '='));
	current = g_main->envplist;
	while (current)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(key) + 1))
		{
			free(current->value);
			current->value = ft_strdup(ft_strchr(str, '=') + 1);
		}
		current = current->next;
	}
	free(key);
}

int	ms_builtin_export(int c, char **args, char **env, int fd)
{
	char	*tmp;

	if (c < 2)
	{
		ms_builtin_env(c, args, env, fd);
		return (0);
	}
	args++;
	while (*args)
	{
		if (!ms_isvalid(*args, fd))
		{
			tmp = ms_getfromenvp(*args);
			if (!tmp[0])
				ms_lstadd_back(&g_main->envplist, ms_lstnew(ft_substr(*args, 0, \
				ft_strlenlimit(*args, '=')), ft_substr(ft_strchr(*args, '='), \
				1, ft_strlen(ft_strchr(*args, '=')) - 1)));
			else
				ms_changeenv(*args);
			free(tmp);
		}
		args++;
	}
	return (0);
}

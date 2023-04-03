/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:44:19 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:32:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ms_isvalid(char *str, int fd)
{
	if (!ft_isalpha(*str) && *str != '_')
		return (ft_printf(fd, "%sunset: %s: invalid parameter name%s%s\n", \
		RED, str, RESETFONT));
	str++;
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (ft_printf(fd, "%sunset: %s: invalid parameter name%s%s\n", \
			RED, str, RESETFONT));
		str++;
	}
	return (0);
}

static void	ms_destroy_key(char *key)
{
	t_plist		*env;
	t_plist		*prev;

	prev = 0;
	env = g_main->envplist;
	while (env)
	{
		if (!ft_strncmp(key, env->key, ft_strlen(env->key) + 1))
		{
			if (prev)
				prev->next = env->next;
			else
				g_main->envplist = env->next;
			ms_plstdelone(env, free);
			return ;
		}
		prev = env;
		env = env->next;
	}
}

int	ms_builtin_unset(int c, char **args, char **env, int fd)
{
	char	*tmp;

	if (c < 2)
	{
		ft_printf(fd, "%sunset: not enough arguments\n%s", RED, RESETFONT);
		return (1);
	}
	env = args;
	args++;
	while (*args)
	{
		if (!ms_isvalid(*args, fd))
		{
			tmp = ms_getfromenvp(*args);
			if (!tmp)
				continue ;
			ms_destroy_key(*args);
			free(tmp);
		}
		args++;
	}
	return (0);
}

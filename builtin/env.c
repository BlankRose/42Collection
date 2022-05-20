/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:02:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:29:01 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_env(int c, char **args, char **env, int fd)
{
	t_plist	*envp;

	if (c > 1 && env)
	{
		ft_printf(fd, "%senv: %s: No such file or directory\n%s", \
			RED, args[1], RESETFONT);
		return (1);
	}
	envp = g_main->envplist;
	while (envp)
	{
		ft_printf(fd, "%s=%s\n", envp->key, envp->value);
		envp = envp->next;
	}
	return (1);
}

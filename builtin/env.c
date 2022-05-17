/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:02:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 19:36:15 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_env(int c, char **args, char **env)
{
	t_plist	*envp;

	if (c > 1 && env)
	{
		ft_printf(1, "%senv: %s: No such file or directory\n%s", \
			RED, args[1], RESETFONT);
		return (1);
	}
	envp = g_main->envplist;
	while (envp)
	{
		ft_printf(1, "%s=%s\n", envp->key, envp->value);
		envp = envp->next;
	}
	return (1);
}

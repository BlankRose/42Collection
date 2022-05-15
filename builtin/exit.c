/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:02:44 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 16:35:07 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/core.h"

int	ms_builtin_exit(int c, char **args, char **env)
{
	args = env;
	if (c == 2)
		c = ft_atoi(args[1]);
	else if (c < 2)
	{
		ms_plstclear(&g_main->envplist, free);
		free(g_main->prompt_msg);
		free(g_main->envp);
		free(g_main);
		exit(c % 256);
	}
	else
		ft_printf(1, "%sexit: too many arguments\n%s", \
			RED, FONTLESS);
	return (1);
}

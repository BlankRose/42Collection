/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:02:44 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 20:01:29 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_exit(int c, char **args, char **env, int fd)
{
	t_byte	exit_code;

	env = args;
	if (c == 2)
		exit_code = ft_atoi(args[1]);
	else
		exit_code = 0;
	if (c < 3)
	{
		ms_plstclear(&g_main->envplist, free);
		ft_lstclear(g_main->tokens, free);
		ms_free_cmd(g_main->cmds);
		ft_freemem(g_main->envp);
		free(g_main->prompt_msg);
		free(g_main->line);
		free(g_main);
		exit(exit_code);
	}
	else
		ft_printf(fd, "%sexit: too many arguments\n%s", \
			RED, RESETFONT);
	return (0);
}

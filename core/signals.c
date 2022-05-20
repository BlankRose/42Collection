/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:57:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 21:50:24 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_signal_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		if (g_main->running)
		{
			printf("%sMiniShell: quit command\n%s", RED, RESETFONT);
			return ;
		}
		rl_on_new_line();
		rl_replace_line("  ", 2);
		rl_redisplay();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGINT)
	{
		printf("\n");
		if (g_main->running)
			return ;
		write(1, g_main->prompt_msg, ft_strlen(g_main->prompt_msg) - \
			ft_strlen(ft_strchr(g_main->prompt_msg, '\n')));
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ms_print_cmd(char ***cmd)
{
	t_vector2	v;

	v = ft_vector2_new(0, 0);
	if (!cmd)
		return ;
	while (cmd[v.x])
	{
		v.y = 0;
		printf("[CMD %d]==----\n", v.x);
		while (cmd[v.x][v.y])
		{
			printf("%d\t[%s]\n", v.y, cmd[v.x][v.y]);
			v.y++;
		}
		v.x++;
	}
}

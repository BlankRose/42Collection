/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:57:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:27:05 by flcollar         ###   ########.fr       */
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

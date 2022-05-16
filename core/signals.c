/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:57:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 21:32:22 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_signal_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("  ", 2);
		rl_redisplay();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGINT)
	{
		if (g_main->running)
			kill(g_main->running, SIGABRT);
		printf("\n");
		write(1, g_main->prompt_msg, ft_strlen(g_main->prompt_msg) - \
			ft_strlen(ft_strchr(g_main->prompt_msg, '\n')));
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

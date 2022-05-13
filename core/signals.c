/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:57:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 18:32:49 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_signal_handler(int sig, siginfo_t *info, void *context)
{
	static t_main	*main;

	if (sig < 0)
		main = (t_main *) context;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		ms_prompt_new(main);
	}
	if (sig == SIGQUIT)
		rl_redisplay();
	info = 0;
}

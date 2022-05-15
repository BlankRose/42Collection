/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:57:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 16:33:10 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_signal_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		ms_prompt_new();
	}
	if (sig == SIGQUIT)
		rl_redisplay();
	context = 0;
	info = 0;
}

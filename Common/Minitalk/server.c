/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:05:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/30 14:35:11 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_abort(int sig)
{
	ft_printf(1, "%s%s\nServer Instance Closed\n%s",
		RED, BOLD, RESETFONT);
	exit(sig);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	s[9];
	char		c;

	if (sig == SIGUSR2)
		s[i++] = '1';
	if (sig == SIGUSR1)
		s[i++] = '0';
	if (i == 8)
	{
		c = ft_binary2byte(s);
		if (c)
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		i = 0;
	}
	context = 0;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(1, "Server's PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	signal(SIGINT, sig_abort);
	while (TRUE)
		pause();
}

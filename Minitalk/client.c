/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:17 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/30 14:31:10 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	ft_printf(1, "%s%sReception: OK!\n%s", GREEN, BOLD, RESETFONT);
	sig = 0;
}

void	send_char(pid_t pid, unsigned char c)
{
	char			*s;
	int				i;

	s = ft_byte2binary(c);
	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
		i++;
	}
	usleep(20);
	free(s);
}

int	main(int c, char **args)
{
	pid_t	pid;
	size_t	i;

	if (c != 3)
		return (ft_printf(2, "%s%sSyntax: ./client <PID> <MESSAGE>\n%s",
				RED, BOLD, RESETFONT));
	signal(SIGUSR2, sig_handler);
	pid = ft_atoi(args[1]);
	i = 0;
	while (args[2][i])
		send_char(pid, (unsigned char) args[2][i++]);
	send_char(pid, '\0');
}

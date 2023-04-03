/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:23:36 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:28:38 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_echo(int c, char **args, char **env, int fd)
{
	size_t	i;
	int		newline;

	i = 1;
	newline = 1;
	if (args[1])
		newline = ft_strncmp("-n", args[1], 3);
	if (!newline)
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i++], fd);
		if (args[i])
			ft_putchar_fd(' ', fd);
	}
	if (!newline && c >= 1)
		ft_printf(fd, "%s%s", BG_REVERSE, RESETFONT);
	else if (newline)
		ft_putchar_fd('\n', fd);
	env = 0;
	return (0);
}

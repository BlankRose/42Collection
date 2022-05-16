/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:23:36 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 14:45:47 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/core.h"

int	ms_builtin_echo(int c, char **args, char **env)
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
		ft_putstr_fd(args[i++], 1);
		if (args[i])
			ft_putchar_fd(' ', 1);
	}
	if (!newline && c >= 1)
		ft_printf(1, "%s%s", BG_REVERSE, RESETFONT);
	else if (newline)
		ft_putchar_fd('\n', 1);
	env = 0;
	return (0);
}

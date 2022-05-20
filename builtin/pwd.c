/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:43:04 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:31:22 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_pwd(int c, char **args, char **env, int fd)
{
	char	buff[501];

	if (c > 1)
		ft_printf(fd, "%spwd: too many arguments\n%s", \
			RED, RESETFONT);
	else
	{
		getcwd(buff, 500);
		ft_putendl_fd(buff, fd);
		return (0);
	}
	args = env;
	return (1);
}

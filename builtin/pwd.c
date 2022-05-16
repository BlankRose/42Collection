/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:43:04 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 14:45:32 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/core.h"

int	ms_builtin_pwd(int c, char **args, char **env)
{
	char	buff[501];

	if (c > 1)
		ft_printf(1, "%spwd: too many arguments\n%s", \
			RED, RESETFONT);
	else
	{
		getcwd(buff, 500);
		ft_putendl_fd(buff, 1);
		return (0);
	}
	args = env;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:22:13 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 15:28:01 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <errno.h>

int	ms_builtin_cd(int c, char **args, char **env, int fd)
{
	if (c != 2)
	{
		if (c < 2)
			ft_printf(fd, "%scd: not enough arguments\n%s", RED, RESETFONT);
		else
			ft_printf(fd, "%scd: too many arguments\n%s", RED, RESETFONT);
		return (1);
	}
	env = args;
	if (chdir(args[1]))
	{
		if (errno == EACCES)
			ft_printf(fd, "%scd: %s: permission denied\n%s", \
			RED, *args, RESETFONT);
		else if (errno == ENOTDIR || errno == ENOENT)
			ft_printf(fd, "%scd: %s: is not a directory\n%s", \
			RED, *args, RESETFONT);
		else
			ft_printf(fd, "%scd: %s: something went wrong\n%s", \
			RED, *args, RESETFONT);
		return (1);
	}
	ms_set_prompt_msg();
	return (0);
}

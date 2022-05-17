/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:02:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 13:53:50 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ms_builtin_env(int c, char **args, char **env)
{
	size_t	i;

	if (c > 1)
	{
		ft_printf(1, "%senv: %s: No such file or directory\n%s", \
			RED, args[1], RESETFONT);
		return (1);
	}
	i = 0;
	while (env[i])
		ft_putendl_fd(env[i++], 1);
	return (1);
}

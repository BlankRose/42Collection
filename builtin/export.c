/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:50:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 14:04:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ms_isvalid(char *str)
{
}

int	ms_builtin_export(int c, char **args, char **env)
{
	if (c < 2)
	{
		ms_builtin_env(c, args, env);
		return (0);
	}
	args++;
	while (*args)
	{
	}
	return (0);
}

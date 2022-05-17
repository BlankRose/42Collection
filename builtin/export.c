/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:50:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 19:44:12 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ms_isvalid(char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
		return (ft_printf(1, "%sexport: not an identifier: %s%s\n", \
		RED, str, RESETFONT));
	str++;
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_' && *str != '=')
			return (ft_printf(1, "%sexport: not an identifier: %s%s\n", \
			RED, str, RESETFONT));
		if (*str == '=')
			return (0);
		str++;
	}
	return (1);
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
		if (!ms_isvalid(*args))
			ms_lstadd_back(&g_main->envplist, ms_lstnew(ft_substr(*args, 0, \
			ft_strlenlimit(*args, '=')), ft_substr(ft_strchr(*args, '='), 1, \
			ft_strlen(ft_strchr(*args, '=')) - 1)));
		args++;
	}
	return (0);
}

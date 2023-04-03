/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:59:01 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/22 18:48:38 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isset(int c, const char *set)
{
	int		i;

	i = 0;
	while (set && set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

int	ft_contains(const char *str, const char *set)
{
	int		i;

	i = 0;
	while (str && str[i])
		if (ft_isset(str[i++], set))
			return (1);
	return (0);
}

int	ft_endswith(const char *str, const char *s)
{
	int	i;
	int	y;

	if (!str || !s)
		return (0);
	i = ft_strlen(str) - 1;
	y = ft_strlen(s) - 1;
	while (i && str[i] == s[y])
	{
		i--;
		if (--y < 0)
			return (1);
	}
	return (0);
}

int	ft_startswith(const char *str, const char *s)
{
	size_t	i;

	if (!str || !s)
		return (0);
	i = 0;
	while (str[i] && str[i] == s[i])
		if (!s[++i])
			return (1);
	return (0);
}

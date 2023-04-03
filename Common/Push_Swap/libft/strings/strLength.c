/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strLength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:31:31 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/06 16:24:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strlenlimit(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	ft_strlenlimitrev(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] == c)
		i++;
	return (i);
}

size_t	ft_strlenlimitset(const char *s, char *set)
{
	size_t	i;

	i = 0;
	while (s && s[i] && !ft_isset(s[i], set))
		i++;
	return (i);
}

size_t	ft_strlenlimitsetrev(const char *s, char *set)
{
	size_t	i;

	i = 0;
	while (s && s[i] && ft_isset(s[i], set))
		i++;
	return (i);
}

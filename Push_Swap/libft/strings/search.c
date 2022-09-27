/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:30:46 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 09:28:12 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*y;
	int			i;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == c)
			y = &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	if (y)
		return ((char *) y);
	return (0);
}

size_t	ft_strnchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *) str);
	while (str[i] && i < len)
	{
		y = 0;
		while (str[i + y] == needle[y] && (i + y) < len)
			if (!needle[++y])
				return ((char *) &str[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlstr(const char *str, const char *needle, size_t len)
{
	size_t	found;
	char	*y;

	found = 0;
	y = ft_strnstr(str, needle, len);
	while (y)
	{
		found++;
		y = ft_strnstr(&y[1], needle, len);
	}
	return (found);
}

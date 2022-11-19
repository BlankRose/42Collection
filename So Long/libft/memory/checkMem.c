/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:15:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:40:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_memlen(const void *s)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (!s)
		return (i);
	str = (unsigned char *) s;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	y;
	size_t			i;

	i = 0;
	y = c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == y)
			return ((void *) &str[i]);
		i++;
	}
	return (0);
}

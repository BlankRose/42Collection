/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeMem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:43:43 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:43:00 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *) s;
	while (i < n)
		str[i++] = '\0';
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	y;
	size_t			i;

	i = 0;
	y = c;
	str = (unsigned char *) b;
	while (i < len)
		str[i++] = y;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) dst;
	str2 = (unsigned char *) src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) dst;
	str2 = (unsigned char *) src;
	temp = str2;
	while (i < len)
	{
		str1[i] = temp[i];
		i++;
	}
	return (dst);
}

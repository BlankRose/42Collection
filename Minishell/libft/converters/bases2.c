/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:53:10 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/30 13:07:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_base2base(char *s, char *b1, char *b2)
{
	return (ft_dec2base(ft_base2dec(s, b1), b2));
}

char	*ft_byte2binary(t_byte c)
{
	char	*s;
	int		i;
	int		y;

	i = 9;
	y = 0;
	s = ft_calloc(i--, sizeof(char));
	if (!s)
		return (0);
	s[i--] = '\0';
	while (i >= 0)
	{
		if (ft_power(2, i) <= c)
		{
			s[y++] = '1';
			c -= ft_power(2, i);
		}
		else
			s[y++] = '0';
		i--;
	}
	return (s);
}

t_byte	ft_binary2byte(char *s)
{
	unsigned char	c;
	size_t			i;
	size_t			y;

	y = 7;
	i = 0;
	c = 0;
	while (i < 8 && s[i])
		c += ft_power((s[i++] - '0') * 2, y--);
	return (c);
}

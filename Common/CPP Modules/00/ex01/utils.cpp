/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:47:44 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 20:49:53 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static size_t	ft_nbrlen(unsigned int x)
{
	size_t	i;

	i = 1;
	while (x > 9)
	{
		x /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa2(char *str, unsigned int nbr, size_t i)
{
	str[i--] = (nbr % 10) + '0';
	while (nbr > 9)
	{
		nbr /= 10;
		str[i--] = (nbr % 10) + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t				len;
	char				*str;

	len = 0;
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	len += ft_nbrlen(nbr);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len--] = '\0';
	return (ft_itoa2(str, nbr, len));
}
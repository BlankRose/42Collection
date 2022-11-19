/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:49:56 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:40:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_itoa2(char *str, unsigned long long nbr, size_t i)
{
	str[i--] = (nbr % 10) + '0';
	while (nbr > 9)
	{
		nbr /= 10;
		str[i--] = (nbr % 10) + '0';
	}
	return (str);
}

char	*ft_itoa_long(long long n)
{
	unsigned long long	nbr;
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
	len += ft_nbrlen_long(nbr);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len--] = '\0';
	return (ft_itoa2(str, nbr, len));
}

char	*ft_itoa_unsigned_long(unsigned long long n)
{
	size_t				len;
	char				*str;

	len = ft_nbrlen_long(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	return (ft_itoa2(str, n, len));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	return (ft_itoa_unsigned_long((long long) n));
}

char	*ft_itoa(int n)
{
	return (ft_itoa_long((long long) n));
}

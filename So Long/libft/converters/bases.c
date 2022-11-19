/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:57 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:40:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_checkbase(char *base)
{
	size_t	i;

	i = 0;
	while (base && base[i])
	{
		if (ft_isset(base[i], &base[i + 1]))
			return (0);
		if (ft_isspace(base[i]) || ft_issign(base[i]))
			return (0);
		i++;
	}
	return (i);
}

unsigned int	ft_base2dec(char *s, char *base)
{
	size_t			len;
	size_t			i;
	unsigned int	r;
	int				sign;

	len = ft_checkbase(base);
	if (!s || len < 2)
		return (0);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	sign = 1;
	while (ft_issign(s[i]))
		if (s[i++] == '-')
			sign = -1;
	r = 0;
	while (ft_isset(s[i], base))
		r = (r * len) + ft_strlenlimit(base, s[i++]);
	return (r);
}

static char	*ft_dec2base2(t_vector3 v, unsigned long long nb, char *base)
{
	char	*r;

	r = (char *) malloc((v.z + 1) * sizeof(char));
	if (!r)
		return (0);
	r[v.z--] = '\0';
	if (v.y < 0)
		r[0] = '-';
	while (nb > (unsigned long long) v.x - 1)
	{
		r[v.z--] = base[nb % v.x];
		nb /= v.x;
	}
	r[v.z] = base[nb % v.x];
	return (r);
}

char	*ft_dec2base(unsigned int n, char *base)
{
	t_vector3		v;

	v = ft_vector3_new(ft_checkbase(base), 1, 0);
	if (v.x < 2)
		return (0);
	if (n < 0)
	{
		v.y = -v.y;
		v.z++;
	}
	v.z += ft_nbrlen_base(n, v.x);
	return (ft_dec2base2(v, (unsigned long long) n, base));
}

char	*ft_ptr2base(void *x, char *base)
{
	unsigned long long	nb;
	t_vector3			v;

	nb = (unsigned long long) x;
	v = ft_vector3_new(ft_checkbase(base), 1, 0);
	if (v.x < 2)
		return (0);
	if (x < 0)
	{
		v.y = -v.y;
		v.z++;
	}
	v.z += ft_nbrlen_base(nb, v.x);
	return (ft_dec2base2(v, nb, base));
}

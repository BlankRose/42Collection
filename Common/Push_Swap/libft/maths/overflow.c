/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:13:41 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/06 10:20:49 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_overflow(char *n, char *cmp, int sign)
{
	int		i;

	if (!n || !cmp)
		return (0);
	if (ft_strlen(n) < ft_strlen(cmp))
		return (0);
	else if (ft_strlen(n) > ft_strlen(cmp))
		return (1);
	else
	{
		i = 0;
		while (n[i] && cmp[i] && n[i] == cmp[i])
			i++;
		if ((sign >= 0 && n[i] <= cmp[i])
			|| (sign < 0 && n[i] >= cmp[i]))
			return (0);
		else
			return (1);
	}
}

int	ft_intoverflow(char *n)
{
	char	*cmp;
	int		sign;
	int		t;

	if (!n)
		return (0);
	sign = ft_issign(n[0]);
	if (sign > 0)
		n++;
	if (sign < 0)
		cmp = ft_itoa(INT_MIN);
	else
		cmp = ft_itoa(INT_MAX);
	t = ft_overflow(n, cmp, sign);
	free (cmp);
	return (t);
}

int	ft_longoverflow(char *n)
{
	char	*cmp;
	int		sign;
	int		t;

	if (!n)
		return (0);
	sign = ft_issign(n[0]);
	if (sign > 0)
		n++;
	if (sign < 0)
		cmp = ft_itoa_long(LONG_MIN);
	else
		cmp = ft_itoa_long(LONG_MAX);
	t = ft_overflow(n, cmp, sign);
	free (cmp);
	return (t);
}

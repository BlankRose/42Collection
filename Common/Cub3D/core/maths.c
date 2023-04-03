/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:40:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 18:44:15 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

float	cb_abs(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

double	cb_dabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_max1(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}

int	ft_mod1(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

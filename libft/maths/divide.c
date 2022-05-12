/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:16:01 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/11 17:42:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_uint	ft_get_gcd(int x, int y)
{
	t_uint	ux;
	t_uint	uy;
	t_uint	gcd;

	if (!x || !y)
		return (0);
	if (x < 0)
		x = -x;
	ux = x;
	if (y < 0)
		y = -y;
	uy = y;
	gcd = ux;
	if (ux > uy)
		gcd = uy;
	while (uy % gcd || ux % gcd)
		gcd--;
	return (gcd);
}

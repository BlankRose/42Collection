/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:43:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/01 15:28:11 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_min(int x, int min)
{
	if (x < min)
		return (min);
	return (x);
}

int	ft_max(int x, int max)
{
	if (x > max)
		return (max);
	return (x);
}

int	ft_clamp(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

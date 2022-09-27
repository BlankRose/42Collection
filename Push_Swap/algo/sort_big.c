/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:26:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 15:59:37 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_sort_big(t_list **a, t_list **b, t_info *data)
{
	size_t	bits;
	size_t	i;
	size_t	y;

	bits = 0;
	while (ft_power(2, bits) <= data->value_max)
		bits++;
	i = 0;
	while (i < bits)
	{
		y = 0;
		while (y++ < data->size)
		{
			if ((*(int *)(*a)->content >> i) & 1)
				ps_rotate_a(a);
			else
				ps_push_b(a, b);
		}
		while (*b)
			ps_push_a(a, b);
		i++;
	}
}

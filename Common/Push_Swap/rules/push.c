/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:56:56 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/05 09:53:36 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ps_push(t_list **src, t_list **dst)
{
	t_list	*current;

	if (!*src)
		return (0);
	current = *src;
	*src = (*src)->next;
	current->next = *dst;
	*dst = current;
	return (1);
}

void	ps_push_a(t_list **a, t_list **b)
{
	if (ps_push(b, a))
		ft_printf(1, "pa\n");
}

void	ps_push_b(t_list **a, t_list **b)
{
	if (ps_push(a, b))
		ft_printf(1, "pb\n");
}

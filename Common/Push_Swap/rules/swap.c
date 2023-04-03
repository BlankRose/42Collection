/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:23:39 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/31 18:29:48 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ps_swap(t_list **c)
{
	t_list	*current;

	if (!*c || !(*c)->next)
		return (0);
	current = (*c)->next;
	(*c)->next = current->next;
	current->next = *c;
	*c = current;
	return (1);
}

void	ps_swap_a(t_list **a)
{
	if (ps_swap(a))
		ft_printf(1, "sa\n");
}

void	ps_swap_b(t_list **b)
{
	if (ps_swap(b))
		ft_printf(1, "sb\n");
}

void	ps_swap_s(t_list **a, t_list **b)
{
	if (ps_swap(a) || ps_swap(b))
		ft_printf(1, "ss\n");
}

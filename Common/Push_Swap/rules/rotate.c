/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:03:11 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/05 11:14:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ps_rotate(t_list **c)
{
	t_list	*current;

	if (!*c)
		return (0);
	current = *c;
	*c = (*c)->next;
	current->next = 0;
	ft_lstlast(*c)->next = current;
	return (1);
}

void	ps_rotate_a(t_list **a)
{
	if (ps_rotate(a))
		ft_printf(1, "ra\n");
}

void	ps_rotate_b(t_list **b)
{
	if (ps_rotate(b))
		ft_printf(1, "rb\n");
}

void	ps_rotate_r(t_list **a, t_list **b)
{
	if (ps_rotate(a) || ps_rotate(b))
		ft_printf(1, "rr\n");
}

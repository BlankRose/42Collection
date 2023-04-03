/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaterev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:51:40 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/05 10:36:24 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ps_revrotate(t_list **c)
{
	t_list	*current;
	t_list	*last;
	int		i;

	if (!*c)
		return (0);
	i = ft_lstsize(*c);
	current = ft_lstlocate(*c, i - 2);
	last = current->next;
	last->next = *c;
	current->next = 0;
	*c = last;
	return (1);
}

void	ps_rotate_ra(t_list **a)
{
	if (ps_revrotate(a))
		ft_printf(1, "rra\n");
}

void	ps_rotate_rb(t_list **b)
{
	if (ps_revrotate(b))
		ft_printf(1, "rrb\n");
}

void	ps_rotate_rr(t_list **a, t_list **b)
{
	if (ps_revrotate(a) || ps_revrotate(b))
		ft_printf(1, "rrr\n");
}

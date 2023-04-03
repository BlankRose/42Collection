/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:28:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 15:43:05 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Quick checks the order of a STACK of 3 values */
static int	ps_check_order(t_list **stack)
{
	t_vector3	v;

	v.z = *((int *)(*stack)->content);
	v.y = *((int *)(*stack)->next->content);
	v.x = *((int *)(*stack)->next->next->content);
	if (v.x > v.z && v.z > v.y)
		return (213);
	else if (v.z > v.y && v.y > v.x)
		return (321);
	else if (v.z > v.x && v.x > v.y)
		return (312);
	else if (v.y > v.x && v.x > v.z)
		return (132);
	else if (v.y > v.z && v.z > v.x)
		return (231);
	return (123);
}

/* Quick sorts a STACK of 3 values */
static void	ps_sort_trio(t_list **stack)
{
	int		order;

	order = ps_check_order(stack);
	while (order != 123)
	{
		if (order == 132 || order == 321 || order == 213)
			ps_swap_a(stack);
		else if (order == 312)
			ps_rotate_a(stack);
		else if (order == 231)
			ps_rotate_ra(stack);
		order = ps_check_order(stack);
	}
}

/* Checks wether VALUE can be safely inserted within LST, to keep it sorted
Return: 1 (TRUE) or 0 (FALSE) */
int	ps_can_insert(t_list **lst, t_list *value, t_info data)
{
	t_vector3	v;

	v = ft_vector3_new(*((int *) value->content), \
		*((int *)(*lst)->content), *((int *) ft_lstlast(*lst)->content));
	if ((v.x <= data.value_min && v.z >= data.value_max)
		|| (v.x >= data.value_max && v.y <= data.value_min)
		|| (v.x >= v.z && v.x <= v.y))
		return (1);
	return (0);
}

void	ps_sort_small(t_list **a, t_list **b, t_info *data)
{
	size_t		i;

	i = data->size;
	while (i > 3)
	{
		ps_push_b(a, b);
		i--;
	}
	ps_sort_trio(a);
	while (i < data->size)
	{
		while (!ps_can_insert(a, *b, ps_data_init(a)))
			ps_rotate_a(a);
		ps_push_a(a, b);
		i++;
	}
	if (!ps_get_closest(a, data->value_max))
		while (!ps_issorted(a))
			ps_rotate_ra(a);
	while (!ps_issorted(a))
		ps_rotate_a(a);
}

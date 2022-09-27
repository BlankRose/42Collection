/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:12:20 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 15:58:13 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ps_issorted(t_list **stack)
{
	t_list	*current;
	int		prev;
	int		tmp;

	current = *stack;
	prev = *((int *) current->content);
	while (current)
	{
		tmp = *((int *) current->content);
		if (tmp < prev)
			return (FALSE);
		prev = tmp;
		current = current->next;
	}
	return (TRUE);
}

int	ps_get_closest(t_list **stack, int value)
{
	t_list	*current;
	t_info	data;
	size_t	i;
	int		s;

	i = 0;
	data = ps_data_init(stack);
	current = *stack;
	while (current)
	{
		s = *((int *) current->content);
		if (s == value)
			break ;
		if (i >= data.size / 2)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

t_info	ps_data_init(t_list **stack)
{
	t_list	*current;
	t_info	data;

	data.size = 0;
	data.value_min = 0;
	data.value_max = 0;
	current = *stack;
	if (current)
	{
		data.value_min = *((int *) current->content);
		data.value_max = *((int *) current->content);
		data.size++;
		current = current->next;
	}
	while (current)
	{
		if (*((int *) current->content) < data.value_min)
			data.value_min = *((int *) current->content);
		else if (*((int *) current->content) > data.value_max)
			data.value_max = *((int *) current->content);
		data.size++;
		current = current->next;
	}
	return (data);
}

void	ps_pre_emptive(t_list **stack)
{
	t_list	*current;
	int		*array;
	size_t	i;

	current = *stack;
	array = ft_lst2range(*stack);
	ft_sort_array(array, ft_lstsize(*stack));
	while (current)
	{
		i = 0;
		while (i < ft_lstsize(*stack))
		{
			if (array[i++] == *(int *) current->content)
			{
				ft_lstupdate(current, free, ft_rangeone(i - 1));
				continue ;
			}
		}
		current = current->next;
	}
	free(array);
}

void	ps_sorting_init(t_list **a, t_list **b)
{
	t_info	data;

	if (ps_issorted(a))
		return ;
	else if (ft_lstsize(*a) == 2)
		ps_rotate_a(a);
	else
	{
		ps_pre_emptive(a);
		data = ps_data_init(a);
		if (data.size <= 5)
			ps_sort_small(a, b, &data);
		else
			ps_sort_big(a, b, &data);
	}
}

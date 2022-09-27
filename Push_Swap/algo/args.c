/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:50:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 12:09:03 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Converts and puts the ARGS into the chained list STACK
Return: STACK */
static t_list	**ps_arg2lst(t_list **stack, char **args)
{
	size_t	i;

	if (!args)
		return (0);
	i = 0;
	if (args[i])
		(*stack)->content = ft_strdup(args[i++]);
	while (args[i])
		ft_lstadd_back(stack, ft_lstnew(ft_strdup(args[i++])));
	return (stack);
}

/* Checks for the content of LST, by checking wether it fits
in a INT or if there's any unwanted duplicates
Return: 1 (PASS) or 0 (FAIL) */
static int	ps_content_checker(t_list *lst)
{
	t_list	*next;

	if (!lst || !lst->content)
		return (0);
	if (!ft_isnum(lst->content))
		return (0);
	if (ft_intoverflow(lst->content))
		return (0);
	next = lst->next;
	while (next)
	{
		if (!ft_strncmp(lst->content, next->content, 11))
			return (0);
		next = next->next;
	}
	return (1);
}

t_list	**ps_args_handler(int c, char **args, t_list **stack)
{
	t_list	*current;
	char	**split;

	if (c == 1)
	{
		split = ft_split(args[0], ' ');
		stack = ps_arg2lst(stack, split);
		ft_free_array((void **) split, ft_array_len((void **) split));
	}
	else if (c > 1)
		stack = ps_arg2lst(stack, args);
	if (!stack || c < 1)
		return (0);
	current = *stack;
	while (current)
	{
		if (!ps_content_checker(current))
			return (0);
		ft_lstupdate(current, free, ft_rangeone(ft_atoi(current->content)));
		current = current->next;
	}
	return (stack);
}

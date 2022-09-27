/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:21:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 14:38:41 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int c, char **args)
{
	t_list	*a;
	t_list	*b;

	if (c < 2)
		return (0);
	a = ft_lstnew(0);
	if (!ps_args_handler(--c, &args[1], &a))
	{
		ft_lstclear(&a, free);
		return (ft_printf(2, "Error\n"));
	}
	b = 0;
	ps_sorting_init(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}

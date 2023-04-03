/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 13:29:06 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_range(int min, int max)
{
	int		*array;
	int		tmp;
	size_t	i;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	i = max - min;
	array = (int *) ft_calloc(i + 1, sizeof(int));
	while (array && min <= max && i >= 0)
		array[i--] = max--;
	return (array);
}

int	*ft_rangerev(int min, int max)
{
	int		*array;
	int		tmp;
	size_t	i;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	i = max - min;
	array = (int *) ft_calloc(i + 1, sizeof(int));
	while (array && min <= max && i >= 0)
		array[i--] = min++;
	return (array);
}

int	*ft_rangeone(int nbr)
{
	int		*array;

	array = (int *) ft_calloc(1, sizeof(int));
	if (array)
		array[0] = nbr;
	return (array);
}

int	*ft_lst2range(t_list *lst)
{
	int		*array;
	size_t	i;

	if (!lst)
		return (0);
	array = (int *) ft_calloc(ft_lstsize(lst), sizeof(int));
	i = 0;
	while (array && lst)
	{
		array[i++] = *((int *) lst->content);
		lst = lst->next;
	}
	return (array);
}

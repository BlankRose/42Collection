/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:45:42 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 13:54:58 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_sort_array(int *array, size_t n)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:58:20 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/06 10:59:48 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_free_multi(void *s1, void *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (0);
}

void	**ft_free_array(void **array, size_t n)
{
	while (n)
		free(array[--n]);
	free(array);
	return (0);
}

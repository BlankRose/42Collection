/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:08:02 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/22 12:20:08 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (!i)
		return (0);
	ft_bzero(i, count * size);
	return (i);
}

char	*ft_realloc(char *prev, size_t n)
{
	char	*new;

	n += ft_strlen(prev);
	new = (char *) ft_calloc(n + 1, sizeof(char));
	if (!prev || !new)
		return (new);
	ft_strlcpy(new, prev, n);
	free(prev);
	return (new);
}

char	*ft_free_multi(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (0);
}

char	**ft_free_array(char **array, size_t n)
{
	while (n)
		free(array[--n]);
	free(array);
	return (0);
}
